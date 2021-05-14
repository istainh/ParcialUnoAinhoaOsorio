#include "Biblioteca.h"
#include "Contribuyentes.h"

#ifndef RECAUDACIONES_H_
#define RECAUDACIONES_H_

typedef struct
{
	int iDRecaudacion;
	int mes;
	int tipo;
	float importe;
	int iDContribuyente;
	int isEmpty;
}eRecaudacion;


void cargaDatosRecaudacion(eRecaudacion* arrayStruct, int tamanio, int* flagCarga, int* flagId, int* iDContribuyente);

int buscarIsEmpty(eRecaudacion arrayStruct[], int tamanio, int* auxTamanio);

int addRecaudacion(eRecaudacion* arrayStruct, int tamanio, int mes, int tipo, int iD, float importe, int iDContribuyente);



#endif /* RECAUDACIONES_H_ */
