/* A Bison parser, made by GNU Bison 3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "./src/myml.y" /* yacc.c:1912  */



#include "Table_des_symboles.h"  // header included in y.tab.h


#line 54 "./src/y.tab.h" /* yacc.c:1912  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    FLOAT = 259,
    ID = 260,
    STRING = 261,
    PV = 262,
    LPAR = 263,
    RPAR = 264,
    LBR = 265,
    RBR = 266,
    LET = 267,
    IN = 268,
    VIR = 269,
    IF = 270,
    THEN = 271,
    ELSE = 272,
    ISLT = 273,
    ISGT = 274,
    ISLEQ = 275,
    ISGEQ = 276,
    ISEQ = 277,
    AND = 278,
    OR = 279,
    NOT = 280,
    BOOL = 281,
    PLUS = 282,
    MOINS = 283,
    MULT = 284,
    DIV = 285,
    EQ = 286,
    CONCAT = 287,
    UNA = 288
  };
#endif
/* Tokens.  */
#define NUM 258
#define FLOAT 259
#define ID 260
#define STRING 261
#define PV 262
#define LPAR 263
#define RPAR 264
#define LBR 265
#define RBR 266
#define LET 267
#define IN 268
#define VIR 269
#define IF 270
#define THEN 271
#define ELSE 272
#define ISLT 273
#define ISGT 274
#define ISLEQ 275
#define ISGEQ 276
#define ISEQ 277
#define AND 278
#define OR 279
#define NOT 280
#define BOOL 281
#define PLUS 282
#define MOINS 283
#define MULT 284
#define DIV 285
#define EQ 286
#define CONCAT 287
#define UNA 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "./src/myml.y" /* yacc.c:1912  */

  symb_value_type val;
  //char * sid;

#line 137 "./src/y.tab.h" /* yacc.c:1912  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
