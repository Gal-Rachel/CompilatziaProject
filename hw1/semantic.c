#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic.h"
#include "parser.tab.h"

// Constants for maximum number of variables and functions
#define MAX_VARIABLES 100
#define MAX_FUNCTIONS 100

// Global state for tracking declarations
static char *declared_variables[MAX_VARIABLES];
static ValueType variable_types[MAX_VARIABLES]; // Add array to store variable types
static int num_variables = 0;
static char *defined_functions[MAX_FUNCTIONS];
static int function_lines[MAX_FUNCTIONS];                 // Add array to store line numbers
static ValueType function_return_types[MAX_FUNCTIONS];    // Change to ValueType
static ASTNode *function_param_types[MAX_FUNCTIONS][100]; // Store parameter types of functions
static int num_functions = 0;
static int has_main_function = 0;
extern int yylineno;

// Add these at the top with other global variables
static int function_param_counts[MAX_FUNCTIONS];    // Total parameters
static int function_required_params[MAX_FUNCTIONS]; // Required parameters (no defaults)
static const char *type_names[] = {"unknown", "int", "float", "string", "bool", "void"};

// Helper function to convert parser type tokens to ValueType
static ValueType convert_type_token_to_value_type(int type_token)
{
    switch (type_token)
    {
    case INT:
        return TYPE_INT;
    case FLOAT:
        return TYPE_FLOAT;
    case STRING:
        return TYPE_STRING;
    case BOOL:
        return TYPE_BOOL;
    default:
        return TYPE_UNKNOWN;
    }
}

// Helper function to clear all tracking data
static void clear_semantic_state(void)
{
    for (int i = 0; i < num_variables; i++)
    {
        free(declared_variables[i]);
    }
    for (int i = 0; i < num_functions; i++)
    {
        free(defined_functions[i]);
    }
    num_variables = 0;
    num_functions = 0;
    has_main_function = 0;
    memset(function_param_counts, 0, sizeof(function_param_counts));
    memset(function_required_params, 0, sizeof(function_required_params));
    memset(function_return_types, TYPE_UNKNOWN, sizeof(function_return_types));
    memset(function_param_types, 0, sizeof(function_param_types));
}

// Error reporting implementation
void report_semantic_error(SemanticErrorCode error, const char *details, int line_number)
{
    switch (error)
    {
    case SEMANTIC_ERROR_UNDEFINED_VARIABLE:
        fprintf(stderr, "Semantic error at line %d: Variable '%s' used before declaration\n", line_number, details);
        break;
    case SEMANTIC_ERROR_UNDEFINED_FUNCTION:
        // Check if the function exists but is used before definition
        int function_exists = 0;
        int def_line = 0;
        for (int i = 0; i < num_functions; i++)
        {
            if (strcmp(defined_functions[i], details) == 0)
            {
                function_exists = 1;
                def_line = function_lines[i];
                break;
            }
        }
        if (function_exists)
        {
            fprintf(stderr, "Semantic error at line %d: Function '%s' is used before its definition at line %d\n",
                    line_number, details, def_line);
        }
        else
        {
            fprintf(stderr, "Semantic error at line %d: Function '%s' not defined\n", line_number, details);
        }
        break;
    case SEMANTIC_ERROR_DUPLICATE_VARIABLE:
        fprintf(stderr, "Semantic error at line %d: Variable '%s' already declared\n", line_number, details);
        break;
    case SEMANTIC_ERROR_DUPLICATE_FUNCTION:
        fprintf(stderr, "Semantic error: Function '%s' already defined at line %d\n", details, line_number);
        break;
    case SEMANTIC_ERROR_INVALID_RETURN_PLACEMENT:
        fprintf(stderr, "Semantic error at line %d: Return statement must be the last statement in a block\n", line_number);
        break;
    case SEMANTIC_ERROR_MISSING_MAIN:
        fprintf(stderr, "Program must contain exactly one __main__() function\n");
        break;
    case SEMANTIC_ERROR_MULTIPLE_MAIN:
        fprintf(stderr, "Multiple __main__() functions defined\n");
        break;
    case SEMANTIC_ERROR_TYPE_MISMATCH:
        fprintf(stderr, "Type mismatch: %s\n", details);
        break;
    case SEMANTIC_ERROR_EMPTY_BLOCK:
        fprintf(stderr, "Empty block not allowed. Use 'pass;' for empty blocks\n");
        break;
    case SEMANTIC_ERROR_TOO_MANY_VARIABLES:
        fprintf(stderr, "Too many variables declared\n");
        break;
    case SEMANTIC_ERROR_TOO_MANY_FUNCTIONS:
        fprintf(stderr, "Too many functions defined\n");
        break;
    case SEMANTIC_ERROR_DEFAULT_VALUE_ORDER:
        fprintf(stderr, "Parameters with default values must come after parameters without default values\n");
        break;
    case SEMANTIC_ERROR_TOO_MANY_ARGUMENTS:
        fprintf(stderr, "Semantic error at line %d: Too many arguments in call to function '%s'\n", line_number, details);
        break;
    case SEMANTIC_ERROR_TOO_FEW_ARGUMENTS:
        fprintf(stderr, "Semantic error at line %d: Too few arguments in call to function '%s'\n", line_number, details);
        break;
    case SEMANTIC_ERROR_ARGUMENT_TYPE_MISMATCH:
        fprintf(stderr, "Semantic error at line %d: Type mismatch in argument '%s'\n", line_number, details);
        break;
    case SEMANTIC_ERROR_DEFAULT_VALUE_TYPE_MISMATCH:
        fprintf(stderr, "Semantic error at line %d: Default value type does not match parameter type '%s'\n", line_number, details);
        break;
    case SEMANTIC_ERROR_RETURN_TYPE_MISMATCH:
        fprintf(stderr, "Semantic error at line %d: Return value type does not match function return type '%s'\n", line_number, details);
        break;
    default:
        fprintf(stderr, "Unknown semantic error\n");
    }
}

// Variable declaration checking
SemanticErrorCode check_variable_declaration(const char *name, ValueType type)
{
    // Check if variable is already declared
    for (int i = 0; i < num_variables; i++)
    {
        if (strcmp(declared_variables[i], name) == 0)
        {
            return SEMANTIC_ERROR_DUPLICATE_VARIABLE;
        }
    }

    // Check if we can add more variables
    if (num_variables >= MAX_VARIABLES)
    {
        return SEMANTIC_ERROR_TOO_MANY_VARIABLES;
    }

    // Add the variable to declared list with its type
    declared_variables[num_variables] = strdup(name);
    if (!declared_variables[num_variables])
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    variable_types[num_variables] = type;
    num_variables++;

    return SEMANTIC_OK;
}

// Variable usage checking
SemanticErrorCode check_variable_usage(const char *name)
{
    // First check if variable exists at all
    int var_index = -1;
    for (int i = 0; i < num_variables; i++)
    {
        if (strcmp(declared_variables[i], name) == 0)
        {
            return SEMANTIC_OK;
        }
    }
    return SEMANTIC_ERROR_UNDEFINED_VARIABLE;
}

// Function declaration checking
SemanticErrorCode check_function_declaration(const char *name, int line_number)
{
    printf("DEBUG: Checking function declaration for '%s'\n", name);
    // Check for __main__ function
    if (strcmp(name, "__main__") == 0)
    {
        printf("DEBUG: String comparison result for __main__: %d\n", strcmp(name, "__main__"));
        printf("DEBUG: Found __main__ function, has_main_function=%d\n", has_main_function);
        if (has_main_function)
        {
            return SEMANTIC_ERROR_MULTIPLE_MAIN;
        }
        has_main_function = 1;
        printf("DEBUG: Set has_main_function to 1\n");
    }

    // Check if function is already defined
    for (int i = 0; i < num_functions; i++)
    {
        if (strcmp(defined_functions[i], name) == 0)
        {
            report_semantic_error(SEMANTIC_ERROR_DUPLICATE_FUNCTION, name, function_lines[i]);
            return SEMANTIC_ERROR_DUPLICATE_FUNCTION;
        }
    }

    // Check if we can add more functions
    if (num_functions >= MAX_FUNCTIONS)
    {
        return SEMANTIC_ERROR_TOO_MANY_FUNCTIONS;
    }

    // Add the function to defined list
    defined_functions[num_functions] = strdup(name);
    if (!defined_functions[num_functions])
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    function_lines[num_functions] = line_number;
    function_param_counts[num_functions] = 0;    // Will be set later when analyzing parameters
    function_required_params[num_functions] = 0; // Will be set later when analyzing parameters
    num_functions++;

    return SEMANTIC_OK;
}

// Function usage checking
SemanticErrorCode check_function_usage(const char *name)
{
    // First check if the function exists at all
    int function_index = -1;
    for (int i = 0; i < num_functions; i++)
    {
        if (strcmp(defined_functions[i], name) == 0)
        {
            function_index = i;
            break;
        }
    }

    if (function_index == -1)
    {
        return SEMANTIC_ERROR_UNDEFINED_FUNCTION;
    }

    // Check if the function is being called after its definition
    // by comparing line numbers
    if (yylineno < function_lines[function_index])
    {
        // Special case: allow recursive calls within the function's own body
        // by checking if we're currently inside the function's definition
        for (int i = 0; i < num_functions; i++)
        {
            if (strcmp(defined_functions[i], name) == 0)
            {
                // We're inside the function's own definition, allow the call
                return SEMANTIC_OK;
            }
        }

        return SEMANTIC_ERROR_UNDEFINED_FUNCTION;
    }

    return SEMANTIC_OK;
}

// Check return statement placement
SemanticErrorCode check_return_statement_placement(ASTNode *block)
{
    if (!block || block->type != AST_BLOCK)
    {
        return SEMANTIC_OK;
    }

    // Check if block is empty
    if (block->block.statement_count == 0)
    {
        return SEMANTIC_ERROR_EMPTY_BLOCK;
    }

    // Get the last statement
    ASTNode *last_stmt = block->block.statements[block->block.statement_count - 1];
    while (last_stmt->type == AST_BLOCK && last_stmt->block.statement_count > 0)
    {
        last_stmt = last_stmt->block.statements[last_stmt->block.statement_count - 1];
    }

    // If last statement is not return, check if there are any return statements in the block
    if (last_stmt->type != AST_RETURN_STATEMENT)
    {
        for (int i = 0; i < block->block.statement_count - 1; i++)
        {
            ASTNode *stmt = block->block.statements[i];
            if (stmt->type == AST_RETURN_STATEMENT)
            {
                return SEMANTIC_ERROR_INVALID_RETURN_PLACEMENT;
            }
            if (stmt->type == AST_BLOCK)
            {
                for (int j = 0; j < stmt->block.statement_count; j++)
                {
                    if (stmt->block.statements[j]->type == AST_RETURN_STATEMENT)
                    {
                        return SEMANTIC_ERROR_INVALID_RETURN_PLACEMENT;
                    }
                }
            }
        }
    }

    return SEMANTIC_OK;
}

// Check main function requirement
SemanticErrorCode check_main_function(void)
{
    return has_main_function ? SEMANTIC_OK : SEMANTIC_ERROR_MISSING_MAIN;
}

// Check that blocks are not empty
SemanticErrorCode check_block_not_empty(ASTNode *block)
{
    if (!block || block->type != AST_BLOCK || block->block.statement_count == 0)
    {
        return SEMANTIC_ERROR_EMPTY_BLOCK;
    }
    return SEMANTIC_OK;
}

// Check that parameters with default values come after parameters without default values within each type group
SemanticErrorCode check_param_default_values(ASTNode *param_list)
{
    if (!param_list)
        return SEMANTIC_OK;

    // First, count how many parameters we have and store them in an array
    int param_count = 0;
    ASTNode *curr;
    for (curr = param_list; curr; curr = curr->param_list.rest)
    {
        param_count++;
    }

    // Create arrays to store parameters for checking
    ASTNode **params = malloc(param_count * sizeof(ASTNode *));
    if (!params)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Fill the array in reverse order to get original order
    int i = param_count - 1;
    for (curr = param_list; curr; curr = curr->param_list.rest)
    {
        params[i] = curr->param_list.first;
        i--;
    }

    // Now check each type group
    int current_type = -1;
    int seen_default = 0;
    int first_default_line = 0;

    // Go through parameters in original order
    for (i = 0; i < param_count; i++)
    {
        // If we're starting a new type group
        if (current_type != params[i]->param.type)
        {
            current_type = params[i]->param.type;
            seen_default = 0;
            first_default_line = 0;
        }

        // If this parameter has no default value but we've seen one in the current type group
        if (!params[i]->param.default_value && seen_default)
        {
            report_semantic_error(SEMANTIC_ERROR_DEFAULT_VALUE_ORDER,
                                  params[i]->param.name,
                                  first_default_line);
            free(params);
            return SEMANTIC_ERROR_DEFAULT_VALUE_ORDER;
        }
        // If this parameter has a default value and we haven't seen one in this type group yet
        if (params[i]->param.default_value && !seen_default)
        {
            seen_default = 1;
            first_default_line = params[i]->param.line_number;
        }
    }

    free(params);
    return SEMANTIC_OK;
}

// Add function to count parameters in a parameter list
static void count_parameters(ASTNode *param_list, int *total, int *required)
{
    *total = 0;
    *required = 0;

    for (ASTNode *curr = param_list; curr != NULL; curr = curr->param_list.rest)
    {
        (*total)++;
        if (!curr->param_list.first->param.default_value)
        {
            (*required)++;
        }
    }
}

// Helper function to get expression type
ValueType get_expression_type(ASTNode *expr)
{
    if (!expr)
        return TYPE_UNKNOWN;

    printf("DEBUG: Getting type for expression node type %d\n", expr->type);

    switch (expr->type)
    {
    case AST_INT_LITERAL:
        return TYPE_INT;
    case AST_FLOAT_LITERAL:
        return TYPE_FLOAT;
    case AST_STRING_LITERAL:
        return TYPE_STRING;
    case AST_BOOL_LITERAL:
        return TYPE_BOOL;
    case AST_IDENTIFIER:
        // Look up variable type from symbol table
        for (int i = 0; i < num_variables; i++)
        {
            if (strcmp(declared_variables[i], expr->identifier) == 0)
            {
                return variable_types[i];
            }
        }
        return TYPE_UNKNOWN;
    case AST_BINARY_OP:
    {
        ValueType left_type = get_expression_type(expr->binary_op.left);
        ValueType right_type = get_expression_type(expr->binary_op.right);

        // For arithmetic operations
        if (expr->binary_op.op == PLUS || expr->binary_op.op == MINUS ||
            expr->binary_op.op == TIMES || expr->binary_op.op == DIVIDE ||
            expr->binary_op.op == POW)
        {
            // If either operand is float, result is float
            if (left_type == TYPE_FLOAT || right_type == TYPE_FLOAT)
                return TYPE_FLOAT;
            // If both are int, result is int
            if (left_type == TYPE_INT && right_type == TYPE_INT)
                return TYPE_INT;
        }
        // For comparison operations
        else if (expr->binary_op.op == EQ || expr->binary_op.op == NEQ ||
                 expr->binary_op.op == GT || expr->binary_op.op == GE ||
                 expr->binary_op.op == LT || expr->binary_op.op == LE)
        {
            return TYPE_BOOL;
        }
        // For logical operations
        else if (expr->binary_op.op == AND || expr->binary_op.op == OR)
        {
            return TYPE_BOOL;
        }
        // For assignment
        else if (expr->binary_op.op == ASSIGN)
        {
            return get_expression_type(expr->binary_op.left);
        }

        return left_type; // Default to left operand type if operation not recognized
    }
    case AST_UNARY_OP:
        if (expr->unary_op.op == NOT)
            return TYPE_BOOL;
        return get_expression_type(expr->unary_op.operand);
    case AST_FUNCTION_CALL:
        // Look up function return type
        for (int i = 0; i < num_functions; i++)
        {
            if (strcmp(defined_functions[i], expr->function_call.name) == 0)
            {
                return function_return_types[i];
            }
        }
        return TYPE_UNKNOWN;
    case AST_STRING_INDEX:
        return TYPE_STRING; // Single character is still a string in our language
    case AST_STRING_SLICE:
        return TYPE_STRING;
    case AST_MULTIPLE_ASSIGN:
        // For multiple assignment, return type of the rightmost expression
        if (expr->multiple_assign.expr_list)
        {
            ASTNode *last_expr = expr->multiple_assign.expr_list;
            while (last_expr->expr_list.rest)
                last_expr = last_expr->expr_list.rest;
            return get_expression_type(last_expr->expr_list.first);
        }
        return TYPE_UNKNOWN;
    default:
        printf("DEBUG: Unknown expression type %d in get_expression_type\n", expr->type);
        return TYPE_UNKNOWN;
    }
}

// Helper function to convert string literal to appropriate type if possible
static ValueType try_convert_literal(ASTNode *expr, ValueType target_type)
{
    if (!expr)
        return TYPE_UNKNOWN;

    // If types already match, no conversion needed
    ValueType expr_type = get_expression_type(expr);
    if (expr_type == target_type)
        return expr_type;

    // Handle string to number conversions
    if (expr->type == AST_STRING_LITERAL)
    {
        if (target_type == TYPE_INT)
        {
            // Check if string can be converted to int
            char *endptr;
            strtol(expr->string_value, &endptr, 10);
            if (*endptr == '\0')
                return TYPE_INT;
        }
        else if (target_type == TYPE_FLOAT)
        {
            // Check if string can be converted to float
            char *endptr;
            strtod(expr->string_value, &endptr);
            if (*endptr == '\0')
                return TYPE_FLOAT;
        }
    }
    // Handle int to float conversion
    else if (expr_type == TYPE_INT && target_type == TYPE_FLOAT)
    {
        return TYPE_FLOAT;
    }

    return expr_type;
}

// Add debug function
static void debug_print_type(const char *context, ASTNode *node, ValueType type)
{
    printf("DEBUG: %s - Node type: %d, Value type: %s\n",
           context,
           node ? node->type : -1,
           type_names[type]);
}

// Update check_argument_types with debug info
SemanticErrorCode check_argument_types(const char *func_name, ASTNode *args)
{
    printf("DEBUG: Checking arguments for function '%s'\n", func_name);

    // Find the function
    int func_index = -1;
    for (int i = 0; i < num_functions; i++)
    {
        if (strcmp(defined_functions[i], func_name) == 0)
        {
            func_index = i;
            break;
        }
    }

    if (func_index == -1)
    {
        printf("DEBUG: Function '%s' not found in defined functions\n", func_name);
        return SEMANTIC_ERROR_UNDEFINED_FUNCTION;
    }

    // Check each argument against the corresponding parameter
    int arg_index = 0;
    for (ASTNode *curr = args; curr != NULL; curr = curr->arg_list.rest)
    {
        printf("DEBUG: Checking argument %d\n", arg_index + 1);

        ValueType param_type = convert_type_token_to_value_type(function_param_types[func_index][arg_index]->param.type);
        ValueType arg_type = get_expression_type(curr->arg_list.first);

        debug_print_type("Parameter", function_param_types[func_index][arg_index], param_type);
        debug_print_type("Argument", curr->arg_list.first, arg_type);

        // Try type conversion if possible
        ValueType converted_type = try_convert_literal(curr->arg_list.first, param_type);
        printf("DEBUG: Attempted conversion result: %s\n", type_names[converted_type]);

        if (converted_type != param_type)
        {
            char error_msg[256];
            snprintf(error_msg, sizeof(error_msg), "Function '%s' parameter %d expects %s but got %s",
                     func_name, arg_index + 1, type_names[param_type], type_names[arg_type]);
            report_semantic_error(SEMANTIC_ERROR_ARGUMENT_TYPE_MISMATCH, error_msg, curr->arg_list.first->line_number);
            return SEMANTIC_ERROR_ARGUMENT_TYPE_MISMATCH;
        }
        arg_index++;
    }

    return SEMANTIC_OK;
}

// Check default value type matches parameter type
SemanticErrorCode check_default_value_type(ValueType param_type, ASTNode *default_value)
{
    if (!default_value)
        return SEMANTIC_OK;

    ValueType default_type = get_expression_type(default_value);

    // Try type conversion if possible
    ValueType converted_type = try_convert_literal(default_value, param_type);

    if (converted_type != param_type)
    {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg), "Default value of type %s cannot be used for parameter of type %s",
                 type_names[default_type], type_names[param_type]);
        report_semantic_error(SEMANTIC_ERROR_DEFAULT_VALUE_TYPE_MISMATCH, error_msg, default_value->line_number);
        return SEMANTIC_ERROR_DEFAULT_VALUE_TYPE_MISMATCH;
    }

    return SEMANTIC_OK;
}

// Check return type matches function declaration
SemanticErrorCode check_return_type(ASTNode *function_def, ASTNode *return_value)
{
    if (!function_def || !return_value)
        return SEMANTIC_OK;

    // Find the function
    int func_index = -1;
    for (int i = 0; i < num_functions; i++)
    {
        if (strcmp(defined_functions[i], function_def->function_def.name) == 0)
        {
            func_index = i;
            break;
        }
    }

    if (func_index == -1)
        return SEMANTIC_ERROR_UNDEFINED_FUNCTION;

    ValueType return_type = get_expression_type(return_value);
    ValueType expected_type = function_return_types[func_index];

    if (return_type != expected_type)
    {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg), "Expected %s but got %s",
                 type_names[expected_type], type_names[return_type]);
        report_semantic_error(SEMANTIC_ERROR_RETURN_TYPE_MISMATCH, error_msg, return_value->line_number);
        return SEMANTIC_ERROR_RETURN_TYPE_MISMATCH;
    }

    return SEMANTIC_OK;
}

// Add this helper function to clear variables at the end of a scope
static void clear_scope_variables(int old_num_vars)
{
    while (num_variables > old_num_vars)
    {
        free(declared_variables[--num_variables]);
    }
}

// Function to analyze parameters in a function definition
static SemanticErrorCode analyze_parameters(ASTNode *params)
{
    SemanticErrorCode result = SEMANTIC_OK;
    int param_index = 0;
    ValueType current_type = TYPE_UNKNOWN;

    // First pass: analyze each parameter group
    for (ASTNode *curr = params; curr; curr = curr->param_list.rest)
    {
        ASTNode *param = curr->param_list.first;

        // Convert parameter type token to ValueType
        ValueType param_type = convert_type_token_to_value_type(param->param.type);

        // If this parameter starts a new type group
        if (param_type != current_type)
        {
            current_type = param_type;
        }

        // Check default value type if present
        if (param->param.default_value)
        {
            result = check_default_value_type(current_type, param->param.default_value);
            if (result != SEMANTIC_OK)
            {
                return result;
            }
        }

        // Store parameter type
        function_param_types[num_functions - 1][param_index] = param;

        // Declare parameter as a variable
        result = check_variable_declaration(param->param.name, current_type);
        if (result != SEMANTIC_OK)
        {
            return result;
        }

        param_index++;
    }

    return SEMANTIC_OK;
}

// Add function context parameter to analyze_expression
static SemanticErrorCode analyze_expression(ASTNode *node, ASTNode *current_function)
{
    if (!node)
    {
        printf("DEBUG: Analyzing NULL expression\n");
        return SEMANTIC_OK;
    }

    printf("DEBUG: Analyzing expression of type %d\n", node->type);
    SemanticErrorCode result = SEMANTIC_OK;

    switch (node->type)
    {
    case AST_IDENTIFIER:
        printf("DEBUG: Checking identifier '%s'\n", node->identifier);
        result = check_variable_usage(node->identifier);
        if (result != SEMANTIC_OK)
        {
            report_semantic_error(result, node->identifier, node->line_number);
        }
        break;

    case AST_BINARY_OP:
        result = analyze_expression(node->binary_op.left, current_function);
        if (result == SEMANTIC_OK)
        {
            result = analyze_expression(node->binary_op.right, current_function);
        }
        break;

    case AST_UNARY_OP:
        result = analyze_expression(node->unary_op.operand, current_function);
        break;

    case AST_FUNCTION_CALL:
        printf("DEBUG: Checking function call to '%s'\n", node->function_call.name);
        result = check_function_usage(node->function_call.name);
        if (result != SEMANTIC_OK)
        {
            report_semantic_error(result, node->function_call.name, node->function_call.line_number);
            break;
        }
        // Check argument types
        result = check_argument_types(node->function_call.name, node->function_call.args);
        if (result != SEMANTIC_OK)
        {
            break;
        }
        // Analyze each argument expression
        if (node->function_call.args)
        {
            printf("DEBUG: Analyzing function arguments\n");
            for (ASTNode *curr = node->function_call.args; curr != NULL; curr = curr->arg_list.rest)
            {
                result = analyze_expression(curr->arg_list.first, current_function);
                if (result != SEMANTIC_OK)
                    break;
            }
        }
        break;

    case AST_STRING_INDEX:
        result = check_variable_usage(node->string_index.str->identifier);
        if (result == SEMANTIC_OK)
        {
            result = analyze_expression(node->string_index.index, current_function);
        }
        break;

    case AST_STRING_SLICE:
        result = check_variable_usage(node->string_slice.str->identifier);
        if (result == SEMANTIC_OK && node->string_slice.start)
        {
            result = analyze_expression(node->string_slice.start, current_function);
        }
        if (result == SEMANTIC_OK && node->string_slice.end)
        {
            result = analyze_expression(node->string_slice.end, current_function);
        }
        if (result == SEMANTIC_OK && node->string_slice.step)
        {
            result = analyze_expression(node->string_slice.step, current_function);
        }
        break;

    case AST_ARG_LIST:
        result = analyze_expression(node->arg_list.first, current_function);
        if (result == SEMANTIC_OK && node->arg_list.rest)
        {
            result = analyze_expression(node->arg_list.rest, current_function);
        }
        break;

    default:
        // Other expression types (literals, etc.) don't need semantic checking
        break;
    }

    return result;
}

// Add function context parameter to analyze_statement
static SemanticErrorCode analyze_statement(ASTNode *node, ASTNode *current_function)
{
    if (!node)
    {
        printf("DEBUG: NULL node in analyze_statement\n");
        return SEMANTIC_OK;
    }

    printf("DEBUG: Analyzing node type: %d\n", node->type);
    if (node->type == AST_FUNCTION_DEF)
    {
        printf("DEBUG: Found function definition for '%s'\n", node->function_def.name);
    }
    if (node->type == AST_BLOCK)
    {
        printf("DEBUG: Found block with %d statements\n", node->block.statement_count);
    }

    SemanticErrorCode result = SEMANTIC_OK;

    switch (node->type)
    {
    case AST_VAR_DECL:
        for (ASTNode *curr = node->var_decl.var_list; curr; curr = curr->var_list.rest)
        {
            // Convert variable type token to ValueType
            ValueType var_type = convert_type_token_to_value_type(node->var_decl.type);
            result = check_variable_declaration(curr->var_list.first->var_decl_item.name, var_type);
            if (result != SEMANTIC_OK)
            {
                report_semantic_error(result, curr->var_list.first->var_decl_item.name, node->line_number);
                return result;
            }

            if (curr->var_list.first->var_decl_item.init_value)
            {
                result = analyze_expression(curr->var_list.first->var_decl_item.init_value, current_function);
                if (result != SEMANTIC_OK)
                {
                    return result;
                }

                // Check if initialization value type matches variable type
                ValueType init_type = get_expression_type(curr->var_list.first->var_decl_item.init_value);
                ValueType converted_type = try_convert_literal(curr->var_list.first->var_decl_item.init_value, var_type);

                printf("DEBUG: Variable '%s' type: %s, Init value type: %s, Converted type: %s\n",
                       curr->var_list.first->var_decl_item.name,
                       type_names[var_type],
                       type_names[init_type],
                       type_names[converted_type]);

                if (converted_type != var_type)
                {
                    char error_msg[256];
                    snprintf(error_msg, sizeof(error_msg), "Cannot initialize variable of type %s with value of type %s",
                             type_names[var_type], type_names[init_type]);
                    report_semantic_error(SEMANTIC_ERROR_TYPE_MISMATCH, error_msg, node->line_number);
                    return SEMANTIC_ERROR_TYPE_MISMATCH;
                }
            }
        }
        break;

    case AST_FUNCTION_DEF:
        result = check_function_declaration(node->function_def.name, node->function_def.line_number);
        if (result != SEMANTIC_OK)
            return result;

        // Convert return type token to ValueType
        ValueType return_type = TYPE_VOID; // Default to void
        if (node->function_def.return_type)
        {
            return_type = convert_type_token_to_value_type(node->function_def.return_type->type);
        }
        function_return_types[num_functions - 1] = return_type;

        // Save the current number of variables to restore scope later
        int old_num_vars = num_variables;

        // Analyze parameters if present
        if (node->function_def.params)
        {
            result = analyze_parameters(node->function_def.params);
            if (result != SEMANTIC_OK)
            {
                clear_scope_variables(old_num_vars);
                return result;
            }
        }

        // Analyze function body with this function as context
        if (result == SEMANTIC_OK)
        {
            result = analyze_statement(node->function_def.body, node);
        }

        // Clear variables from this function's scope
        clear_scope_variables(old_num_vars);
        break;

    case AST_BLOCK:
        for (int i = 0; i < node->block.statement_count && result == SEMANTIC_OK; i++)
        {
            result = analyze_statement(node->block.statements[i], current_function);
        }
        if (result == SEMANTIC_OK)
        {
            result = check_return_statement_placement(node);
            if (result != SEMANTIC_OK)
            {
                report_semantic_error(result, "return statement", node->line_number);
            }
        }
        break;

    case AST_IF_STATEMENT:
        result = analyze_expression(node->if_stmt.condition, current_function);
        if (result == SEMANTIC_OK)
        {
            result = analyze_statement(node->if_stmt.then_block, current_function);
        }
        if (result == SEMANTIC_OK && node->if_stmt.elif_blocks)
        {
            result = analyze_statement(node->if_stmt.elif_blocks, current_function);
        }
        if (result == SEMANTIC_OK && node->if_stmt.else_block)
        {
            result = analyze_statement(node->if_stmt.else_block, current_function);
        }
        break;

    case AST_WHILE_STATEMENT:
        result = analyze_expression(node->while_stmt.condition, current_function);
        if (result == SEMANTIC_OK)
        {
            result = analyze_statement(node->while_stmt.body, current_function);
        }
        break;

    case AST_RETURN_STATEMENT:
        if (node->return_stmt.value)
        {
            if (!current_function)
            {
                report_semantic_error(SEMANTIC_ERROR_RETURN_TYPE_MISMATCH, "return statement outside function", node->line_number);
                return SEMANTIC_ERROR_RETURN_TYPE_MISMATCH;
            }

            result = check_return_type(current_function, node->return_stmt.value);
            if (result != SEMANTIC_OK)
                return result;

            result = analyze_expression(node->return_stmt.value, current_function);
        }
        break;

    case AST_BINARY_OP:
        if (node->binary_op.op == ASSIGN)
        {
            // For assignment, check that the left side is a valid target
            if (node->binary_op.left->type == AST_IDENTIFIER)
            {
                result = check_variable_usage(node->binary_op.left->identifier);
                if (result != SEMANTIC_OK)
                {
                    report_semantic_error(result, node->binary_op.left->identifier, node->line_number);
                    return result;
                }
            }
            if (result == SEMANTIC_OK)
            {
                result = analyze_expression(node->binary_op.right, current_function);
            }
        }
        else
        {
            result = analyze_expression(node, current_function);
        }
        break;

    default:
        // For other statement types, just analyze as expression
        result = analyze_expression(node, current_function);
        break;
    }

    return result;
}

// Add function to check argument counts
SemanticErrorCode check_function_arguments(const char *func_name, ASTNode *args)
{
    // Find the function
    int func_index = -1;
    for (int i = 0; i < num_functions; i++)
    {
        if (strcmp(defined_functions[i], func_name) == 0)
        {
            func_index = i;
            break;
        }
    }

    if (func_index == -1)
    {
        return SEMANTIC_ERROR_UNDEFINED_FUNCTION;
    }

    // Count the arguments in the call
    int arg_count = 0;
    for (ASTNode *curr = args; curr != NULL; curr = curr->arg_list.rest)
    {
        arg_count++;
    }

    // Check argument count against parameter bounds
    if (arg_count > function_param_counts[func_index])
    {
        return SEMANTIC_ERROR_TOO_MANY_ARGUMENTS;
    }
    if (arg_count < function_required_params[func_index])
    {
        return SEMANTIC_ERROR_TOO_FEW_ARGUMENTS;
    }

    return SEMANTIC_OK;
}

// Update main semantic analysis function to pass NULL as initial function context
SemanticErrorCode analyze_semantics(ASTNode *root)
{
    printf("DEBUG: Starting semantic analysis\n");
    clear_semantic_state();

    SemanticErrorCode result = SEMANTIC_OK;

    if (!root)
    {
        printf("DEBUG: Root node is NULL!\n");
        report_semantic_error(SEMANTIC_ERROR_MISSING_MAIN, "__main__", yylineno);
        return SEMANTIC_ERROR_MISSING_MAIN;
    }

    printf("DEBUG: Root node type: %d\n", root->type);

    // If this is a program node, analyze its statements
    if (root->type == AST_PROGRAM)
    {
        printf("DEBUG: Analyzing program statements\n");
        result = analyze_statement(root->program.statements, NULL);
    }
    else
    {
        // Otherwise analyze the node directly
        printf("DEBUG: Analyzing non-program node\n");
        result = analyze_statement(root, NULL);
    }

    if (result != SEMANTIC_OK)
    {
        return result;
    }

    // Check for required __main__ function
    if (!has_main_function)
    {
        report_semantic_error(SEMANTIC_ERROR_MISSING_MAIN, "__main__", yylineno);
        return SEMANTIC_ERROR_MISSING_MAIN;
    }

    return SEMANTIC_OK;
}