#include "Recaudaciones.h"

void cargaDatosRecaudacion(eRecaudacion* arrayStruct, int tamanio, int* flagCarga, int* flagId, int* iDContribuyente)
{
	int posicion;
	int mes;
	int tipo;
	float importe;
	int iD;
	int flagAux;

	int iDContribuyenteAux=iDContribuyente;

	eRecaudacion auxStruct;

	if(buscarIsEmpty(arrayStruct, tamanio, &posicion))
	{
		if(utn_getNumero(&mes, "Ingrese el mes de la recaudación:\n", "Error al ingresar el mes. Intente de nuevo.\n", 1, 12, 5)&&
           utn_getFloat(&importe, "Ingrese el importe de las recaudación", "Error al ingresar el importe de la recaudación", 100.99, 10000.99, 5)
		   &&utn_getNumero(&tipo, "Ingrese un tipo de recaudación:\n [1]-ARBA\n [2]-IIBB\n [3]-GANANCIAS\n", "Ingrese una opción válida", 1, 3, 5)&&obtenerId(&flagAux, 100, &iD))
		{
			if(addRecaudacion(arrayStruct, tamanio, mes, tipo, iD, importe, iDContribuyente))
			{
				arrayStruct[posicion]=auxStruct;
				printf("Se cargó exitosamente la reacudacion %d\n", iD);
				*flagCarga=1;
				*flagId=flagAux;
			}
		}
		else
		{
			printf("Hubo algún error en el ingreso de alguno de los datos.\n");
		}
	}
	else
	{
		printf("Intente dar de baja alguna recaudacion para poder cargar.\n");
	}
}

//Funciones para dar de alta

int buscarIsEmpty(eRecaudacion arrayStruct[], int tamanio, int* auxTamanio)
{
	int i;
	int retorno=0;
	if(arrayStruct!=NULL&&tamanio>0)
	{
		for(i=0;i<tamanio;i++)
		{
			if(arrayStruct[i].isEmpty==1)
			{
				*auxTamanio=i;
				retorno=1;
				break;
			}
			else
			{
				printf("No hay más espacio para cargar. \n");
			}
		}
	}
	return retorno;
}

int addRecaudacion(eRecaudacion* arrayStruct, int tamanio, int mes, int tipo, int iD, float importe, int iDContribuyente)
{
	int retorno=0;

	if(arrayStruct!=NULL&&tamanio>0)
	{
		arrayStruct[tamanio].mes=mes;
		arrayStruct[tamanio].tipo=tipo;
		arrayStruct[tamanio].iDRecaudacion=iD;
		arrayStruct[tamanio].importe=importe;
		arrayStruct[tamanio].iDContribuyente=iDContribuyente;
		arrayStruct[tamanio].isEmpty=0;
		retorno=1;
	}
	return retorno;
}
