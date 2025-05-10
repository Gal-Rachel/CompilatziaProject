/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    HEX_LITERAL = 259,             /* HEX_LITERAL  */
    FLOAT_LITERAL = 260,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 261,          /* STRING_LITERAL  */
    IDENTIFIER = 262,              /* IDENTIFIER  */
    BOOL_LITERAL = 263,            /* BOOL_LITERAL  */
    IF = 264,                      /* IF  */
    ELIF = 265,                    /* ELIF  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    RETURN = 268,                  /* RETURN  */
    PASS = 269,                    /* PASS  */
    DEF = 270,                     /* DEF  */
    BOOL = 271,                    /* BOOL  */
    INT = 272,                     /* INT  */
    FLOAT = 273,                   /* FLOAT  */
    STRING = 274,                  /* STRING  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    NOT = 277,                     /* NOT  */
    EQ = 278,                      /* EQ  */
    GT = 279,                      /* GT  */
    GE = 280,                      /* GE  */
    LT = 281,                      /* LT  */
    LE = 282,                      /* LE  */
    NEQ = 283,                     /* NEQ  */
    PLUS = 284,                    /* PLUS  */
    MINUS = 285,                   /* MINUS  */
    POW = 286,                     /* POW  */
    TIMES = 287,                   /* TIMES  */
    DIVIDE = 288,                  /* DIVIDE  */
    SEMICOLON = 289,               /* SEMICOLON  */
    COMMA = 290,                   /* COMMA  */
    LBRACE = 291,                  /* LBRACE  */
    RBRACE = 292,                  /* RBRACE  */
    LPAREN = 293,                  /* LPAREN  */
    RPAREN = 294,                  /* RPAREN  */
    LBRACKET = 295,                /* LBRACKET  */
    RBRACKET = 296,                /* RBRACKET  */
    COLON = 297,                   /* COLON  */
    ASSIGN = 298,                  /* ASSIGN  */
    ARROW = 299,                   /* ARROW  */
    UNMINUS = 300                  /* UNMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "parser.y"

    int intval;
    float floatval;
    char *strval;
    ASTNode* ast_node;
    int typeval;

#line 117 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
