#include "../head/archivo.h"
int Archivo::tamano_archivo(int tamano, char dim)
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

void Archivo::crear_archivo(char *path, int tamano, char dim)
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
}
FILE *Archivo::abrir_archivo(char *path, char *modo) {
    return fopen(path, modo);
}