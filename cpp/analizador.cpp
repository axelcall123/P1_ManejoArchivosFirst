#include "../head/analizador.h"
void Analizador::leerC(char *paths)
{
	FILE *in;
	Nodo *raiz = nullptr;
	//leer txt
	in = fopen(paths, "r");
	yyrestart(in); // Lexico
	yyparse();	   // Sintactico
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
	if (raiz->Nombre == "FINAL")
	{
		recorrer(raiz->Hojas[0]);
		recorrer(raiz->Hojas[1]);
	}
	else if (raiz->Nombre == "LCMD")
	{
		switch (raiz->Hojas.size())
		{
			// COMANDOS
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
	else if (raiz->Nombre == "SUBCOMAND")
	{
		// Mayor SUB
		switch (raiz->Hojas.size())
		{
		case 1:
			recorrer(raiz->Hojas[0]);
			break;
		case 2:
			// SUBCOMAND:SUBCOMAND Mayor SUB
			recorrer(raiz->Hojas[0]);
			recorrer(raiz->Hojas[1]);
			break;
		}
	}
	// PRINCIPALCOM
	else if (raiz->Nombre == "execute")
	{
		ejecutarComando(strLeerComado);
		strLeerComado = "execute";
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
	else if (raiz->Nombre == "rep")
	{
		ejecutarComando(strLeerComado);
		strLeerComado = "rep";
	}
	// SUBCOMAND Token
	else if (raiz->Nombre == "size")
	{
		strucEjComando->size = stoi(raiz->Token); // str->int
	}
	else if (raiz->Nombre == "path")
	{
		strucEjComando->path = raiz->Token;

	}
	else if (raiz->Nombre == "unit")
	{

		char *str = new char[raiz->Token.length() + 1];
		strcpy(str, raiz->Token.c_str());
		strucEjComando->unit = *str;
	}
	else if (raiz->Nombre == "name")
	{
		strucEjComando->name = raiz->Token;
	}
	
	// EXCEPCIONES
	else if (raiz->Nombre == "thend")
	{
		ejecutarComando(strLeerComado);
	}
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
				strLeerComado=" ";
				leerC(str);
			}
		}
		else if (comando == "mkdisk")
		{
			if (strucEjComando->path != " " && strucEjComando->size != 0) // obligatorio
			{
				string fit = "FF";
				char unit = 'M';
				// asignar las opcionales si existe asigno
				if (strucEjComando->fit != " ")
				{
					fit = strucEjComando->fit;
				}
				if (strucEjComando->unit != ' ')
				{
					unit = strucEjComando->unit;
				}
				Archivo<MBR> arc;
				// char
				char *str = new char[strucEjComando->path.length() + 1];
				strcpy(str, strucEjComando->path.c_str());		
				arc.crear_archivo(str, strucEjComando->size, unit);
				delete str;
				// tamaño
				struct stat st;
				stat(str, &st);
				structMbr->mbr_tamano = st.st_size;
				// tiempo
				structMbr->mbr_fecha_creacion = time(0);
				// random
				structMbr->mbr_dsk_signature = 0 + rand() % (1000000 + 1 - 0);
				// char
				str = new char[1];
				strcpy(str, fit.c_str());
				structMbr->dsk_fit = *str;
				delete str;
				str = new char[strucEjComando->path.length() + 1];
				strcpy(str, strucEjComando->path.c_str());
				arc.escribir_archivo(str, *structMbr, 0);
				//arc.leer_todo(str);
			}
		}
		else if (comando == "fdisk")
		{
			if (strucEjComando->size != 0 && strucEjComando->path != " " && strucEjComando->name != " ") // obligatorio
			{
				char unit = 'K';
				if (strucEjComando->unit != ' ')
				{
					unit = strucEjComando->unit;
				}
				//
				Archivo<MBR> arc;
				int tamParticion=arc.tamano_archivo(strucEjComando->size, strucEjComando->unit);
				//get nombre
				
				char strA[16];
				// uno a uno particion
				if (structMbr->mbr_partition_1.part_s ==0)
				{
					structMbr->mbr_partition_1.part_start='F';
					structMbr->mbr_partition_1.part_type='P';
					structMbr->mbr_partition_1.part_fit='W';
					structMbr->mbr_partition_1.part_start = 0;
					structMbr->mbr_partition_1.part_s = tamParticion; // FIXME:arreglar esto

					char *str = new char[16];
					strcpy(str, strucEjComando->name.c_str());

					nameParticion(structMbr->mbr_partition_1.part_name, str);
					char *str2 = new char[strucEjComando->path.length() + 1];
					strcpy(str, strucEjComando->path.c_str());
					arc.escribir_archivo(str, *structMbr, 0);
					
				}
				else if (structMbr->mbr_partition_2.part_s ==0)
				{
					structMbr->mbr_partition_2.part_start = 'F';
					structMbr->mbr_partition_2.part_type = 'P';
					structMbr->mbr_partition_2.part_fit = 'W';
					structMbr->mbr_partition_2.part_start = 0;
					structMbr->mbr_partition_2.part_s = tamParticion; // FIXME:arreglar esto

					char *str = new char[16];
					strcpy(str, strucEjComando->name.c_str());

					nameParticion(structMbr->mbr_partition_2.part_name, str);

					char *str2 = new char[strucEjComando->path.length() + 1];
					strcpy(str, strucEjComando->path.c_str());
					arc.escribir_archivo(str, *structMbr, 0);
				}
				else if (structMbr->mbr_partition_3.part_s ==0)
				{
					structMbr->mbr_partition_3.part_start = 'F';
					structMbr->mbr_partition_3.part_type = 'P';
					structMbr->mbr_partition_3.part_fit = 'W';
					structMbr->mbr_partition_3.part_start = 0;
					structMbr->mbr_partition_3.part_s = tamParticion; // FIXME:arreglar esto

					char *str = new char[16];
					strcpy(str, strucEjComando->name.c_str());

					nameParticion(structMbr->mbr_partition_3.part_name, str);

					char *str2 = new char[strucEjComando->path.length() + 1];
					strcpy(str, strucEjComando->path.c_str());
					arc.escribir_archivo(str, *structMbr, 0);
				}
				else if (structMbr->mbr_partition_4.part_s ==0)
				{
					structMbr->mbr_partition_4.part_start = 'F';
					structMbr->mbr_partition_4.part_type = 'P';
					structMbr->mbr_partition_4.part_fit = 'W';
					structMbr->mbr_partition_4.part_start = 0;
					structMbr->mbr_partition_4.part_s = tamParticion; // FIXME:arreglar esto

					char *str = new char[16];
					strcpy(str, strucEjComando->name.c_str());

					nameParticion(structMbr->mbr_partition_4.part_name, str);

					char *str2 = new char[strucEjComando->path.length() + 1];
					strcpy(str, strucEjComando->path.c_str());
					arc.escribir_archivo(str, *structMbr, 0);
					Leer reaD;
					reaD.leerD(structMbr);
				}

			}
		}
	}
	vaciarComando();
}
void Analizador::nameParticion(char *strU[], char strD[])
{
	for(int i=0;i<16;i++){
		strU[0]=&strD[0];
	}
}
void Analizador::vaciarComando()
{
	delete strucEjComando;
	strucEjComando = new structComandos;
}