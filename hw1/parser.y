%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "parser.tab.h"

void yyerror(const char *s);
extern int yylex(void);
extern int yylineno;
ASTNode* root = NULL;
int has_main_function = 0;  // Track if __main__ function exists

// Function definition tracking
#define MAX_FUNCTIONS 100
char* defined_functions[MAX_FUNCTIONS];
int num_functions = 0;

// Variable tracking
#define MAX_VARIABLES 100
char* declared_variables[MAX_VARIABLES];
int num_variables = 0;

void add_function(const char* name) {
    if (num_functions >= MAX_FUNCTIONS) {
        fprintf(stderr, "Error: Too many functions defined\n");
        yyerror("Too many functions defined");
        return;
    }
    defined_functions[num_functions++] = strdup(name);
}

int is_function_defined(const char* name) {
    for (int i = 0; i < num_functions; i++) {
        if (strcmp(defined_functions[i], name) == 0) {
            return 1;
        }
    }
    return 0;
}

void add_variable(const char* name) {
    if (num_variables >= MAX_VARIABLES) {
        fprintf(stderr, "Error: Too many variables declared\n");
        yyerror("Too many variables declared");
        return;
    }
    declared_variables[num_variables++] = strdup(name);
}

int is_variable_declared(const char* name) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(declared_variables[i], name) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function parameter tracking
void add_parameter(const char* name) {
    add_variable(name);  // Parameters are automatically declared variables
}

void clear_parameters(void) {
    // Clear all variables when entering a new function scope
    for (int i = 0; i < num_variables; i++) {
        free(declared_variables[i]);
    }
    num_variables = 0;
}

// Declare create_node as extern since it's defined in ast.c
extern struct ASTNode *create_node(ASTNodeType type);
%}

%union {
    int intval;
    float floatval;
    char *strval;
    ASTNode* ast_node;
    int typeval;
}

%type <ast_node> program statement_list statement expr literal block if_statement elif_list while_statement return_statement pass_statement function_def function_body param_list_opt param_list return_type_opt var_decl var_list var_decl_item param_with_default_list param_with_default else_stmt lhs lhs_list expr_list func_call arg_list function_call_statement string_op

%type <typeval> type

%token <intval> INTEGER
%token <intval> HEX_LITERAL
%token <floatval> FLOAT_LITERAL
%token <strval> STRING_LITERAL IDENTIFIER
%token <intval> BOOL_LITERAL

%token IF ELIF ELSE WHILE RETURN PASS DEF 
%token BOOL INT FLOAT STRING
%token AND OR NOT
%token EQ GT GE LT LE NEQ PLUS MINUS POW TIMES DIVIDE
%token SEMICOLON COMMA LBRACE RBRACE LPAREN RPAREN LBRACKET RBRACKET COLON
%token ASSIGN ARROW

%left OR
%left AND
%left NOT
%left EQ NEQ
%left GT GE LT LE
%left PLUS MINUS
%left TIMES DIVIDE
%right POW
%right UNMINUS
%right ASSIGN
%precedence IF
%precedence ELSE
%precedence ELIF
%precedence COLON
%precedence LBRACE
%precedence RBRACE
%precedence SEMICOLON

%%

program:
    statement_list { 
        if (!has_main_function) {
            fprintf(stderr, "Error: Program must contain exactly one __main__() function\n");
            YYERROR;
        }
        root = create_program($1); 
    }
    ;

statement_list:
    statement_list statement {
        if (!$1) {
            $$ = create_block();
        } else {
            $$ = $1;
        }
        if ($2) {
            add_statement_to_block($$, $2);
        }
    }
    | /* empty */ {
        $$ = NULL;
    }
    ;

statement:
    expr SEMICOLON %prec SEMICOLON {
        $$ = $1;
    }
    | lhs ASSIGN expr SEMICOLON %prec ASSIGN {
        if ($1->type == AST_IDENTIFIER) {
            if (!is_variable_declared($1->identifier)) {
                fprintf(stderr, "Error: Variable '%s' used before declaration\n", $1->identifier);
                yyerror("Variable used before declaration");
                YYERROR;
            }
        }
        $$ = create_binary_op(ASSIGN, $1, $3);
    }
    | lhs_list ASSIGN expr_list SEMICOLON %prec ASSIGN {
        $$ = create_multiple_assignment($1, $3);
    }
    | function_call_statement %prec SEMICOLON {
        $$ = $1;
    }
    | if_statement {
        $$ = $1;
    }
    | while_statement {
        $$ = $1;
    }
    | return_statement {
        $$ = $1;
    }
    | pass_statement {
        $$ = $1;
    }
    | function_def { 
        $$ = $1;
    }
    | var_decl {
        $$ = $1;
    }
    ;

function_call_statement:
    func_call SEMICOLON %prec SEMICOLON {
        $$ = $1;
    }
    | lhs ASSIGN func_call SEMICOLON %prec ASSIGN {
        if ($1->type == AST_IDENTIFIER) {
            if (!is_variable_declared($1->identifier)) {
                fprintf(stderr, "Error: Variable '%s' used before declaration\n", $1->identifier);
                yyerror("Variable used before declaration");
                YYERROR;
            }
        }
        $$ = create_binary_op(ASSIGN, $1, $3);
    }
    ;

if_statement:
    IF expr COLON statement %prec IF {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, $4);
        $$ = create_if_statement($2, block, NULL);
    }
    | IF expr COLON block %prec IF {
        $$ = create_if_statement($2, $4, NULL);
    }
    | IF expr COLON statement elif_list %prec IF {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, $4);
        $$ = create_if_statement($2, block, $5);
    }
    | IF expr COLON block elif_list %prec IF {
        $$ = create_if_statement($2, $4, $5);
    }
    | IF expr COLON statement elif_list ELSE COLON else_stmt %prec IF {
        struct ASTNode *if_block = create_block();
        add_statement_to_block(if_block, $4);
        $$ = create_if_statement($2, if_block, $5);
        $$->if_stmt.else_block = $8;
    }
    | IF expr COLON block elif_list ELSE COLON else_stmt %prec IF {
        $$ = create_if_statement($2, $4, $5);
        $$->if_stmt.else_block = $8;
    }
    | IF expr COLON statement ELSE COLON else_stmt %prec IF {
        struct ASTNode *if_block = create_block();
        add_statement_to_block(if_block, $4);
        $$ = create_if_statement($2, if_block, NULL);
        $$->if_stmt.else_block = $7;
    }
    | IF expr COLON block ELSE COLON else_stmt %prec IF {
        $$ = create_if_statement($2, $4, NULL);
        $$->if_stmt.else_block = $7;
    }
    ;

elif_list:
    ELIF expr COLON statement %prec ELIF {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, $4);
        $$ = create_block();
        add_statement_to_block($$, create_elif($2, block));
    }
    | ELIF expr COLON block %prec ELIF {
        $$ = create_block();
        add_statement_to_block($$, create_elif($2, $4));
    }
    | elif_list ELIF expr COLON statement %prec ELIF {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, $5);
        add_statement_to_block($1, create_elif($3, block));
        $$ = $1;
    }
    | elif_list ELIF expr COLON block %prec ELIF {
        add_statement_to_block($1, create_elif($3, $5));
        $$ = $1;
    }
    ;

else_stmt:
    statement %prec ELSE {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, $1);
        $$ = block;
    }
    | block %prec ELSE {
        $$ = $1;
    }
    ;

while_statement:
    WHILE expr COLON statement %prec IF {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, $4);
        $$ = create_while_statement($2, block);
    }
    | WHILE expr COLON block %prec IF {
        $$ = create_while_statement($2, $4);
    }
    ;

return_statement:
    RETURN expr SEMICOLON {
        $$ = create_return_statement($2);
    }
    ;

pass_statement:
    PASS SEMICOLON {
        $$ = create_pass_statement();
    }
    ;

function_body:
    LBRACE statement_list RBRACE {
        $$ = create_block();
        if ($2) {
            // Handle the statement list
            if ($2->type == AST_BLOCK) {
                // If it's already a block, copy its statements
                for (int i = 0; i < $2->block.statement_count; i++) {
                    add_statement_to_block($$, $2->block.statements[i]);
                }
            } else {
                // If it's a single statement, add it directly
                add_statement_to_block($$, $2);
            }

            // Check for return statement placement
            struct ASTNode *last_stmt = $$;
            while (last_stmt->type == AST_BLOCK && last_stmt->block.statement_count > 0) {
                last_stmt = last_stmt->block.statements[last_stmt->block.statement_count - 1];
            }

            if (last_stmt->type == AST_RETURN_STATEMENT) {
                // If return is the last statement, it's valid
                // Continue with the current block
            } else {
                // Check for return statements elsewhere in the block
                int has_return = 0;
                for (int i = 0; i < $$->block.statement_count - 1; i++) {
                    struct ASTNode *stmt = $$->block.statements[i];
                    if (stmt->type == AST_RETURN_STATEMENT) {
                        has_return = 1;
                        break;
                    }
                    if (stmt->type == AST_BLOCK) {
                        for (int j = 0; j < stmt->block.statement_count; j++) {
                            if (stmt->block.statements[j]->type == AST_RETURN_STATEMENT) {
                                has_return = 1;
                                break;
                            }
                        }
                    }
                }

                if (has_return) {
                    fprintf(stderr, "Error: Return statement must be the last statement in a block\n");
                    yyerror("Return statement must be last");
                    YYERROR;
                }
            }
        }
    }
    | statement SEMICOLON {
        $$ = create_block();
        add_statement_to_block($$, $1);
        // Single return statement is always valid
    }
    ;

function_def:
    DEF IDENTIFIER LPAREN param_list_opt RPAREN return_type_opt COLON function_body {
        if (strcmp($2, "__main__") == 0) {
            if (has_main_function) {
                fprintf(stderr, "Error: Multiple __main__() functions defined\n");
                YYERROR;
            }
            has_main_function = 1;
        }
        add_function($2);  // Add function to defined functions list
        clear_parameters();  // Clear any previous parameters
        ASTNode* func_def = create_function_def($2, $4, $6, $8);
        if (!func_def) {
            fprintf(stderr, "Failed to create function definition\n");
            YYERROR;
        }
        $$ = func_def;
    }
    ;

return_type_opt:
    ARROW type {
        $$ = create_return_type($2);
    }
    | /* empty */ {
        $$ = NULL;
    }
    ;

param_list_opt:
    param_list {
        $$ = $1;
    }
    | /* empty */ {
        $$ = NULL;
    }
    ;

param_list:
    param_list SEMICOLON type param_with_default_list {
        struct ASTNode *new_list = $4;
        // Set the type for all parameters in this group
        struct ASTNode *current = new_list;
        while (current) {
            current->param_list.first->param.type = $3;
            current = current->param_list.rest;
        }
        // Link this group to the previous groups
        if ($1) {
            struct ASTNode *last = new_list;
            while (last->param_list.rest) {
                last = last->param_list.rest;
            }
            last->param_list.rest = $1;
            $$ = new_list;
        } else {
            $$ = new_list;
        }
    }
    | type param_with_default_list {
        $$ = $2;
        // Set the type for all parameters in this group
        struct ASTNode *current = $$;
        while (current) {
            current->param_list.first->param.type = $1;
            current = current->param_list.rest;
        }
    }
    ;

param_with_default_list:
    param_with_default_list COMMA param_with_default {
        $$ = create_param_list($3, $1);
    }
    | param_with_default {
        $$ = create_param_list($1, NULL);
    }
    ;

param_with_default:
    IDENTIFIER {
        add_parameter($1);
        $$ = create_param_with_default($1, NULL);
    }
    | IDENTIFIER COLON expr {
        add_parameter($1);
        $$ = create_param_with_default($1, $3);
    }
    ;

type:
    BOOL   { $$ = BOOL; }
    | INT  { $$ = INT; }
    | FLOAT { $$ = FLOAT; }
    | STRING { $$ = STRING; }
    ;

block:
    LBRACE statement_list RBRACE %prec LBRACE {
        if (!$2) {
            fprintf(stderr, "Error: Empty block not allowed. Use 'pass;' for empty blocks.\n");
            yyerror("Empty block not allowed");
            YYERROR;
        }
        $$ = create_block();
        add_statement_to_block($$, $2);
    }
    ;

expr:
    expr OR expr {
        $$ = create_binary_op(OR, $1, $3);
    }
    | expr AND expr {
        $$ = create_binary_op(AND, $1, $3);
    }
    | NOT expr {
        $$ = create_unary_op(NOT, $2);
    }
    | expr EQ expr {
        $$ = create_binary_op(EQ, $1, $3);
    }
    | expr NEQ expr {
        $$ = create_binary_op(NEQ, $1, $3);
    }
    | expr GT expr {
        $$ = create_binary_op(GT, $1, $3);
    }
    | expr GE expr {
        $$ = create_binary_op(GE, $1, $3);
    }
    | expr LT expr {
        $$ = create_binary_op(LT, $1, $3);
    }
    | expr LE expr {
        $$ = create_binary_op(LE, $1, $3);
    }
    | expr PLUS expr {
        $$ = create_binary_op(PLUS, $1, $3);
    }
    | expr MINUS expr {
        $$ = create_binary_op(MINUS, $1, $3);
    }
    | expr TIMES expr {
        $$ = create_binary_op(TIMES, $1, $3);
    }
    | expr DIVIDE expr {
        $$ = create_binary_op(DIVIDE, $1, $3);
    }
    | expr POW expr {
        $$ = create_binary_op(POW, $1, $3);
    }
    | MINUS expr %prec UNMINUS {
        $$ = create_unary_op(MINUS, $2);
    }
    | LPAREN expr RPAREN {
        $$ = $2;
    }
    | literal {
        $$ = $1;
    }
    | IDENTIFIER {
        if (!is_variable_declared($1)) {
            fprintf(stderr, "Error: Variable '%s' used before declaration\n", $1);
            yyerror("Variable used before declaration");
            YYERROR;
        }
        $$ = create_identifier($1);
    }
    | func_call {
        $$ = $1;
    }
     | string_op {
        $$ = $1;
    }
    ;

string_op:
    IDENTIFIER LBRACKET expr RBRACKET {
        if (!is_variable_declared($1)) {
            fprintf(stderr, "Error: Variable '%s' used before declaration\n", $1);
            yyerror("Variable used before declaration");
            YYERROR;
        }
        $$ = create_string_index(create_identifier($1), $3);
    }
    | IDENTIFIER LBRACKET expr COLON expr RBRACKET {
        if (!is_variable_declared($1)) {
            fprintf(stderr, "Error: Variable '%s' used before declaration\n", $1);
            yyerror("Variable used before declaration");
            YYERROR;
        }
        $$ = create_string_slice(create_identifier($1), $3, $5, NULL);
    }
    | IDENTIFIER LBRACKET COLON expr RBRACKET {
        if (!is_variable_declared($1)) {
            fprintf(stderr, "Error: Variable '%s' used before declaration\n", $1);
            yyerror("Variable used before declaration");
            YYERROR;
        }
        $$ = create_string_slice(create_identifier($1), NULL, $4, NULL);
    }
    | IDENTIFIER LBRACKET expr COLON RBRACKET {
        if (!is_variable_declared($1)) {
            fprintf(stderr, "Error: Variable '%s' used before declaration\n", $1);
            yyerror("Variable used before declaration");
            YYERROR;
        }
        $$ = create_string_slice(create_identifier($1), $3, NULL, NULL);
    }
    | IDENTIFIER LBRACKET expr COLON expr COLON expr RBRACKET {
        if (!is_variable_declared($1)) {
            fprintf(stderr, "Error: Variable '%s' used before declaration\n", $1);
            yyerror("Variable used before declaration");
            YYERROR;
        }
        $$ = create_string_slice(create_identifier($1), $3, $5, $7);
    }
    ;

literal:
    INTEGER {
        $$ = create_int_literal($1);
    }
    | HEX_LITERAL {
        $$ = create_hex_literal($1);
    }
    | FLOAT_LITERAL {
        $$ = create_float_literal($1);
    }
    | BOOL_LITERAL {
        $$ = create_bool_literal($1);
    }
    | STRING_LITERAL {
        $$ = create_string_literal($1);
    }
    ;

var_decl:
    type var_list SEMICOLON {
        $$ = create_var_decl($1, $2);
    }
    ;

var_list:
    var_list COMMA var_decl_item {
        if (!$1) {
            $$ = create_var_list($3, NULL);
        } else {
            $$ = create_var_list($3, $1);
        }
    }
    | var_decl_item {
        $$ = create_var_list($1, NULL);
    }
    ;

var_decl_item:
    IDENTIFIER {
        if (!is_variable_declared($1)) {
            add_variable($1);
            $$ = create_var_decl_item($1, NULL);
        } else {
            fprintf(stderr, "Error: Variable '%s' already declared\n", $1);
            yyerror("Variable already declared");
            YYERROR;
        }
    }
    | IDENTIFIER ASSIGN expr {
        if (!is_variable_declared($1)) {
            add_variable($1);
            $$ = create_var_decl_item($1, $3);
        } else {
            fprintf(stderr, "Error: Variable '%s' already declared\n", $1);
            yyerror("Variable already declared");
            YYERROR;
        }
    }
    ;

lhs:
    IDENTIFIER %prec ASSIGN {
        $$ = create_identifier($1);
    }
    | IDENTIFIER LBRACKET expr RBRACKET %prec ASSIGN {
        if (!is_variable_declared($1)) {
            fprintf(stderr, "Error: Variable '%s' used before declaration\n", $1);
            yyerror("Variable used before declaration");
            YYERROR;
        }
        $$ = create_string_index(create_identifier($1), $3);
    }
    ;

lhs_list:
    lhs %prec ASSIGN {
        $$ = create_lhs_list($1, NULL);
    }
    | lhs_list COMMA lhs %prec ASSIGN {
        $$ = create_lhs_list($3, $1);
    }
    ;

expr_list:
    expr %prec ASSIGN {
        $$ = create_expr_list($1, NULL);
    }
    | expr_list COMMA expr %prec ASSIGN {
        $$ = create_expr_list($3, $1);
    }
    ;

func_call:
    IDENTIFIER LPAREN arg_list RPAREN {
        if (!is_function_defined($1)) {
            fprintf(stderr, "Error: Function '%s' not defined\n", $1);
            yyerror("Function not defined");
            YYERROR;
        }
        $$ = create_function_call($1, $3);
    }
    ;

arg_list:
    /* empty */ {
        $$ = NULL;
    }
    | expr {
        $$ = create_arg_list($1, NULL);
    }
    | arg_list COMMA expr {
        $$ = create_arg_list($3, $1);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}

int main(void) {
    // Initialize root to NULL
    root = NULL;
    has_main_function = 0;
    num_functions = 0;
    
    int result = yyparse();
    
    if (result == 0) {
        if (root) {
            printf("------------------\n");
            printf("AST STRUCTURE:\n");
            print_ast(root, 0);
        }
    } else {
        fprintf(stderr, "Parse failed with error code %d\n", result);
    }
    
    // Clean up
    if (root) {
        free_ast(root);
    }
    
    // Clean up function tracking
    for (int i = 0; i < num_functions; i++) {
        free(defined_functions[i]);
    }
    
    // Clean up variable tracking
    for (int i = 0; i < num_variables; i++) {
        free(declared_variables[i]);
    }
    
    return result;
}