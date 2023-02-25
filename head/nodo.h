#ifndef NODO_H
#define NODO_H
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Nodo
{
public:
    Nodo(const string &token);
    Nodo(const string& nombre, const string& token, const string& tipo);
    string Nombre;
    string Token;
    string Tipo;
    vector<Nodo*> Hojas;
    void addHijo(Nodo* hoja);
};

#endif // NODO_H
