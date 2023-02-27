#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <fstream>
#include <iostream>

template <class T>
class Archivo
{
    public:
        int crear_archivo(char *path, int tamano, char dim);
        void escribir_archivo(char *path, T estructura, int posicion);
        void leer_todo(char *path);
        void fSpace(char *path,int tamDisc,int inicio);//inicio desde donde leo
        int tamano_archivo(int tamano, char dim);
        
    private:    
        FILE *abrir_archivo(char *path, char *modo);
        
};
#endif // ARCHIVO_H