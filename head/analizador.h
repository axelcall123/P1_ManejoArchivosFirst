#ifndef ANALIZADOR_H
#define ANALIZADOR_H
using namespace std;
#include <string>
// var tipo tiempo
#include <time.h>
// medir tamño archivo
#include <sys/stat.h>
// tiempo
#include <chrono>
// mis
#include "../cpp/nodo.cpp"
#include "../cpp/archivo.cpp"
#include "../flexbison/parser.cpp"
#include "../cpp/leer.cpp"
#include "struct.h"


class Analizador
{
private:
    string strLeerComado = " "; // comando que se esta leyendo en este momento

public:
    structComandos *strucEjComando = new structComandos;
    MBR *structMbr=new MBR;
    void leerC(char *in);
    void ejecutar(Nodo *raiz);
    void recorrer(Nodo *raiz);
    void ejecutarComando(string comando);
    void vaciarComando();
private:
    void nameParticion(char *strU[],char strD[]);
};
#endif // ANALIZADOR_H