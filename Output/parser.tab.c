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
#line 1 "Frontend/Parser/parser.y"

#include "../Frontend/Parser/parser.h"
struct Node * root;
int numIdentifiers;

#line 77 "Output/parser.tab.c"

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
  YYSYMBOL_ERROR = 3,                      /* ERROR  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_PATH = 5,                       /* PATH  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_ARRAY = 7,                      /* ARRAY  */
  YYSYMBOL_PLUS = 8,                       /* PLUS  */
  YYSYMBOL_MINUS = 9,                      /* MINUS  */
  YYSYMBOL_TIMES = 10,                     /* TIMES  */
  YYSYMBOL_ASSIGNMENT = 11,                /* ASSIGNMENT  */
  YYSYMBOL_COMMA = 12,                     /* COMMA  */
  YYSYMBOL_LPAREN = 13,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 14,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 15,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 16,                  /* RBRACKET  */
  YYSYMBOL_DOUBLE_EXCLAMATION = 17,        /* DOUBLE_EXCLAMATION  */
  YYSYMBOL_RESIZE = 18,                    /* RESIZE  */
  YYSYMBOL_ROTATE = 19,                    /* ROTATE  */
  YYSYMBOL_FLIP = 20,                      /* FLIP  */
  YYSYMBOL_LOAD = 21,                      /* LOAD  */
  YYSYMBOL_SHOW = 22,                      /* SHOW  */
  YYSYMBOL_GAUSSIAN_BLUR = 23,             /* GAUSSIAN_BLUR  */
  YYSYMBOL_BILATERAL_BLUR = 24,            /* BILATERAL_BLUR  */
  YYSYMBOL_MEDIAN_BLUR = 25,               /* MEDIAN_BLUR  */
  YYSYMBOL_BINARY_THRESHOLD = 26,          /* BINARY_THRESHOLD  */
  YYSYMBOL_BINARY_INV_THRESHOLD = 27,      /* BINARY_INV_THRESHOLD  */
  YYSYMBOL_OTSU_THRESHOLD = 28,            /* OTSU_THRESHOLD  */
  YYSYMBOL_BINARIZATION = 29,              /* BINARIZATION  */
  YYSYMBOL_COUNTOR = 30,                   /* COUNTOR  */
  YYSYMBOL_LOOP = 31,                      /* LOOP  */
  YYSYMBOL_COMPILE = 32,                   /* COMPILE  */
  YYSYMBOL_DOUBLE_GREATER = 33,            /* DOUBLE_GREATER  */
  YYSYMBOL_RECOGNIZE_TEXT = 34,            /* RECOGNIZE_TEXT  */
  YYSYMBOL_PRINT = 35,                     /* PRINT  */
  YYSYMBOL_TIMER = 36,                     /* TIMER  */
  YYSYMBOL_ON = 37,                        /* ON  */
  YYSYMBOL_OFF = 38,                       /* OFF  */
  YYSYMBOL_SET_MODE = 39,                  /* SET_MODE  */
  YYSYMBOL_SEQUENTIAL_MODE = 40,           /* SEQUENTIAL_MODE  */
  YYSYMBOL_PARALLEL_MODE = 41,             /* PARALLEL_MODE  */
  YYSYMBOL_PARALLEL_CHUNKED_MODE = 42,     /* PARALLEL_CHUNKED_MODE  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_command_list = 45,              /* command_list  */
  YYSYMBOL_command = 46,                   /* command  */
  YYSYMBOL_on_off = 47,                    /* on_off  */
  YYSYMBOL_mode = 48,                      /* mode  */
  YYSYMBOL_func = 49,                      /* func  */
  YYSYMBOL_func_loop = 50,                 /* func_loop  */
  YYSYMBOL_func_list = 51,                 /* func_list  */
  YYSYMBOL_expression = 52,                /* expression  */
  YYSYMBOL_nested_func = 53,               /* nested_func  */
  YYSYMBOL_expression_list = 54,           /* expression_list  */
  YYSYMBOL_identifier_list = 55            /* identifier_list  */
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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   203

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    72,    72,    74,    79,    87,    92,    97,   103,   110,
     116,   122,   128,   134,   139,   146,   151,   156,   160,   164,
     171,   178,   184,   189,   196,   203,   209,   215,   221,   227,
     232,   239,   245,   250,   254,   258,   264,   270,   275,   280,
     285,   290,   294,   300,   305,   317,   318,   324,   330,   336,
     342,   345,   355,   360,   372,   377
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
  "\"end of file\"", "error", "\"invalid token\"", "ERROR", "IDENTIFIER",
  "PATH", "INT", "ARRAY", "PLUS", "MINUS", "TIMES", "ASSIGNMENT", "COMMA",
  "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "DOUBLE_EXCLAMATION",
  "RESIZE", "ROTATE", "FLIP", "LOAD", "SHOW", "GAUSSIAN_BLUR",
  "BILATERAL_BLUR", "MEDIAN_BLUR", "BINARY_THRESHOLD",
  "BINARY_INV_THRESHOLD", "OTSU_THRESHOLD", "BINARIZATION", "COUNTOR",
  "LOOP", "COMPILE", "DOUBLE_GREATER", "RECOGNIZE_TEXT", "PRINT", "TIMER",
  "ON", "OFF", "SET_MODE", "SEQUENTIAL_MODE", "PARALLEL_MODE",
  "PARALLEL_CHUNKED_MODE", "$accept", "program", "command_list", "command",
  "on_off", "mode", "func", "func_loop", "func_list", "expression",
  "nested_func", "expression_list", "identifier_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,    14,    17,    -4,    23,    28,     9,    44,    45,    46,
      48,    55,    -2,   -78,    20,    47,    59,    60,    58,    62,
      63,    64,   -34,    11,   -78,   -78,    13,    53,    61,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,   -78,
     -78,   -78,    84,    77,    57,    78,    39,    79,    80,   -78,
     -78,    81,   -78,   -78,   -78,    82,    88,    89,    93,    20,
      92,    94,    95,    98,    97,    99,   100,   101,   102,   103,
     106,   107,   -78,    19,   108,   -78,   -12,   -12,   110,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,    42,   -78,    87,   104,
      90,   105,   109,   111,   112,   113,   114,   115,   116,   118,
     -78,   117,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   -78,    40,   132,    20,   -78,
     138,   143,   -78,   142,   144,   145,   147,   148,   149,   -78,
     -78,   -78,   -78,   150,   151,   140,   141,   152,   153,   154,
     155,   156,   157,   158,   159,   -78,   -12,   -78,   -78,   162,
     161,   164,   165,   166,   167,   168,   169,   172,   171,   -78,
     -78,   174,   175,   176,   177,   178,   179,   -78,   -78,   -78,
     160,   -78,   163,   184,   -78,   -78,   -78,   -78,   173,   -78,
     183,   188,   -78,   -78,   -78,   -78,   181,   182,   185,   186,
     187,   189,   -78,   -78,   -78,   -78,   -78,   -78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       9,    50,     0,     0,     0,     0,     0,     0,     0,    15,
      16,     0,    17,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     5,     0,     0,     0,     6,
      13,    14,    47,    48,    46,    52,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,    12,     0,     0,    51,
       0,     0,    22,     0,     0,     0,     0,     0,     0,    29,
      30,    55,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,    11,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,     0,     0,     0,     0,     0,     0,    41,    42,    44,
       0,    21,     0,     0,    25,    26,    27,    28,     0,    32,
       0,     0,    37,    38,    39,    40,     0,     0,     0,     0,
       0,     0,    20,    23,    24,    31,    35,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   -78,   190,   -78,   -78,   -78,   -77,   -78,   -58,
     -78,   -78,   -78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,    13,    51,    55,    39,   114,   116,    40,
      41,    86,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     115,    85,     1,    49,    50,     2,   102,   103,   104,    16,
     105,   106,   107,   108,   109,   110,   111,   112,   113,     3,
       4,    56,    57,    58,    26,    14,    59,    27,    15,     5,
       6,    99,     7,     8,     9,   100,    17,    10,    28,    29,
      30,    18,    19,    31,    32,    33,    34,    35,    36,    37,
      38,    52,    53,    54,   118,    24,   119,    20,    21,    22,
     148,    23,    42,    43,    44,    45,    46,    47,    48,   169,
      60,    75,    77,   146,    61,     0,     0,     0,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    74,
      76,    78,    82,    83,    79,    80,    81,    84,    87,   120,
      88,    89,    90,    91,   122,    92,    93,    94,    95,    96,
      97,    98,     0,   101,   117,     0,   121,   123,     0,     0,
       0,   124,   131,   125,   126,   127,   128,     0,     0,   129,
     130,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   149,   145,   147,   150,   151,   153,
     152,   154,   155,   156,   159,   160,   157,   158,   161,   162,
     163,   164,   165,   166,   186,     0,     0,   187,     0,     0,
       0,     0,   167,   168,   170,   171,   172,   173,     0,   189,
     174,   175,   176,   177,   178,   179,   180,   181,   188,   190,
     182,   183,   184,   185,   191,   192,   193,     0,     0,   194,
     195,   196,    25,   197
};

static const yytype_int16 yycheck[] =
{
      77,    59,     4,    37,    38,     7,    18,    19,    20,    13,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    21,
      22,     8,     9,    10,     4,    11,    13,     7,    11,    31,
      32,    12,    34,    35,    36,    16,    13,    39,    18,    19,
      20,    13,    33,    23,    24,    25,    26,    27,    28,    29,
      30,    40,    41,    42,    12,     0,    14,    13,    13,    13,
     118,    13,    15,     4,     4,     7,     4,     4,     4,   146,
      17,    14,    33,    33,    13,    -1,    -1,    -1,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,     4,    12,
      12,    12,     4,     4,    14,    14,    14,     4,     6,    12,
       6,     6,     4,     6,    14,     6,     6,     6,     6,     6,
       4,     4,    -1,     5,     4,    -1,    12,    12,    -1,    -1,
      -1,    12,     4,    12,    12,    12,    12,    -1,    -1,    14,
      14,    14,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,     6,    14,    14,     4,     6,     4,
       6,     4,     4,     4,    14,    14,     6,     6,     6,     6,
       6,     6,     6,     6,     4,    -1,    -1,     4,    -1,    -1,
      -1,    -1,    14,    14,    12,    14,    12,    12,    -1,     6,
      14,    14,    14,    14,    12,    14,    12,    12,     4,     6,
      14,    14,    14,    14,     6,    14,    14,    -1,    -1,    14,
      14,    14,    12,    14
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     7,    21,    22,    31,    32,    34,    35,    36,
      39,    44,    45,    46,    11,    11,    13,    13,    13,    33,
      13,    13,    13,    13,     0,    46,     4,     7,    18,    19,
      20,    23,    24,    25,    26,    27,    28,    29,    30,    49,
      52,    53,    15,     4,     4,     7,     4,     4,     4,    37,
      38,    47,    40,    41,    42,    48,     8,     9,    10,    13,
      17,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,     4,    55,    12,    14,    12,    33,    12,    14,
      14,    14,     4,     4,     4,    52,    54,     6,     6,     6,
       4,     6,     6,     6,     6,     6,     6,     4,     4,    12,
      16,     5,    18,    19,    20,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    50,    50,    51,     4,    12,    14,
      12,    12,    14,    12,    12,    12,    12,    12,    12,    14,
      14,     4,    14,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    14,    33,    14,    52,     6,
       4,     6,     6,     4,     4,     4,     4,     6,     6,    14,
      14,     6,     6,     6,     6,     6,     6,    14,    14,    50,
      12,    14,    12,    12,    14,    14,    14,    14,    12,    14,
      12,    12,    14,    14,    14,    14,     4,     4,     4,     6,
       6,     6,    14,    14,    14,    14,    14,    14
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    47,    47,    48,    48,    48,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    53,    54,    54,    55,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     4,     4,     6,     5,     3,
       6,     6,     5,     4,     4,     1,     1,     1,     1,     1,
       8,     6,     4,     8,     8,     6,     6,     6,     6,     4,
       4,     6,     4,     3,     3,     6,     6,     4,     4,     4,
       4,     3,     3,     1,     3,     1,     3,     3,     3,     3,
       1,     4,     1,     3,     1,     3
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
  case 2: /* program: command_list  */
#line 72 "Frontend/Parser/parser.y"
                       { root = (yyvsp[0].node); }
#line 1232 "Output/parser.tab.c"
    break;

  case 3: /* command_list: command  */
#line 75 "Frontend/Parser/parser.y"
             {
                (yyval.node) = createNode("Command", 1, 0); // Create a new Node representing a command list
                addChild((yyval.node), (yyvsp[0].node), 0); // Add the only one command as a child of the program
             }
#line 1241 "Output/parser.tab.c"
    break;

  case 4: /* command_list: command_list command  */
#line 80 "Frontend/Parser/parser.y"
             {
                 (yyval.node) = createNode("CommandList", 2, 0); // Create a new Node representing a command list
                 addChild((yyval.node), (yyvsp[-1].node), 0); // Add the first command as a child of the command list Node
                 addChild((yyval.node), (yyvsp[0].node), 1); // Add the second command as a child of the command list Node
             }
#line 1251 "Output/parser.tab.c"
    break;

  case 5: /* command: SHOW LPAREN IDENTIFIER RPAREN  */
#line 88 "Frontend/Parser/parser.y"
        {
              (yyval.node) = createNode("Show", 1, 0); // Create a new Node representing a show operation
              addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 0); // Add the expression as a child of the show Node
        }
#line 1260 "Output/parser.tab.c"
    break;

  case 6: /* command: PRINT LPAREN IDENTIFIER RPAREN  */
#line 93 "Frontend/Parser/parser.y"
        {
              (yyval.node) = createNode("Print", 1, 0); // Create a new Node representing a print operation
              addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 0); // Add the identifier as a child of the print Node
        }
#line 1269 "Output/parser.tab.c"
    break;

  case 7: /* command: LOAD LPAREN IDENTIFIER COMMA PATH RPAREN  */
#line 98 "Frontend/Parser/parser.y"
        {
              (yyval.node) = createNode("Load", 2, 0); // Create a new Node representing a load operation
              addChild((yyval.node), createNode((yyvsp[-3].stringVal), 0, 0), 0); // Add the identifier as a child 
              addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 1); // Add the path as a child 
        }
#line 1279 "Output/parser.tab.c"
    break;

  case 8: /* command: ARRAY ASSIGNMENT LBRACKET identifier_list RBRACKET  */
#line 104 "Frontend/Parser/parser.y"
        {
            numIdentifiers = (yyvsp[-1].node)->num_children; // Obtém o número de identificadores na lista diretamente
            (yyval.node) = createNode("Array", 2, 0); // Define um nó como uma lista de identificadores incluída entre colchetes
            addChild((yyval.node), createNode((yyvsp[-4].stringVal), 0, 0), 0);
            addChild((yyval.node), (yyvsp[-1].node), 1); // Adiciona a lista de identificadores como filho do nó da expressão
        }
#line 1290 "Output/parser.tab.c"
    break;

  case 9: /* command: IDENTIFIER ASSIGNMENT expression  */
#line 111 "Frontend/Parser/parser.y"
        {
              (yyval.node) = createNode("Assignment", 2, 0); // Create a new Node representing an assignment operation
              addChild((yyval.node), createNode((yyvsp[-2].stringVal), 0, 0), 0); // Add the identifier as a child
              addChild((yyval.node), (yyvsp[0].node), 1); // Add the expression as a child
        }
#line 1300 "Output/parser.tab.c"
    break;

  case 10: /* command: LOOP LPAREN ARRAY COMMA func_loop RPAREN  */
#line 117 "Frontend/Parser/parser.y"
        {
              (yyval.node) = createNode("Loop", 2, 0); // Create a new Node representing a loop operation
              addChild((yyval.node), createNode((yyvsp[-3].stringVal), 0, 0), 0); // Add the expression as a child of the loop Node
              addChild((yyval.node), (yyvsp[-1].node), 1); // Add the function as a child of the loop Node
        }
#line 1310 "Output/parser.tab.c"
    break;

  case 11: /* command: RECOGNIZE_TEXT LPAREN IDENTIFIER COMMA IDENTIFIER RPAREN  */
#line 123 "Frontend/Parser/parser.y"
        {
              (yyval.node) = createNode("RecognizeText", 2, 0); // Create a new Node representing a text recognition operation
              addChild((yyval.node), createNode((yyvsp[-3].stringVal), 0, 0), 0); // First identifier is the loaded image with a text
              addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 1); // Second identifier is a variable that contains the text recognized
        }
#line 1320 "Output/parser.tab.c"
    break;

  case 12: /* command: COMPILE DOUBLE_GREATER IDENTIFIER DOUBLE_GREATER func_list  */
#line 129 "Frontend/Parser/parser.y"
        {
            (yyval.node) = createNode("Compile", 2, 0);
            addChild((yyval.node), createNode((yyvsp[-2].stringVal), 0, 0), 0); 
            addChild((yyval.node), (yyvsp[0].node), 1); 
        }
#line 1330 "Output/parser.tab.c"
    break;

  case 13: /* command: TIMER LPAREN on_off RPAREN  */
#line 135 "Frontend/Parser/parser.y"
        {
            (yyval.node) = createNode("Timer", 1, 0);
            addChild((yyval.node), (yyvsp[-1].node), 0); 
        }
#line 1339 "Output/parser.tab.c"
    break;

  case 14: /* command: SET_MODE LPAREN mode RPAREN  */
#line 140 "Frontend/Parser/parser.y"
        {
            (yyval.node) = createNode("Mode", 1, 0);
            addChild((yyval.node), (yyvsp[-1].node), 0); 
        }
#line 1348 "Output/parser.tab.c"
    break;

  case 15: /* on_off: ON  */
#line 147 "Frontend/Parser/parser.y"
      {
        (yyval.node) = createNode("On", 1, 0);    
      }
#line 1356 "Output/parser.tab.c"
    break;

  case 16: /* on_off: OFF  */
#line 152 "Frontend/Parser/parser.y"
      {
        (yyval.node) = createNode("Off", 1, 0);    
      }
#line 1364 "Output/parser.tab.c"
    break;

  case 17: /* mode: SEQUENTIAL_MODE  */
#line 157 "Frontend/Parser/parser.y"
     {
        (yyval.node) = createNode("Sequential", 1, 0);    
     }
#line 1372 "Output/parser.tab.c"
    break;

  case 18: /* mode: PARALLEL_MODE  */
#line 161 "Frontend/Parser/parser.y"
     {
        (yyval.node) = createNode("Parallel", 1, 0);
     }
#line 1380 "Output/parser.tab.c"
    break;

  case 19: /* mode: PARALLEL_CHUNKED_MODE  */
#line 165 "Frontend/Parser/parser.y"
     {
        (yyval.node) = createNode("Parallel_Chunked", 1, 0);
     }
#line 1388 "Output/parser.tab.c"
    break;

  case 20: /* func: RESIZE LPAREN INT COMMA INT COMMA IDENTIFIER RPAREN  */
#line 172 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("Resize", 3, 0); // Create a new Node representing a resize operation
           addChild((yyval.node), createNode("Width", 0, (yyvsp[-5].intVal)), 0); // Add a child Node representing the width
           addChild((yyval.node), createNode("Height", 0, (yyvsp[-3].intVal)), 1); // Add a child Node representing the height
           addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 2); // Add a child Node representing the identifier
       }
#line 1399 "Output/parser.tab.c"
    break;

  case 21: /* func: ROTATE LPAREN INT COMMA IDENTIFIER RPAREN  */
#line 179 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("Rotate", 2, 0); // Create a new Node representing a rotate operation
           addChild((yyval.node), createNode("Angle", 0, (yyvsp[-3].intVal)), 0); // Add a child Node representing the angle
           addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 1); // Add a child Node representing the identifier
       }
#line 1409 "Output/parser.tab.c"
    break;

  case 22: /* func: FLIP LPAREN IDENTIFIER RPAREN  */
#line 185 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("Flip", 1, 0); // Create a new Node representing a flip operation
           addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 0); // Add a child Node representing the identifier
       }
#line 1418 "Output/parser.tab.c"
    break;

  case 23: /* func: GAUSSIAN_BLUR LPAREN INT COMMA INT COMMA IDENTIFIER RPAREN  */
#line 190 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("GaussianBlur", 3, 0); // Create a new Node representing a gaussian blur
           addChild((yyval.node), createNode("KernelSize", 0, (yyvsp[-5].intVal)), 0); // Add a child Node representing the kernel width 
           addChild((yyval.node), createNode("Sigma", 0, (yyvsp[-3].intVal)), 1); // Add a child Node representing the kernel height
           addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 2); // Add a child Node representing the identifier
       }
#line 1429 "Output/parser.tab.c"
    break;

  case 24: /* func: BILATERAL_BLUR LPAREN INT COMMA INT COMMA IDENTIFIER RPAREN  */
#line 197 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("BilateralBlur", 3, 0); // Create a new Node representing a 'bilateral blur' operation
           addChild((yyval.node), createNode("KernelSize", 0, (yyvsp[-5].intVal)), 0); // Add a child Node representing the diameter 
           addChild((yyval.node), createNode("Sigma", 0, (yyvsp[-3].intVal)), 1); // Add a child Node representing the sigma color
           addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 2); // Add a child Node representing the identifier
       }
#line 1440 "Output/parser.tab.c"
    break;

  case 25: /* func: MEDIAN_BLUR LPAREN INT COMMA IDENTIFIER RPAREN  */
#line 204 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("MedianBlur", 2, 0); // Create a new Node representing a median blur operation
           addChild((yyval.node), createNode("KernelSize", 0, (yyvsp[-3].intVal)), 0); // Add a child Node representing the kernel size 
           addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 1); // Add a child Node representing the identifier
       }
#line 1450 "Output/parser.tab.c"
    break;

  case 26: /* func: BINARY_THRESHOLD LPAREN INT COMMA IDENTIFIER RPAREN  */
#line 210 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("BinaryThreshold", 2, 0); // Create a new Node representing a binary threshold operation
           addChild((yyval.node), createNode("Threshold", 0, (yyvsp[-3].intVal)), 0); // Add a child Node representing the threshold
           addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 1); // Add a child Node representing the identifier
       }
#line 1460 "Output/parser.tab.c"
    break;

  case 27: /* func: BINARY_INV_THRESHOLD LPAREN INT COMMA IDENTIFIER RPAREN  */
#line 216 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("BinaryInverseThreshold", 2, 0); // Create a new Node representing a binary inverse threshold operation
           addChild((yyval.node), createNode("Threshold", 0, (yyvsp[-3].intVal)), 0); // Add a child Node representing the threshold
           addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 1); // Add a child Node representing the identifier 
       }
#line 1470 "Output/parser.tab.c"
    break;

  case 28: /* func: OTSU_THRESHOLD LPAREN INT COMMA IDENTIFIER RPAREN  */
#line 222 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("OtsuThreshold", 2, 0); // Create a new Node representing a otsu threshold operation
           addChild((yyval.node), createNode("Threshold", 0, (yyvsp[-3].intVal)), 0); // Add a child Node representing the threshold
           addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 1); // Add a child Node representing the identifier
       }
#line 1480 "Output/parser.tab.c"
    break;

  case 29: /* func: BINARIZATION LPAREN IDENTIFIER RPAREN  */
#line 228 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("Binarization", 1, 0); // Create a new Node representing a otsu binary inverse threshold operation
           addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 0); // Add a child Node representing the identifier
       }
#line 1489 "Output/parser.tab.c"
    break;

  case 30: /* func: COUNTOR LPAREN IDENTIFIER RPAREN  */
#line 233 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("Countor", 1, 0); // Create a new Node representing a otsu binary inverse threshold operation
           addChild((yyval.node), createNode((yyvsp[-1].stringVal), 0, 0), 0); // Add a child Node representing the identifier
       }
#line 1498 "Output/parser.tab.c"
    break;

  case 31: /* func_loop: RESIZE LPAREN INT COMMA INT RPAREN  */
#line 240 "Frontend/Parser/parser.y"
        {
            (yyval.node) = createNode("ResizeLoop", 3, 0); // Create a new Node representing a resize operation
            addChild((yyval.node), createNode("Width", 0, (yyvsp[-3].intVal)), 0); // Add a child Node representing the width
            addChild((yyval.node), createNode("Height", 0, (yyvsp[-1].intVal)), 1); // Add a child Node representing the height
        }
#line 1508 "Output/parser.tab.c"
    break;

  case 32: /* func_loop: ROTATE LPAREN INT RPAREN  */
#line 246 "Frontend/Parser/parser.y"
        {
            (yyval.node) = createNode("RotateLoop", 2, 0); // Create a new Node representing a rotate operation
            addChild((yyval.node), createNode("Angle", 0, (yyvsp[-1].intVal)), 0); // Add a child Node representing the angle
        }
#line 1517 "Output/parser.tab.c"
    break;

  case 33: /* func_loop: FLIP LPAREN RPAREN  */
#line 251 "Frontend/Parser/parser.y"
        {
            (yyval.node) = createNode("FlipLoop", 0, 0); // Create a new Node representing a flip operation
        }
#line 1525 "Output/parser.tab.c"
    break;

  case 34: /* func_loop: SHOW LPAREN RPAREN  */
#line 255 "Frontend/Parser/parser.y"
        {
            (yyval.node) = createNode("ShowLoop", 0, 0); // Create a new Node representing a show operation
        }
#line 1533 "Output/parser.tab.c"
    break;

  case 35: /* func_loop: GAUSSIAN_BLUR LPAREN INT COMMA INT RPAREN  */
#line 259 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("GaussianBlurLoop", 2, 0); // Create a new Node representing a gaussian blur
           addChild((yyval.node), createNode("KernelSize", 0, (yyvsp[-3].intVal)), 0); // Add a child Node representing the kernel width 
           addChild((yyval.node), createNode("Sigma", 0, (yyvsp[-1].intVal)), 1); // Add a child Node representing the kernel height
       }
#line 1543 "Output/parser.tab.c"
    break;

  case 36: /* func_loop: BILATERAL_BLUR LPAREN INT COMMA INT RPAREN  */
#line 265 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("BilateralBlurLoop", 2, 0); // Create a new Node representing a 'bilateral blur' operation
           addChild((yyval.node), createNode("KernelSize", 0, (yyvsp[-3].intVal)), 0); // Add a child Node representing the diameter 
           addChild((yyval.node), createNode("Sigma", 0, (yyvsp[-1].intVal)), 1); // Add a child Node representing the sigma color
       }
#line 1553 "Output/parser.tab.c"
    break;

  case 37: /* func_loop: MEDIAN_BLUR LPAREN INT RPAREN  */
#line 271 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("MedianBlurLoop", 1, 0); // Create a new Node representing a median blur operation
           addChild((yyval.node), createNode("KernelSize", 0, (yyvsp[-1].intVal)), 0); // Add a child Node representing the kernel size 
       }
#line 1562 "Output/parser.tab.c"
    break;

  case 38: /* func_loop: BINARY_THRESHOLD LPAREN INT RPAREN  */
#line 276 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("BinaryThresholdLoop", 1, 0); // Create a new Node representing a binary threshold operation
           addChild((yyval.node), createNode("Threshold", 0, (yyvsp[-1].intVal)), 0); // Add a child Node representing the threshold
       }
#line 1571 "Output/parser.tab.c"
    break;

  case 39: /* func_loop: BINARY_INV_THRESHOLD LPAREN INT RPAREN  */
#line 281 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("BinaryInverseThresholdLoop", 1, 0); // Create a new Node representing a binary inverse threshold operation
           addChild((yyval.node), createNode("Threshold", 0, (yyvsp[-1].intVal)), 0); // Add a child Node representing the threshold
       }
#line 1580 "Output/parser.tab.c"
    break;

  case 40: /* func_loop: OTSU_THRESHOLD LPAREN INT RPAREN  */
#line 286 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("OtsuThresholdLoop", 1, 0); // Create a new Node representing a otsu threshold operation
           addChild((yyval.node), createNode("Threshold", 0, (yyvsp[-1].intVal)), 0); // Add a child Node representing the threshold
       }
#line 1589 "Output/parser.tab.c"
    break;

  case 41: /* func_loop: BINARIZATION LPAREN RPAREN  */
#line 291 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("BinarizationLoop", 0, 0); // Create a new Node representing a otsu binary inverse threshold operation
       }
#line 1597 "Output/parser.tab.c"
    break;

  case 42: /* func_loop: COUNTOR LPAREN RPAREN  */
#line 295 "Frontend/Parser/parser.y"
       {
           (yyval.node) = createNode("CountorLoop", 0, 0); // Create a new Node representing a otsu binary inverse threshold operation
       }
#line 1605 "Output/parser.tab.c"
    break;

  case 43: /* func_list: func_loop  */
#line 301 "Frontend/Parser/parser.y"
            {
                (yyval.node) = createNode("func", 1, 0); // Define an function list with a single function
                addChild((yyval.node), (yyvsp[0].node), 0); // Add the function as a child of the function list Node
            }
#line 1614 "Output/parser.tab.c"
    break;

  case 44: /* func_list: func_list DOUBLE_GREATER func_loop  */
#line 306 "Frontend/Parser/parser.y"
            {
                Node *temp = createNode("funcList", (yyval.node)->num_children + 1, 0); 
                for (int i = 0; i < (yyval.node)->num_children; i++) 
                {
                    addChild(temp, (yyval.node)->children[i], i); 
                }
                addChild(temp, (yyvsp[0].node), (yyval.node)->num_children);
                (yyval.node) = temp; 
            }
#line 1628 "Output/parser.tab.c"
    break;

  case 45: /* expression: func  */
#line 317 "Frontend/Parser/parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1634 "Output/parser.tab.c"
    break;

  case 46: /* expression: IDENTIFIER TIMES IDENTIFIER  */
#line 319 "Frontend/Parser/parser.y"
           {
                (yyval.node) = createNode("Multiplication", 2, 0); // Define an expression as a multiplication operation
                addChild((yyval.node), createNode((yyvsp[-2].stringVal), 0, 0), 0); // Add the first identifier as a child of the multiplication Node
                addChild((yyval.node), createNode((yyvsp[0].stringVal), 0, 0), 1); // Add the second identifier as a child of the multiplication Node
           }
#line 1644 "Output/parser.tab.c"
    break;

  case 47: /* expression: IDENTIFIER PLUS IDENTIFIER  */
#line 325 "Frontend/Parser/parser.y"
           {
                  (yyval.node) = createNode("Addition", 2, 0); // Define an expression as an addition operation
                  addChild((yyval.node), createNode((yyvsp[-2].stringVal), 0, 0), 0); // Add the first identifier as a child of the addition Node
                  addChild((yyval.node), createNode((yyvsp[0].stringVal), 0, 0), 1); // Add the second identifier as a child of the addition Node
           }
#line 1654 "Output/parser.tab.c"
    break;

  case 48: /* expression: IDENTIFIER MINUS IDENTIFIER  */
#line 331 "Frontend/Parser/parser.y"
           {
                  (yyval.node) = createNode("Subtraction", 2, 0); // Define an expression as a subtraction operation
                  addChild((yyval.node), createNode((yyvsp[-2].stringVal), 0, 0), 0); // Add the first identifier as a child of the subtraction Node
                  addChild((yyval.node), createNode((yyvsp[0].stringVal), 0, 0), 1); // Add the second identifier as a child of the subtraction Node
           }
#line 1664 "Output/parser.tab.c"
    break;

  case 49: /* expression: ARRAY DOUBLE_EXCLAMATION INT  */
#line 337 "Frontend/Parser/parser.y"
            {
                (yyval.node) = createNode("Indexing", 2, 0); // Define an expression as an indexing operation
                addChild((yyval.node), createNode((yyvsp[-2].stringVal), 0, 0), 0); // Add the identifier as a child of the indexing Node
                addChild((yyval.node), createNode("Index", 0, (yyvsp[0].intVal)), 1); // Add a child Node representing the index
            }
#line 1674 "Output/parser.tab.c"
    break;

  case 50: /* expression: nested_func  */
#line 342 "Frontend/Parser/parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1680 "Output/parser.tab.c"
    break;

  case 51: /* nested_func: IDENTIFIER LPAREN expression_list RPAREN  */
#line 346 "Frontend/Parser/parser.y"
            {
                  (yyval.node) = createNode((yyvsp[-3].stringVal), (yyvsp[-1].node)->num_children, 0); // Define a nested function as a function call
                  for (int i = 0; i < (yyvsp[-1].node)->num_children; i++) 
                  {
                    addChild((yyval.node), (yyvsp[-1].node)->children[i], i); // Add each expression in the list as a child of the nested function Node
                  }
            }
#line 1692 "Output/parser.tab.c"
    break;

  case 52: /* expression_list: expression  */
#line 356 "Frontend/Parser/parser.y"
                {
                      (yyval.node) = createNode("Expression", 1, 0); // Define an expression list with a single expression
                      addChild((yyval.node), (yyvsp[0].node), 0); // Add the expression as a child of the expression list Node
                }
#line 1701 "Output/parser.tab.c"
    break;

  case 53: /* expression_list: expression_list COMMA expression  */
#line 361 "Frontend/Parser/parser.y"
                {
                      Node *temp = createNode("ExpressionList", (yyval.node)->num_children + 1, 0); // Define an expression list with multiple expressions
                      for (int i = 0; i < (yyval.node)->num_children; i++) 
                      {
                          addChild(temp, (yyval.node)->children[i], i); // Add each expression from the existing list to the new list
                      }
                      addChild(temp, (yyvsp[0].node), (yyval.node)->num_children); // Add the new expression to the end of the list
                      (yyval.node) = temp; // Set the result to the new expression list Node
                }
#line 1715 "Output/parser.tab.c"
    break;

  case 54: /* identifier_list: IDENTIFIER  */
#line 373 "Frontend/Parser/parser.y"
                {
                    (yyval.node) = createNode("Identifier", 1, 0); // Define an identifier list with a single identifier
                    addChild((yyval.node), createNode((yyvsp[0].stringVal), 0, 0), 0); // Add the identifier as a child of the identifier list Node
                }
#line 1724 "Output/parser.tab.c"
    break;

  case 55: /* identifier_list: identifier_list COMMA IDENTIFIER  */
#line 378 "Frontend/Parser/parser.y"
                {
                    Node *temp = createNode("IdentifierList", (yyval.node)->num_children + 1, 0); // Define an identifier list with multiple identifiers.
                    for (int i = 0; i < (yyval.node)->num_children; i++) 
                    {
                        addChild(temp, (yyval.node)->children[i], i); // Add each identifier from the existing list to the new list.
                    }
                    addChild(temp, createNode((yyvsp[0].stringVal), 0, 0), (yyval.node)->num_children); // Add the new identifier to the end of the list.
                    (yyval.node) = temp; // Set the result to the new identifier list Node.
                }
#line 1738 "Output/parser.tab.c"
    break;


#line 1742 "Output/parser.tab.c"

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

#line 389 "Frontend/Parser/parser.y"



void yyerror(const char *s) 
{
  fprintf(stderr, "Error: %s in line %d \n\n", s, line_number);
}

int parser(FILE *inputFile) 
{
    if (!inputFile)
    {
        printf("Error: Input file not opened.\n");  
        return 1;
    }
    yyparse();
    return 0;
}
