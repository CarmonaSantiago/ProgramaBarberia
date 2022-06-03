#include "Tipos.h"
#include <iostream> //  cin cout << mostrar<<endl;


using namespace std;
//carga una lista , la ordena y la muestra

void MostrarLista(puntero xcab)
{
	   
    puntero p;
    char* c;
    int lon;
    
	
	printf("....................................................................................\n\t");
	printf("\n\tLista de Productos\n\n");
	cout<<setw(30)<<left<<"\tProducto"<<setw(10)<<"Precio"<<setw(10)<<"Stock"<<setw(10)<<"Codigo\n"<<endl;
	
	p=xcab;
	
	while(p!=NULL)
	{
		lon=strlen(p->nom);
		c=(char*)malloc(sizeof(char)*lon);
		strcpy(c,p->nom);
		
		cout <<"\t"<<setw(30)<<left<<c<<setw(0)<<left<<"$"<<p->precio<<setw(10)<<right<<p->stock<<setw(10)<<right<<p->cod<<endl;
	
		p=p->sig;
	}
	printf("\n....................................................................................\n\t");
}


void MostrarProductos (puntero cab)
{	
	if(cab==NULL)
	{
		CargaLista(cab);
		OrdenaLista(cab);	
	} 
    MostrarLista(cab);

}
