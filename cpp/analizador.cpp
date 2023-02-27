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

	// PRINCIPALCOM Nombre
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
	else if (raiz->Nombre == "rmkdis")
	{
		ejecutarComando(strLeerComado);
		strLeerComado = "rmkdis";
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
		delete str;
		str=nullptr;
	}
	else if (raiz->Nombre == "name")
	{
		strucEjComando->name = raiz->Token;
	}
	else if (raiz->Nombre == "type")
	{
		char *str = new char[raiz->Token.length() + 1];
		strcpy(str, raiz->Token.c_str());
		strucEjComando->type=*str;
		delete str;
		str = nullptr;
	}
	else if (raiz->Nombre == "delete")
	{
		strucEjComando->delEte=raiz->Token;
	}
	else if (raiz->Nombre == "fit"){
		strucEjComando->fit = raiz->Token;
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
				delete str;
				str=nullptr;
			}
		}
		else if (comando == "mkdisk")
		{
			if (strucEjComando->path != " " && strucEjComando->size != 0) // obligatorio
			{
				
				//comando default
				string fit = "FF";
				char unit = 'M';
				bool error=false;
				// asignar las opcionales si existe asigno
				if (strucEjComando->fit != " ")
				{
					Extras<string> ext;
					Retorno<string> rtn;
					string m[3] = {"BF", "FF", "WF"};
					rtn = ext.error(m, strucEjComando->fit, "fit");
					if(rtn.tf)
						fit=rtn.str;
				}
				if (strucEjComando->unit != ' ')
				{
					Extras<char> ext;
					Retorno<char> rtn;
					char m[3] = {'K', 'M'};
					rtn = ext.error(m, strucEjComando->unit, "unit");
					if (rtn.tf)
						unit = rtn.str;
				}
				Archivo<MBR> arc;
				// char
				char *str = new char[strucEjComando->path.length() + 1];
				strcpy(str, strucEjComando->path.c_str());		
				int ver=arc.crear_archivo(str, strucEjComando->size, unit);
				
				// tamaño disco
				struct stat st;
				stat(str, &st);
				delete str;
				str = nullptr;
				structMbr->mbr_tamano = st.st_size;
				cout<<"tam 1:2>> "<<st.st_size<<" : "<<ver<<endl;
				// tiempo
				structMbr->mbr_fecha_creacion = time(0);
				// random
				structMbr->mbr_dsk_signature = 0 + rand() % (1000000 + 1 - 0);
				// char
				str = new char[1];
				strcpy(str, fit.c_str());
				structMbr->dsk_fit = *str;
				delete str;
				str=nullptr;
				str = new char[strucEjComando->path.length() + 1];
				strcpy(str, strucEjComando->path.c_str());
				arc.escribir_archivo(str, *structMbr, 0);
				//arc.leer_todo(str);
				delete str;
				str = nullptr;
			}
		}else if(comando=="rmdisk"){
			if (strucEjComando->path!=" "){
				char *str = new char[strucEjComando->path.length() + 1];
				strcpy(str, strucEjComando->path.c_str());
				remove(str);
				delete str;
				str = nullptr;
			}
		}
		else if (comando == "fdisk")
		{
			if (strucEjComando->size != 0 && strucEjComando->path != " " && strucEjComando->name != " ") // obligatorio
			{
				//default
				char unit = 'k';
				char type='p';
				string fit="wf";
				bool error;
				if (strucEjComando->unit != ' ')
				{
					Extras<char> ext;
					Retorno<char> rtn;
					char m[3] = {'B','K','M'};
					rtn = ext.error(m, strucEjComando->unit, "unit");
					if (rtn.tf)
						unit = rtn.str;
				}
				if (strucEjComando->type!=' ')
				{
					Extras<char> ext;
					Retorno<char> rtn;
					char m[3] = {'P', 'E','L'};
					rtn = ext.error(m, strucEjComando->unit, "type");
					if (rtn.tf)
						type = rtn.str;
				}
				if (strucEjComando->fit != " ")//string ejcomando
				{
					Extras<string> ext;
					Retorno<string> rtn;
					string m[3] = {"BF", "FF", "WF"};
					rtn = ext.error(m, strucEjComando->fit, "type");
					if (rtn.tf)
						fit = rtn.str;
				}
				//
				Archivo<MBR> arc;
				int tamParticion=arc.tamano_archivo(strucEjComando->size, unit)*1024;
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
					delete str;
					str = nullptr;
					char *str2 = new char[strucEjComando->path.length() + 1];
					strcpy(str2, strucEjComando->path.c_str());
					arc.escribir_archivo(str2, *structMbr, 0);
					delete str2;
					str2 = nullptr;
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
					delete str;
					str = nullptr;
					char *str2 = new char[strucEjComando->path.length() + 1];
					strcpy(str2, strucEjComando->path.c_str());
					arc.escribir_archivo(str2, *structMbr, 0);
					delete str2;
					str2 = nullptr;
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
					delete str;
					str = nullptr;
					char *str2 = new char[strucEjComando->path.length() + 1];
					strcpy(str2, strucEjComando->path.c_str());
					arc.escribir_archivo(str2, *structMbr, 0);
					delete str2;
					str2 = nullptr;
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
					delete str;
					str = nullptr;
					char *str2 = new char[strucEjComando->path.length() + 1];
					strcpy(str2, strucEjComando->path.c_str());
					delete str2;
					str2 = nullptr;
					arc.escribir_archivo(str2, *structMbr, 0);
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
	strucEjComando=nullptr;
	strucEjComando = new structComandos;
}