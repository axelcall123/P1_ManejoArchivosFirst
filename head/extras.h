#ifndef EXTRAS_H
#define EXTRAS_H
#include <string>
#include "struct.h"
using namespace std;

template <class T>
class Extras
{
    public:
        Retorno<T> error(T arrayStr[], T strComp, string subCo);//saber si el comando tiene algun char o string diferente a lo asignado
        /*
            bf,ff,wf diferente entonces error
        */

    private:
        Retorno<T> rtn;
        
};
#endif // EXTRAS_H