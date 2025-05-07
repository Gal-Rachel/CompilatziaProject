%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "parser.tab.h"

void yyerror(const char *s);

%}

%option noyywrap
%option yylineno

%%

[ \t\n]         ; /* Skip whitespace */
"#".*           ; /* Skip comments */

"def"           { return DEF; }
"if"            { return IF; }
"elif"          { return ELIF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"return"        { return RETURN; }
"pass"          { return PASS; }
"bool"          { return BOOL; }
"int"           { return INT; }
"float"         { return FLOAT; }
"string"        { return STRING; }
"and"           { return AND; }
"or"            { return OR; }
"not"           { return NOT; }

"=="            { return EQ; }
">"             { return GT; }
">="            { return GE; }
"<"             { return LT; }
"<="            { return LE; }
"!="            { return NEQ; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"**"            { return POW; }
"*"             { return TIMES; }
"/"             { return DIVIDE; }

":"             { return COLON; }
";"             { return SEMICOLON; }
","             { return COMMA; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
"="             { return ASSIGN; }
"->"            { return ARROW; }

"true"          { yylval.intval = 1; return BOOL_LITERAL; }
"false"         { yylval.intval = 0; return BOOL_LITERAL; }

[a-zA-Z_][a-zA-Z0-9_]*   { 
    yylval.strval = strdup(yytext);
    if (!yylval.strval) {
        fprintf(stderr, "Memory allocation failed for identifier\n");
        exit(1);
    }
    return IDENTIFIER; 
}

0[xX][0-9a-fA-F]+       {
    yylval.intval = (int) strtol(yytext, NULL, 16);
    return HEX_LITERAL;
}

[0-9]+\.[0-9]+           {
    yylval.floatval = atof(yytext);
    return FLOAT_LITERAL;
}

(0|[1-9][0-9]*)          {
    yylval.intval = atoi(yytext);
    return INTEGER;
}

\"([^\\\n\"]|\\.)*\"   { 
    yylval.strval = process_string(yytext); 
    return STRING_LITERAL; 
}

\'([^\\\n\']|\\.)*\'   { 
    yylval.strval = process_string(yytext); 
    return STRING_LITERAL; 
}

.               { 
    fprintf(stderr, "Error: Unexpected character '%s'\n", yytext);
    yyerror("Unexpected character");
}

%% 
char* process_string(const char* text) {
    int len = strlen(text);
    char* str = (char*)malloc(len - 1);  // Allocate space for the string without the quotes
    if (!str) {
        fprintf(stderr, "Memory allocation failed in process_string\n");
        exit(1);
    }
    strncpy(str, text + 1, len - 2);  // Copy the string without the quotes
    str[len - 2] = '\0';  // Null terminate
    return str;
}