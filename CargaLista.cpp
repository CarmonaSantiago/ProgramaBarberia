#include "Tipos.h"


void CargaLista (puntero &cab)
{
	FILE* archivo;
	puntero p,nuevo,anterior;
	datos producto;
	
	archivo=fopen("Productos.dat","r");
	
	if(archivo!=NULL)
	{
		fseek(archivo,0,SEEK_SET);
		
		while(fread(&producto,sizeof(producto),1,archivo))
		{
			nuevo=(puntero)malloc(sizeof(struct nodo));
			
			strcpy(nuevo->nom,producto.nom);
			nuevo->cod=producto.cod;
			nuevo->stock=producto.stock;
			nuevo->precio=producto.precio;
			
			nuevo->sig=NULL;
			
			if(cab==NULL)
			{
				cab=nuevo;
				
			}
			else
			{
			    p=cab;
			    
				while(p!=NULL)
			    {
			    	anterior=p;
					p=p->sig;
				}
			    anterior->sig=nuevo;
			}		
		}
			
	}
	
	
}
