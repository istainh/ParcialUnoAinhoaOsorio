#include "Biblioteca.h"

#ifndef CONTRIBUYENTES_H_
#define CONTRIBUYENTES_H_


typedef struct
{
	int iDContribuyente;
	char nombre[MAX];
	char apellido[MAX];
	int cuil;
	int isEmpty;
}eContribuyente;

//Inicializacion
int initContribuyentes(eContribuyente* arrayStruct, int tamanio);

//Alta
void cargaDatosContribuyente(eContribuyente* arrayStruct, int tamanio, int* flagCarga, int* flagId);
int addContribuyente(eContribuyente* arrayStruct, int tamanio, char nombre[], char apellido[], int cuil, int iD);

//Baja
void darBaja(eContribuyente arrayStruct[], int tamanio);

//Imprimir
void mostrarDatosStruct(eContribuyente arrayStruct[], int tamanio);

//Busqueda
int buscarContribuyenteConId (eContribuyente arrayStruct, int tamanio, int iD, int* posicion);
void revizarIsEmpty(eContribuyente arrayStruct[], int tamanio, int* flag);
int buscarIsEmpty(eContribuyente arrayStruct[], int tamanio, int* auxTamanio);

//Modificar
void menuModificador(eContribuyente arrayStruct[], int tamanio);











#endif /* CONTRIBUYENTES_H_ */
