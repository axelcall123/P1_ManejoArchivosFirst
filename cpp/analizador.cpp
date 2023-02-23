#include "../head/analizador.h"
void Analizador::leerC(char *paths)
{
    FILE *in;
    Nodo *raiz = nullptr;
    in = fopen(paths, "r");
    yyrestart(in); // Lexico
    yyparse();     // Sintactico
    raiz = getRaiz();
    if (raiz != nullptr)
    {
        recorrer(raiz);
    }
    fclose(in);
}
void Analizador::recorrer(Nodo *raiz)
{
    // LCMD
    if (raiz->Nombre == "LCMD")
    {
        switch (raiz->Hojas.size())
        {
        case 1:
            recorrer(raiz->Hojas[0]);
            break;
        case 2:
            // LCMD:LCMD COMANDOS
            recorrer(raiz->Hojas[0]);
            recorrer(raiz->Hojas[1]);
            break;
        }
    }
    else if (raiz->Nombre == "COMANDOS")
    {
        // COMANDOS:PRINCIPALCOM SUBCOMAND
        recorrer(raiz->Hojas[0]);
        recorrer(raiz->Hojas[1]);
    }
    // PRINCIPALCOM
    else if (raiz->Nombre == "execute")
    {
    }
    else if (raiz->Nombre == "mkdisk")
    {
        ejecutarComando(strLeerComado);
        strLeerComado = "mkdisk";
    }
    else if (raiz->Nombre == "fdisk")
    {
        ejecutarComando(strLeerComado);
        strLeerComado = "fdisk";
    }
    // SUBCOMAND
    else if (raiz->Nombre == "size")
    {
        strucEjComando->size = stoi(raiz->Nombre); // str->int
    }
    else if (raiz->Nombre == "path")
    {
        strucEjComando->path = raiz->Nombre;
    }
    else if (raiz->Nombre == "unit")
    {
        char *char_array = new char[raiz->Nombre.length() + 1];
        strcpy(char_array, raiz->Nombre.c_str());
        strucEjComando->unit = *char_array;
    }
    else if (raiz->Nombre == "path")
    {
        strucEjComando->path = raiz->Nombre;
    }
    // EXCEPCIONES
}
void Analizador::ejecutarComando(string comando)
{
    if (comando != "")
    { // difrente primer comando
        if (comando == "execute")
        {
            if (strucEjComando->path != "")
            { // tiene los obligatorios
                char *str = new char[strucEjComando->path.length() + 1];
                strcpy(str, strucEjComando->path.c_str());
                leerC(str);
            }
        }
        else if (comando == "mkdisk")
        {
            if (strucEjComando->path != " " && strucEjComando->size != 0)
            {
                string fit = "FF";
                char unit = 'M';
                // asignar las opcionales
                if (strucEjComando->fit != " ")
                {
                    fit = strucEjComando->fit;
                }
                if (strucEjComando->unit != ' ')
                {
                    unit = strucEjComando->unit;
                }
                Archivo arc;
                // char
                char *str = new char[strucEjComando->path.length() + 1];
                strcpy(str, strucEjComando->path.c_str());
								delete str;
                arc.crear_archivo(str, strucEjComando->size, unit);
                // tamaño
                struct stat st;
                stat(str, &st);
                structMbr->mbr_tamano = st.st_size;
                // tiempo
                structMbr->mbr_fecha_creacion = time(0);
                // random
                structMbr->mbr_dsk_signature = 0 + rand() % (1000000 + 1 - 0);
								//char
								str = new char[1];
								strcpy(str, fit.c_str());
								structMbr->dsk_fit=*str;
								

						}
        }
        else if (comando == "fdisk")
      	{

        }
    }
    vaciarComando();
}
void Analizador::vaciarComando()
{
    delete strucEjComando;
    strucEjComando = new structComandos;
}