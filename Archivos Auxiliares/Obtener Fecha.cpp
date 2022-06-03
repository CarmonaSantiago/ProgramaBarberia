#include <stdio.h>
#include <string.h>
#include <ctime>
#include <malloc.h>
typedef char string [10];

struct datos
{
	char* dia;
	char* mes;
	char num[2];
	char hora[8];
	char anio[4];
};



int main ()
{
	FILE* archi;
	time_t horaActual; 
	char* horaenCadena;
	horaActual = time(0);
	char a[3],m[3];
	string c; 
	datos fecha;
	
	
	horaenCadena=ctime(&horaActual);
	
	
	
	archi=fopen("Hora.txt","a");
	rewind(archi);
	if(archi!=NULL)
	{
		fprintf(archi,"%s",horaenCadena);
		
	}
	fclose(archi);
	archi=fopen("Hora.txt","r");
	rewind(archi);
	fscanf(archi,"%s",&a);
	fscanf(archi,"%s",&m);
	fscanf(archi,"%s",&fecha.num);
    fscanf(archi,"%s",&fecha.hora);
    fscanf(archi,"%s",&fecha.anio);
	{
		if(strcmp(a,"Mon")==0)
	{
		fecha.dia=(char*)malloc(sizeof(char)*5);
		strcpy(fecha.dia,"Lunes");
		
	}
     else if(strcmp(a,"Tue")==0)
	{
		fecha.dia=(char*)malloc(sizeof(char)*6);
		strcpy(fecha.dia,"Martes");
    }
    else if(strcmp(a,"Wed")==0)
	{
		fecha.dia=(char*)malloc(sizeof(char)*9);
		strcpy(fecha.dia,"Miercoles");
	}
    else if(strcmp(a,"Thu")==0)
	{
		fecha.dia=(char*)malloc(sizeof(char)*6);
		strcpy(fecha.dia,"Jueves");
    }
     else if(strcmp(a,"Fri")==0)
	{
		fecha.dia=(char*)malloc(sizeof(char)*7);
		strcpy(fecha.dia,"Viernes");
    }
    else if(strcmp(a,"Sat")==0)
	{
		fecha.dia=(char*)malloc(sizeof(char)*6);
		strcpy(fecha.dia,"Sabado");
    }
	else if(strcmp(a,"Sun")==0)
	{
		fecha.dia=(char*)malloc(sizeof(char)*7);
		strcpy(fecha.dia,"Domingo");
    }
	}
	
	

    {
    	
    	if(strcmp(m,"Jan")==0)
	{
		fecha.mes=(char*)malloc(sizeof(char)*5);
		strcpy(fecha.mes,"Enero");
		
	}
     else if(strcmp(m,"Feb")==0)
	{
		fecha.mes=(char*)malloc(sizeof(char)*7);
		strcpy(fecha.mes,"Febrero");
    }
    else if(strcmp(m,"Mar")==0)
	{
		fecha.mes=(char*)malloc(sizeof(char)*9);
		strcpy(fecha.mes,"Marzo");
	}
    else if(strcmp(m,"Apr")==0)
	{
		fecha.mes=(char*)malloc(sizeof(char)*6);
		strcpy(fecha.mes,"Abril");
    }
     else if(strcmp(m,"May")==0)
	{
		fecha.mes=(char*)malloc(sizeof(char)*7);
		strcpy(fecha.mes,"Mayo");
    }
    else if(strcmp(m,"Jun")==0)
	{
		fecha.mes=(char*)malloc(sizeof(char)*6);
		strcpy(fecha.mes,"Junio");
    }
	else if(strcmp(m,"Jul")==0)
	{
		fecha.mes=(char*)malloc(sizeof(char)*7);
		strcpy(fecha.mes,"Julio ");
    }
    else if(strcmp(m,"Aug")==0)
	{
		fecha.mes=(char*)malloc(sizeof(char)*7);
		strcpy(fecha.mes,"Agosto ");
    }
    else if(strcmp(m,"Sep")==0)
	{
		fecha.mes=(char*)malloc(sizeof(char)*7);
		strcpy(fecha.mes,"Septiembre");
    }
    else if(strcmp(m,"Oct")==0)
	{
		fecha.mes=(char*)malloc(sizeof(char)*7);
		strcpy(fecha.mes,"Octubre");
    }
    else if(strcmp(m,"Nov")==0)
	{
		fecha.mes=(char*)malloc(sizeof(char)*7);
		strcpy(fecha.mes,"Noviembre");
    }else if(strcmp(m,"Dec")==0)
	{
		fecha.mes=(char*)malloc(sizeof(char)*7);
		strcpy(fecha.mes,"Diciembre");
    }
	}



    fflush(stdin);
	fclose(archi);
    fflush(stdout);
	printf("Traduccion\n");

	printf("Hora : %.8s\n",fecha.hora);
	printf("Anio : %s\n",fecha.anio);

	
	return(0);
	
}