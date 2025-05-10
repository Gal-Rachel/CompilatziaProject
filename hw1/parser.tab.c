/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 88 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_HEX_LITERAL = 4,                /* HEX_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 5,              /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_IDENTIFIER = 7,                 /* IDENTIFIER  */
  YYSYMBOL_BOOL_LITERAL = 8,               /* BOOL_LITERAL  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELIF = 10,                      /* ELIF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_PASS = 14,                      /* PASS  */
  YYSYMBOL_DEF = 15,                       /* DEF  */
  YYSYMBOL_BOOL = 16,                      /* BOOL  */
  YYSYMBOL_INT = 17,                       /* INT  */
  YYSYMBOL_FLOAT = 18,                     /* FLOAT  */
  YYSYMBOL_STRING = 19,                    /* STRING  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_EQ = 23,                        /* EQ  */
  YYSYMBOL_GT = 24,                        /* GT  */
  YYSYMBOL_GE = 25,                        /* GE  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_LE = 27,                        /* LE  */
  YYSYMBOL_NEQ = 28,                       /* NEQ  */
  YYSYMBOL_PLUS = 29,                      /* PLUS  */
  YYSYMBOL_MINUS = 30,                     /* MINUS  */
  YYSYMBOL_POW = 31,                       /* POW  */
  YYSYMBOL_TIMES = 32,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 33,                    /* DIVIDE  */
  YYSYMBOL_SEMICOLON = 34,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 35,                     /* COMMA  */
  YYSYMBOL_LBRACE = 36,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 37,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 38,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 39,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 40,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 41,                  /* RBRACKET  */
  YYSYMBOL_COLON = 42,                     /* COLON  */
  YYSYMBOL_ASSIGN = 43,                    /* ASSIGN  */
  YYSYMBOL_ARROW = 44,                     /* ARROW  */
  YYSYMBOL_UNMINUS = 45,                   /* UNMINUS  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_statement_list = 48,            /* statement_list  */
  YYSYMBOL_statement = 49,                 /* statement  */
  YYSYMBOL_function_call_statement = 50,   /* function_call_statement  */
  YYSYMBOL_if_statement = 51,              /* if_statement  */
  YYSYMBOL_elif_list = 52,                 /* elif_list  */
  YYSYMBOL_else_stmt = 53,                 /* else_stmt  */
  YYSYMBOL_while_statement = 54,           /* while_statement  */
  YYSYMBOL_return_statement = 55,          /* return_statement  */
  YYSYMBOL_pass_statement = 56,            /* pass_statement  */
  YYSYMBOL_function_body = 57,             /* function_body  */
  YYSYMBOL_function_def = 58,              /* function_def  */
  YYSYMBOL_return_type_opt = 59,           /* return_type_opt  */
  YYSYMBOL_param_list_opt = 60,            /* param_list_opt  */
  YYSYMBOL_param_list = 61,                /* param_list  */
  YYSYMBOL_param_with_default_list = 62,   /* param_with_default_list  */
  YYSYMBOL_param_with_default = 63,        /* param_with_default  */
  YYSYMBOL_type = 64,                      /* type  */
  YYSYMBOL_block = 65,                     /* block  */
  YYSYMBOL_expr = 66,                      /* expr  */
  YYSYMBOL_literal = 67,                   /* literal  */
  YYSYMBOL_var_decl = 68,                  /* var_decl  */
  YYSYMBOL_var_list = 69,                  /* var_list  */
  YYSYMBOL_var_decl_item = 70,             /* var_decl_item  */
  YYSYMBOL_lhs = 71,                       /* lhs  */
  YYSYMBOL_lhs_list = 72,                  /* lhs_list  */
  YYSYMBOL_expr_list = 73,                 /* expr_list  */
  YYSYMBOL_func_call = 74,                 /* func_call  */
  YYSYMBOL_arg_list = 75,                  /* arg_list  */
  YYSYMBOL_string_op = 76                  /* string_op  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   667

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    73,    83,    89,    92,    95,    98,   101,
     104,   107,   110,   113,   116,   122,   125,   131,   136,   139,
     144,   147,   153,   157,   163,   170,   176,   180,   186,   193,
     198,   204,   209,   215,   221,   227,   239,   246,   252,   255,
     261,   264,   270,   288,   299,   302,   308,   311,   317,   318,
     319,   320,   324,   337,   340,   343,   346,   349,   352,   355,
     358,   361,   364,   367,   370,   373,   376,   379,   382,   385,
     388,   391,   394,   400,   403,   406,   409,   412,   418,   424,
     427,   433,   436,   442,   445,   451,   454,   460,   463,   469,
     475,   478,   481,   487,   490,   493,   496,   499
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER",
  "HEX_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "IDENTIFIER",
  "BOOL_LITERAL", "IF", "ELIF", "ELSE", "WHILE", "RETURN", "PASS", "DEF",
  "BOOL", "INT", "FLOAT", "STRING", "AND", "OR", "NOT", "EQ", "GT", "GE",
  "LT", "LE", "NEQ", "PLUS", "MINUS", "POW", "TIMES", "DIVIDE",
  "SEMICOLON", "COMMA", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "COLON", "ASSIGN", "ARROW", "UNMINUS", "$accept", "program",
  "statement_list", "statement", "function_call_statement", "if_statement",
  "elif_list", "else_stmt", "while_statement", "return_statement",
  "pass_statement", "function_body", "function_def", "return_type_opt",
  "param_list_opt", "param_list", "param_with_default_list",
  "param_with_default", "type", "block", "expr", "literal", "var_decl",
  "var_list", "var_decl_item", "lhs", "lhs_list", "expr_list", "func_call",
  "arg_list", "string_op", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-140)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-85)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -140,    10,   325,  -140,  -140,  -140,  -140,  -140,   -32,  -140,
     109,   109,   109,   -18,    20,  -140,  -140,  -140,  -140,   109,
     109,   109,  -140,  -140,  -140,  -140,  -140,  -140,  -140,    32,
     564,  -140,  -140,    -8,   -31,     3,  -140,   109,    14,   -14,
     410,  -140,   430,   579,  -140,     5,   634,  -140,   547,    22,
      11,  -140,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,  -140,   109,    41,   109,  -140,
     609,    -1,   109,   341,    14,   181,   181,  -140,    62,  -140,
     109,  -140,    32,   634,   623,   183,    28,    28,    28,    28,
     183,    39,    39,    66,    66,    66,   594,    67,    63,  -140,
     609,    19,   109,  -140,   490,   -28,    25,   364,  -140,    89,
      95,  -140,  -140,    70,    86,   114,   609,  -140,  -140,  -140,
     109,  -140,   109,   609,  -140,  -140,   387,  -140,   217,   109,
      80,    97,    81,   108,    83,    62,    82,    90,  -140,   509,
     609,  -140,   109,  -140,   450,   181,   109,    87,   181,    88,
      62,    91,   114,   109,   114,  -140,   528,   181,  -140,  -140,
    -140,   470,   181,  -140,   181,  -140,   253,    90,   609,  -140,
    -140,  -140,  -140,   181,  -140,  -140,  -140,   100,  -140,  -140,
    -140,   289,  -140,  -140
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    73,    74,    75,    77,    70,    76,
       0,     0,     0,     0,     0,    48,    49,    50,    51,     0,
       0,     0,     3,     8,     9,    10,    11,    12,    13,     0,
       0,    69,    14,    85,     0,    71,    72,    90,     0,    70,
       0,    71,     0,     0,    34,     0,    55,    67,     0,    81,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     0,    15,
      91,     0,     0,     0,     0,     0,     0,    33,    41,    68,
       0,    78,     0,    54,    53,    56,    58,    59,    60,    61,
      57,    62,    63,    66,    64,    65,     0,    71,    83,    86,
      87,     0,     0,    89,     0,    93,     0,     0,     4,    17,
      18,    31,    32,     0,    40,     0,    82,    79,     6,    16,
       0,     7,     0,    92,    95,    96,     0,    93,     0,     0,
       0,    19,     0,    20,    39,     0,    46,    43,    45,     0,
      88,    94,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,    29,    23,
      30,     0,     0,    24,     0,    38,     0,    42,    47,    44,
      97,    25,    26,     0,    21,    22,     4,     0,    37,    27,
      28,     0,    36,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,  -107,     0,  -140,  -140,    27,  -139,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,   -17,   -16,   -73,   -62,
      30,  -140,  -140,  -140,    58,    74,  -140,  -140,    -2,  -140,
    -140
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,   158,    23,    24,   131,   159,    25,    26,
      27,   178,    28,   151,   113,   114,   137,   138,    29,   160,
      30,    31,    32,    50,    51,    33,    34,   101,    41,    71,
      36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,   128,    22,   -83,    67,   115,    37,   -84,    38,   163,
       3,   -83,    68,   110,   112,   -84,    44,     4,     5,     6,
       7,    39,     9,   174,    37,   175,    74,    45,     4,     5,
       6,     7,    39,     9,   102,    66,    19,    69,   103,    49,
      40,    42,    43,    78,    20,    81,    82,    19,    98,    46,
      47,    48,    21,   121,   122,    20,    72,    60,    61,    62,
      63,    64,   152,    21,    97,    80,   125,    70,    73,   181,
      62,    63,    64,    35,    35,   109,   111,   165,    15,    16,
      17,    18,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   172,    96,    62,   100,   129,
     130,   119,   104,   120,   107,   129,   132,   146,   147,   134,
     116,   180,     4,     5,     6,     7,    39,     9,   146,   149,
     135,   136,   145,   148,   153,   154,    35,   150,    22,   162,
     164,    19,   123,   166,   182,   167,   126,   133,   169,    20,
     117,    99,     0,    35,     0,     0,    35,    21,     0,     0,
     139,     0,   140,     0,     0,    35,     0,   171,     0,   144,
      35,     0,    35,     0,    35,     0,   177,     0,     0,     0,
       0,    35,   156,   179,     0,     0,   161,     0,     0,    35,
       0,    22,     0,   168,     4,     5,     6,     7,     8,     9,
      10,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,     0,     0,    19,     0,     0,     0,    55,    56,    57,
      58,    20,    60,    61,    62,    63,    64,   108,     0,    21,
       4,     5,     6,     7,     8,     9,    10,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,   143,    21,     4,     5,     6,     7,
       8,     9,    10,     0,     0,    11,    12,    13,    14,    15,
      16,    17,    18,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,     0,   176,
       0,    21,     4,     5,     6,     7,     8,     9,    10,     0,
       0,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,     0,     0,   183,    21,     4,     5,
       6,     7,     8,     9,    10,     0,     0,    11,    12,    13,
      14,    15,    16,    17,    18,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,    52,    53,    21,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,     0,   105,   106,    52,    53,     0,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,   127,   106,    52,    53,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,   141,   142,
      52,    53,     0,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,     0,
      52,    53,    75,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,     0,
      52,    53,    76,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,     0,
      52,    53,   157,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,     0,
      52,    53,   173,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,    52,
      53,   124,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     0,     0,     0,     0,     0,    52,    53,
     155,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,    52,    53,   170,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,    52,    53,    79,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    52,
      53,     0,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    77,    52,    53,     0,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   118,    52,
      53,     0,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    52,     0,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64
};

static const yytype_int16 yycheck[] =
{
       2,   108,     2,    35,    35,    78,    38,    35,    40,   148,
       0,    43,    43,    75,    76,    43,    34,     3,     4,     5,
       6,     7,     8,   162,    38,   164,    40,     7,     3,     4,
       5,     6,     7,     8,    35,    43,    22,    34,    39,     7,
      10,    11,    12,    38,    30,    34,    35,    22,     7,    19,
      20,    21,    38,    34,    35,    30,    42,    29,    30,    31,
      32,    33,   135,    38,    66,    43,    41,    37,    38,   176,
      31,    32,    33,    75,    76,    75,    76,   150,    16,    17,
      18,    19,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   157,    66,    31,    68,    10,
      11,    34,    72,    40,    74,    10,    11,    10,    11,    39,
      80,   173,     3,     4,     5,     6,     7,     8,    10,    11,
      34,     7,    42,    42,    42,    35,   128,    44,   128,    42,
      42,    22,   102,    42,    34,   152,   106,   110,   154,    30,
      82,    67,    -1,   145,    -1,    -1,   148,    38,    -1,    -1,
     120,    -1,   122,    -1,    -1,   157,    -1,   157,    -1,   129,
     162,    -1,   164,    -1,   166,    -1,   166,    -1,    -1,    -1,
      -1,   173,   142,   173,    -1,    -1,   146,    -1,    -1,   181,
      -1,   181,    -1,   153,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    24,    25,    26,
      27,    30,    29,    30,    31,    32,    33,    36,    -1,    38,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    38,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    20,    21,    38,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    42,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    42,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    42,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    42,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    20,
      21,    41,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    20,    21,
      41,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    20,    21,    41,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    20,    21,    39,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    20,
      21,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    20,
      21,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    20,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    48,     0,     3,     4,     5,     6,     7,     8,
       9,    12,    13,    14,    15,    16,    17,    18,    19,    22,
      30,    38,    49,    50,    51,    54,    55,    56,    58,    64,
      66,    67,    68,    71,    72,    74,    76,    38,    40,     7,
      66,    74,    66,    66,    34,     7,    66,    66,    66,     7,
      69,    70,    20,    21,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    43,    35,    43,    34,
      66,    75,    42,    66,    40,    42,    42,    34,    38,    39,
      43,    34,    35,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    74,     7,    71,
      66,    73,    35,    39,    66,    41,    42,    66,    36,    49,
      65,    49,    65,    60,    61,    64,    66,    70,    34,    34,
      40,    34,    35,    66,    41,    41,    66,    41,    48,    10,
      11,    52,    11,    52,    39,    34,     7,    62,    63,    66,
      66,    41,    42,    37,    66,    42,    10,    11,    42,    11,
      44,    59,    64,    42,    35,    41,    66,    42,    49,    53,
      65,    66,    42,    53,    42,    64,    42,    62,    66,    63,
      41,    49,    65,    42,    53,    53,    36,    49,    57,    49,
      65,    48,    34,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    52,    52,    53,
      53,    54,    54,    55,    56,    57,    57,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      64,    64,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    67,    67,    67,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      75,    75,    75,    76,    76,    76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     5,
       5,     8,     8,     7,     7,     4,     4,     5,     5,     1,
       1,     4,     4,     3,     2,     3,     2,     8,     2,     0,
       1,     0,     4,     2,     3,     1,     1,     3,     1,     1,
       1,     1,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     3,     1,     4,     1,     3,     1,     3,     4,
       0,     1,     3,     4,     6,     5,     5,     8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statement_list  */
#line 64 "parser.y"
                   { 
        if (!(yyvsp[0].ast_node)) {
            (yyvsp[0].ast_node) = create_block();
        }
        root = create_program((yyvsp[0].ast_node)); 
    }
#line 1378 "parser.tab.c"
    break;

  case 3: /* statement_list: statement_list statement  */
#line 73 "parser.y"
                             {
        if (!(yyvsp[-1].ast_node)) {
            (yyval.ast_node) = create_block();
        } else {
            (yyval.ast_node) = (yyvsp[-1].ast_node);
        }
        if ((yyvsp[0].ast_node)) {
            add_statement_to_block((yyval.ast_node), (yyvsp[0].ast_node));
        }
    }
#line 1393 "parser.tab.c"
    break;

  case 4: /* statement_list: %empty  */
#line 83 "parser.y"
                  {
        (yyval.ast_node) = NULL;
    }
#line 1401 "parser.tab.c"
    break;

  case 5: /* statement: expr SEMICOLON  */
#line 89 "parser.y"
                                   {
        (yyval.ast_node) = (yyvsp[-1].ast_node);
    }
#line 1409 "parser.tab.c"
    break;

  case 6: /* statement: lhs ASSIGN expr SEMICOLON  */
#line 92 "parser.y"
                                             {
        (yyval.ast_node) = create_binary_op(ASSIGN, (yyvsp[-3].ast_node), (yyvsp[-1].ast_node));
    }
#line 1417 "parser.tab.c"
    break;

  case 7: /* statement: lhs_list ASSIGN expr_list SEMICOLON  */
#line 95 "parser.y"
                                                       {
        (yyval.ast_node) = create_multiple_assignment((yyvsp[-3].ast_node), (yyvsp[-1].ast_node));
    }
#line 1425 "parser.tab.c"
    break;

  case 8: /* statement: function_call_statement  */
#line 98 "parser.y"
                                              {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1433 "parser.tab.c"
    break;

  case 9: /* statement: if_statement  */
#line 101 "parser.y"
                   {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1441 "parser.tab.c"
    break;

  case 10: /* statement: while_statement  */
#line 104 "parser.y"
                      {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1449 "parser.tab.c"
    break;

  case 11: /* statement: return_statement  */
#line 107 "parser.y"
                       {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1457 "parser.tab.c"
    break;

  case 12: /* statement: pass_statement  */
#line 110 "parser.y"
                     {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1465 "parser.tab.c"
    break;

  case 13: /* statement: function_def  */
#line 113 "parser.y"
                   { 
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1473 "parser.tab.c"
    break;

  case 14: /* statement: var_decl  */
#line 116 "parser.y"
               {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1481 "parser.tab.c"
    break;

  case 15: /* function_call_statement: func_call SEMICOLON  */
#line 122 "parser.y"
                                        {
        (yyval.ast_node) = (yyvsp[-1].ast_node);
    }
#line 1489 "parser.tab.c"
    break;

  case 16: /* function_call_statement: lhs ASSIGN func_call SEMICOLON  */
#line 125 "parser.y"
                                                  {
        (yyval.ast_node) = create_binary_op(ASSIGN, (yyvsp[-3].ast_node), (yyvsp[-1].ast_node));
    }
#line 1497 "parser.tab.c"
    break;

  case 17: /* if_statement: IF expr COLON statement  */
#line 131 "parser.y"
                                     {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, (yyvsp[0].ast_node));
        (yyval.ast_node) = create_if_statement((yyvsp[-2].ast_node), block, NULL);
    }
#line 1507 "parser.tab.c"
    break;

  case 18: /* if_statement: IF expr COLON block  */
#line 136 "parser.y"
                                   {
        (yyval.ast_node) = create_if_statement((yyvsp[-2].ast_node), (yyvsp[0].ast_node), NULL);
    }
#line 1515 "parser.tab.c"
    break;

  case 19: /* if_statement: IF expr COLON statement elif_list  */
#line 139 "parser.y"
                                                 {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, (yyvsp[-1].ast_node));
        (yyval.ast_node) = create_if_statement((yyvsp[-3].ast_node), block, (yyvsp[0].ast_node));
    }
#line 1525 "parser.tab.c"
    break;

  case 20: /* if_statement: IF expr COLON block elif_list  */
#line 144 "parser.y"
                                             {
        (yyval.ast_node) = create_if_statement((yyvsp[-3].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
    }
#line 1533 "parser.tab.c"
    break;

  case 21: /* if_statement: IF expr COLON statement elif_list ELSE COLON else_stmt  */
#line 147 "parser.y"
                                                                      {
        struct ASTNode *if_block = create_block();
        add_statement_to_block(if_block, (yyvsp[-4].ast_node));
        (yyval.ast_node) = create_if_statement((yyvsp[-6].ast_node), if_block, (yyvsp[-3].ast_node));
        (yyval.ast_node)->if_stmt.else_block = (yyvsp[0].ast_node);
    }
#line 1544 "parser.tab.c"
    break;

  case 22: /* if_statement: IF expr COLON block elif_list ELSE COLON else_stmt  */
#line 153 "parser.y"
                                                                  {
        (yyval.ast_node) = create_if_statement((yyvsp[-6].ast_node), (yyvsp[-4].ast_node), (yyvsp[-3].ast_node));
        (yyval.ast_node)->if_stmt.else_block = (yyvsp[0].ast_node);
    }
#line 1553 "parser.tab.c"
    break;

  case 23: /* if_statement: IF expr COLON statement ELSE COLON else_stmt  */
#line 157 "parser.y"
                                                            {
        struct ASTNode *if_block = create_block();
        add_statement_to_block(if_block, (yyvsp[-3].ast_node));
        (yyval.ast_node) = create_if_statement((yyvsp[-5].ast_node), if_block, NULL);
        (yyval.ast_node)->if_stmt.else_block = (yyvsp[0].ast_node);
    }
#line 1564 "parser.tab.c"
    break;

  case 24: /* if_statement: IF expr COLON block ELSE COLON else_stmt  */
#line 163 "parser.y"
                                                        {
        (yyval.ast_node) = create_if_statement((yyvsp[-5].ast_node), (yyvsp[-3].ast_node), NULL);
        (yyval.ast_node)->if_stmt.else_block = (yyvsp[0].ast_node);
    }
#line 1573 "parser.tab.c"
    break;

  case 25: /* elif_list: ELIF expr COLON statement  */
#line 170 "parser.y"
                                         {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, (yyvsp[0].ast_node));
        (yyval.ast_node) = create_block();
        add_statement_to_block((yyval.ast_node), create_elif((yyvsp[-2].ast_node), block));
    }
#line 1584 "parser.tab.c"
    break;

  case 26: /* elif_list: ELIF expr COLON block  */
#line 176 "parser.y"
                                       {
        (yyval.ast_node) = create_block();
        add_statement_to_block((yyval.ast_node), create_elif((yyvsp[-2].ast_node), (yyvsp[0].ast_node)));
    }
#line 1593 "parser.tab.c"
    break;

  case 27: /* elif_list: elif_list ELIF expr COLON statement  */
#line 180 "parser.y"
                                                     {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, (yyvsp[0].ast_node));
        add_statement_to_block((yyvsp[-4].ast_node), create_elif((yyvsp[-2].ast_node), block));
        (yyval.ast_node) = (yyvsp[-4].ast_node);
    }
#line 1604 "parser.tab.c"
    break;

  case 28: /* elif_list: elif_list ELIF expr COLON block  */
#line 186 "parser.y"
                                                 {
        add_statement_to_block((yyvsp[-4].ast_node), create_elif((yyvsp[-2].ast_node), (yyvsp[0].ast_node)));
        (yyval.ast_node) = (yyvsp[-4].ast_node);
    }
#line 1613 "parser.tab.c"
    break;

  case 29: /* else_stmt: statement  */
#line 193 "parser.y"
                         {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, (yyvsp[0].ast_node));
        (yyval.ast_node) = block;
    }
#line 1623 "parser.tab.c"
    break;

  case 30: /* else_stmt: block  */
#line 198 "parser.y"
                       {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1631 "parser.tab.c"
    break;

  case 31: /* while_statement: WHILE expr COLON statement  */
#line 204 "parser.y"
                                        {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, (yyvsp[0].ast_node));
        (yyval.ast_node) = create_while_statement((yyvsp[-2].ast_node), block);
    }
#line 1641 "parser.tab.c"
    break;

  case 32: /* while_statement: WHILE expr COLON block  */
#line 209 "parser.y"
                                      {
        (yyval.ast_node) = create_while_statement((yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1649 "parser.tab.c"
    break;

  case 33: /* return_statement: RETURN expr SEMICOLON  */
#line 215 "parser.y"
                          {
        (yyval.ast_node) = create_return_statement((yyvsp[-1].ast_node));
    }
#line 1657 "parser.tab.c"
    break;

  case 34: /* pass_statement: PASS SEMICOLON  */
#line 221 "parser.y"
                   {
        (yyval.ast_node) = create_pass_statement();
    }
#line 1665 "parser.tab.c"
    break;

  case 35: /* function_body: LBRACE statement_list RBRACE  */
#line 227 "parser.y"
                                 {
        (yyval.ast_node) = create_block();
        if ((yyvsp[-1].ast_node)) {
            if ((yyvsp[-1].ast_node)->type == AST_BLOCK) {
                for (int i = 0; i < (yyvsp[-1].ast_node)->block.statement_count; i++) {
                    add_statement_to_block((yyval.ast_node), (yyvsp[-1].ast_node)->block.statements[i]);
                }
            } else {
                add_statement_to_block((yyval.ast_node), (yyvsp[-1].ast_node));
            }
        }
    }
#line 1682 "parser.tab.c"
    break;

  case 36: /* function_body: statement SEMICOLON  */
#line 239 "parser.y"
                          {
        (yyval.ast_node) = create_block();
        add_statement_to_block((yyval.ast_node), (yyvsp[-1].ast_node));
    }
#line 1691 "parser.tab.c"
    break;

  case 37: /* function_def: DEF IDENTIFIER LPAREN param_list_opt RPAREN return_type_opt COLON function_body  */
#line 246 "parser.y"
                                                                                    {
        (yyval.ast_node) = create_function_def((yyvsp[-6].strval), (yyvsp[-4].ast_node), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1699 "parser.tab.c"
    break;

  case 38: /* return_type_opt: ARROW type  */
#line 252 "parser.y"
               {
        (yyval.ast_node) = create_return_type((yyvsp[0].typeval));
    }
#line 1707 "parser.tab.c"
    break;

  case 39: /* return_type_opt: %empty  */
#line 255 "parser.y"
                  {
        (yyval.ast_node) = NULL;
    }
#line 1715 "parser.tab.c"
    break;

  case 40: /* param_list_opt: param_list  */
#line 261 "parser.y"
               {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1723 "parser.tab.c"
    break;

  case 41: /* param_list_opt: %empty  */
#line 264 "parser.y"
                  {
        (yyval.ast_node) = NULL;
    }
#line 1731 "parser.tab.c"
    break;

  case 42: /* param_list: param_list SEMICOLON type param_with_default_list  */
#line 270 "parser.y"
                                                      {
        struct ASTNode *new_list = (yyvsp[0].ast_node);
        struct ASTNode *current = new_list;
        while (current) {
            current->param_list.first->param.type = (yyvsp[-1].typeval);
            current = current->param_list.rest;
        }
        if ((yyvsp[-3].ast_node)) {
            struct ASTNode *last = new_list;
            while (last->param_list.rest) {
                last = last->param_list.rest;
            }
            last->param_list.rest = (yyvsp[-3].ast_node);
            (yyval.ast_node) = new_list;
        } else {
            (yyval.ast_node) = new_list;
        }
    }
#line 1754 "parser.tab.c"
    break;

  case 43: /* param_list: type param_with_default_list  */
#line 288 "parser.y"
                                   {
        (yyval.ast_node) = (yyvsp[0].ast_node);
        struct ASTNode *current = (yyval.ast_node);
        while (current) {
            current->param_list.first->param.type = (yyvsp[-1].typeval);
            current = current->param_list.rest;
        }
    }
#line 1767 "parser.tab.c"
    break;

  case 44: /* param_with_default_list: param_with_default_list COMMA param_with_default  */
#line 299 "parser.y"
                                                     {
        (yyval.ast_node) = create_param_list((yyvsp[0].ast_node), (yyvsp[-2].ast_node));
    }
#line 1775 "parser.tab.c"
    break;

  case 45: /* param_with_default_list: param_with_default  */
#line 302 "parser.y"
                         {
        (yyval.ast_node) = create_param_list((yyvsp[0].ast_node), NULL);
    }
#line 1783 "parser.tab.c"
    break;

  case 46: /* param_with_default: IDENTIFIER  */
#line 308 "parser.y"
               {
        (yyval.ast_node) = create_param_with_default((yyvsp[0].strval), NULL);
    }
#line 1791 "parser.tab.c"
    break;

  case 47: /* param_with_default: IDENTIFIER COLON expr  */
#line 311 "parser.y"
                            {
        (yyval.ast_node) = create_param_with_default((yyvsp[-2].strval), (yyvsp[0].ast_node));
    }
#line 1799 "parser.tab.c"
    break;

  case 48: /* type: BOOL  */
#line 317 "parser.y"
           { (yyval.typeval) = BOOL; }
#line 1805 "parser.tab.c"
    break;

  case 49: /* type: INT  */
#line 318 "parser.y"
           { (yyval.typeval) = INT; }
#line 1811 "parser.tab.c"
    break;

  case 50: /* type: FLOAT  */
#line 319 "parser.y"
            { (yyval.typeval) = FLOAT; }
#line 1817 "parser.tab.c"
    break;

  case 51: /* type: STRING  */
#line 320 "parser.y"
             { (yyval.typeval) = STRING; }
#line 1823 "parser.tab.c"
    break;

  case 52: /* block: LBRACE statement_list RBRACE  */
#line 324 "parser.y"
                                              {
        if (!(yyvsp[-1].ast_node)) {
            (yyval.ast_node) = create_block();
        } else if ((yyvsp[-1].ast_node)->type == AST_BLOCK) {
            (yyval.ast_node) = (yyvsp[-1].ast_node);
        } else {
            (yyval.ast_node) = create_block();
            add_statement_to_block((yyval.ast_node), (yyvsp[-1].ast_node));
        }
    }
#line 1838 "parser.tab.c"
    break;

  case 53: /* expr: expr OR expr  */
#line 337 "parser.y"
                 {
        (yyval.ast_node) = create_binary_op(OR, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1846 "parser.tab.c"
    break;

  case 54: /* expr: expr AND expr  */
#line 340 "parser.y"
                    {
        (yyval.ast_node) = create_binary_op(AND, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1854 "parser.tab.c"
    break;

  case 55: /* expr: NOT expr  */
#line 343 "parser.y"
               {
        (yyval.ast_node) = create_unary_op(NOT, (yyvsp[0].ast_node));
    }
#line 1862 "parser.tab.c"
    break;

  case 56: /* expr: expr EQ expr  */
#line 346 "parser.y"
                   {
        (yyval.ast_node) = create_binary_op(EQ, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1870 "parser.tab.c"
    break;

  case 57: /* expr: expr NEQ expr  */
#line 349 "parser.y"
                    {
        (yyval.ast_node) = create_binary_op(NEQ, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1878 "parser.tab.c"
    break;

  case 58: /* expr: expr GT expr  */
#line 352 "parser.y"
                   {
        (yyval.ast_node) = create_binary_op(GT, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1886 "parser.tab.c"
    break;

  case 59: /* expr: expr GE expr  */
#line 355 "parser.y"
                   {
        (yyval.ast_node) = create_binary_op(GE, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1894 "parser.tab.c"
    break;

  case 60: /* expr: expr LT expr  */
#line 358 "parser.y"
                   {
        (yyval.ast_node) = create_binary_op(LT, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1902 "parser.tab.c"
    break;

  case 61: /* expr: expr LE expr  */
#line 361 "parser.y"
                   {
        (yyval.ast_node) = create_binary_op(LE, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1910 "parser.tab.c"
    break;

  case 62: /* expr: expr PLUS expr  */
#line 364 "parser.y"
                     {
        (yyval.ast_node) = create_binary_op(PLUS, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1918 "parser.tab.c"
    break;

  case 63: /* expr: expr MINUS expr  */
#line 367 "parser.y"
                      {
        (yyval.ast_node) = create_binary_op(MINUS, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1926 "parser.tab.c"
    break;

  case 64: /* expr: expr TIMES expr  */
#line 370 "parser.y"
                      {
        (yyval.ast_node) = create_binary_op(TIMES, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1934 "parser.tab.c"
    break;

  case 65: /* expr: expr DIVIDE expr  */
#line 373 "parser.y"
                       {
        (yyval.ast_node) = create_binary_op(DIVIDE, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1942 "parser.tab.c"
    break;

  case 66: /* expr: expr POW expr  */
#line 376 "parser.y"
                    {
        (yyval.ast_node) = create_binary_op(POW, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1950 "parser.tab.c"
    break;

  case 67: /* expr: MINUS expr  */
#line 379 "parser.y"
                               {
        (yyval.ast_node) = create_unary_op(MINUS, (yyvsp[0].ast_node));
    }
#line 1958 "parser.tab.c"
    break;

  case 68: /* expr: LPAREN expr RPAREN  */
#line 382 "parser.y"
                         {
        (yyval.ast_node) = (yyvsp[-1].ast_node);
    }
#line 1966 "parser.tab.c"
    break;

  case 69: /* expr: literal  */
#line 385 "parser.y"
              {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1974 "parser.tab.c"
    break;

  case 70: /* expr: IDENTIFIER  */
#line 388 "parser.y"
                 {
        (yyval.ast_node) = create_identifier((yyvsp[0].strval));
    }
#line 1982 "parser.tab.c"
    break;

  case 71: /* expr: func_call  */
#line 391 "parser.y"
                {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1990 "parser.tab.c"
    break;

  case 72: /* expr: string_op  */
#line 394 "parser.y"
                {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1998 "parser.tab.c"
    break;

  case 73: /* literal: INTEGER  */
#line 400 "parser.y"
            {
        (yyval.ast_node) = create_int_literal((yyvsp[0].intval));
    }
#line 2006 "parser.tab.c"
    break;

  case 74: /* literal: HEX_LITERAL  */
#line 403 "parser.y"
                  {
        (yyval.ast_node) = create_hex_literal((yyvsp[0].intval));
    }
#line 2014 "parser.tab.c"
    break;

  case 75: /* literal: FLOAT_LITERAL  */
#line 406 "parser.y"
                    {
        (yyval.ast_node) = create_float_literal((yyvsp[0].floatval));
    }
#line 2022 "parser.tab.c"
    break;

  case 76: /* literal: BOOL_LITERAL  */
#line 409 "parser.y"
                   {
        (yyval.ast_node) = create_bool_literal((yyvsp[0].intval));
    }
#line 2030 "parser.tab.c"
    break;

  case 77: /* literal: STRING_LITERAL  */
#line 412 "parser.y"
                     {
        (yyval.ast_node) = create_string_literal((yyvsp[0].strval));
    }
#line 2038 "parser.tab.c"
    break;

  case 78: /* var_decl: type var_list SEMICOLON  */
#line 418 "parser.y"
                            {
        (yyval.ast_node) = create_var_decl((yyvsp[-2].typeval), (yyvsp[-1].ast_node));
    }
#line 2046 "parser.tab.c"
    break;

  case 79: /* var_list: var_list COMMA var_decl_item  */
#line 424 "parser.y"
                                 {
        (yyval.ast_node) = create_var_list((yyvsp[0].ast_node), (yyvsp[-2].ast_node));
    }
#line 2054 "parser.tab.c"
    break;

  case 80: /* var_list: var_decl_item  */
#line 427 "parser.y"
                    {
        (yyval.ast_node) = create_var_list((yyvsp[0].ast_node), NULL);
    }
#line 2062 "parser.tab.c"
    break;

  case 81: /* var_decl_item: IDENTIFIER  */
#line 433 "parser.y"
               {
        (yyval.ast_node) = create_var_decl_item((yyvsp[0].strval), NULL);
    }
#line 2070 "parser.tab.c"
    break;

  case 82: /* var_decl_item: IDENTIFIER ASSIGN expr  */
#line 436 "parser.y"
                             {
        (yyval.ast_node) = create_var_decl_item((yyvsp[-2].strval), (yyvsp[0].ast_node));
    }
#line 2078 "parser.tab.c"
    break;

  case 83: /* lhs: IDENTIFIER  */
#line 442 "parser.y"
                            {
        (yyval.ast_node) = create_identifier((yyvsp[0].strval));
    }
#line 2086 "parser.tab.c"
    break;

  case 84: /* lhs: IDENTIFIER LBRACKET expr RBRACKET  */
#line 445 "parser.y"
                                                     {
        (yyval.ast_node) = create_string_index(create_identifier((yyvsp[-3].strval)), (yyvsp[-1].ast_node));
    }
#line 2094 "parser.tab.c"
    break;

  case 85: /* lhs_list: lhs  */
#line 451 "parser.y"
                     {
        (yyval.ast_node) = create_lhs_list((yyvsp[0].ast_node), NULL);
    }
#line 2102 "parser.tab.c"
    break;

  case 86: /* lhs_list: lhs_list COMMA lhs  */
#line 454 "parser.y"
                                      {
        (yyval.ast_node) = create_lhs_list((yyvsp[0].ast_node), (yyvsp[-2].ast_node));
    }
#line 2110 "parser.tab.c"
    break;

  case 87: /* expr_list: expr  */
#line 460 "parser.y"
                      {
        (yyval.ast_node) = create_expr_list((yyvsp[0].ast_node), NULL);
    }
#line 2118 "parser.tab.c"
    break;

  case 88: /* expr_list: expr_list COMMA expr  */
#line 463 "parser.y"
                                        {
        (yyval.ast_node) = create_expr_list((yyvsp[0].ast_node), (yyvsp[-2].ast_node));
    }
#line 2126 "parser.tab.c"
    break;

  case 89: /* func_call: IDENTIFIER LPAREN arg_list RPAREN  */
#line 469 "parser.y"
                                      {
        (yyval.ast_node) = create_function_call((yyvsp[-3].strval), (yyvsp[-1].ast_node));
    }
#line 2134 "parser.tab.c"
    break;

  case 90: /* arg_list: %empty  */
#line 475 "parser.y"
                {
        (yyval.ast_node) = NULL;
    }
#line 2142 "parser.tab.c"
    break;

  case 91: /* arg_list: expr  */
#line 478 "parser.y"
           {
        (yyval.ast_node) = create_arg_list((yyvsp[0].ast_node), NULL);
    }
#line 2150 "parser.tab.c"
    break;

  case 92: /* arg_list: arg_list COMMA expr  */
#line 481 "parser.y"
                          {
        (yyval.ast_node) = create_arg_list((yyvsp[0].ast_node), (yyvsp[-2].ast_node));
    }
#line 2158 "parser.tab.c"
    break;

  case 93: /* string_op: IDENTIFIER LBRACKET expr RBRACKET  */
#line 487 "parser.y"
                                      {
        (yyval.ast_node) = create_string_index(create_identifier((yyvsp[-3].strval)), (yyvsp[-1].ast_node));
    }
#line 2166 "parser.tab.c"
    break;

  case 94: /* string_op: IDENTIFIER LBRACKET expr COLON expr RBRACKET  */
#line 490 "parser.y"
                                                   {
        (yyval.ast_node) = create_string_slice(create_identifier((yyvsp[-5].strval)), (yyvsp[-3].ast_node), (yyvsp[-1].ast_node), NULL);
    }
#line 2174 "parser.tab.c"
    break;

  case 95: /* string_op: IDENTIFIER LBRACKET COLON expr RBRACKET  */
#line 493 "parser.y"
                                              {
        (yyval.ast_node) = create_string_slice(create_identifier((yyvsp[-4].strval)), NULL, (yyvsp[-1].ast_node), NULL);
    }
#line 2182 "parser.tab.c"
    break;

  case 96: /* string_op: IDENTIFIER LBRACKET expr COLON RBRACKET  */
#line 496 "parser.y"
                                              {
        (yyval.ast_node) = create_string_slice(create_identifier((yyvsp[-4].strval)), (yyvsp[-2].ast_node), NULL, NULL);
    }
#line 2190 "parser.tab.c"
    break;

  case 97: /* string_op: IDENTIFIER LBRACKET expr COLON expr COLON expr RBRACKET  */
#line 499 "parser.y"
                                                              {
        (yyval.ast_node) = create_string_slice(create_identifier((yyvsp[-7].strval)), (yyvsp[-5].ast_node), (yyvsp[-3].ast_node), (yyvsp[-1].ast_node));
    }
#line 2198 "parser.tab.c"
    break;


#line 2202 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 504 "parser.y"


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
