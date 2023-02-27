#include "../head/archivo.h"
// https://youtu.be/yrDIuzNCEEI
template <class T>
int Archivo<T>::tamano_archivo(int tamano, char dim)
{
    // tamaño del archivo
    int tamFile = 0;
    dim = tolower(dim);
    if (dim == 'k')
    {
        return tamano;
    }
    else if (dim == 'm')
    {
        return tamano * 1024;
    }
    else if (dim == 'g')
    {
        return tamano * 1024 * 1024;
    }
    return 0;
}

template <class T>
int Archivo<T>::crear_archivo(char *path, int tamano, char dim)
{
    // tamaño del archivo
    int tamFile = tamano_archivo(tamano, dim);
    // bloque
    char bloque[1024];
    for (int i = 0; i < 1024; i++)
    {
        bloque[i] = '\0';
    }
    // escritura de bloque en el archivo
    int limite = 0;
    FILE *archivoBinario = abrir_archivo(path, "w");
    // archivoBinario = fopen("T1.dsk", "w");
    while (limite != tamFile)
    {
        fwrite(&bloque, 1024, 1, archivoBinario);
        limite++;
    }
    fclose(archivoBinario);
    delete archivoBinario;
    archivoBinario=nullptr;
    return tamFile*1024;
}

template <class T>
FILE *Archivo<T>::abrir_archivo(char *path, char *modo)
{
    return fopen(path, modo);
}

template <class T>
void Archivo<T>::escribir_archivo(char *path, T estructura, int posicion)
{
    // tamaño del archivo
    FILE *archivoBinario = abrir_archivo(path, "rb+");
    // archivoBinario = fopen("T1.dsk", "rb+");

    cout << "Creando struc tam: ";
    cout << sizeof(T) << endl;                         // devuelve caracter que separa el tipo
    fseek(archivoBinario, posicion * (sizeof(T)), SEEK_SET);    // bloque struc + tipo
    fwrite(&estructura, sizeof(estructura), 1, archivoBinario); // escribe struct
    fclose(archivoBinario);
}

template <class T>
void Archivo<T>::leer_todo(char *path)
{
    
}