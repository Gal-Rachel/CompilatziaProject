%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantic.h"
#include "parser.tab.h"

void yyerror(const char *s);
extern int yylex(void);
extern int yylineno;
ASTNode* root = NULL;

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
        if (!$1) {
            $1 = create_block();
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
            if ($2->type == AST_BLOCK) {
                for (int i = 0; i < $2->block.statement_count; i++) {
                    add_statement_to_block($$, $2->block.statements[i]);
                }
            } else {
                add_statement_to_block($$, $2);
            }
        }
    }
    | statement SEMICOLON {
        $$ = create_block();
        add_statement_to_block($$, $1);
    }
    ;

function_def:
    DEF IDENTIFIER LPAREN param_list_opt RPAREN return_type_opt COLON function_body {
        $$ = create_function_def($2, $4, $6, $8);
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
        struct ASTNode *current = new_list;
        while (current) {
            current->param_list.first->param.type = $3;
            current = current->param_list.rest;
        }
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
        $$ = create_param_with_default($1, NULL);
    }
    | IDENTIFIER COLON expr {
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
            $$ = create_block();
        } else if ($2->type == AST_BLOCK) {
            $$ = $2;
        } else {
            $$ = create_block();
            add_statement_to_block($$, $2);
        }
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
        $$ = create_identifier($1);
    }
    | func_call {
        $$ = $1;
    }
    | string_op {
        $$ = $1;
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
        $$ = create_var_list($3, $1);
    }
    | var_decl_item {
        $$ = create_var_list($1, NULL);
    }
    ;

var_decl_item:
    IDENTIFIER {
        $$ = create_var_decl_item($1, NULL);
    }
    | IDENTIFIER ASSIGN expr {
        $$ = create_var_decl_item($1, $3);
    }
    ;

lhs:
    IDENTIFIER %prec ASSIGN {
        $$ = create_identifier($1);
    }
    | IDENTIFIER LBRACKET expr RBRACKET %prec ASSIGN {
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

string_op:
    IDENTIFIER LBRACKET expr RBRACKET {
        $$ = create_string_index(create_identifier($1), $3);
    }
    | IDENTIFIER LBRACKET expr COLON expr RBRACKET {
        $$ = create_string_slice(create_identifier($1), $3, $5, NULL);
    }
    | IDENTIFIER LBRACKET COLON expr RBRACKET {
        $$ = create_string_slice(create_identifier($1), NULL, $4, NULL);
    }
    | IDENTIFIER LBRACKET expr COLON RBRACKET {
        $$ = create_string_slice(create_identifier($1), $3, NULL, NULL);
    }
    | IDENTIFIER LBRACKET expr COLON expr COLON expr RBRACKET {
        $$ = create_string_slice(create_identifier($1), $3, $5, $7);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}

int main(void) {
    root = NULL;
    
    int parse_result = yyparse();
    
    if (parse_result == 0) {
        if (root) {
            // Perform semantic analysis
            SemanticErrorCode semantic_result = analyze_semantics(root);
            
            if (semantic_result == SEMANTIC_OK) {
                printf("------------------\n");
                printf("AST STRUCTURE:\n");
                print_ast(root, 0);
                printf("\nSemantic analysis completed successfully.\n");
            } else {
                // The error details will be printed by report_semantic_error
                parse_result = 1;
            }
        }
    } else {
        fprintf(stderr, "Parse failed with error code %d\n", parse_result);
    }
    
    if (root) {
        free_ast(root);
    }
    
    return parse_result;
}