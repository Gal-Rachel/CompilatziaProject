%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#include "ast.h"

void yyerror(const char *s);
extern int yylineno;
%}

%option noyywrap

%%

[ \t\n]+    { /* Skip whitespace */ }

#.*         { /* Python-style single-line comment */ }

"//".*      { 
    fprintf(stderr, "Error at line %d: C++ style comments (//) are not allowed\n", yylineno);
    yyerror("C++ style comments not allowed");
    return -1;
}

"/\*"([^*]|\*+[^*/])*\*+"/" {
    fprintf(stderr, "Error at line %d: C style block comments (/* */) are not allowed\n", yylineno);
    yyerror("C style block comments not allowed");
    return -1;
}

"if"        { return IF; }
"elif"      { return ELIF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"return"    { return RETURN; }
"pass"      { return PASS; }
"def"       { return DEF; }
"true"      { yylval.intval = 1; return BOOL_LITERAL; }
"false"     { yylval.intval = 0; return BOOL_LITERAL; }
"and"       { return AND; }
"or"        { return OR; }
"not"       { return NOT; }
"bool"      { return BOOL; }
"int"       { return INT; }
"float"     { return FLOAT; }
"string"    { return STRING; }

[0-9]+      { yylval.intval = atoi(yytext); return INTEGER; }
0[xX][0-9a-fA-F]+ { yylval.intval = strtol(yytext, NULL, 16); return HEX_LITERAL; }
[0-9]+\.[0-9]* { yylval.floatval = atof(yytext); return FLOAT_LITERAL; }
\"[^"\n]*\" { 
    yylval.strval = strdup(yytext);
    // Remove quotes
    yylval.strval[strlen(yylval.strval)-1] = '\0';
    memmove(yylval.strval, yylval.strval+1, strlen(yylval.strval));
    return STRING_LITERAL;
}

[a-zA-Z_][a-zA-Z0-9_]* { 
    yylval.strval = strdup(yytext); 
    return IDENTIFIER; 
}

"=="        { return EQ; }
">"         { return GT; }
">="        { return GE; }
"<"         { return LT; }
"<="        { return LE; }
"!="        { return NEQ; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"**"        { return POW; }
"*"         { return TIMES; }
"/"         { return DIVIDE; }
";"         { return SEMICOLON; }
","         { return COMMA; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
"("         { return LPAREN; }
")"         { return RPAREN; }
"["         { return LBRACKET; }
"]"         { return RBRACKET; }
":"         { return COLON; }
"="         { return ASSIGN; }
"->"        { return ARROW; }

.           { 
    fprintf(stderr, "Error at line %d: Unexpected character '%s'\n", yylineno, yytext);
    yyerror("Unexpected character");
    return -1;
}

%% 