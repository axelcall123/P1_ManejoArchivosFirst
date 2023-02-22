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
%token<TXT> Add
%token<TXT> Cat
%token<TXT> Chgrp
%token<TXT> Chmod
%token<TXT> Chown
%token<TXT> Cont
%token<TXT> Copy
%token<TXT> Delete
%token<TXT> Destino
%token<TXT> Edit
%token<TXT> Fdisk
%token<TXT> FileN
%token<TXT> Find
%token<TXT> Fit
%token<TXT> Fs
%token<TXT> Full
%token<TXT> Grp
%token<TXT> Id
%token<TXT> Login
%token<TXT> Logout
%token<TXT> Mkdir
%token<TXT> Mkdisk
%token<TXT> Mkfile
%token<TXT> Mkfs
%token<TXT> Mkusr
%token<TXT> Mount
%token<TXT> Move
%token<TXT> Name
%token<TXT> Pass
%token<TXT> Path
%token<TXT> Pause
%token<TXT> R
%token<TXT> Remove
%token<TXT> Rename
%token<TXT> Rmdisk
%token<TXT> Rmgrp
%token<TXT> Rmusr
%token<TXT> Size
%token<TXT> Type
%token<TXT> Ugo
%token<TXT> Unit
%token<TXT> Unmount
%token<TXT> User



%token<TXT> Dfs
%token<TXT> Tfs
%token<TXT> Igual
%token<TXT> Mayor
%token<TXT> Interrogacion
%token<TXT> Asterisco
%token<TXT> PathES
%token<TXT> PathS
%token<TXT> Entero
%token<TXT> Palabra
%token<TXT> PalabraC
%token<TXT> Nnatural
%token<TXT> Ids

%token<TXT> Byte
%token<TXT> Bf
%token<TXT> Extendida
%token<TXT> Ff
%token<TXT> Kilo
%token<TXT> Logica
%token<TXT> Mega
%token<TXT> Primaria
%token<TXT> Wf

%type<NODO> INICIO
%type<NODO> LCMD
%type<NODO> COMANDOS
%type<NODO> PRINCIPALCOM
%type<NODO> SUBCOMAND
%type<NODO> SUB
%type<NODO> CPATH
%type<NODO> CFIT
%type<NODO> CUNIT
%type<NODO> CTYPE
%type<NODO> CFS
%type<NODO> CUSER
%type<NODO> CPASS


%start INICIO
%%
INICIO:LCMD{
    Raiz=$$;
}
;

LCMD:LCMD COMANDOS{
    Nodo * n =new Nodo("LCMD","","");
    n->addHijo($1);
    n->addHijo($2);
    $$=n;
}
|COMANDOS{
    Nodo * n =new Nodo("LCMD","","");
    n->addHijo($1);
    $$=n;
}
;

COMANDOS:PRINCIPALCOM SUBCOMAND{
    Nodo * n =new Nodo("COMANDOS","","");
    n->addHijo($1);
    n->addHijo($2);
    $$=n;
}
;

PRINCIPALCOM:Cat{

}
|Chgrp{

}
|Chmod{

}
|Chown{

}
|Copy{

}
|Edit{

}
|Fdisk{

}
|Find{

}
|Login{

}
|Logout{

}
|Mkdir{

}
|Mkdisk{
    Nodo *n=new Nodo("mkdisk",$1,"");
    $$=n;
}
|Mkfile{

}
|Mkfs{

}
|Mkusr{

}
|Mount{

}
|Move{

}
|Pause{

}
|Remove{

}
|Rename{

}
|Rmdisk{

}
|Rmgrp{

}
|Rmusr{

}
|Unmount{

}
;

SUBCOMAND:SUBCOMAND Mayor SUB{

}
|Mayor SUB{

}
;

SUB:Add Igual Nnatural{

}//
|Cont Igual PathES{

}//
|Delete Igual Full{

}//
|Destino Igual PathS{

}
|FileN Igual PathES{

}//
|Fit Igual CFIT{
    Nodo *n=new Nodo("fit",$3,"");
    $$=n;
}//
|Fs Igual CFS{

}//
|Grp Igual CPASS{

}//
|Id Igual Ids{

}//
|Name Igual Palabra{

}//
|Pass Igual CPASS{

}//
|Path Igual CPATH{
    Nodo *n=new Nodo("path",$3,"");
    $$=n;
}//
|R{

}//
|Size Igual Entero{
    Nodo *n=new Nodo("size",$3,"");
    $$=n;
}//
|Type Igual CTYPE{

}//
|Ugo Igual Entero{

}//
|Unit Igual CUNIT{
    Nodo *n=new Nodo("unit",$3,"");
    $$=n;
}//
|User Igual CUSER{

}//
;

CPATH:PathES{

}
|PathS{

}
;

CFIT:Bf{$$=n;}
|Ff{$$=n;}
|Wf{$$=n;}
;

CUNIT:Byte{$$=n;}
|Kilo{$$=n;}
|Mega{$$=n;}
;

CTYPE:Extendida{

}
|Logica{

}
|Primaria{

}
;

CFS:Tfs{

}
|Dfs{

}
;

CUSER:Palabra{

}
|PalabraC{

}
;

CPASS:Ids{

}
|PalabraC{

}
|Palabra{

}
;