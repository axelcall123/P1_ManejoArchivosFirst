#include <iostream>
#include <vector>
using namespace std;
#include "cpp/nodo.cpp"
#include <string.h>
typedef struct
{
	int a = 0;
} uno;
typedef struct
{
	vector<uno> b{};
} dos;
char *charStr(string st){
	char *str2 = new char[st.length() + 1];
	strcpy(str2, st.c_str());
	cout<<str2<<" "<<&str2<<" "<<*str2<<" "<<endl;
	return str2;
}

int main()
{
	uno *ab = new uno;
	delete ab;
	cout << ab->a << "1" << endl;
	ab = new uno;
	ab->a = 15;
	cout << ab->a << "1" << endl;
	delete ab;
	cout << ab->a << "1" << endl;
	ab = new uno;
	cout << ab->a << "1" << endl;
	// vector https://es.stackoverflow.com/questions/138714/c%C3%B3mo-crear-un-arreglo-de-estructuras-din%C3%A1micas-en-c
	auto tam=2;
	vector<dos> cb(tam);//2 dos
	for(auto &jug:cb){
		jug.b.resize(4);//4 uno
	}
	tam=5;
	cb.resize(5);
	for (auto &jug : cb)
	{
		jug.b.resize(2); // 4 uno
	}
	cb.clear();

	// tiempo
	time_t ahora = time(0);
	char *dateTime = ctime(&ahora);
	tm *getTime = gmtime(&ahora);
	dateTime = asctime(getTime);
	cout<<"tiempo: "<<dateTime<<endl;

	//nodo
	Nodo non=Nodo("a");;
	Nodo *nan=new Nodo("b");
	cout<<nan->Token<<" XD"<<endl;
	
	return 0;
}