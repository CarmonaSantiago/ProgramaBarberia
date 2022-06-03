#include "Tipos.h"

void OrdenaLista(puntero xcab)
{
	puntero k,cota,p;
	datos aux;
	cota=NULL;
	k=NULL;
	
	while(k!=xcab)
	{
		k=xcab;
		p=xcab;
		
		while(p->sig!=cota)
		{
			if(strcmp(p->nom , p->sig->nom)>0)
		    {
		    	aux.cod=p->cod;
		    	strcpy(aux.nom,p->nom);
		    	aux.precio=p->precio;
		    	aux.stock=p->stock;
		    	
		    	p->cod=p->sig->cod;
		    	strcpy(p->nom,p->sig->nom);
				p->precio=p->sig->precio;
		    	p->stock=p->sig->stock;
		    	
		    	p->sig->cod=aux.cod;
		    	strcpy(p->sig->nom,aux.nom);
		    	p->sig->precio=aux.precio;
		    	p->sig->stock=aux.stock;
		    	
		    	k=p;
		    	
			}
			p=p->sig;
		
		}
		cota=k->sig;
	}
	
}

