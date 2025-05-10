#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "parser.tab.h"

extern int yylineno; // Add external declaration for yylineno

// Helper function to create a new AST node
struct ASTNode *create_node(ASTNodeType type)
{
    struct ASTNode *node = (struct ASTNode *)malloc(sizeof(struct ASTNode));
    if (!node)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    // Initialize all fields to safe defaults
    memset(node, 0, sizeof(struct ASTNode));
    node->type = type;
    return node;
}

// Literal creation functions
struct ASTNode *create_int_literal(int value)
{
    struct ASTNode *node = create_node(AST_INT_LITERAL);
    node->int_value = value;
    return node;
}

struct ASTNode *create_float_literal(double value)
{
    struct ASTNode *node = create_node(AST_FLOAT_LITERAL);
    node->float_value = value;
    return node;
}

struct ASTNode *create_bool_literal(int value)
{
    struct ASTNode *node = create_node(AST_BOOL_LITERAL);
    node->bool_value = value;
    return node;
}

struct ASTNode *create_string_literal(const char *value)
{
    struct ASTNode *node = create_node(AST_STRING_LITERAL);
    node->string_value = strdup(value);
    return node;
}

struct ASTNode *create_hex_literal(int value)
{
    return create_int_literal(value); // Treat hex as int for now
}

// Identifier creation
struct ASTNode *create_identifier(const char *name)
{
    struct ASTNode *node = create_node(AST_IDENTIFIER);
    node->identifier = strdup(name);
    return node;
}

// Binary operation creation
struct ASTNode *create_binary_op(int op, struct ASTNode *left, struct ASTNode *right)
{
    struct ASTNode *node = create_node(AST_BINARY_OP);
    node->binary_op.op = op;
    node->binary_op.left = left;
    node->binary_op.right = right;
    return node;
}

// Unary operation creation
struct ASTNode *create_unary_op(int op, struct ASTNode *operand)
{
    struct ASTNode *node = create_node(AST_UNARY_OP);
    node->unary_op.op = op;
    node->unary_op.operand = operand;
    return node;
}

// Block creation
struct ASTNode *create_block(void)
{
    struct ASTNode *node = create_node(AST_BLOCK);
    node->block.statements = NULL;
    node->block.statement_count = 0;
    return node;
}

void add_statement_to_block(struct ASTNode *block, struct ASTNode *statement)
{
    if (!block || !statement)
        return;

    struct ASTNode **new_statements = realloc(block->block.statements,
                                              (block->block.statement_count + 1) * sizeof(struct ASTNode *));
    if (!new_statements)
    {
        fprintf(stderr, "Memory allocation failed in add_statement_to_block\n");
        exit(1);
    }

    block->block.statements = new_statements;
    block->block.statements[block->block.statement_count] = statement;
    block->block.statement_count++;
}

// If statement creation
struct ASTNode *create_if_statement(struct ASTNode *condition, struct ASTNode *then_block, struct ASTNode *elif_blocks)
{
    struct ASTNode *node = create_node(AST_IF_STATEMENT);
    node->if_stmt.condition = condition;
    node->if_stmt.then_block = then_block;
    node->if_stmt.elif_blocks = elif_blocks;
    node->if_stmt.else_block = NULL;
    return node;
}

struct ASTNode *create_elif(struct ASTNode *condition, struct ASTNode *block)
{
    struct ASTNode *node = create_node(AST_IF_STATEMENT);
    node->if_stmt.condition = condition;
    node->if_stmt.then_block = block;
    node->if_stmt.elif_blocks = NULL;
    node->if_stmt.else_block = NULL;
    return node;
}

struct ASTNode *create_else(struct ASTNode *block)
{
    struct ASTNode *node = create_node(AST_IF_STATEMENT);
    node->if_stmt.condition = NULL;
    node->if_stmt.then_block = block;
    node->if_stmt.elif_blocks = NULL;
    node->if_stmt.else_block = NULL;
    return node;
}

// While statement creation
struct ASTNode *create_while_statement(struct ASTNode *condition, struct ASTNode *body)
{
    struct ASTNode *node = create_node(AST_WHILE_STATEMENT);
    node->while_stmt.condition = condition;
    node->while_stmt.body = body;
    return node;
}

// Return statement creation
struct ASTNode *create_return_statement(struct ASTNode *value)
{
    struct ASTNode *node = create_node(AST_RETURN_STATEMENT);
    node->return_stmt.value = value;
    return node;
}

// Pass statement creation
struct ASTNode *create_pass_statement(void)
{
    return create_node(AST_PASS_STATEMENT);
}

// Function definition creation
struct ASTNode *create_function_def(const char *name, struct ASTNode *params, struct ASTNode *return_type, struct ASTNode *body)
{
    if (!name)
    {
        fprintf(stderr, "Function name is NULL\n");
        return NULL;
    }

    struct ASTNode *node = create_node(AST_FUNCTION_DEF);
    if (!node)
    {
        fprintf(stderr, "Failed to create function definition node\n");
        return NULL;
    }

    node->function_def.name = strdup(name);
    if (!node->function_def.name)
    {
        fprintf(stderr, "Failed to duplicate function name\n");
        free(node);
        return NULL;
    }

    node->function_def.params = params;
    node->function_def.return_type = return_type;
    node->function_def.body = body;
    return node;
}

// Return type creation
struct ASTNode *create_return_type(int type)
{
    struct ASTNode *node = create_node(AST_TYPE);
    node->type = type;
    return node;
}

// Parameter list creation
struct ASTNode *create_param_list(struct ASTNode *first, struct ASTNode *rest)
{
    if (!first)
    {
        fprintf(stderr, "First parameter is NULL\n");
        return NULL;
    }

    struct ASTNode *node = create_node(AST_PARAM_LIST);
    if (!node)
    {
        fprintf(stderr, "Failed to create parameter list node\n");
        return NULL;
    }

    node->param_list.first = first;
    node->param_list.rest = rest;
    return node;
}

// Parameter creation
struct ASTNode *create_param(int type, const char *name)
{
    struct ASTNode *node = create_node(AST_PARAM);
    if (!node)
    {
        fprintf(stderr, "Failed to create parameter node\n");
        return NULL;
    }
    node->param.type = type;
    node->param.name = strdup(name);
    if (!node->param.name)
    {
        fprintf(stderr, "Failed to duplicate parameter name\n");
        free(node);
        return NULL;
    }
    return node;
}

// Parameter creation with default value
struct ASTNode *create_param_with_default(const char *name, struct ASTNode *default_value)
{
    struct ASTNode *node = create_node(AST_PARAM);
    if (!node)
    {
        fprintf(stderr, "Failed to create parameter node\n");
        return NULL;
    }
    node->param.name = strdup(name);
    if (!node->param.name)
    {
        fprintf(stderr, "Failed to duplicate parameter name\n");
        free(node);
        return NULL;
    }
    node->param.default_value = default_value;
    node->param.type = 0;               // Initialize type to 0, will be set later
    node->param.line_number = yylineno; // Store the current line number
    return node;
}

// Function call creation
struct ASTNode *create_function_call(const char *name, struct ASTNode *args)
{
    struct ASTNode *node = create_node(AST_FUNCTION_CALL);
    node->function_call.name = strdup(name);
    node->function_call.args = args;
    return node;
}

struct ASTNode *create_arg_list(struct ASTNode *first, struct ASTNode *rest)
{
    struct ASTNode *node = create_node(AST_ARG_LIST);
    node->arg_list.first = first;
    node->arg_list.rest = rest;
    return node;
}

// Variable declaration creation
struct ASTNode *create_var_decl(int type, struct ASTNode *var_list)
{
    struct ASTNode *node = create_node(AST_VAR_DECL);
    if (!node)
    {
        fprintf(stderr, "Failed to create variable declaration node\n");
        return NULL;
    }
    node->var_decl.type = type;
    node->var_decl.var_list = var_list;
    return node;
}

struct ASTNode *create_var_list(struct ASTNode *first, struct ASTNode *rest)
{
    struct ASTNode *node = create_node(AST_VAR_LIST);
    if (!node)
    {
        fprintf(stderr, "Failed to create variable list node\n");
        return NULL;
    }
    node->var_list.first = first;
    node->var_list.rest = rest;
    return node;
}

struct ASTNode *create_var_decl_item(const char *name, struct ASTNode *init_value)
{
    struct ASTNode *node = create_node(AST_VAR_DECL_ITEM);
    if (!node)
    {
        fprintf(stderr, "Failed to create variable declaration item node\n");
        return NULL;
    }
    node->var_decl_item.name = strdup(name);
    if (!node->var_decl_item.name)
    {
        fprintf(stderr, "Failed to duplicate variable name\n");
        free(node);
        return NULL;
    }
    node->var_decl_item.init_value = init_value;
    return node;
}

// String operations implementation
struct ASTNode *create_string_slice(struct ASTNode *str, struct ASTNode *start, struct ASTNode *end, struct ASTNode *step)
{
    struct ASTNode *node = create_node(AST_STRING_SLICE);
    if (!node)
    {
        fprintf(stderr, "Failed to create string slice node\n");
        return NULL;
    }
    node->string_slice.str = str;
    node->string_slice.start = start;
    node->string_slice.end = end;
    node->string_slice.step = step;
    return node;
}

struct ASTNode *create_string_index(struct ASTNode *str, struct ASTNode *index)
{
    struct ASTNode *node = create_node(AST_STRING_INDEX);
    if (!node)
    {
        fprintf(stderr, "Failed to create string index node\n");
        return NULL;
    }
    node->string_index.str = str;
    node->string_index.index = index;
    return node;
}

struct ASTNode *create_lhs_list(struct ASTNode *first, struct ASTNode *rest)
{
    struct ASTNode *node = create_node(AST_LHS_LIST);
    node->lhs_list.first = first;
    node->lhs_list.rest = rest;
    return node;
}

struct ASTNode *create_expr_list(struct ASTNode *first, struct ASTNode *rest)
{
    struct ASTNode *node = create_node(AST_EXPR_LIST);
    node->expr_list.first = first;
    node->expr_list.rest = rest;
    return node;
}

struct ASTNode *create_multiple_assignment(struct ASTNode *lhs_list, struct ASTNode *expr_list)
{
    struct ASTNode *node = create_node(AST_MULTIPLE_ASSIGN);
    node->multiple_assign.lhs_list = lhs_list;
    node->multiple_assign.expr_list = expr_list;
    return node;
}

struct ASTNode *create_program(struct ASTNode *statements)
{
    printf("DEBUG: Creating program node with statements %p\n", (void *)statements);
    struct ASTNode *node = create_node(AST_PROGRAM);
    if (!node)
    {
        fprintf(stderr, "Failed to create program node\n");
        return NULL;
    }
    node->program.statements = statements;
    if (statements)
    {
        printf("DEBUG: Program node created with statements type: %d\n", statements->type);
    }
    return node;
}

// AST printing function
void print_ast(struct ASTNode *node, int indent)
{

    if (!node)
        return;

    switch (node->type)
    {
    case AST_PROGRAM:
        printf("(CODE\n");
        print_ast(node->program.statements, indent + 1);
        printf(")\n");
        break;

    case AST_FUNCTION_DEF:
        printf("%*s(FUNC\n", indent * 2, "");
        printf("%*s%s\n", (indent + 1) * 2, "", node->function_def.name);
        printf("%*s(ARGS\n", (indent + 1) * 2, "");
        if (node->function_def.params)
        {
            print_ast(node->function_def.params, indent + 2);
        }
        else
        {
            printf("%*sNONE\n", (indent + 2) * 2, "");
        }
        printf("%*s)\n", (indent + 1) * 2, "");
        printf("%*s(RETURN ", (indent + 1) * 2, "");
        if (node->function_def.return_type)
        {
            switch (node->function_def.return_type->type)
            {
            case INT:
                printf("INT");
                break;
            case BOOL:
                printf("BOOL");
                break;
            case STRING:
                printf("STR");
                break;
            default:
                printf("VOID");
                break;
            }
        }
        else
        {
            printf("VOID");
        }
        printf(")\n");
        printf("%*s(BODY\n", (indent + 1) * 2, "");
        if (node->function_def.body)
        {
            print_ast(node->function_def.body, indent + 2);
        }
        else
        {
            printf("%*s(BLOCK\n", (indent + 2) * 2, "");
            printf("%*s)\n", (indent + 2) * 2, "");
        }
        printf("%*s)\n", (indent + 1) * 2, "");
        printf("%*s)\n", indent * 2, "");
        break;

    case AST_PARAM_LIST:
        if (node->param_list.first)
        {
            int current_type = node->param_list.first->param.type;
            printf("%*s(", indent * 2, "");

            // Print the type
            switch (current_type)
            {
            case INT:
                printf("INT\n");
                break;
            case BOOL:
                printf("BOOL\n");
                break;
            case STRING:
                printf("STR\n");
                break;
            case FLOAT:
                printf("FLOAT\n");
                break;
            }

            // Find all parameters of the same type
            struct ASTNode *current = node;
            struct ASTNode *next_group = NULL;

            while (current)
            {
                if (current->param_list.first->param.type != current_type)
                {
                    next_group = current;
                    break;
                }
                printf("%*s%s", (indent + 1) * 2, "", current->param_list.first->param.name);
                if (current->param_list.first->param.default_value)
                {
                    printf(" = ");
                    print_ast(current->param_list.first->param.default_value, 0);
                }
                printf("\n");
                current = current->param_list.rest;
            }
            printf("%*s)\n", indent * 2, "");

            // Print next group of parameters
            if (next_group)
            {
                print_ast(next_group, indent);
            }
        }
        break;

    case AST_PARAM:
        if (node->param.type == INT)
        {
            printf("%*s(INT\n", indent * 2, "");
        }
        else if (node->param.type == BOOL)
        {
            printf("%*s(BOOL\n", indent * 2, "");
        }
        else if (node->param.type == STRING)
        {
            printf("%*s(STR\n", indent * 2, "");
        }
        printf("%*s%s\n", (indent + 1) * 2, "", node->param.name);
        printf("%*s)\n", indent * 2, "");
        break;

    case AST_BLOCK:
        printf("%*s(BLOCK\n", indent * 2, "");
        if (node->block.statements)
        {
            for (int i = 0; i < node->block.statement_count; i++)
            {
                print_ast(node->block.statements[i], indent + 1);
            }
        }
        printf("%*s)\n", indent * 2, "");
        break;

    case AST_IF_STATEMENT:
        printf("%*s(IF-ELSE\n", indent * 2, "");
        printf("%*s(COND\n", (indent + 1) * 2, "");
        print_ast(node->if_stmt.condition, indent + 2);
        printf("%*s)\n", (indent + 1) * 2, "");
        printf("%*s(THEN\n", (indent + 1) * 2, "");
        print_ast(node->if_stmt.then_block, indent + 2);
        printf("%*s)\n", (indent + 1) * 2, "");
        if (node->if_stmt.else_block)
        {
            printf("%*s(ELSE\n", (indent + 1) * 2, "");
            print_ast(node->if_stmt.else_block, indent + 2);
            printf("%*s)\n", (indent + 1) * 2, "");
        }
        printf("%*s)\n", indent * 2, "");
        break;

    case AST_BINARY_OP:
        if (node->binary_op.op == ASSIGN)
        {
            printf("%*s(ASS ", indent * 2, "");
            print_ast(node->binary_op.left, 0);
            print_ast(node->binary_op.right, indent + 1);
            printf("%*s)\n", indent * 2, "");
        }
        else
        {
            printf("%*s(", indent * 2, "");
            switch (node->binary_op.op)
            {
            case PLUS:
                printf("+");
                break;
            case MINUS:
                printf("-");
                break;
            case TIMES:
                printf("*");
                break;
            case DIVIDE:
                printf("/");
                break;
            case EQ:
                printf("==");
                break;
            case NEQ:
                printf("!=");
                break;
            case GT:
                printf(">");
                break;
            case GE:
                printf(">=");
                break;
            case LT:
                printf("<");
                break;
            case LE:
                printf("<=");
                break;
            case AND:
                printf("&&");
                break;
            case OR:
                printf("||");
                break;
            default:
                printf("UNKNOWN");
                break;
            }
            printf("\n");
            print_ast(node->binary_op.left, indent + 1);
            print_ast(node->binary_op.right, indent + 1);
            printf("%*s)\n", indent * 2, "");
        }
        break;

    case AST_IDENTIFIER:
        printf("%*s%s\n", indent * 2, "", node->identifier);
        break;

    case AST_INT_LITERAL:
        printf("%*s%d\n", indent * 2, "", node->int_value);
        break;

    case AST_FLOAT_LITERAL:
        printf("%*s%f\n", indent * 2, "", node->float_value);
        break;

    case AST_BOOL_LITERAL:
        printf("%*s%s\n", indent * 2, "", node->bool_value ? "true" : "false");
        break;

    case AST_STRING_LITERAL:
        printf("%*s'%s'\n", indent * 2, "", node->string_value);
        break;

    case AST_RETURN_STATEMENT:
        printf("%*s(RET ", indent * 2, "");
        if (node->return_stmt.value)
        {
            switch (node->return_stmt.value->type)
            {
            case AST_STRING_LITERAL:
                printf("'%s'\n", node->return_stmt.value->string_value);
                break;
            case AST_INT_LITERAL:
                printf("%d\n", node->return_stmt.value->int_value);
                break;
            case AST_FLOAT_LITERAL:
                printf("%f\n", node->return_stmt.value->float_value);
                break;
            case AST_BOOL_LITERAL:
                printf("%s\n", node->return_stmt.value->bool_value ? "true" : "false");
                break;
            case AST_IDENTIFIER:
                printf("%s\n", node->return_stmt.value->identifier);
                break;
            default:
                printf("\n");
                print_ast(node->return_stmt.value, indent + 1);
                break;
            }
            printf("%*s)\n", indent * 2, ""); // Indented closing parenthesis
        }
        else
        {
            printf(")\n"); // Handle 'return;'
        }
        break;

    case AST_WHILE_STATEMENT:
        printf("%*s(WHILE\n", indent * 2, "");
        printf("%*s(COND\n", (indent + 1) * 2, "");
        print_ast(node->while_stmt.condition, indent + 2);
        printf("%*s)\n", (indent + 1) * 2, "");
        printf("%*s(BODY\n", (indent + 1) * 2, "");
        print_ast(node->while_stmt.body, indent + 2);
        printf("%*s)\n", (indent + 1) * 2, "");
        printf("%*s)\n", indent * 2, "");
        break;

    case AST_PASS_STATEMENT:
        printf("%*s(PASS)\n", indent * 2, "");
        break;

    case AST_VAR_DECL:
        // Print the type
        switch (node->var_decl.type)
        {
        case INT:
            printf("%*s(INT\n", indent * 2, "");
            break;
        case FLOAT:
            printf("%*s(FLOAT\n", indent * 2, "");
            break;
        case BOOL:
            printf("%*s(BOOL\n", indent * 2, "");
            break;
        case STRING:
            printf("%*s(STRING\n", indent * 2, "");
            break;
        }
        // Print the variable list
        if (node->var_decl.var_list)
        {
            print_ast(node->var_decl.var_list, indent + 1);
        }
        printf("%*s)\n", indent * 2, "");
        break;

    case AST_VAR_LIST:
        if (node->var_list.first)
        {
            print_ast(node->var_list.first, indent);
            if (node->var_list.rest)
            {
                print_ast(node->var_list.rest, indent);
            }
        }
        break;

    case AST_VAR_DECL_ITEM:
        printf("%*s%s\n", (indent + 1) * 2, "", node->var_decl_item.name);
        if (node->var_decl_item.init_value)
        {
            printf("%*s(\n", (indent + 1) * 2, "");
            print_ast(node->var_decl_item.init_value, indent + 2);
            printf("%*s)\n", (indent + 1) * 2, "");
        }
        break;

    case AST_STRING_SLICE:
        printf("%*s(STRING_SLICE\n", indent * 2, "");
        printf("%*s(STR\n", (indent + 1) * 2, "");
        print_ast(node->string_slice.str, indent + 2);
        printf("%*s)\n", (indent + 1) * 2, "");
        if (node->string_slice.start)
        {
            printf("%*s(START\n", (indent + 1) * 2, "");
            print_ast(node->string_slice.start, indent + 2);
            printf("%*s)\n", (indent + 1) * 2, "");
        }
        if (node->string_slice.end)
        {
            printf("%*s(END\n", (indent + 1) * 2, "");
            print_ast(node->string_slice.end, indent + 2);
            printf("%*s)\n", (indent + 1) * 2, "");
        }
        if (node->string_slice.step)
        {
            printf("%*s(STEP\n", (indent + 1) * 2, "");
            print_ast(node->string_slice.step, indent + 2);
            printf("%*s)\n", (indent + 1) * 2, "");
        }
        printf("%*s)\n", indent * 2, "");
        break;

    case AST_STRING_INDEX:
        printf("%*s(STRING_INDEX\n", indent * 2, "");
        printf("%*s(STR\n", (indent + 1) * 2, "");
        print_ast(node->string_index.str, indent + 2);
        printf("%*s)\n", (indent + 1) * 2, "");
        printf("%*s(INDEX\n", (indent + 1) * 2, "");
        print_ast(node->string_index.index, indent + 2);
        printf("%*s)\n", (indent + 1) * 2, "");
        printf("%*s)\n", indent * 2, "");
        break;

    case AST_LHS_LIST:
        free_ast(node->lhs_list.first);
        free_ast(node->lhs_list.rest);
        break;

    case AST_EXPR_LIST:
        free_ast(node->expr_list.first);
        free_ast(node->expr_list.rest);
        break;

    case AST_MULTIPLE_ASSIGN:
        free_ast(node->multiple_assign.lhs_list);
        free_ast(node->multiple_assign.expr_list);
        break;

    case AST_ARG_LIST:
        free_ast(node->arg_list.first);
        free_ast(node->arg_list.rest);
        break;

    default:
        printf("%*s(UNKNOWN NODE TYPE %d)\n", indent * 2, "", node->type);
        break;
    }
}

// Memory cleanup function
void free_ast(struct ASTNode *node)
{
    if (!node)
        return;

    switch (node->type)
    {
    case AST_STRING_LITERAL:
        free(node->string_value);
        break;
    case AST_IDENTIFIER:
        free(node->identifier);
        break;
    case AST_BINARY_OP:
        free_ast(node->binary_op.left);
        free_ast(node->binary_op.right);
        break;
    case AST_UNARY_OP:
        free_ast(node->unary_op.operand);
        break;
    case AST_IF_STATEMENT:
        free_ast(node->if_stmt.condition);
        free_ast(node->if_stmt.then_block);
        free_ast(node->if_stmt.elif_blocks);
        free_ast(node->if_stmt.else_block);
        break;
    case AST_WHILE_STATEMENT:
        free_ast(node->while_stmt.condition);
        free_ast(node->while_stmt.body);
        break;
    case AST_RETURN_STATEMENT:
        free_ast(node->return_stmt.value);
        break;
    case AST_FUNCTION_DEF:
        free(node->function_def.name);
        free_ast(node->function_def.params);
        free_ast(node->function_def.return_type);
        free_ast(node->function_def.body);
        break;
    case AST_BLOCK:
        for (int i = 0; i < node->block.statement_count; i++)
        {
            free_ast(node->block.statements[i]);
        }
        free(node->block.statements);
        break;
    case AST_PARAM_LIST:
        free_ast(node->param_list.first);
        free_ast(node->param_list.rest);
        break;
    case AST_PARAM:
        free(node->param.name);
        if (node->param.default_value)
            free_ast(node->param.default_value);
        break;
    case AST_FUNCTION_CALL:
        free(node->function_call.name);
        free_ast(node->function_call.args);
        break;
    case AST_VAR_DECL:
        free_ast(node->var_decl.var_list);
        break;
    case AST_VAR_LIST:
        free_ast(node->var_list.first);
        free_ast(node->var_list.rest);
        break;
    case AST_VAR_DECL_ITEM:
        free(node->var_decl_item.name);
        if (node->var_decl_item.init_value)
            free_ast(node->var_decl_item.init_value);
        break;
    case AST_STRING_SLICE:
        free_ast(node->string_slice.str);
        free_ast(node->string_slice.start);
        free_ast(node->string_slice.end);
        free_ast(node->string_slice.step);
        break;
    case AST_STRING_INDEX:
        free_ast(node->string_index.str);
        free_ast(node->string_index.index);
        break;
    case AST_LHS_LIST:
        free_ast(node->lhs_list.first);
        free_ast(node->lhs_list.rest);
        break;
    case AST_EXPR_LIST:
        free_ast(node->expr_list.first);
        free_ast(node->expr_list.rest);
        break;
    case AST_MULTIPLE_ASSIGN:
        free_ast(node->multiple_assign.lhs_list);
        free_ast(node->multiple_assign.expr_list);
        break;
    case AST_ARG_LIST:
        free_ast(node->arg_list.first);
        free_ast(node->arg_list.rest);
        break;
    default:
        break;
    }

    free(node);
}
