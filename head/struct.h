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
    char type=' ';
    string delEte=" ";
    
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
    int mbr_tamano;//tam total del disco
    time_t mbr_fecha_creacion;//fecha creacion
    int mbr_dsk_signature;//numero random
    char dsk_fit;//tipo de ajuste
    Partition mbr_partition_1;//p1
    Partition mbr_partition_2;//p2
    Partition mbr_partition_3;//p3
    Partition mbr_partition_4;//p4
} MBR;

typedef struct{
    char part_status;
    char part_fit;
    int part_start;
    int part_s;
    int part_next;
    char part_name[16];
}EBR;

typedef struct{
    int inicioF=0;//inico free space
    int tamnoD=0;//tamño bytes del disco
    int inicioR=0;//inicio leer el disco
}structFSpace;

template <typename T>
struct Retorno
{
    T str = " ";
    bool tf = false;
};

typedef struct{
    int inicio=0;
    int tamano=0;
    char tipo=' ';
}Vacio;
#endif // STRUCT_H