#ifndef ARCHIVO1_H
#define ARCHIVO1_H
#include <fstream>
#include <iostream>

template <class T>
class Archivo
{
    public:
        void crear_archivo(char *path, int tamano, char dim);
        void escribir_archivo(char *path, T estructura, int posicion);
        void leer_todo(char *path);
        int tamano_archivo(int tamano, char dim);

    private:    
        FILE *abrir_archivo(char *path, char *modo);
};
#endif // ARCHIVO1_H