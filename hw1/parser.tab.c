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
  YYSYMBOL_59_1 = 59,                      /* @1  */
  YYSYMBOL_return_type_opt = 60,           /* return_type_opt  */
  YYSYMBOL_param_list_opt = 61,            /* param_list_opt  */
  YYSYMBOL_param_list = 62,                /* param_list  */
  YYSYMBOL_param_with_default_list = 63,   /* param_with_default_list  */
  YYSYMBOL_param_with_default = 64,        /* param_with_default  */
  YYSYMBOL_type = 65,                      /* type  */
  YYSYMBOL_block = 66,                     /* block  */
  YYSYMBOL_expr = 67,                      /* expr  */
  YYSYMBOL_literal = 68,                   /* literal  */
  YYSYMBOL_var_decl = 69,                  /* var_decl  */
  YYSYMBOL_var_list = 70,                  /* var_list  */
  YYSYMBOL_var_decl_item = 71,             /* var_decl_item  */
  YYSYMBOL_lhs = 72,                       /* lhs  */
  YYSYMBOL_lhs_list = 73,                  /* lhs_list  */
  YYSYMBOL_expr_list = 74,                 /* expr_list  */
  YYSYMBOL_func_call = 75,                 /* func_call  */
  YYSYMBOL_arg_list = 76,                  /* arg_list  */
  YYSYMBOL_string_op = 77                  /* string_op  */
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
#define YYLAST   644

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

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
     198,   204,   209,   215,   221,   227,   239,   246,   246,   256,
     259,   265,   268,   274,   292,   303,   306,   312,   315,   321,
     322,   323,   324,   328,   341,   344,   347,   350,   353,   356,
     359,   362,   365,   368,   371,   374,   377,   380,   383,   386,
     389,   392,   395,   398,   404,   407,   410,   413,   416,   422,
     428,   431,   437,   440,   446,   449,   455,   458,   464,   467,
     473,   479,   482,   485,   491,   494,   497,   500,   503
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
  "pass_statement", "function_body", "function_def", "@1",
  "return_type_opt", "param_list_opt", "param_list",
  "param_with_default_list", "param_with_default", "type", "block", "expr",
  "literal", "var_decl", "var_list", "var_decl_item", "lhs", "lhs_list",
  "expr_list", "func_call", "arg_list", "string_op", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-86)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -111,    23,   325,  -111,  -111,  -111,  -111,  -111,    63,  -111,
      24,    24,    24,   -20,    27,  -111,  -111,  -111,  -111,    24,
      24,    24,  -111,  -111,  -111,  -111,  -111,  -111,  -111,    36,
     541,  -111,  -111,    -8,   -31,    16,  -111,    24,     3,   -14,
     387,  -111,   407,   556,  -111,  -111,   611,  -111,   524,    20,
      25,  -111,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,  -111,    24,    54,    24,  -111,
     586,    18,    24,    90,     3,   181,   181,  -111,    57,  -111,
      24,  -111,    36,   611,   600,   183,    38,    38,    38,    38,
     183,    46,    46,    66,    66,    66,   571,    65,    67,  -111,
     586,    70,    24,  -111,   467,   -30,    14,   341,  -111,   117,
     130,  -111,  -111,   119,   586,  -111,  -111,  -111,    24,  -111,
      24,   586,  -111,  -111,   364,  -111,   217,    24,    83,   133,
      87,   139,    73,    99,   138,   486,   586,  -111,    24,  -111,
     427,   181,    24,   105,   181,   110,   113,   119,   112,   124,
    -111,  -111,   505,   181,  -111,  -111,  -111,   447,   181,  -111,
     181,   119,   118,   138,    24,   138,  -111,  -111,  -111,   181,
    -111,  -111,  -111,   253,   124,   586,  -111,  -111,  -111,  -111,
     127,  -111,   289,  -111,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    74,    75,    76,    78,    71,    77,
       0,     0,     0,     0,     0,    49,    50,    51,    52,     0,
       0,     0,     3,     8,     9,    10,    11,    12,    13,     0,
       0,    70,    14,    86,     0,    72,    73,    91,     0,    71,
       0,    72,     0,     0,    34,    37,    56,    68,     0,    82,
       0,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     0,    15,
      92,     0,     0,     0,     0,     0,     0,    33,     0,    69,
       0,    79,     0,    55,    54,    57,    59,    60,    61,    62,
      58,    63,    64,    67,    65,    66,     0,    72,    84,    87,
      88,     0,     0,    90,     0,    94,     0,     0,     4,    17,
      18,    31,    32,    42,    83,    80,     6,    16,     0,     7,
       0,    93,    96,    97,     0,    94,     0,     0,     0,    19,
       0,    20,     0,    41,     0,     0,    89,    95,     0,    53,
       0,     0,     0,     0,     0,     0,    40,     0,    47,    44,
      46,    85,     0,     0,    29,    23,    30,     0,     0,    24,
       0,     0,     0,     0,     0,     0,    98,    25,    26,     0,
      21,    22,    39,     0,    43,    48,    45,    27,    28,     4,
       0,    38,     0,    36,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -111,  -111,  -107,     0,  -111,  -111,    52,  -102,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,     1,     7,  -110,
     -60,    28,  -111,  -111,  -111,    81,    98,  -111,  -111,    -2,
    -111,  -111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,   154,    23,    24,   129,   155,    25,    26,
      27,   181,    28,    78,   162,   132,   133,   149,   150,    29,
     156,    30,    31,    32,    50,    51,    33,    34,   101,    41,
      71,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,   126,    22,   134,    67,   -85,     4,     5,     6,     7,
      39,     9,    68,   -85,    44,   110,   112,     4,     5,     6,
       7,    39,     9,     3,    37,    19,    74,     4,     5,     6,
       7,    39,     9,    20,    45,    66,    19,   163,    40,    42,
      43,    21,   159,    49,    20,    72,    19,    46,    47,    48,
      69,   172,    21,   102,    20,   123,   170,   103,   171,    81,
      82,    98,    21,    80,    97,    70,    73,    60,    61,    62,
      63,    64,   182,    35,    35,   109,   111,    62,    63,    64,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   168,    96,   113,   100,    62,   -84,   117,
     104,    37,   107,    38,   119,   120,   -84,   118,   114,   178,
      52,    53,   146,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    35,   141,    22,   127,   128,   144,
     121,   105,   106,   147,   124,    15,    16,    17,    18,    35,
     127,   130,    35,   142,   143,   148,   135,   158,   136,   142,
     145,    35,   160,   167,   164,   140,    35,   161,    35,   165,
     173,   183,   131,   115,   174,    99,   152,    35,     0,   177,
     157,    35,   176,   180,     0,     0,     0,     0,     0,     0,
      35,     0,    22,     0,     4,     5,     6,     7,     8,     9,
      10,     0,   175,    11,    12,    13,    14,    15,    16,    17,
      18,     0,     0,    19,     0,     0,     0,    55,    56,    57,
      58,    20,    60,    61,    62,    63,    64,   108,     0,    21,
       4,     5,     6,     7,     8,     9,    10,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,   139,    21,     4,     5,     6,     7,
       8,     9,    10,     0,     0,    11,    12,    13,    14,    15,
      16,    17,    18,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,     0,   179,
       0,    21,     4,     5,     6,     7,     8,     9,    10,     0,
       0,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,     0,     0,   184,    21,     4,     5,
       6,     7,     8,     9,    10,     0,     0,    11,    12,    13,
      14,    15,    16,    17,    18,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,    52,    53,    21,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,     0,   125,   106,    52,    53,     0,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,   137,   138,    52,    53,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,    52,    53,    75,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,    52,    53,    76,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,    52,    53,   153,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,    52,    53,   169,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,    52,    53,   122,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,    52,    53,   151,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
       0,     0,     0,     0,    52,    53,   166,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,    52,    53,    79,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    52,    53,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      77,    52,    53,     0,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   116,    52,    53,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      52,     0,     0,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64
};

static const yytype_int16 yycheck[] =
{
       2,   108,     2,   113,    35,    35,     3,     4,     5,     6,
       7,     8,    43,    43,    34,    75,    76,     3,     4,     5,
       6,     7,     8,     0,    38,    22,    40,     3,     4,     5,
       6,     7,     8,    30,     7,    43,    22,   147,    10,    11,
      12,    38,   144,     7,    30,    42,    22,    19,    20,    21,
      34,   161,    38,    35,    30,    41,   158,    39,   160,    34,
      35,     7,    38,    43,    66,    37,    38,    29,    30,    31,
      32,    33,   179,    75,    76,    75,    76,    31,    32,    33,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   153,    66,    38,    68,    31,    35,    34,
      72,    38,    74,    40,    34,    35,    43,    40,    80,   169,
      20,    21,    39,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,   126,    42,   126,    10,    11,    42,
     102,    41,    42,    34,   106,    16,    17,    18,    19,   141,
      10,    11,   144,    10,    11,     7,   118,    42,   120,    10,
      11,   153,    42,   153,    42,   127,   158,    44,   160,    35,
      42,    34,   110,    82,   163,    67,   138,   169,    -1,   169,
     142,   173,   165,   173,    -1,    -1,    -1,    -1,    -1,    -1,
     182,    -1,   182,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,   164,    12,    13,    14,    15,    16,    17,    18,
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
      33,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    42,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    42,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    42,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    42,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    20,    21,    41,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    20,    21,    41,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    20,    21,    41,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    20,    21,    39,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    20,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    20,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    20,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      20,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    48,     0,     3,     4,     5,     6,     7,     8,
       9,    12,    13,    14,    15,    16,    17,    18,    19,    22,
      30,    38,    49,    50,    51,    54,    55,    56,    58,    65,
      67,    68,    69,    72,    73,    75,    77,    38,    40,     7,
      67,    75,    67,    67,    34,     7,    67,    67,    67,     7,
      70,    71,    20,    21,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    43,    35,    43,    34,
      67,    76,    42,    67,    40,    42,    42,    34,    59,    39,
      43,    34,    35,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    75,     7,    72,
      67,    74,    35,    39,    67,    41,    42,    67,    36,    49,
      66,    49,    66,    38,    67,    71,    34,    34,    40,    34,
      35,    67,    41,    41,    67,    41,    48,    10,    11,    52,
      11,    52,    61,    62,    65,    67,    67,    41,    42,    37,
      67,    42,    10,    11,    42,    11,    39,    34,     7,    63,
      64,    41,    67,    42,    49,    53,    66,    67,    42,    53,
      42,    44,    60,    65,    42,    35,    41,    49,    66,    42,
      53,    53,    65,    42,    63,    67,    64,    49,    66,    36,
      49,    57,    48,    34,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    52,    52,    53,
      53,    54,    54,    55,    56,    57,    57,    59,    58,    60,
      60,    61,    61,    62,    62,    63,    63,    64,    64,    65,
      65,    65,    65,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    68,    68,    69,
      70,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      75,    76,    76,    76,    77,    77,    77,    77,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     5,
       5,     8,     8,     7,     7,     4,     4,     5,     5,     1,
       1,     4,     4,     3,     2,     3,     2,     0,     9,     2,
       0,     1,     0,     4,     2,     3,     1,     1,     3,     1,
       1,     1,     1,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     3,     1,     4,     1,     3,     1,     3,
       4,     0,     1,     3,     4,     6,     5,     5,     8
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
#line 1375 "parser.tab.c"
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
#line 1390 "parser.tab.c"
    break;

  case 4: /* statement_list: %empty  */
#line 83 "parser.y"
                  {
        (yyval.ast_node) = NULL;
    }
#line 1398 "parser.tab.c"
    break;

  case 5: /* statement: expr SEMICOLON  */
#line 89 "parser.y"
                                   {
        (yyval.ast_node) = (yyvsp[-1].ast_node);
    }
#line 1406 "parser.tab.c"
    break;

  case 6: /* statement: lhs ASSIGN expr SEMICOLON  */
#line 92 "parser.y"
                                             {
        (yyval.ast_node) = create_binary_op(ASSIGN, (yyvsp[-3].ast_node), (yyvsp[-1].ast_node));
    }
#line 1414 "parser.tab.c"
    break;

  case 7: /* statement: lhs_list ASSIGN expr_list SEMICOLON  */
#line 95 "parser.y"
                                                       {
        (yyval.ast_node) = create_multiple_assignment((yyvsp[-3].ast_node), (yyvsp[-1].ast_node));
    }
#line 1422 "parser.tab.c"
    break;

  case 8: /* statement: function_call_statement  */
#line 98 "parser.y"
                                              {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1430 "parser.tab.c"
    break;

  case 9: /* statement: if_statement  */
#line 101 "parser.y"
                   {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1438 "parser.tab.c"
    break;

  case 10: /* statement: while_statement  */
#line 104 "parser.y"
                      {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1446 "parser.tab.c"
    break;

  case 11: /* statement: return_statement  */
#line 107 "parser.y"
                       {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1454 "parser.tab.c"
    break;

  case 12: /* statement: pass_statement  */
#line 110 "parser.y"
                     {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1462 "parser.tab.c"
    break;

  case 13: /* statement: function_def  */
#line 113 "parser.y"
                   { 
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1470 "parser.tab.c"
    break;

  case 14: /* statement: var_decl  */
#line 116 "parser.y"
               {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1478 "parser.tab.c"
    break;

  case 15: /* function_call_statement: func_call SEMICOLON  */
#line 122 "parser.y"
                                        {
        (yyval.ast_node) = (yyvsp[-1].ast_node);
    }
#line 1486 "parser.tab.c"
    break;

  case 16: /* function_call_statement: lhs ASSIGN func_call SEMICOLON  */
#line 125 "parser.y"
                                                  {
        (yyval.ast_node) = create_binary_op(ASSIGN, (yyvsp[-3].ast_node), (yyvsp[-1].ast_node));
    }
#line 1494 "parser.tab.c"
    break;

  case 17: /* if_statement: IF expr COLON statement  */
#line 131 "parser.y"
                                     {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, (yyvsp[0].ast_node));
        (yyval.ast_node) = create_if_statement((yyvsp[-2].ast_node), block, NULL);
    }
#line 1504 "parser.tab.c"
    break;

  case 18: /* if_statement: IF expr COLON block  */
#line 136 "parser.y"
                                   {
        (yyval.ast_node) = create_if_statement((yyvsp[-2].ast_node), (yyvsp[0].ast_node), NULL);
    }
#line 1512 "parser.tab.c"
    break;

  case 19: /* if_statement: IF expr COLON statement elif_list  */
#line 139 "parser.y"
                                                 {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, (yyvsp[-1].ast_node));
        (yyval.ast_node) = create_if_statement((yyvsp[-3].ast_node), block, (yyvsp[0].ast_node));
    }
#line 1522 "parser.tab.c"
    break;

  case 20: /* if_statement: IF expr COLON block elif_list  */
#line 144 "parser.y"
                                             {
        (yyval.ast_node) = create_if_statement((yyvsp[-3].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
    }
#line 1530 "parser.tab.c"
    break;

  case 21: /* if_statement: IF expr COLON statement elif_list ELSE COLON else_stmt  */
#line 147 "parser.y"
                                                                      {
        struct ASTNode *if_block = create_block();
        add_statement_to_block(if_block, (yyvsp[-4].ast_node));
        (yyval.ast_node) = create_if_statement((yyvsp[-6].ast_node), if_block, (yyvsp[-3].ast_node));
        (yyval.ast_node)->if_stmt.else_block = (yyvsp[0].ast_node);
    }
#line 1541 "parser.tab.c"
    break;

  case 22: /* if_statement: IF expr COLON block elif_list ELSE COLON else_stmt  */
#line 153 "parser.y"
                                                                  {
        (yyval.ast_node) = create_if_statement((yyvsp[-6].ast_node), (yyvsp[-4].ast_node), (yyvsp[-3].ast_node));
        (yyval.ast_node)->if_stmt.else_block = (yyvsp[0].ast_node);
    }
#line 1550 "parser.tab.c"
    break;

  case 23: /* if_statement: IF expr COLON statement ELSE COLON else_stmt  */
#line 157 "parser.y"
                                                            {
        struct ASTNode *if_block = create_block();
        add_statement_to_block(if_block, (yyvsp[-3].ast_node));
        (yyval.ast_node) = create_if_statement((yyvsp[-5].ast_node), if_block, NULL);
        (yyval.ast_node)->if_stmt.else_block = (yyvsp[0].ast_node);
    }
#line 1561 "parser.tab.c"
    break;

  case 24: /* if_statement: IF expr COLON block ELSE COLON else_stmt  */
#line 163 "parser.y"
                                                        {
        (yyval.ast_node) = create_if_statement((yyvsp[-5].ast_node), (yyvsp[-3].ast_node), NULL);
        (yyval.ast_node)->if_stmt.else_block = (yyvsp[0].ast_node);
    }
#line 1570 "parser.tab.c"
    break;

  case 25: /* elif_list: ELIF expr COLON statement  */
#line 170 "parser.y"
                                         {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, (yyvsp[0].ast_node));
        (yyval.ast_node) = create_block();
        add_statement_to_block((yyval.ast_node), create_elif((yyvsp[-2].ast_node), block));
    }
#line 1581 "parser.tab.c"
    break;

  case 26: /* elif_list: ELIF expr COLON block  */
#line 176 "parser.y"
                                       {
        (yyval.ast_node) = create_block();
        add_statement_to_block((yyval.ast_node), create_elif((yyvsp[-2].ast_node), (yyvsp[0].ast_node)));
    }
#line 1590 "parser.tab.c"
    break;

  case 27: /* elif_list: elif_list ELIF expr COLON statement  */
#line 180 "parser.y"
                                                     {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, (yyvsp[0].ast_node));
        add_statement_to_block((yyvsp[-4].ast_node), create_elif((yyvsp[-2].ast_node), block));
        (yyval.ast_node) = (yyvsp[-4].ast_node);
    }
#line 1601 "parser.tab.c"
    break;

  case 28: /* elif_list: elif_list ELIF expr COLON block  */
#line 186 "parser.y"
                                                 {
        add_statement_to_block((yyvsp[-4].ast_node), create_elif((yyvsp[-2].ast_node), (yyvsp[0].ast_node)));
        (yyval.ast_node) = (yyvsp[-4].ast_node);
    }
#line 1610 "parser.tab.c"
    break;

  case 29: /* else_stmt: statement  */
#line 193 "parser.y"
                         {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, (yyvsp[0].ast_node));
        (yyval.ast_node) = block;
    }
#line 1620 "parser.tab.c"
    break;

  case 30: /* else_stmt: block  */
#line 198 "parser.y"
                       {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1628 "parser.tab.c"
    break;

  case 31: /* while_statement: WHILE expr COLON statement  */
#line 204 "parser.y"
                                        {
        struct ASTNode *block = create_block();
        add_statement_to_block(block, (yyvsp[0].ast_node));
        (yyval.ast_node) = create_while_statement((yyvsp[-2].ast_node), block);
    }
#line 1638 "parser.tab.c"
    break;

  case 32: /* while_statement: WHILE expr COLON block  */
#line 209 "parser.y"
                                      {
        (yyval.ast_node) = create_while_statement((yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1646 "parser.tab.c"
    break;

  case 33: /* return_statement: RETURN expr SEMICOLON  */
#line 215 "parser.y"
                          {
        (yyval.ast_node) = create_return_statement((yyvsp[-1].ast_node));
    }
#line 1654 "parser.tab.c"
    break;

  case 34: /* pass_statement: PASS SEMICOLON  */
#line 221 "parser.y"
                   {
        (yyval.ast_node) = create_pass_statement();
    }
#line 1662 "parser.tab.c"
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
#line 1679 "parser.tab.c"
    break;

  case 36: /* function_body: statement SEMICOLON  */
#line 239 "parser.y"
                          {
        (yyval.ast_node) = create_block();
        add_statement_to_block((yyval.ast_node), (yyvsp[-1].ast_node));
    }
#line 1688 "parser.tab.c"
    break;

  case 37: /* @1: %empty  */
#line 246 "parser.y"
                   {
        // Store the line number as soon as we see the DEF token
        (yyval.intval) = yylineno;
    }
#line 1697 "parser.tab.c"
    break;

  case 38: /* function_def: DEF IDENTIFIER @1 LPAREN param_list_opt RPAREN return_type_opt COLON function_body  */
#line 249 "parser.y"
                                                                       {
        (yyval.ast_node) = create_function_def((yyvsp[-7].strval), (yyvsp[-4].ast_node), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
        (yyval.ast_node)->function_def.line_number = (yyvsp[-6].intval);  // Use the stored line number
    }
#line 1706 "parser.tab.c"
    break;

  case 39: /* return_type_opt: ARROW type  */
#line 256 "parser.y"
               {
        (yyval.ast_node) = create_return_type((yyvsp[0].typeval));
    }
#line 1714 "parser.tab.c"
    break;

  case 40: /* return_type_opt: %empty  */
#line 259 "parser.y"
                  {
        (yyval.ast_node) = NULL;
    }
#line 1722 "parser.tab.c"
    break;

  case 41: /* param_list_opt: param_list  */
#line 265 "parser.y"
               {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1730 "parser.tab.c"
    break;

  case 42: /* param_list_opt: %empty  */
#line 268 "parser.y"
                  {
        (yyval.ast_node) = NULL;
    }
#line 1738 "parser.tab.c"
    break;

  case 43: /* param_list: param_list SEMICOLON type param_with_default_list  */
#line 274 "parser.y"
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
#line 1761 "parser.tab.c"
    break;

  case 44: /* param_list: type param_with_default_list  */
#line 292 "parser.y"
                                   {
        (yyval.ast_node) = (yyvsp[0].ast_node);
        struct ASTNode *current = (yyval.ast_node);
        while (current) {
            current->param_list.first->param.type = (yyvsp[-1].typeval);
            current = current->param_list.rest;
        }
    }
#line 1774 "parser.tab.c"
    break;

  case 45: /* param_with_default_list: param_with_default_list COMMA param_with_default  */
#line 303 "parser.y"
                                                     {
        (yyval.ast_node) = create_param_list((yyvsp[0].ast_node), (yyvsp[-2].ast_node));
    }
#line 1782 "parser.tab.c"
    break;

  case 46: /* param_with_default_list: param_with_default  */
#line 306 "parser.y"
                         {
        (yyval.ast_node) = create_param_list((yyvsp[0].ast_node), NULL);
    }
#line 1790 "parser.tab.c"
    break;

  case 47: /* param_with_default: IDENTIFIER  */
#line 312 "parser.y"
               {
        (yyval.ast_node) = create_param_with_default((yyvsp[0].strval), NULL);
    }
#line 1798 "parser.tab.c"
    break;

  case 48: /* param_with_default: IDENTIFIER COLON expr  */
#line 315 "parser.y"
                            {
        (yyval.ast_node) = create_param_with_default((yyvsp[-2].strval), (yyvsp[0].ast_node));
    }
#line 1806 "parser.tab.c"
    break;

  case 49: /* type: BOOL  */
#line 321 "parser.y"
           { (yyval.typeval) = BOOL; }
#line 1812 "parser.tab.c"
    break;

  case 50: /* type: INT  */
#line 322 "parser.y"
           { (yyval.typeval) = INT; }
#line 1818 "parser.tab.c"
    break;

  case 51: /* type: FLOAT  */
#line 323 "parser.y"
            { (yyval.typeval) = FLOAT; }
#line 1824 "parser.tab.c"
    break;

  case 52: /* type: STRING  */
#line 324 "parser.y"
             { (yyval.typeval) = STRING; }
#line 1830 "parser.tab.c"
    break;

  case 53: /* block: LBRACE statement_list RBRACE  */
#line 328 "parser.y"
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
#line 1845 "parser.tab.c"
    break;

  case 54: /* expr: expr OR expr  */
#line 341 "parser.y"
                 {
        (yyval.ast_node) = create_binary_op(OR, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1853 "parser.tab.c"
    break;

  case 55: /* expr: expr AND expr  */
#line 344 "parser.y"
                    {
        (yyval.ast_node) = create_binary_op(AND, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1861 "parser.tab.c"
    break;

  case 56: /* expr: NOT expr  */
#line 347 "parser.y"
               {
        (yyval.ast_node) = create_unary_op(NOT, (yyvsp[0].ast_node));
    }
#line 1869 "parser.tab.c"
    break;

  case 57: /* expr: expr EQ expr  */
#line 350 "parser.y"
                   {
        (yyval.ast_node) = create_binary_op(EQ, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1877 "parser.tab.c"
    break;

  case 58: /* expr: expr NEQ expr  */
#line 353 "parser.y"
                    {
        (yyval.ast_node) = create_binary_op(NEQ, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1885 "parser.tab.c"
    break;

  case 59: /* expr: expr GT expr  */
#line 356 "parser.y"
                   {
        (yyval.ast_node) = create_binary_op(GT, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1893 "parser.tab.c"
    break;

  case 60: /* expr: expr GE expr  */
#line 359 "parser.y"
                   {
        (yyval.ast_node) = create_binary_op(GE, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1901 "parser.tab.c"
    break;

  case 61: /* expr: expr LT expr  */
#line 362 "parser.y"
                   {
        (yyval.ast_node) = create_binary_op(LT, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1909 "parser.tab.c"
    break;

  case 62: /* expr: expr LE expr  */
#line 365 "parser.y"
                   {
        (yyval.ast_node) = create_binary_op(LE, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1917 "parser.tab.c"
    break;

  case 63: /* expr: expr PLUS expr  */
#line 368 "parser.y"
                     {
        (yyval.ast_node) = create_binary_op(PLUS, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1925 "parser.tab.c"
    break;

  case 64: /* expr: expr MINUS expr  */
#line 371 "parser.y"
                      {
        (yyval.ast_node) = create_binary_op(MINUS, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1933 "parser.tab.c"
    break;

  case 65: /* expr: expr TIMES expr  */
#line 374 "parser.y"
                      {
        (yyval.ast_node) = create_binary_op(TIMES, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1941 "parser.tab.c"
    break;

  case 66: /* expr: expr DIVIDE expr  */
#line 377 "parser.y"
                       {
        (yyval.ast_node) = create_binary_op(DIVIDE, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1949 "parser.tab.c"
    break;

  case 67: /* expr: expr POW expr  */
#line 380 "parser.y"
                    {
        (yyval.ast_node) = create_binary_op(POW, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1957 "parser.tab.c"
    break;

  case 68: /* expr: MINUS expr  */
#line 383 "parser.y"
                               {
        (yyval.ast_node) = create_unary_op(MINUS, (yyvsp[0].ast_node));
    }
#line 1965 "parser.tab.c"
    break;

  case 69: /* expr: LPAREN expr RPAREN  */
#line 386 "parser.y"
                         {
        (yyval.ast_node) = (yyvsp[-1].ast_node);
    }
#line 1973 "parser.tab.c"
    break;

  case 70: /* expr: literal  */
#line 389 "parser.y"
              {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1981 "parser.tab.c"
    break;

  case 71: /* expr: IDENTIFIER  */
#line 392 "parser.y"
                 {
        (yyval.ast_node) = create_identifier((yyvsp[0].strval));
    }
#line 1989 "parser.tab.c"
    break;

  case 72: /* expr: func_call  */
#line 395 "parser.y"
                {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1997 "parser.tab.c"
    break;

  case 73: /* expr: string_op  */
#line 398 "parser.y"
                {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 2005 "parser.tab.c"
    break;

  case 74: /* literal: INTEGER  */
#line 404 "parser.y"
            {
        (yyval.ast_node) = create_int_literal((yyvsp[0].intval));
    }
#line 2013 "parser.tab.c"
    break;

  case 75: /* literal: HEX_LITERAL  */
#line 407 "parser.y"
                  {
        (yyval.ast_node) = create_hex_literal((yyvsp[0].intval));
    }
#line 2021 "parser.tab.c"
    break;

  case 76: /* literal: FLOAT_LITERAL  */
#line 410 "parser.y"
                    {
        (yyval.ast_node) = create_float_literal((yyvsp[0].floatval));
    }
#line 2029 "parser.tab.c"
    break;

  case 77: /* literal: BOOL_LITERAL  */
#line 413 "parser.y"
                   {
        (yyval.ast_node) = create_bool_literal((yyvsp[0].intval));
    }
#line 2037 "parser.tab.c"
    break;

  case 78: /* literal: STRING_LITERAL  */
#line 416 "parser.y"
                     {
        (yyval.ast_node) = create_string_literal((yyvsp[0].strval));
    }
#line 2045 "parser.tab.c"
    break;

  case 79: /* var_decl: type var_list SEMICOLON  */
#line 422 "parser.y"
                            {
        (yyval.ast_node) = create_var_decl((yyvsp[-2].typeval), (yyvsp[-1].ast_node));
    }
#line 2053 "parser.tab.c"
    break;

  case 80: /* var_list: var_list COMMA var_decl_item  */
#line 428 "parser.y"
                                 {
        (yyval.ast_node) = create_var_list((yyvsp[0].ast_node), (yyvsp[-2].ast_node));
    }
#line 2061 "parser.tab.c"
    break;

  case 81: /* var_list: var_decl_item  */
#line 431 "parser.y"
                    {
        (yyval.ast_node) = create_var_list((yyvsp[0].ast_node), NULL);
    }
#line 2069 "parser.tab.c"
    break;

  case 82: /* var_decl_item: IDENTIFIER  */
#line 437 "parser.y"
               {
        (yyval.ast_node) = create_var_decl_item((yyvsp[0].strval), NULL);
    }
#line 2077 "parser.tab.c"
    break;

  case 83: /* var_decl_item: IDENTIFIER ASSIGN expr  */
#line 440 "parser.y"
                             {
        (yyval.ast_node) = create_var_decl_item((yyvsp[-2].strval), (yyvsp[0].ast_node));
    }
#line 2085 "parser.tab.c"
    break;

  case 84: /* lhs: IDENTIFIER  */
#line 446 "parser.y"
                            {
        (yyval.ast_node) = create_identifier((yyvsp[0].strval));
    }
#line 2093 "parser.tab.c"
    break;

  case 85: /* lhs: IDENTIFIER LBRACKET expr RBRACKET  */
#line 449 "parser.y"
                                                     {
        (yyval.ast_node) = create_string_index(create_identifier((yyvsp[-3].strval)), (yyvsp[-1].ast_node));
    }
#line 2101 "parser.tab.c"
    break;

  case 86: /* lhs_list: lhs  */
#line 455 "parser.y"
                     {
        (yyval.ast_node) = create_lhs_list((yyvsp[0].ast_node), NULL);
    }
#line 2109 "parser.tab.c"
    break;

  case 87: /* lhs_list: lhs_list COMMA lhs  */
#line 458 "parser.y"
                                      {
        (yyval.ast_node) = create_lhs_list((yyvsp[0].ast_node), (yyvsp[-2].ast_node));
    }
#line 2117 "parser.tab.c"
    break;

  case 88: /* expr_list: expr  */
#line 464 "parser.y"
                      {
        (yyval.ast_node) = create_expr_list((yyvsp[0].ast_node), NULL);
    }
#line 2125 "parser.tab.c"
    break;

  case 89: /* expr_list: expr_list COMMA expr  */
#line 467 "parser.y"
                                        {
        (yyval.ast_node) = create_expr_list((yyvsp[0].ast_node), (yyvsp[-2].ast_node));
    }
#line 2133 "parser.tab.c"
    break;

  case 90: /* func_call: IDENTIFIER LPAREN arg_list RPAREN  */
#line 473 "parser.y"
                                      {
        (yyval.ast_node) = create_function_call((yyvsp[-3].strval), (yyvsp[-1].ast_node));
    }
#line 2141 "parser.tab.c"
    break;

  case 91: /* arg_list: %empty  */
#line 479 "parser.y"
                {
        (yyval.ast_node) = NULL;
    }
#line 2149 "parser.tab.c"
    break;

  case 92: /* arg_list: expr  */
#line 482 "parser.y"
           {
        (yyval.ast_node) = create_arg_list((yyvsp[0].ast_node), NULL);
    }
#line 2157 "parser.tab.c"
    break;

  case 93: /* arg_list: arg_list COMMA expr  */
#line 485 "parser.y"
                          {
        (yyval.ast_node) = create_arg_list((yyvsp[0].ast_node), (yyvsp[-2].ast_node));
    }
#line 2165 "parser.tab.c"
    break;

  case 94: /* string_op: IDENTIFIER LBRACKET expr RBRACKET  */
#line 491 "parser.y"
                                      {
        (yyval.ast_node) = create_string_index(create_identifier((yyvsp[-3].strval)), (yyvsp[-1].ast_node));
    }
#line 2173 "parser.tab.c"
    break;

  case 95: /* string_op: IDENTIFIER LBRACKET expr COLON expr RBRACKET  */
#line 494 "parser.y"
                                                   {
        (yyval.ast_node) = create_string_slice(create_identifier((yyvsp[-5].strval)), (yyvsp[-3].ast_node), (yyvsp[-1].ast_node), NULL);
    }
#line 2181 "parser.tab.c"
    break;

  case 96: /* string_op: IDENTIFIER LBRACKET COLON expr RBRACKET  */
#line 497 "parser.y"
                                              {
        (yyval.ast_node) = create_string_slice(create_identifier((yyvsp[-4].strval)), NULL, (yyvsp[-1].ast_node), NULL);
    }
#line 2189 "parser.tab.c"
    break;

  case 97: /* string_op: IDENTIFIER LBRACKET expr COLON RBRACKET  */
#line 500 "parser.y"
                                              {
        (yyval.ast_node) = create_string_slice(create_identifier((yyvsp[-4].strval)), (yyvsp[-2].ast_node), NULL, NULL);
    }
#line 2197 "parser.tab.c"
    break;

  case 98: /* string_op: IDENTIFIER LBRACKET expr COLON expr COLON expr RBRACKET  */
#line 503 "parser.y"
                                                              {
        (yyval.ast_node) = create_string_slice(create_identifier((yyvsp[-7].strval)), (yyvsp[-5].ast_node), (yyvsp[-3].ast_node), (yyvsp[-1].ast_node));
    }
#line 2205 "parser.tab.c"
    break;


#line 2209 "parser.tab.c"

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

#line 508 "parser.y"


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
