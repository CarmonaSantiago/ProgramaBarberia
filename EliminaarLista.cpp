#include "Tipos.h"

void EliminarLista(puntero &xcab)
{
	puntero p;
	while (xcab!=NULL)
	{
		p=xcab;
		xcab=xcab->sig;
		free(p);
		
	}
}

