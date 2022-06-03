#include "Tipos.h"


	
void Venta(puntero cab)
{
	FILE* archi,*archi2;
	int u,cod;
	datos producto;
	
	time_t fechaActual; 
	char* fechaenCadena;
	fechaActual = time(0);
		
	fechaenCadena=ctime(&fechaActual);
	
	
	archi=fopen("Productos.dat","r+");
	archi2=fopen("Ventas.txt","a");
	
	MostrarProductos(cab);
	printf("\tIngrese codigo del producto que desea vender\n\t");
	scanf("%d",&cod);
	fflush(stdin);
	
	fseek(archi,((cod-100)/10)*sizeof(datos),SEEK_SET);
	fread(&producto,sizeof(producto),1,archi);
    
    printf("\tIngrese unidades :\n\t");
    scanf("%d",&u);
    
    
    producto.stock=producto.stock-u;
    
    if(producto.stock<0)
    {
    	printf("No hay unidades en existencia\n\t");
	
	} 
	else
	{
		
		fprintf(archi2,"\n%s\040",producto.nom);
		fprintf(archi2,"%d\040",u);
		fprintf(archi2,"%d\040",producto.precio*u);
		fprintf(archi2,"%s\n",fechaenCadena);
		
		fseek(archi,((cod-100)/10)*sizeof(datos),SEEK_SET);
	    fwrite(&producto,sizeof(producto),1,archi);
	}
	
    fclose(archi);
    fclose(archi2);
    
    
}
