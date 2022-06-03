#ifndef Tipos
#define Tipos
using namespace std;
#include <iostream>
#include <iomanip> //  setw (Cantidad caracteres) << alineacion << mostrar
#include <stdio.h>
#include <malloc.h>

#include<stdlib.h>
#include<string.h>
#include <ctime>

typedef char str[30];

struct info
{
	char* dia;
	char* mes;
	char num[2];
	char hora[8];
	char anio[4];
};

struct nodo
{ 
    str nom;
	int precio;
	int stock;
	int cod;   
	struct nodo* sig;
};

typedef struct nodo* puntero;

struct datos
{ 
    str nom;
	int precio;
	int stock;
	int cod;   	
};


void Carga ();

void MostrarProductos(puntero cab);

void MostrarLista(puntero cab);

void CargaLista(puntero &cab);

void EliminarLista(puntero &xcab);

void OrdenaLista(puntero cab);

void Modificar();

void Venta(puntero cab);

void MostrarVentas();

void Traducir(info &f,char xdia[20],char xm[20]);


#endif
