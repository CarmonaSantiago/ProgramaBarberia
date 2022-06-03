#include "Tipos.h"

void Modificar()
{
	int cod;
	int opc;
	char* c;
	string nom;
	FILE* archi;
	fpos_t x;
	datos producto;
	
	
	archi=fopen("Productos.dat","r+");
	if(archi!=NULL)
	{
		printf("\tIngrese codigo del producto que desea modificar\n");
		scanf("%d",&cod);
		fflush(stdin);
		fgetpos(archi,&x);
		fseek(archi,((cod-100)/10)*sizeof(datos),SEEK_SET);
		fread(&producto,sizeof(producto),1,archi);
		
		printf("\tQue dato desea modificar?\n");
	
		printf("\t1:nombre\n");
		printf("\t2:precio\n");
		printf("\t3:stock\n");
		printf("\t0:Terminar\n\t");
		scanf("%d",&opc);
		fflush(stdin);
	   
	   while(opc)
	   {
	      switch(opc)
		   {
				case 1:
					printf("\tIngrese nuevo nombre:\n\t");
					gets(producto.nom);
					fflush(stdin);
					fseek(archi,((cod-100)/10)*sizeof(datos),SEEK_SET);
					fwrite(&producto,sizeof(producto),1,archi);
			
				break;
		
				case 2:
					printf("\tIngrese nuevo precio:\n\t");
					scanf("%d",&producto.precio);
					fflush(stdin);
					fgetpos(archi,&x);
					if(producto.precio>0 && producto.precio<10000)
					{
						fseek(archi,x-sizeof(datos),SEEK_SET);
						fwrite(&producto,sizeof(producto),1,archi);
					}
					else
					{
						printf("\t #Error datos ingresados invalidos\n");
					}	
				break;
					
				case 3:
					printf("\tIngrese nuevo stock:\n\t");
					scanf("%d",&producto.stock);
					if((producto.stock>0 && producto.stock<1000))
					{
						fseek(archi,((cod-100)/10)*sizeof(datos),SEEK_SET);
			            fwrite(&producto,sizeof(producto),1,archi);
					}
					else
					{
						printf("Error stock ingresado no valido");
					}
					fflush(stdin);
				break;
		
			}
				
	   	    printf("\tQue otro dato desea modificar?\n");
	
			printf("\t1:nombre\n");
			printf("\t2:precio\n");
			printf("\t3:stock\n");
			printf("\t0:Terminar\n\t");
			scanf("%d",&opc);
	   }
	   
	}
	fclose(archi);
	
}
