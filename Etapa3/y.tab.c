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

    //INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
    //  Etapa 2 
   //Joao Pedro Ferreira, 324521

    #include <stdio.h>
    #include <stdlib.h>
    #include "hash.h"
    #include "ast.h"

    int yylex();
	int yyerror(char *message);
    extern int getLineNumber();
    AST_NODE *root;

#line 87 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 18 "parser.y"

    #include "hash.h"
    #include "ast.h"

#line 127 "y.tab.c"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_CHAR = 258,                 /* KW_CHAR  */
    KW_INT = 259,                  /* KW_INT  */
    KW_FLOAT = 260,                /* KW_FLOAT  */
    KW_CODE = 261,                 /* KW_CODE  */
    KW_IF = 262,                   /* KW_IF  */
    KW_ELSE = 263,                 /* KW_ELSE  */
    KW_WHILE = 264,                /* KW_WHILE  */
    KW_INPUT = 265,                /* KW_INPUT  */
    KW_PRINT = 266,                /* KW_PRINT  */
    KW_RETURN = 267,               /* KW_RETURN  */
    OPERATOR_LE = 268,             /* OPERATOR_LE  */
    OPERATOR_GE = 269,             /* OPERATOR_GE  */
    OPERATOR_EQ = 270,             /* OPERATOR_EQ  */
    OPERATOR_DIF = 271,            /* OPERATOR_DIF  */
    TK_IDENTIFIER = 272,           /* TK_IDENTIFIER  */
    LIT_INT = 273,                 /* LIT_INT  */
    LIT_REAL = 274,                /* LIT_REAL  */
    LIT_CHAR = 275,                /* LIT_CHAR  */
    LIT_STRING = 276,              /* LIT_STRING  */
    TOKEN_ERROR = 277              /* TOKEN_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KW_CHAR 258
#define KW_INT 259
#define KW_FLOAT 260
#define KW_CODE 261
#define KW_IF 262
#define KW_ELSE 263
#define KW_WHILE 264
#define KW_INPUT 265
#define KW_PRINT 266
#define KW_RETURN 267
#define OPERATOR_LE 268
#define OPERATOR_GE 269
#define OPERATOR_EQ 270
#define OPERATOR_DIF 271
#define TK_IDENTIFIER 272
#define LIT_INT 273
#define LIT_REAL 274
#define LIT_CHAR 275
#define LIT_STRING 276
#define TOKEN_ERROR 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "parser.y"

    HASH_ENTRY *symbol; 
    AST_NODE *ast;

#line 196 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_CHAR = 3,                    /* KW_CHAR  */
  YYSYMBOL_KW_INT = 4,                     /* KW_INT  */
  YYSYMBOL_KW_FLOAT = 5,                   /* KW_FLOAT  */
  YYSYMBOL_KW_CODE = 6,                    /* KW_CODE  */
  YYSYMBOL_KW_IF = 7,                      /* KW_IF  */
  YYSYMBOL_KW_ELSE = 8,                    /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 9,                   /* KW_WHILE  */
  YYSYMBOL_KW_INPUT = 10,                  /* KW_INPUT  */
  YYSYMBOL_KW_PRINT = 11,                  /* KW_PRINT  */
  YYSYMBOL_KW_RETURN = 12,                 /* KW_RETURN  */
  YYSYMBOL_OPERATOR_LE = 13,               /* OPERATOR_LE  */
  YYSYMBOL_OPERATOR_GE = 14,               /* OPERATOR_GE  */
  YYSYMBOL_OPERATOR_EQ = 15,               /* OPERATOR_EQ  */
  YYSYMBOL_OPERATOR_DIF = 16,              /* OPERATOR_DIF  */
  YYSYMBOL_TK_IDENTIFIER = 17,             /* TK_IDENTIFIER  */
  YYSYMBOL_LIT_INT = 18,                   /* LIT_INT  */
  YYSYMBOL_LIT_REAL = 19,                  /* LIT_REAL  */
  YYSYMBOL_LIT_CHAR = 20,                  /* LIT_CHAR  */
  YYSYMBOL_LIT_STRING = 21,                /* LIT_STRING  */
  YYSYMBOL_TOKEN_ERROR = 22,               /* TOKEN_ERROR  */
  YYSYMBOL_23_ = 23,                       /* '+'  */
  YYSYMBOL_24_ = 24,                       /* '-'  */
  YYSYMBOL_25_ = 25,                       /* '*'  */
  YYSYMBOL_26_ = 26,                       /* '/'  */
  YYSYMBOL_27_ = 27,                       /* '<'  */
  YYSYMBOL_28_ = 28,                       /* '>'  */
  YYSYMBOL_29_ = 29,                       /* '&'  */
  YYSYMBOL_30_ = 30,                       /* '|'  */
  YYSYMBOL_31_ = 31,                       /* '~'  */
  YYSYMBOL_32_ = 32,                       /* '='  */
  YYSYMBOL_33_ = 33,                       /* ';'  */
  YYSYMBOL_34_ = 34,                       /* '['  */
  YYSYMBOL_35_ = 35,                       /* ']'  */
  YYSYMBOL_36_ = 36,                       /* '('  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_start = 43,                     /* start  */
  YYSYMBOL_declaration_list = 44,          /* declaration_list  */
  YYSYMBOL_declaration = 45,               /* declaration  */
  YYSYMBOL_implementation_list = 46,       /* implementation_list  */
  YYSYMBOL_implementation = 47,            /* implementation  */
  YYSYMBOL_command = 48,                   /* command  */
  YYSYMBOL_command_list = 49,              /* command_list  */
  YYSYMBOL_print_function = 50,            /* print_function  */
  YYSYMBOL_argument_list = 51,             /* argument_list  */
  YYSYMBOL_next_argument = 52,             /* next_argument  */
  YYSYMBOL_expression = 53,                /* expression  */
  YYSYMBOL_vector_elements = 54,           /* vector_elements  */
  YYSYMBOL_parameters_list = 55,           /* parameters_list  */
  YYSYMBOL_next_parameter = 56,            /* next_parameter  */
  YYSYMBOL_parameter = 57,                 /* parameter  */
  YYSYMBOL_type = 58,                      /* type  */
  YYSYMBOL_literal = 59                    /* literal  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
       2,     2,     2,     2,     2,     2,     2,     2,    29,     2,
      36,    37,    25,    23,    40,    24,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
      27,    32,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,    30,    39,    31,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    86,    86,    88,    89,    92,    93,    97,    98,    99,
     101,   102,   106,   110,   111,   112,   113,   114,   115,   116,
     117,   120,   121,   125,   126,   129,   130,   132,   133,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   158,   159,
     165,   166,   170,   171,   174,   178,   179,   180,   183,   184,
     185
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
  "\"end of file\"", "error", "\"invalid token\"", "KW_CHAR", "KW_INT",
  "KW_FLOAT", "KW_CODE", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_INPUT",
  "KW_PRINT", "KW_RETURN", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ",
  "OPERATOR_DIF", "TK_IDENTIFIER", "LIT_INT", "LIT_REAL", "LIT_CHAR",
  "LIT_STRING", "TOKEN_ERROR", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'",
  "'&'", "'|'", "'~'", "'='", "';'", "'['", "']'", "'('", "')'", "'{'",
  "'}'", "','", "$accept", "program", "start", "declaration_list",
  "declaration", "implementation_list", "implementation", "command",
  "command_list", "print_function", "argument_list", "next_argument",
  "expression", "vector_elements", "parameters_list", "next_parameter",
  "parameter", "type", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-30)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-6)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   -30,   -30,   -30,    16,   -30,    25,    22,    18,   -30,
      21,   -30,    25,   -30,   -17,    -5,   -30,    10,     4,    22,
      24,    29,    79,    91,   -29,    -5,   -30,   -30,   -30,   -30,
       6,    23,    30,    28,    49,    91,    91,    44,    -2,   -30,
      91,    50,   271,   -30,   208,    91,    91,    -5,    42,   -30,
      10,    52,    22,   -30,   -30,   105,   124,    22,    91,    91,
     143,   -30,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,   -30,   229,   162,   -30,   -30,
      53,    10,   -30,    28,    -5,    -5,    45,   185,    54,    48,
     -30,    26,    26,    26,    26,   276,   276,   276,   276,    26,
      26,   -30,   -30,   -30,   -30,    55,   -30,   -30,   -30,    82,
     -30,   -30,   -30,   -30,    91,   -30,    91,    -5,    48,   250,
     -30,   -30,   -30
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    55,    56,    57,     0,     2,    11,     5,     0,     1,
       0,     4,    11,     6,     0,     0,    10,     0,     0,    50,
       0,     0,     0,     0,     0,    22,    12,    59,    60,    58,
       0,     0,     0,    52,     0,     0,     0,     0,    30,    23,
       0,     0,    24,    29,     0,     0,     0,    22,     0,     7,
      49,     0,     0,    51,    54,     0,     0,     0,     0,    26,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,    21,    14,
       0,    49,     9,    52,     0,     0,     0,     0,     0,    28,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    16,     0,     8,    48,    53,    18,
      20,    47,    31,    32,     0,    25,     0,     0,    28,     0,
      19,    27,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,   -30,    86,   -30,    83,   -30,   -15,    56,   -30,
     -30,   -14,   -22,    31,   -30,    33,    61,     2,     3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    11,    12,    47,    48,    41,
      88,   115,    42,    80,    32,    53,    33,     8,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      26,    44,    20,    45,    21,    46,    22,    23,     1,     2,
       3,    -5,    24,    55,    56,    17,     9,    18,    60,    19,
      30,    34,    31,    76,    77,     1,     2,     3,    27,    28,
      29,    10,    58,    25,    59,    14,    87,    89,    15,    49,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    81,    34,    72,    73,    74,    50,    86,
      35,    62,    63,    64,    65,    36,    54,    51,    52,   109,
     110,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      57,    79,   111,    61,    81,    82,   106,   116,   114,    37,
     117,   113,   118,    13,   119,    16,    38,    27,    28,    29,
      39,    37,   120,    78,   121,     0,     0,     0,    38,    27,
      28,    29,   107,    83,     0,    40,   108,     0,    62,    63,
      64,    65,     0,     0,     0,     0,     0,    40,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    62,    63,    64,
      65,     0,    84,     0,     0,     0,     0,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    62,    63,    64,    65,
       0,    85,     0,     0,     0,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    62,    63,    64,    65,     0,
      90,     0,     0,     0,     0,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,     0,     0,   105,    62,    63,
      64,    65,     0,     0,     0,     0,     0,     0,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,     0,
     112,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,    75,    62,    63,    64,    65,     0,     0,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,   104,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,   122,    62,    63,    64,    65,     0,    62,
      63,    64,    65,     0,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    70,    71,    72,    73,    74
};

static const yytype_int8 yycheck[] =
{
      15,    23,     7,    32,     9,    34,    11,    12,     3,     4,
       5,     6,    17,    35,    36,    32,     0,    34,    40,    36,
      17,    19,    18,    45,    46,     3,     4,     5,    18,    19,
      20,     6,    34,    38,    36,    17,    58,    59,    17,    33,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    50,    52,    29,    30,    31,    35,    57,
      36,    13,    14,    15,    16,    36,    17,    37,    40,    84,
      85,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      36,    39,    37,    33,    81,    33,    33,    32,    40,    10,
       8,    37,   114,     7,   116,    12,    17,    18,    19,    20,
      21,    10,   117,    47,   118,    -1,    -1,    -1,    17,    18,
      19,    20,    81,    52,    -1,    36,    83,    -1,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    36,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    13,    14,    15,
      16,    -1,    37,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    13,    14,    15,    16,
      -1,    37,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    13,    14,    15,    16,    -1,
      37,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    35,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      35,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    33,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    33,    13,    14,    15,    16,    -1,    13,
      14,    15,    16,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    27,    28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    42,    43,    44,    45,    58,     0,
       6,    46,    47,    44,    17,    17,    46,    32,    34,    36,
       7,     9,    11,    12,    17,    38,    48,    18,    19,    20,
      59,    18,    55,    57,    58,    36,    36,    10,    17,    21,
      36,    50,    53,    59,    53,    32,    34,    48,    49,    33,
      35,    37,    40,    56,    17,    53,    53,    36,    34,    36,
      53,    33,    13,    14,    15,    16,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    33,    53,    53,    49,    39,
      54,    59,    33,    57,    37,    37,    58,    53,    51,    53,
      37,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    33,    35,    33,    54,    56,    48,
      48,    37,    35,    37,    40,    52,    32,     8,    53,    53,
      48,    52,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    45,    45,
      46,    46,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      55,    55,    56,    56,    57,    58,    58,    58,    59,    59,
      59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     2,     5,     7,     6,
       2,     0,     3,     3,     3,     3,     4,     7,     5,     7,
       5,     2,     0,     1,     1,     2,     0,     3,     0,     1,
       1,     4,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     2,     0,
       0,     2,     0,     3,     2,     1,     1,     1,     1,     1,
       1
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
  case 2: /* program: start  */
#line 86 "parser.y"
                                                                            {root=(yyval.ast);astree_print(0, root);}
#line 1347 "y.tab.c"
    break;

  case 4: /* start: declaration_list implementation_list  */
#line 89 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_START, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0);}
#line 1353 "y.tab.c"
    break;

  case 5: /* declaration_list: %empty  */
#line 92 "parser.y"
                                                                            {(yyval.ast)=0;}
#line 1359 "y.tab.c"
    break;

  case 6: /* declaration_list: declaration declaration_list  */
#line 93 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_DECLARATION_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0);}
#line 1365 "y.tab.c"
    break;

  case 7: /* declaration: type TK_IDENTIFIER '=' literal ';'  */
#line 97 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_DECLARATION, (yyvsp[-3].symbol), (yyvsp[-4].ast), (yyvsp[-1].ast), 0, 0);}
#line 1371 "y.tab.c"
    break;

  case 8: /* declaration: type TK_IDENTIFIER '[' LIT_INT ']' vector_elements ';'  */
#line 98 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_DECLARATION_VECTOR, (yyvsp[-5].symbol), (yyvsp[-6].ast), astree_create(AST_SYMBOL, (yyvsp[-3].symbol), 0, 0, 0, 0), (yyvsp[-1].ast), 0);}
#line 1377 "y.tab.c"
    break;

  case 9: /* declaration: type TK_IDENTIFIER '(' parameters_list ')' ';'  */
#line 99 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_DECLARATION_FUNCTION, (yyvsp[-4].symbol), (yyvsp[-5].ast), (yyvsp[-2].ast), 0, 0);}
#line 1383 "y.tab.c"
    break;

  case 10: /* implementation_list: implementation implementation_list  */
#line 101 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_IMPLEMENTATION_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0);}
#line 1389 "y.tab.c"
    break;

  case 11: /* implementation_list: %empty  */
#line 102 "parser.y"
                                                                            {(yyval.ast)=0;}
#line 1395 "y.tab.c"
    break;

  case 12: /* implementation: KW_CODE TK_IDENTIFIER command  */
#line 106 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_IMPLEMENTATION, (yyvsp[-1].symbol), (yyvsp[0].ast), 0, 0, 0);}
#line 1401 "y.tab.c"
    break;

  case 13: /* command: KW_PRINT print_function ';'  */
#line 110 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_PRINT, 0, (yyvsp[-1].ast), 0, 0, 0);}
#line 1407 "y.tab.c"
    break;

  case 14: /* command: '{' command_list '}'  */
#line 111 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_COMMAND_BLOCK, 0, (yyvsp[-1].ast), 0, 0, 0);}
#line 1413 "y.tab.c"
    break;

  case 15: /* command: KW_RETURN expression ';'  */
#line 112 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_RETURN, 0, (yyvsp[-1].ast), 0, 0, 0);}
#line 1419 "y.tab.c"
    break;

  case 16: /* command: TK_IDENTIFIER '=' expression ';'  */
#line 113 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_ATTRIBUTION, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0, 0);}
#line 1425 "y.tab.c"
    break;

  case 17: /* command: TK_IDENTIFIER '[' expression ']' '=' expression ';'  */
#line 114 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_VECTOR_ATTRIBUTION, (yyvsp[-6].symbol), (yyvsp[-4].ast), (yyvsp[-1].ast), 0, 0);}
#line 1431 "y.tab.c"
    break;

  case 18: /* command: KW_IF '(' expression ')' command  */
#line 115 "parser.y"
                                                                           {(yyval.ast)=astree_create(AST_IF, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1437 "y.tab.c"
    break;

  case 19: /* command: KW_IF '(' expression ')' command KW_ELSE command  */
#line 116 "parser.y"
                                                                             {(yyval.ast)=astree_create(AST_IF_ELSE, 0, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), 0);}
#line 1443 "y.tab.c"
    break;

  case 20: /* command: KW_WHILE '(' expression ')' command  */
#line 117 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_WHILE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1449 "y.tab.c"
    break;

  case 21: /* command_list: command command_list  */
#line 120 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_COMMAND_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0);}
#line 1455 "y.tab.c"
    break;

  case 22: /* command_list: %empty  */
#line 121 "parser.y"
                                                                            {(yyval.ast)=0;}
#line 1461 "y.tab.c"
    break;

  case 23: /* print_function: LIT_STRING  */
#line 125 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0);}
#line 1467 "y.tab.c"
    break;

  case 24: /* print_function: expression  */
#line 126 "parser.y"
                                                                            {(yyval.ast)=(yyvsp[0].ast);}
#line 1473 "y.tab.c"
    break;

  case 25: /* argument_list: expression next_argument  */
#line 129 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_ARGUMENT_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0);}
#line 1479 "y.tab.c"
    break;

  case 26: /* argument_list: %empty  */
#line 130 "parser.y"
                                                                            {(yyval.ast)=0;}
#line 1485 "y.tab.c"
    break;

  case 27: /* next_argument: ',' expression next_argument  */
#line 132 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_NEXT_ARGUMENT, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0);}
#line 1491 "y.tab.c"
    break;

  case 28: /* next_argument: %empty  */
#line 133 "parser.y"
                                                                            {(yyval.ast)=0;}
#line 1497 "y.tab.c"
    break;

  case 29: /* expression: literal  */
#line 136 "parser.y"
                                                                            {(yyval.ast)=(yyvsp[0].ast);}
#line 1503 "y.tab.c"
    break;

  case 30: /* expression: TK_IDENTIFIER  */
#line 137 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0);}
#line 1509 "y.tab.c"
    break;

  case 31: /* expression: TK_IDENTIFIER '[' expression ']'  */
#line 138 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_VECTOR, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0, 0);}
#line 1515 "y.tab.c"
    break;

  case 32: /* expression: TK_IDENTIFIER '(' argument_list ')'  */
#line 139 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_FUNCTION, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0, 0);}
#line 1521 "y.tab.c"
    break;

  case 33: /* expression: '(' expression ')'  */
#line 140 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_PARENTHESIS, 0, (yyvsp[-1].ast), 0, 0, 0);}
#line 1527 "y.tab.c"
    break;

  case 34: /* expression: expression OPERATOR_LE expression  */
#line 141 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_LE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1533 "y.tab.c"
    break;

  case 35: /* expression: expression OPERATOR_GE expression  */
#line 142 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_GE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1539 "y.tab.c"
    break;

  case 36: /* expression: expression OPERATOR_EQ expression  */
#line 143 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_EQ, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1545 "y.tab.c"
    break;

  case 37: /* expression: expression OPERATOR_DIF expression  */
#line 144 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_DIF, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1551 "y.tab.c"
    break;

  case 38: /* expression: expression '+' expression  */
#line 145 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_SUM, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1557 "y.tab.c"
    break;

  case 39: /* expression: expression '-' expression  */
#line 146 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_SUB, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1563 "y.tab.c"
    break;

  case 40: /* expression: expression '*' expression  */
#line 147 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_MUL, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1569 "y.tab.c"
    break;

  case 41: /* expression: expression '/' expression  */
#line 148 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_DIV, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1575 "y.tab.c"
    break;

  case 42: /* expression: expression '<' expression  */
#line 149 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_LESS, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1581 "y.tab.c"
    break;

  case 43: /* expression: expression '>' expression  */
#line 150 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_GREATER, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1587 "y.tab.c"
    break;

  case 44: /* expression: expression '&' expression  */
#line 151 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_AND, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1593 "y.tab.c"
    break;

  case 45: /* expression: expression '|' expression  */
#line 152 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_OR, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1599 "y.tab.c"
    break;

  case 46: /* expression: expression '~' expression  */
#line 153 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_NOT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0);}
#line 1605 "y.tab.c"
    break;

  case 47: /* expression: KW_INPUT '(' type ')'  */
#line 154 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_INPUT, 0, (yyvsp[-1].ast), 0, 0, 0);}
#line 1611 "y.tab.c"
    break;

  case 48: /* vector_elements: literal vector_elements  */
#line 158 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_VECTOR_ELEMENTS, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0);}
#line 1617 "y.tab.c"
    break;

  case 49: /* vector_elements: %empty  */
#line 159 "parser.y"
                                                                            {(yyval.ast)=0;}
#line 1623 "y.tab.c"
    break;

  case 50: /* parameters_list: %empty  */
#line 165 "parser.y"
                                                                               {(yyval.ast)=0;}
#line 1629 "y.tab.c"
    break;

  case 51: /* parameters_list: parameter next_parameter  */
#line 166 "parser.y"
                                                                               {(yyval.ast)=astree_create(AST_PARAMETERS_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0);}
#line 1635 "y.tab.c"
    break;

  case 52: /* next_parameter: %empty  */
#line 170 "parser.y"
                                                                                {(yyval.ast)=0;}
#line 1641 "y.tab.c"
    break;

  case 53: /* next_parameter: ',' parameter next_parameter  */
#line 171 "parser.y"
                                                                                {(yyval.ast)=astree_create(AST_NEXT_PARAMETER, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0);}
#line 1647 "y.tab.c"
    break;

  case 54: /* parameter: type TK_IDENTIFIER  */
#line 174 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_PARAMETER, (yyvsp[0].symbol), (yyvsp[-1].ast), 0, 0, 0);}
#line 1653 "y.tab.c"
    break;

  case 55: /* type: KW_CHAR  */
#line 178 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_TYPE_CHAR, 0, 0, 0, 0, 0);}
#line 1659 "y.tab.c"
    break;

  case 56: /* type: KW_INT  */
#line 179 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_TYPE_INT, 0, 0, 0, 0, 0);}
#line 1665 "y.tab.c"
    break;

  case 57: /* type: KW_FLOAT  */
#line 180 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_TYPE_FLOAT, 0, 0, 0, 0, 0);}
#line 1671 "y.tab.c"
    break;

  case 58: /* literal: LIT_CHAR  */
#line 183 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0);}
#line 1677 "y.tab.c"
    break;

  case 59: /* literal: LIT_INT  */
#line 184 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0);}
#line 1683 "y.tab.c"
    break;

  case 60: /* literal: LIT_REAL  */
#line 185 "parser.y"
                                                                            {(yyval.ast)=astree_create(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0);}
#line 1689 "y.tab.c"
    break;


#line 1693 "y.tab.c"

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

#line 189 "parser.y"


int yyerror(char *err){
	
	fprintf(stderr, "Syntax Error in line %d\n", getLineNumber());
	exit(3);
}

AST_NODE* getAST(){
    return root;
}
