#ifndef STRUCT_H
#define STRUCT_H
using namespace std;
#include <string>
#include <vector>
// var tipo tiempo
#include <time.h>
typedef struct
{
    int size=0;
    string path=" ";
    string fit=" ";
    char unit=' ';
    string name=" ";
    
} structComandos;
typedef struct
{
    char part_status;
    char part_type;
    char part_fit;
    int part_start;
    int part_s=0;
    char *part_name[16];
} Partition;
typedef struct 
{
    int mbr_tamano;
    time_t mbr_fecha_creacion;
    int mbr_dsk_signature;
    char dsk_fit;
    Partition mbr_partition_1;
    Partition mbr_partition_2;
    Partition mbr_partition_3;
    Partition mbr_partition_4;
} MBR;
typedef struct{
    char part_status;
    char part_fit;
    int part_start;
    int part_s;
    int part_next;
    char part_name[16];
}EBR;
#endif // STRUCT_H