#include "Tipos.h"


void Carga ()
{
	FILE* archivo;
	datos producto;
	fpos_t x;
	archivo= fopen("Productos.dat","a");
	
	
	
	if(archivo!=NULL)
	{
		printf("....................................................................................\n\t");
		printf("\n\tIngrese NOMBRE del Producto Nuevo (Hasta 30 caracteres) \n\n\t");
		gets(producto.nom);
		fflush(stdin);
		
		while(strcmp(producto.nom,"FIN"))
		{
			fseek(archivo,0,SEEK_END);
			fgetpos(archivo,&x);
			
			producto.cod=(int)((x/sizeof(datos))*10)+100;
			
			printf("\n\tIngrese STOCK\n\n\t");
			scanf("%d",&producto.stock);
			if(producto.stock>0 && producto.stock<1000)
			{
				fflush(stdin);
				printf("\n\tIngrese PRECIO\n\n\t");
				scanf("%d",&producto.precio);
				fflush(stdin);
				if(producto.precio>0 && producto.precio<10000)
				{
					fwrite(&producto,sizeof(producto),1,archivo);
					printf("\t-----HECHO-----\n\n");
					system("pause");  
				}
				else
				{
					printf("\tError precio no valido \n");
				}
				
			
			}
			else
			{
				printf("\tError stock no valido \n");
			}
			
            system("cls");
			printf("\n....................................................................................\n");   
			printf("\n\tIngrese NOMBRE del Producto Nuevo (Hasta 30 caracteres/ Para terminar 'FIN') \n\t");
			gets(producto.nom);
			fflush(stdin);
		}

		
			
	}
	else
	{
		printf("\tError al Abrir el archivo\n");
	}
    
	fclose(archivo);
	
}
