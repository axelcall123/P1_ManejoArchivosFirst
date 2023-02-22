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
    Fdisk = 268,                   /* Fdisk  */
    FileN = 269,                   /* FileN  */
    Find = 270,                    /* Find  */
    Fit = 271,                     /* Fit  */
    Fs = 272,                      /* Fs  */
    Full = 273,                    /* Full  */
    Grp = 274,                     /* Grp  */
    Id = 275,                      /* Id  */
    Login = 276,                   /* Login  */
    Logout = 277,                  /* Logout  */
    Mkdir = 278,                   /* Mkdir  */
    Mkdisk = 279,                  /* Mkdisk  */
    Mkfile = 280,                  /* Mkfile  */
    Mkfs = 281,                    /* Mkfs  */
    Mkusr = 282,                   /* Mkusr  */
    Mount = 283,                   /* Mount  */
    Move = 284,                    /* Move  */
    Name = 285,                    /* Name  */
    Pass = 286,                    /* Pass  */
    Path = 287,                    /* Path  */
    Pause = 288,                   /* Pause  */
    R = 289,                       /* R  */
    Remove = 290,                  /* Remove  */
    Rename = 291,                  /* Rename  */
    Rmdisk = 292,                  /* Rmdisk  */
    Rmgrp = 293,                   /* Rmgrp  */
    Rmusr = 294,                   /* Rmusr  */
    Size = 295,                    /* Size  */
    Type = 296,                    /* Type  */
    Ugo = 297,                     /* Ugo  */
    Unit = 298,                    /* Unit  */
    Unmount = 299,                 /* Unmount  */
    User = 300,                    /* User  */
    Dfs = 301,                     /* Dfs  */
    Tfs = 302,                     /* Tfs  */
    Igual = 303,                   /* Igual  */
    Mayor = 304,                   /* Mayor  */
    Interrogacion = 305,           /* Interrogacion  */
    Asterisco = 306,               /* Asterisco  */
    PathES = 307,                  /* PathES  */
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
    Wf = 322                       /* Wf  */
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

#line 136 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
