#include "../head/leer.h"

void Leer::leerU(Partition estr){
    cout << "PARTITION:";
    cout << *estr.part_name<<" "<<estr.part_s <<"|";
};
void Leer::leerD(MBR *estr)
{
    cout << "MNR:";
    char *dateTime = ctime(&estr->mbr_fecha_creacion);
    tm *getTime = gmtime(&estr->mbr_fecha_creacion);
    dateTime = asctime(getTime);

    cout << estr->mbr_dsk_signature <<" "<< dateTime << "|";
    delete dateTime;//puede sobre escribir cont
    delete getTime;
    dateTime=nullptr;//puedo apuntar donde quiera
    getTime=nullptr;
    leerU(estr->mbr_partition_1);
    leerU(estr->mbr_partition_2);
    leerU(estr->mbr_partition_3);
    leerU(estr->mbr_partition_4);
};