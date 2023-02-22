%option case-insensitive
%option noyywrap
%option nounput

%{
#include "parser.h"
#include <iostream>

using namespace std;

int yyfila = 1;
int yycolum = 0;
%}
Letra [a-zñA-ZÑ]
LetraE [a-zñ A-ZÑ]


PathUE ([/]{Letra}+)+[.]{Letra}+
PathDE ["]([/]{LetraE}+)+[.]{Letra}+["]
PathU ([/]{Letra}+)+
PathD ["]([/]{LetraE}+)+["]
Entero [0-9]+
Palabra {Letra}({Entero}|{Letra}|".")*
PalabraC ["]{Letra}({Entero}|{LetraE}|".")*["]
NNatural ([+]|[-])?{Entero}
Ids {Entero}{Letra}+

Espacios (" "|"\r"|"\t"|"n")
%%


"cat"               {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Cat;}
"chgrp"             {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Chgrp;}
"chmod"             {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Chmod;}
"chown"             {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Chown;}
"copy"              {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Copy;}
"edit"              {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Edit;}
"fdisk"             {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Fdisk;}
"find"              {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Find;}
"login"             {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Login;}
"logout"            {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Logout;}
"mkdir"             {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Mkdir;}
"mkdisk"            {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Mkdisk;}
"mkfile"            {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Mkfile;}
"mkfs"              {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Mkfs;}
"mkusr"             {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Mkusr;}
"mount"             {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Mount;}
"move"              {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Move;}
"pause"             {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Pause;}
"remove"            {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Remove;}
"rename"            {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Rename;}
"rmdisk"            {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Rmdisk;}
"rmgrp"             {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Rmgrp;}
"rmusr"             {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Rmusr;}
"unmount"           {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Unmount;}


">"                 {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Igual;}
"="                 {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Mayor;}

"add"               {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Add;}
"cont"              {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Cont;}
"delete"            {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Delete;}
"destino"           {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Destino;}
"fileN"             {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return FileN;}
"fit"               {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Fit;}
"fs"                {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Fs;}
"full"              {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Full;}
"grp"               {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Grp;}
"id"                {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Id;}
"name"              {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Name;}
"pass"              {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Pass;}
"path"              {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Path;}
"r"                 {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return R;}
"size"              {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Size;}
"type"              {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Type;}
"ugo"               {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Ugo;}
"unit"              {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Unit;}
"user"              {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return User;}

"B"                 {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Byte;}
"BF"                {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Bf;}
"E"                 {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Extendida;}
"FF"                {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Ff;}
"K"                 {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Kilo;}
"L"                 {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Logica;}
"M"                 {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Mega;}
"P"                 {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Primaria;}
"WF"                {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Wf;}
"2fs"               {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Dfs;}
"3fs"               {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Tfs;}


"?"                 {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Interrogacion;}
"*"                 {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Asterisco;}

{PathUE}|{PathDE}   {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return PathES;}
{PathU}|{PathD}     {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return PathS;}
{Entero}            {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Entero;}
{Palabra}           {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Palabra;}
{PalabraC}          {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return PalabraC;}
{NNatural}          {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Nnatural;}
{Ids}               {yycolum+=yyleng; strcpy(yylval.TXT, yytext); return Ids;}

{Espacios}          { /* Nada */}
.                   {  cout<<"Error lexico, no se esperaba token:   "<<yytext<<yycolum<<yyfila<<endl;}
%%
//{yycolum+=yyleng; strcpy(yylval.TEXT, yytext); return asd;}