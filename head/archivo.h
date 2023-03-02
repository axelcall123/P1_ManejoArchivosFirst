#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <fstream>
#include <iostream>
#include "struct.h"
#include <vector>
template <class T>
class Archivo
{
    public:
        int crear_archivo(char *path, int tamano, char dim);
        void escribir_archivo(char *path, T estructura, int posicion);
        int tamano_archivo(int tamano, char dim);
        T   leer_struct(char *path,T estructura,int inicio);

        char wType(T estructura);
        vector<Vacio> fSpace(char *path, int tamDisc); // ver el espacio libre que tengo
    private:    
        FILE *abrir_archivo(char *path, char *modo);
};
#endif // ARCHIVO_H