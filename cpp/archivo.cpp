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
    char tipo = wType<T>(estructura);
    cout << "Creando struc tam: ";
    cout << sizeof(T) << endl;
    fseek(archivoBinario, posicion, SEEK_SET); // bloque struc + tipo
    char escritura[2] = {'/', tipo};
    // inicio
    fwrite(&escritura, sizeof(escritura), 1, archivoBinario); // /tipo
    // struct
    fwrite(&estructura, sizeof(estructura), 1, archivoBinario); // [estruct]
    // final
    escritura[2] = {tipo,'\\'};
    fwrite(&escritura, sizeof(escritura), 1, archivoBinario);/*\*/
    fclose(archivoBinario);
    /*/n[estructura]\*/
}

template <class T>
T Archivo<T>::leer_struct(char *path, T estructura, int inicio)
    {
        while (!feof(archivoBinario))
        {
            fseek(archivoBinario, inicio, SEEK_SET);                   // corremos cont posiciones{profe+tipo}
            fread(&estructura, sizeof(estructura), 1, archivoBinario); // lee solo la estructura
        }
        fclose(archivoBinario);
        return estructura;
    }

template <>
char Archivo<MBR>::wType(MBR estructura)
{
    return 'm';
}

template <class T>
vector<Vacio> Archivo<T>::fSpace(char *path, int tamDisc)
{
    char cFile[tamFile * 1024];
    archivoBinario = abrir_archivo(path,"rb+");
    fseek(archivoBinario, 0, SEEK_SET);
    fread(&cFile, tamFile * 1024, 1, archivoBinario);
    int conteo=0;
    int inicio=0;
    vector<Vacio> vVacio(0);
    vector<char> vChar(0);
    vChar.push_back('$');

    for (int i = 0; i < tamFile * 1024; i++)
    {
            if (bitset<8>(cFile[i]).to_string() != "00000000")//vacio
            {
                cout << cFile[i];
                if(cFile[i]=="/"){// /m
                    vChar.push_back(cFile[i+1]);
                    inicio=i;
                }else if(cFile[i]=="\\"){/*\m*/    
                    Vacio vc;
                    vc.inicio=inicio;
                    vc.tamano=conteo;
                    vc.tipo=vChar.back();
                    vChar.pop_back();
                    vVacio.push_back(vc);
                }
                conteo=0;
            }
            else//leno
            {
                conteo++;
            }
            if(vChar.size()==0)//contar afuera de todo
                vChar.push_back('$');
    }
    return vc;
}
