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

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    Add = 258,                     /* Add  */
    Cat = 259,                     /* Cat  */
    Chgrp = 260,                   /* Chgrp  */
    Chmod = 261,                   /* Chmod  */
    Chown = 262,                   /* Chown  */
    Cont = 263,                    /* Cont  */
    Copy = 264,                    /* Copy  */
    Delete = 265,                  /* Delete  */
    Destino = 266,                 /* Destino  */
    Edit = 267,                    /* Edit  */
    Execute = 268,                 /* Execute  */
    Fdisk = 269,                   /* Fdisk  */
    FileN = 270,                   /* FileN  */
    Find = 271,                    /* Find  */
    Fit = 272,                     /* Fit  */
    Fs = 273,                      /* Fs  */
    Full = 274,                    /* Full  */
    Grp = 275,                     /* Grp  */
    Id = 276,                      /* Id  */
    Login = 277,                   /* Login  */
    Logout = 278,                  /* Logout  */
    Mkdir = 279,                   /* Mkdir  */
    Mkdisk = 280,                  /* Mkdisk  */
    Mkfile = 281,                  /* Mkfile  */
    Mkfs = 282,                    /* Mkfs  */
    Mkusr = 283,                   /* Mkusr  */
    Mount = 284,                   /* Mount  */
    Move = 285,                    /* Move  */
    Name = 286,                    /* Name  */
    Pass = 287,                    /* Pass  */
    Path = 288,                    /* Path  */
    Pause = 289,                   /* Pause  */
    R = 290,                       /* R  */
    Remove = 291,                  /* Remove  */
    Rename = 292,                  /* Rename  */
    Rmdisk = 293,                  /* Rmdisk  */
    Rmgrp = 294,                   /* Rmgrp  */
    Rmusr = 295,                   /* Rmusr  */
    Size = 296,                    /* Size  */
    Type = 297,                    /* Type  */
    Ugo = 298,                     /* Ugo  */
    Unit = 299,                    /* Unit  */
    Unmount = 300,                 /* Unmount  */
    User = 301,                    /* User  */
    Dfs = 302,                     /* Dfs  */
    Tfs = 303,                     /* Tfs  */
    Igual = 304,                   /* Igual  */
    Mayor = 305,                   /* Mayor  */
    Interrogacion = 306,           /* Interrogacion  */
    Asterisco = 307,               /* Asterisco  */
    PathS = 308,                   /* PathS  */
    Entero = 309,                  /* Entero  */
    Palabra = 310,                 /* Palabra  */
    PalabraC = 311,                /* PalabraC  */
    Nnatural = 312,                /* Nnatural  */
    Ids = 313,                     /* Ids  */
    Byte = 314,                    /* Byte  */
    Bf = 315,                      /* Bf  */
    Extendida = 316,               /* Extendida  */
    Ff = 317,                      /* Ff  */
    Kilo = 318,                    /* Kilo  */
    Logica = 319,                  /* Logica  */
    Mega = 320,                    /* Mega  */
    Primaria = 321,                /* Primaria  */
    Wf = 322,                      /* Wf  */
    TheEnd = 323                   /* TheEnd  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "ASintactico.y"

    char TXT[300];
    struct Nodo* NODO;

#line 137 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
