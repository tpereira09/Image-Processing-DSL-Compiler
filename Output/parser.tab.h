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

#ifndef YY_YY_OUTPUT_PARSER_TAB_H_INCLUDED
# define YY_YY_OUTPUT_PARSER_TAB_H_INCLUDED
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
    ERROR = 258,                   /* ERROR  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    PATH = 260,                    /* PATH  */
    INT = 261,                     /* INT  */
    ARRAY = 262,                   /* ARRAY  */
    PLUS = 263,                    /* PLUS  */
    MINUS = 264,                   /* MINUS  */
    TIMES = 265,                   /* TIMES  */
    ASSIGNMENT = 266,              /* ASSIGNMENT  */
    COMMA = 267,                   /* COMMA  */
    LPAREN = 268,                  /* LPAREN  */
    RPAREN = 269,                  /* RPAREN  */
    LBRACKET = 270,                /* LBRACKET  */
    RBRACKET = 271,                /* RBRACKET  */
    DOUBLE_EXCLAMATION = 272,      /* DOUBLE_EXCLAMATION  */
    RESIZE = 273,                  /* RESIZE  */
    ROTATE = 274,                  /* ROTATE  */
    FLIP = 275,                    /* FLIP  */
    LOAD = 276,                    /* LOAD  */
    SHOW = 277,                    /* SHOW  */
    GAUSSIAN_BLUR = 278,           /* GAUSSIAN_BLUR  */
    BILATERAL_BLUR = 279,          /* BILATERAL_BLUR  */
    MEDIAN_BLUR = 280,             /* MEDIAN_BLUR  */
    BINARY_THRESHOLD = 281,        /* BINARY_THRESHOLD  */
    BINARY_INV_THRESHOLD = 282,    /* BINARY_INV_THRESHOLD  */
    OTSU_THRESHOLD = 283,          /* OTSU_THRESHOLD  */
    BINARIZATION = 284,            /* BINARIZATION  */
    COUNTOR = 285,                 /* COUNTOR  */
    LOOP = 286,                    /* LOOP  */
    COMPILE = 287,                 /* COMPILE  */
    DOUBLE_GREATER = 288,          /* DOUBLE_GREATER  */
    RECOGNIZE_TEXT = 289,          /* RECOGNIZE_TEXT  */
    PRINT = 290,                   /* PRINT  */
    TIMER = 291,                   /* TIMER  */
    ON = 292,                      /* ON  */
    OFF = 293,                     /* OFF  */
    SET_MODE = 294,                /* SET_MODE  */
    SEQUENTIAL_MODE = 295,         /* SEQUENTIAL_MODE  */
    PARALLEL_MODE = 296,           /* PARALLEL_MODE  */
    PARALLEL_CHUNKED_MODE = 297    /* PARALLEL_CHUNKED_MODE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 58 "Frontend/Parser/parser.y"

    char *stringVal;
    int intVal;
    struct Node * node;

#line 112 "Output/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_OUTPUT_PARSER_TAB_H_INCLUDED  */
