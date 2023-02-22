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
    ejecutarComando();
}
void Analizador::recorrer(Nodo *raiz)
{   
    
}
void Analizador::ejecutarComando()
{

}
