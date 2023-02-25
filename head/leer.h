#ifndef LEER_H
#define LEER_H
using namespace std;
#include <string>
#include <iostream>
#include "struct.h"
class Leer{
    public:
          void leerU(Partition estr);
          void leerD(MBR *estr);

      private:
          Partition partition;
          MBR mbr;
};

#endif // LEER_H