#include "Tipos.h"
#include <iostream>
#include <iomanip>

void Traducir(info &f,char xdia[20],char xm[20])
{
	int lon;
	
			if(strcmp(xdia,"Mon")==0)
	{
		f.dia=(char*)malloc(sizeof(char)*5);
		strcpy(f.dia,"Lunes");
		
	}
     else if(strcmp(xdia,"Tue")==0)
	{
		f.dia=(char*)malloc(sizeof(char)*6);
		strcpy(f.dia,"Martes");
    }
    else if(strcmp(xdia,"Wed")==0)
	{
		f.dia=(char*)malloc(sizeof(char)*9);
		strcpy(f.dia,"Miercoles");
	}
    else if(strcmp(xdia,"Thu")==0)
	{
		f.dia=(char*)malloc(sizeof(char)*6);
		strcpy(f.dia,"Jueves");
    }
     else if(strcmp(xdia,"Fri")==0)
	{
		f.dia=(char*)malloc(sizeof(char)*7);
		strcpy(f.dia,"Viernes");
    }
    else if(strcmp(xdia,"Sat")==0)
	{
		f.dia=(char*)malloc(sizeof(char)*6);
		strcpy(f.dia,"Sabado");
    }
	else if(strcmp(xdia,"Sun")==0)
	{
		f.dia=(char*)malloc(sizeof(char)*7);
		strcpy(f.dia,"Domingo");
    }
	
		
    	if(strcmp(xm,"Jan")==0)
	{
		f.mes=(char*)malloc(sizeof(char)*5);
		strcpy(f.mes,"Enero");
		
	}
     else if(strcmp(xm,"Feb")==0)
	{
		f.mes=(char*)malloc(sizeof(char)*7);
		strcpy(f.mes,"Febrero");
    }
    else if(strcmp(xm,"Mar")==0)
	{
		f.mes=(char*)malloc(sizeof(char)*9);
		strcpy(f.mes,"Marzo");
	}
    else if(strcmp(xm,"Apr")==0)
	{
		f.mes=(char*)malloc(sizeof(char)*6);
		strcpy(f.mes,"Abril");
    }
     else if(strcmp(xm,"May")==0)
	{
		f.mes=(char*)malloc(sizeof(char)*7);
		strcpy(f.mes,"Mayo");
    }
    else if(strcmp(xm,"Jun")==0)
	{
		f.mes=(char*)malloc(sizeof(char)*6);
		strcpy(f.mes,"Junio");
    }
	else if(strcmp(xm,"Jul")==0)
	{
		f.mes=(char*)malloc(sizeof(char)*7);
		strcpy(f.mes,"Julio ");
    }
    else if(strcmp(xm,"Aug")==0)
	{
		f.mes=(char*)malloc(sizeof(char)*7);
		strcpy(f.mes,"Agosto ");
    }
    else if(strcmp(xm,"Sep")==0)
	{
		f.mes=(char*)malloc(sizeof(char)*7);
		strcpy(f.mes,"Septiembre");
    }
    else if(strcmp(xm,"Oct")==0)
	{
		f.mes=(char*)malloc(sizeof(char)*7);
		strcpy(f.mes,"Octubre");
    }
    else if(strcmp(xm,"Nov")==0)
	{
		f.mes=(char*)malloc(sizeof(char)*7);
		strcpy(f.mes,"Noviembre");
    }
	else if(strcmp(xm,"Dec")==0)
	{
		f.mes=(char*)malloc(sizeof(char)*7);
		strcpy(f.mes,"Diciembre");
    }
	

	
}

void MostrarVentas()
{
	FILE *archi;
	archi=fopen("Ventas.txt","r");
	char prod[20],cant[20];
	char dia[20],m[20];
	char *mesActual;
	int lon,recaudo,total;
	
	info fecha;

	fscanf(archi,"%s\040",&prod);
	fscanf(archi,"%s\040",&cant);
	fscanf(archi,"%d\040",&total);

	fscanf(archi,"%s\040",&dia);
		
	fscanf(archi,"%s\040",&m);
	fscanf(archi,"%s\040",&fecha.num);
	fscanf(archi,"%s\040",&fecha.hora);
	fscanf(archi,"%s\040",&fecha.anio);	

	
	while(feof(archi)==0)
	{
		Traducir(fecha,dia,m);
		
		recaudo=0;
		printf("....................................................................................\n");
		//printf("\tVENTAS MES DE %s\n\n\tFecha\tProducto\tCantidad\tTotal\n\n",fecha.mes);
		cout <<setw(30)<<right<<"VENTAS MES DE\t"<<fecha.mes<<setw(10)<<right<<"\n\n\tFecha\t"<<setw(10)<<"Producto\t\t"<<setw(10)<<"Cantidad"<<setw(10)<<"Total\n"<<endl;
		lon=strlen(fecha.mes);
		mesActual=(char*)malloc(sizeof(char)*lon);
		strcpy(mesActual,fecha.mes);
		
		
	    while(strcmp(fecha.mes,mesActual)==0&&feof(archi)==0)
	    {
			
			printf("\t%.2s\t",fecha.num);
			cout<<setw(30)<<left<<prod<<setw(0)<<left<<cant<<setw(10)<<right<<total<<endl;
			
			//printf("%s\t",prod);
			//printf("%s\t",cant);
			//printf("\t%d\t\n",total);
			recaudo=recaudo+total;
			
			fscanf(archi,"%s",&prod);
			fscanf(archi,"%s",&cant);
			fscanf(archi,"%d",&total);
			fscanf(archi,"%s",&dia);
			fscanf(archi,"%s",&m);
			fscanf(archi,"%s",&fecha.num);
    		fscanf(archi,"%s",&fecha.hora);
    		fscanf(archi,"%s",&fecha.anio);
			Traducir(fecha,dia,m);
			
		}
		printf("\n\t\t\tRecaudo del mes :%d\n",recaudo);
	}
	
}
