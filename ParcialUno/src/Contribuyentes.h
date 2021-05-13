#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef CONTRIBUYENTES_H_
#define CONTRIBUYENTES_H_

#define TAM 20
#define CANTIDAD 50


typedef struct
{
	int iDContribuyente;
	char nombre[TAM];
	char apellido[TAM];
	int cuil;
	int isEmpty;
}eContribuyente;

//Inicializacion
int initContribuyentes(eContribuyente* arrayStruct, int tamanio);

//Alta
void cargaDatosContribuyente(eContribuyente* arrayStruct, int tamanio, int* flagCarga, int* flagId);

int buscarIsEmpty(eContribuyente arrayStruct[], int tamanio, int* auxTamanio);

int addContribuyente(eContribuyente* arrayStruct, int tamanio, char nombre[], char apellido[], int cuil, int iD);








#endif /* CONTRIBUYENTES_H_ */
