using namespace std;
#include <string>
// cout
#include <iostream>
#include "cpp/analizador.cpp"
// strcpy
#include <string.h>
int main(int argc, char *argv[])
{
	string Entrada;
	FILE *in;
	while (!(Entrada.compare("exit") == 0))
	{
		cout << "INGRESE COMANDO INCIAL" << endl;
		cout << "[MIA]@201901458:~$ ";
		getline(cin, Entrada);
		in = fopen("Inicial.txt", "w");
		char *str = new char[Entrada.length() + 1];
		strcpy(str, Entrada.c_str());
		if (in)
		{
			for (int i = 0; i < strlen(str); i++)
			{
				putc(str[i], in);
			}
		}
		delete str;
		str=nullptr;
		Analizador analizador;
		fclose(in);
		analizador.leerC("Inicial.txt");
	}
	return 0;
} // execute >path=/media/alexgg/DATA/ALEX/U/prueba.eea