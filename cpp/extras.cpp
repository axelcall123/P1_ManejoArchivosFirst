#include "../head/extras.h"
template <class T>
Retorno<T> Extras<T>::error(T arrayStr[], T strComp, string subCo)
{
    bool tf=false;
    for (int a : arrayStr)
    {
        if(a==strComp){
            rtn.tf=true;
            break;
        }
    }
    if(tf==false)
        cout<<"error en "<<subCo<<endl;
    return rtn;
}