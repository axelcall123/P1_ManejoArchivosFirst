%defines
%{
    #include "scanner.cpp"
    #include <stdlib.h>
    #include <iostream>
    #include "../head/nodo.h"

    using namespace std;

    extern int yylineno;
    extern char *yytext;
    extern int yyfila;
    extern int yycolum;
    Nodo* Raiz = nullptr;

    int yyerror(const char* mensaje){
        return 0;
    }

    Nodo* getRaiz(){
    return Raiz;
    }

%}
%define parse.error verbose
%union{
    char TXT[300];
    struct Nodo* NODO;
}
%token<TXT> add
%token<TXT> cat
%token<TXT> chgrp
%token<TXT> chmod
%token<TXT> chown
%token<TXT> cont
%token<TXT> copy
%token<TXT> delete
%token<TXT> destino
%token<TXT> edit
%token<TXT> fdisk
%token<TXT> fileN
%token<TXT> find
%token<TXT> fit
%token<TXT> fs
%token<TXT> grp
%token<TXT> id
%token<TXT> login
%token<TXT> logout
%token<TXT> mkdir
%token<TXT> mkdisk
%token<TXT> mkfile
%token<TXT> mkfs
%token<TXT> mkusr
%token<TXT> mount
%token<TXT> move
%token<TXT> name
%token<TXT> pass
%token<TXT> path
%token<TXT> pause
%token<TXT> r
%token<TXT> remove
%token<TXT> rename
%token<TXT> rmdisk
%token<TXT> rmgrp
%token<TXT> rmsur
%token<TXT> size
%token<TXT> type
%token<TXT> ugo
%token<TXT> unit
%token<TXT> unmount
%token<TXT> user

%token<TXT> palabra

%token<TXT> igual
%token<TXT> mayor
%token<TXT> interrogacion
%token<TXT> asterisco
%token<TXT> pathES
%token<TXT> pathS
%token<TXT> entero

%token<TXT> bf
%token<TXT> ff
%token<TXT> kilo
%token<TXT> mega
%token<TXT> wf


%type<NODO>



%start INICIO
%%
INICIO:LCMD{}
;

LCMD:LCMD COMANDOS{}
|COMANDOS{}
;

COMANDOS:PRINCIPALCOM SUBCOMAND{}
;

PRINCIPALCOM:cat{}
|chgrp{}
|chmod{}
|chown{}
|copy{}
|edit{}
|fdisk{}
|find{}
|login{}
|logout{}
|mkdir{}
|mkdisk{}
|mkfile{}
|mkfs{}
|mkusr{}
|mount{}
|move{}
|pause{}
|remove{}
|rename{}
|rmdisk{}
|rmgrp{}
|rmsur{}
|unmount{}
;

SUBCOMAND:SUBCOMAND mayor SUB{}
|mayor SUB{}
;

SUB:add igual{}
|cont igual pathS{}
|delete{}
|destino igual{}
|fileN igual{}
|fit igual CFIT{}//
|fs igual{}
|grp igual{}
|id igual{}
|name igual palabra{}//
|pass igual{}
|path igual CPATH{}//
|r igual{}
|size igual entero{}//
|type igual{}
|ugo igual{}
|unit igual{}//
|user igual{}
;

CPATH:pathES
|pathS
;

CFIT:bb
|ff
|wf
;

CUNIT:kilo
|mega
;