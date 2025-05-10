#ifndef AST_H
#define AST_H

// Forward declaration of ASTNode
typedef struct ASTNode ASTNode;

typedef enum
{
    AST_PROGRAM,
    AST_INT_LITERAL,
    AST_FLOAT_LITERAL,
    AST_BOOL_LITERAL,
    AST_STRING_LITERAL,
    AST_IDENTIFIER,
    AST_BINARY_OP,
    AST_UNARY_OP,
    AST_IF_STATEMENT,
    AST_WHILE_STATEMENT,
    AST_RETURN_STATEMENT,
    AST_PASS_STATEMENT,
    AST_FUNCTION_DEF,
    AST_FUNCTION_CALL,
    AST_BLOCK,
    AST_PARAM_LIST,
    AST_PARAM,
    AST_TYPE,
    AST_VAR_DECL,
    AST_VAR_LIST,
    AST_VAR_DECL_ITEM,
    AST_EMPTY,
    AST_STRING_SLICE,
    AST_STRING_INDEX,
    AST_LHS_LIST,
    AST_EXPR_LIST,
    AST_MULTIPLE_ASSIGN,
    AST_ARG_LIST
} ASTNodeType;

// Define ASTFunctionCall struct before ASTNode
typedef struct
{
    char *name;
    struct ASTNode *args;
} ASTFunctionCall;

struct ASTNode
{
    ASTNodeType type;

    union
    {
        /* ליטרלים */
        int int_value;
        double float_value;
        int bool_value; // 1 = true, 0 = false
        char *string_value;
        char *identifier;

        /* אופרטור בינארי */
        struct
        {
            int op; // הטוקן של האופרטור (PLUS, MINUS, וכד')
            struct ASTNode *left;
            struct ASTNode *right;
        } binary_op;

        /* אופרטור יונרי */
        struct
        {
            int op;
            struct ASTNode *operand;
        } unary_op;

        /* תנאי if */
        struct
        {
            struct ASTNode *condition;
            struct ASTNode *then_block;
            struct ASTNode *elif_blocks; // אופציונלי
            struct ASTNode *else_block;  // אופציונלי
        } if_stmt;

        /* לולאת while */
        struct
        {
            struct ASTNode *condition;
            struct ASTNode *body;
        } while_stmt;

        /* return */
        struct
        {
            struct ASTNode *value;
        } return_stmt;

        /* פונקציה */
        struct
        {
            char *name;
            struct ASTNode *params;
            struct ASTNode *return_type;
            struct ASTNode *body;
        } function_def;

        /* בלוק פקודות */
        struct
        {
            struct ASTNode **statements;
            int statement_count;
        } block;

        /* רשימת פרמטרים */
        struct
        {
            struct ASTNode *first;
            struct ASTNode *rest;
        } param_list;

        /* פרמטר */
        struct
        {
            int type;
            char *name;
            struct ASTNode *default_value; // Optional default value
            int line_number;               // Add line number tracking
        } param;

        /* Variable declaration */
        struct
        {
            int type;
            struct ASTNode *var_list;
        } var_decl;

        /* Variable list */
        struct
        {
            struct ASTNode *first;
            struct ASTNode *rest;
        } var_list;

        /* Variable declaration item */
        struct
        {
            char *name;
            struct ASTNode *init_value;
        } var_decl_item;

        ASTFunctionCall function_call;

        struct
        {
            struct ASTNode *str;
            struct ASTNode *start;
            struct ASTNode *end;
            struct ASTNode *step;
        } string_slice;

        struct
        {
            struct ASTNode *str;
            struct ASTNode *index;
        } string_index;

        struct
        {
            struct ASTNode *first;
            struct ASTNode *rest;
        } lhs_list;
        struct
        {
            struct ASTNode *first;
            struct ASTNode *rest;
        } expr_list;
        struct
        {
            struct ASTNode *lhs_list;
            struct ASTNode *expr_list;
        } multiple_assign;
        struct
        {
            struct ASTNode *first;
            struct ASTNode *rest;
        } arg_list;

        struct
        {
            struct ASTNode *statements;
        } program;
    };
};

/* פונקציות עזר */
struct ASTNode *create_int_literal(int value);
struct ASTNode *create_float_literal(double value);
struct ASTNode *create_bool_literal(int value);
struct ASTNode *create_string_literal(const char *value);
struct ASTNode *create_identifier(const char *name);
struct ASTNode *create_binary_op(int op, struct ASTNode *left, struct ASTNode *right);
struct ASTNode *create_unary_op(int op, struct ASTNode *operand);
struct ASTNode *create_block(void);
void add_statement_to_block(struct ASTNode *block, struct ASTNode *statement);

/* New function declarations */
struct ASTNode *create_if_statement(struct ASTNode *condition, struct ASTNode *then_block, struct ASTNode *elif_blocks);
struct ASTNode *create_elif(struct ASTNode *condition, struct ASTNode *block);
struct ASTNode *create_else(struct ASTNode *block);
struct ASTNode *create_while_statement(struct ASTNode *condition, struct ASTNode *body);
struct ASTNode *create_return_statement(struct ASTNode *value);
struct ASTNode *create_pass_statement(void);
struct ASTNode *create_function_def(const char *name, struct ASTNode *params, struct ASTNode *return_type, struct ASTNode *body);
struct ASTNode *create_return_type(int type);
struct ASTNode *create_param_list(struct ASTNode *first, struct ASTNode *rest);
struct ASTNode *create_param(int type, const char *name);
struct ASTNode *create_param_with_default(const char *name, struct ASTNode *default_value);
struct ASTNode *create_var_decl(int type, struct ASTNode *var_list);
struct ASTNode *create_var_list(struct ASTNode *first, struct ASTNode *rest);
struct ASTNode *create_var_decl_item(const char *name, struct ASTNode *init_value);
struct ASTNode *create_hex_literal(int value);
void print_ast(struct ASTNode *node, int indent);

/* פונקציה לשחרור זיכרון של AST */
void free_ast(struct ASTNode *node);

/* String processing function */
char *process_string(const char *text);

/* Function call creation */
struct ASTNode *create_function_call(const char *name, struct ASTNode *args);
struct ASTNode *create_arg_list(struct ASTNode *first, struct ASTNode *rest);

// String operations
struct ASTNode *create_string_slice(struct ASTNode *str, struct ASTNode *start, struct ASTNode *end, struct ASTNode *step);
struct ASTNode *create_string_index(struct ASTNode *str, struct ASTNode *index);

struct ASTNode *create_lhs_list(struct ASTNode *first, struct ASTNode *rest);
struct ASTNode *create_expr_list(struct ASTNode *first, struct ASTNode *rest);
struct ASTNode *create_multiple_assignment(struct ASTNode *lhs_list, struct ASTNode *expr_list);

struct ASTNode *create_program(struct ASTNode *statements);

#endif