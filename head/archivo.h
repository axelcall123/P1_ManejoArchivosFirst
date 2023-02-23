#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <fstream>
#include <iostream>
class Archivo
{
    public:
        void crear_archivo(char *path, int tamano, char dim);
    private:
        int tamano_archivo(int tamano, char dim);
        FILE *abrir_archivo(char *path, char *modo);
};
#endif // ARCHIVO_H