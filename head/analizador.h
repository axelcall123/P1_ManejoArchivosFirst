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
//mis
#include "../cpp/nodo.cpp"
#include "../flexbison/parser.cpp"
class Analizador{
    public:
        void leerC(char *in);
        void ejecutar(Nodo *raiz);
        void recorrer(Nodo *raiz);
        void ejecutarComando();
};
#endif // ANALIZADOR_H