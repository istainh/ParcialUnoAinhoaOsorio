#include "Contribuyentes.h"



//Inicializar

int initContribuyentes(eContribuyente* arrayStruct, int tamanio)
{
	int retorno=-1;
	int i;

	if(arrayStruct!=NULL)
	{
		for(i=0;i<tamanio;i++)
		{
			arrayStruct[i].isEmpty=1;
			retorno=0;
		}
	}
	return retorno;
}

//Alta

void cargaDatosContribuyente(eContribuyente* arrayStruct, int tamanio, int* flagCarga, int* flagId)
{
	int posicion;
	char nombre[TAM];
	char apellido[TAM];
	int cuil;
	int iD;
	int flagIdDos=flagId;
	eContribuyente auxStruct;

	if(buscarIsEmpty(arrayStruct, tamanio, &posicion))
	{
		if(utn_getString("Ingrese el nombre del contribuyente: \n","Error al ingresar el nombre del contribuyente. Intentelo de nuevo: \n", nombre, 2)&&
		   utn_getString("Ingrese el apellido del contribuyente: \n", "Error al ingresar el apellido del contribuyente. Intentelo de nuevo: \n", apellido, 2)&&
		   getCuil(cuil, "Ingrese el CUIL del contribuyente:\n", "Error al ingresar el CUIL. Intente de nuevo:\n", 5)&&obtenerId(&flagIdDos, 1000, &iD))
		{
			if(addContribuyente(&auxStruct, posicion, nombre, apellido, cuil, iD))
			{
				arrayStruct=auxStruct;
				printf("Se cargó exitosamente el contribuyente %d\n", iD);
				break;
			}
		}
		else
		{
			printf("Hubo algún error en el ingreso de alguno de los datos.\n");
			break;
		}
	}
	else
	{
		printf("Intente dar de baja algún contribuyente para poder cargar.\n");
		break;
	}
}

//Funciones para dar de alta

int buscarIsEmpty(eContribuyente arrayStruct[], int tamanio, int* auxTamanio)
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

int addContribuyente(eContribuyente* arrayStruct, int tamanio, char nombre[], char apellido[], int cuil, int iD)
{
	int retorno=0;

	if(arrayStruct!=NULL&&nombre!=NULL&&apellido!=NULL&&tamanio>0)
	{
		strcpy(arrayStruct[tamanio].nombre, nombre);
		strcpy(arrayStruct[tamanio].apellido, apellido);
		arrayStruct[tamanio].cuil=cuil;
		arrayStruct[tamanio].iDContribuyente=iD;
		arrayStruct[tamanio].isEmpty=0;

		retorno=1;
	}
	return retorno;
}


