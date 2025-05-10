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
static int num_variables = 0;
static char *defined_functions[MAX_FUNCTIONS];
static int num_functions = 0;
static int has_main_function = 0;
extern int yylineno; // Add this to get line numbers from flex

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
}

// Error reporting implementation
void report_semantic_error(SemanticErrorCode error, const char *details, int line_number)
{
    fprintf(stderr, "Semantic error at line %d: ", line_number);
    switch (error)
    {
    case SEMANTIC_ERROR_UNDEFINED_VARIABLE:
        fprintf(stderr, "Variable '%s' used before declaration\n", details);
        break;
    case SEMANTIC_ERROR_UNDEFINED_FUNCTION:
        fprintf(stderr, "Function '%s' not defined\n", details);
        break;
    case SEMANTIC_ERROR_DUPLICATE_VARIABLE:
        fprintf(stderr, "Variable '%s' already declared\n", details);
        break;
    case SEMANTIC_ERROR_DUPLICATE_FUNCTION:
        fprintf(stderr, "Function '%s' already defined\n", details);
        break;
    case SEMANTIC_ERROR_INVALID_RETURN_PLACEMENT:
        fprintf(stderr, "Return statement must be the last statement in a block\n");
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
    default:
        fprintf(stderr, "Unknown semantic error\n");
    }
}

// Variable declaration checking
SemanticErrorCode check_variable_declaration(const char *name)
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

    // Add the variable to declared list
    declared_variables[num_variables] = strdup(name);
    if (!declared_variables[num_variables])
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    num_variables++;

    return SEMANTIC_OK;
}

// Variable usage checking
SemanticErrorCode check_variable_usage(const char *name)
{
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
SemanticErrorCode check_function_declaration(const char *name)
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
    num_functions++;

    return SEMANTIC_OK;
}

// Function usage checking
SemanticErrorCode check_function_usage(const char *name)
{
    for (int i = 0; i < num_functions; i++)
    {
        if (strcmp(defined_functions[i], name) == 0)
        {
            return SEMANTIC_OK;
        }
    }
    return SEMANTIC_ERROR_UNDEFINED_FUNCTION;
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

// Check that parameters with default values come after parameters without default values
SemanticErrorCode check_param_default_values(ASTNode *param_list)
{
    if (!param_list)
        return SEMANTIC_OK;

    // Flag to track if we've seen a parameter with default value
    int seen_default = 0;
    int first_default_line = 0;

    for (ASTNode *curr = param_list; curr; curr = curr->param_list.rest)
    {
        // If this parameter has no default value but we've seen one before
        if (!curr->param_list.first->param.default_value && seen_default)
        {
            report_semantic_error(SEMANTIC_ERROR_DEFAULT_VALUE_ORDER,
                                  curr->param_list.first->param.name,
                                  first_default_line);
            return SEMANTIC_ERROR_DEFAULT_VALUE_ORDER;
        }
        // If this parameter has a default value, mark that we've seen one
        if (curr->param_list.first->param.default_value && !seen_default)
        {
            seen_default = 1;
            first_default_line = curr->param_list.first->param.line_number;
        }
    }

    return SEMANTIC_OK;
}

// Function to analyze an expression node
static SemanticErrorCode analyze_expression(ASTNode *node)
{
    if (!node)
        return SEMANTIC_OK;

    SemanticErrorCode result = SEMANTIC_OK;

    switch (node->type)
    {
    case AST_IDENTIFIER:
        result = check_variable_usage(node->identifier);
        if (result != SEMANTIC_OK)
        {
            report_semantic_error(result, node->identifier, yylineno);
        }
        break;
    case AST_BINARY_OP:
        result = analyze_expression(node->binary_op.left);
        if (result == SEMANTIC_OK)
        {
            result = analyze_expression(node->binary_op.right);
        }
        break;
    case AST_UNARY_OP:
        result = analyze_expression(node->unary_op.operand);
        break;
    case AST_FUNCTION_CALL:
        result = check_function_usage(node->function_call.name);
        if (result != SEMANTIC_OK)
        {
            report_semantic_error(result, node->function_call.name, yylineno);
            break;
        }
        if (node->function_call.args)
        {
            result = analyze_expression(node->function_call.args);
        }
        break;
    case AST_STRING_INDEX:
        result = check_variable_usage(node->string_index.str->identifier);
        if (result == SEMANTIC_OK)
        {
            result = analyze_expression(node->string_index.index);
        }
        break;
    case AST_STRING_SLICE:
        result = check_variable_usage(node->string_slice.str->identifier);
        if (result == SEMANTIC_OK && node->string_slice.start)
        {
            result = analyze_expression(node->string_slice.start);
        }
        if (result == SEMANTIC_OK && node->string_slice.end)
        {
            result = analyze_expression(node->string_slice.end);
        }
        if (result == SEMANTIC_OK && node->string_slice.step)
        {
            result = analyze_expression(node->string_slice.step);
        }
        break;
    default:
        // Other expression types (literals, etc.) don't need semantic checking
        break;
    }

    return result;
}

// Function to analyze a statement node
static SemanticErrorCode analyze_statement(ASTNode *node)
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
        // Analyze each statement in the block
        SemanticErrorCode result = SEMANTIC_OK;
        for (int i = 0; i < node->block.statement_count && result == SEMANTIC_OK; i++)
        {
            result = analyze_statement(node->block.statements[i]);
        }
        return result;
    }

    SemanticErrorCode result = SEMANTIC_OK;

    switch (node->type)
    {
    case AST_VAR_DECL:
        for (ASTNode *curr = node->var_decl.var_list; curr; curr = curr->var_list.rest)
        {
            result = check_variable_declaration(curr->var_list.first->var_decl_item.name);
            if (result != SEMANTIC_OK)
            {
                report_semantic_error(result, curr->var_list.first->var_decl_item.name, yylineno);
                return result;
            }

            if (curr->var_list.first->var_decl_item.init_value)
            {
                result = analyze_expression(curr->var_list.first->var_decl_item.init_value);
                if (result != SEMANTIC_OK)
                {
                    return result;
                }
            }
        }
        break;

    case AST_FUNCTION_DEF:
        result = check_function_declaration(node->function_def.name);
        if (result != SEMANTIC_OK)
        {
            report_semantic_error(result, node->function_def.name, yylineno);
            return result;
        }

        // Check parameter default value ordering
        if (node->function_def.params)
        {
            result = check_param_default_values(node->function_def.params);
            if (result != SEMANTIC_OK)
            {
                return result;
            }
        }

        int old_num_vars = num_variables;

        if (node->function_def.params)
        {
            for (ASTNode *curr = node->function_def.params; curr; curr = curr->param_list.rest)
            {
                result = check_variable_declaration(curr->param_list.first->param.name);
                if (result != SEMANTIC_OK)
                {
                    report_semantic_error(result, curr->param_list.first->param.name, yylineno);
                    return result;
                }
            }
        }

        if (result == SEMANTIC_OK)
        {
            result = analyze_statement(node->function_def.body);
        }

        while (num_variables > old_num_vars)
        {
            free(declared_variables[--num_variables]);
        }
        break;

    case AST_BLOCK:
        for (int i = 0; i < node->block.statement_count && result == SEMANTIC_OK; i++)
        {
            result = analyze_statement(node->block.statements[i]);
        }
        if (result == SEMANTIC_OK)
        {
            result = check_return_statement_placement(node);
            if (result != SEMANTIC_OK)
            {
                report_semantic_error(result, "return statement", yylineno);
            }
        }
        break;

    case AST_IF_STATEMENT:
        result = analyze_expression(node->if_stmt.condition);
        if (result == SEMANTIC_OK)
        {
            result = analyze_statement(node->if_stmt.then_block);
        }
        if (result == SEMANTIC_OK && node->if_stmt.elif_blocks)
        {
            result = analyze_statement(node->if_stmt.elif_blocks);
        }
        if (result == SEMANTIC_OK && node->if_stmt.else_block)
        {
            result = analyze_statement(node->if_stmt.else_block);
        }
        break;

    case AST_WHILE_STATEMENT:
        result = analyze_expression(node->while_stmt.condition);
        if (result == SEMANTIC_OK)
        {
            result = analyze_statement(node->while_stmt.body);
        }
        break;

    case AST_RETURN_STATEMENT:
        if (node->return_stmt.value)
        {
            result = analyze_expression(node->return_stmt.value);
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
                    report_semantic_error(result, node->binary_op.left->identifier, yylineno);
                    return result;
                }
            }
            if (result == SEMANTIC_OK)
            {
                result = analyze_expression(node->binary_op.right);
            }
        }
        else
        {
            result = analyze_expression(node);
        }
        break;

    default:
        // For other statement types, just analyze as expression
        result = analyze_expression(node);
        break;
    }

    return result;
}

// Main semantic analysis function
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
        result = analyze_statement(root->program.statements);
    }
    else
    {
        // Otherwise analyze the node directly
        printf("DEBUG: Analyzing non-program node\n");
        result = analyze_statement(root);
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