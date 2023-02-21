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
Entero [0-9]+

Palabra {Letra}({Entero}|{Letra}|".")*

PathUE ([/]{Letra}+)+[.]{Letra}+
PathDE ["]([/]{LetraE}+)+[.]{Letra}+["]

PathU ([/]{Letra}+)+
PathD ["]([/]{LetraE}+)+["]

Espacios (" "|"\r"|"\t"|"n")
%%


"cat"               {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return cat;}
"chgrp"             {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return chgrp;}
"chmod"             {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return chmod;}
"chown"             {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return chown;}
"copy"              {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return copy;}
"edit"              {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return edit;}
"fdisk"             {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return fdisk;}
"find"              {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return find;}
"login"             {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return login;}
"logout"            {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return logout;}
"mkdir"             {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return mkdir;}
"mkdisk"            {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return mkdisk;}
"mkfile"            {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return mkfile;}
"mkfs"              {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return mkfs;}
"mkusr"             {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return mkusr;}
"mount"             {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return mount;}
"move"              {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return move;}
"pause"             {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return pause;}
"remove"            {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return remove;}
"rename"            {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return rename;}
"rmdisk"            {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return rmdisk;}
"rmgrp"             {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return rmgrp;}
"rmusr"             {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return rmusr;}
"unmount"           {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return unmount;}


">"                 {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return igual;}
"="                 {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return mayor;}

"add"               {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return add;}
"cont"              {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return cont;}
"delete"            {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return delete;}
"destino"           {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return destino;}
"fileN"             {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return fileN;}
"fit"               {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return fit;}
"fs"                {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return fs;}
"grp"               {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return grp;}
"id"                {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return id;}
"name"              {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return name;}
"pass"              {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return pass;}
"path"              {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return path;}
"r"                 {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return r;}
"size"              {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return size;}
"type"              {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return type;}
"ugo"               {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return ugo;}
"unit"              {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return unit;}
"user"              {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return user;}

"BF"                {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return bf;}
"E"                 {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return bf;}
"FF"                {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return ff;}
"K"                 {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return kilo;}
"L"                 {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return bf;}
"M"                 {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return mega;}
"P"                 {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return bf;}
"WF"                {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return wf;}


"?"                 {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return interrogacion;}
"*"                 {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return asterisco;}

{PathUE}|{PathDE}   {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return pathES;}
{PathU}|{PathD}     {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return pathS;}
{Entero}            {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return entero;}
{Palabra}           {  yycolum+=yyleng; strcpy(yylval.TXT, yytext); return palabra;}

{Espacios}          { /* Nada */}
.                   {  cout<<"Error lexico, no se esperaba token:   "<<yytext<<yycolum<<yyfila<<endl;}
%%
//{  yycolum+=yyleng; strcpy(yylval.TEXT, yytext); return asd;}
//ar