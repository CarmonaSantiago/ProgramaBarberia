#include "Tipos.h"

#include <stdio.h>
//system("pause");  pausa el programa,para continuar debe presionar una tecla 
//system("cls");    borra la pantalla


void menu()
{
	printf("\tSeleccione Operacion\n");
	printf("....................................................................................\n");
	printf("\t1:Venta\n");
	printf("\t2:Modificar datos de un Producto\n");
	printf("\t3:Lista de Productos\n");
	printf("\t4:Cargar Nuevo Producto\n");
	printf("\t5:Balance\n");
	printf("\t0:Terminar\n");
	printf("....................................................................................\n\t");
}

int main() {
	
	puntero cabeza;
	int op;
	
	cabeza=NULL;
	
	printf("\n\t########  BIENVENIDO AL PROGRAMA  #########\n");
	printf("---------------------------------------------------------\n\n");
	
	menu();
	scanf("%d",&op);
	fflush(stdin);
	
	while(op!=0)
	{
		switch(op)
		{
			case 1: 
			    
				Venta(cabeza);
			break;
			       
		    case 2: 
		       MostrarProductos(cabeza);
		       EliminarLista(cabeza);
			   Modificar();
			 break;
		    
			case 3:
				MostrarProductos(cabeza);
			 break;
			
			case 4: 
			   EliminarLista(cabeza);
		       Carga();
			 
			 break;       
	        
			case 5: 
                 MostrarVentas();		   
		     break;
			
				
		}
		printf("\n\n");
		system("pause");
		system("cls");
		menu();
		scanf("%d",&op);
		fflush(stdin);
		
	}
	return 0;
}
