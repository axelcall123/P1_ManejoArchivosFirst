#ifndef STRUCT_H
#define STRUCT_H
using namespace std;
#include <string>
typedef struct
{
    //obligatorio
    int size;
    string path;
    //opcional
    char fit[2];
    char unit;
    //obligatorios::sirve para que tenga los 2 pueda ejecutarse
    bool obligacion[2];

} MkDisk;

#endif // STRUCT_H