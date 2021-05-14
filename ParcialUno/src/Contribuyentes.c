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
	int flagAux;

	eContribuyente auxStruct;

	if(buscarIsEmpty(arrayStruct, tamanio, &posicion))
	{
		if(utn_getString("Ingrese el nombre del contribuyente: \n", "Error al ingresar el nombre del contribuyente. Intentelo de nuevo: \n", nombre, 2)&&
           utn_getString("Ingrese el apellido del contribuyente: \n", "Error al ingresar el apellido del contribuyente. Intentelo de nuevo: \n", apellido, 2)&&
		   getCuil(&cuil, "Ingrese el CUIL del contribuyente:\n", "Error al ingresar el CUIL. Intente de nuevo:\n", 5)&&obtenerId(&flagAux, 1000, &iD))
		{
			if(addContribuyente(&auxStruct, posicion, nombre, apellido, cuil, iD))
			{
				arrayStruct[posicion]=auxStruct;
				printf("Se cargó exitosamente el contribuyente %d\n", iD);
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
		printf("Intente dar de baja algún contribuyente para poder cargar.\n");
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

//Punto 3 Baja Contribuyente

void darBaja(eContribuyente arrayStruct[], int tamanio)
{
	int id;
	int posicion;
	char darBaja;

	utn_getNumero(&id, "Ingrese en ID del contribuyente que desee dar de baja:\n", "Error al ingresar el ID. Intentelo de nuevo:\n", 1001, 1050, 5);

	if(buscarContribuyenteConId(*arrayStruct, tamanio, id, &posicion))
	{
		printf("ID    NOMBRE    APELLIDO    CUIL\n");
		mostrarDatosStruct(arrayStruct, posicion);

		printf("¿Desea dar de baja este contribuyente? s-si n-no \n");
		fflush(stdin);
		scanf("%c", &darBaja);
		if(darBaja=='s')
		{
			arrayStruct[posicion].isEmpty=1;
			printf("Se dio de baja al contribuyente.\n");
		}
		else
		{
			printf("No dio de baja al ID %d \n", id);
		}
	}
}


//Funciones para dar de baja

int buscarContribuyenteConId (eContribuyente arrayStruct, int tamanio, int iD, int* posicion)
{
	int retorno=0;
	int i;

	for(i=0;i<tamanio;i++)
		{
			if(arrayStruct[i].isEmpty==0)
			{
				if(arrayStruct[i].iDContribuyente==iD)
				{
					*posicion=i;
					retorno=1;
				}
				else
				{
					printf("No existe el ID ingresado.\n");
				}
			}
		}
	return retorno;
}

void revizarIsEmpty(eContribuyente arrayStruct[], int tamanio, int* flag)
{
	int i;
	int contaIsEmpty=0;

	for(i=0;i<tamanio;i++)
	{
		if(arrayStruct[i].isEmpty==1)
		{
			contaIsEmpty++;
		}
	}

	if(contaIsEmpty==tamanio)
	{
		*flag=0;
	}
}


//Imprimir en pantalla

void mostrarDatosStruct(eContribuyente arrayStruct[], int tamanio)
{
	printf("%d       %s        %s       %d\n", arrayStruct[tamanio].iDContribuyente, arrayStruct[tamanio].nombre, arrayStruct[tamanio].apellido, arrayStruct[tamanio].cuil);
}


//Punto 2 Modificar Contribuyente

void menuModificador(eContribuyente arrayStruct[], int tamanio)
{
	int opcion;
	char salir;
	int menu;
	char modificar;
	int posicion;
	char nombre[TAM];
	char apellido[TAM];
	int cuil;
	int id;

	if(arrayStruct!=NULL&&tamanio>0)
	{
		do
		{
			utn_getNumero(&id, "Ingrese en ID del contribuyente que desee dar de baja:\n", "Error al ingresar el ID. Intentelo de nuevo:\n", 1001, 1050, 5);

			if(buscarContribuyenteConId(*arrayStruct, tamanio, id, &posicion))
			{
				printf("ID    NOMBRE    APELLIDO    CUIL\n");
				mostrarDatosStruct(arrayStruct, posicion);

				printf("¿Desea modificar este ID? s-si n-no \n");
				fflush(stdin);
				scanf("%c", &modificar);

				if(modificar=='s')
				{
					menu=utn_getNumero(&opcion,"MODIFICAR \n\nSeleccione una opción:\n [1]-Nombre del contribuyente.\n [2]-Apellido del contribuyente.\n [3]-CUIL del contribuyente.\n [4]-Salir.\n", "No ingresó una opción válida, vuelva a intentarlo.\n\n", 1, 3, 5);
					if(menu==0)
					{
						switch (opcion)
						{
							case 1:
								utn_getString("Ingrese el nombre del contribuyente:\n","Error al ingresar el nombre del contribuyente. Intentelo de nuevo: \n", nombre, 2);
								strncpy(arrayStruct[posicion].nombre,nombre,30);
								break;

							case 2:
								utn_getString("Ingrese el apellido del contribuyente:\n","Error al ingresar el apellido del contribuyente. Intentelo de nuevo: \n", apellido, 2);
								strncpy(arrayStruct[posicion].apellido,apellido,30);
								break;

							case 3:
								getCuil(&cuil, "Ingrese el CUIL del contribuyente:\n", "Error al ingresar el CUIL. Intente de nuevo:\n", 5);
								arrayStruct[posicion].iDContribuyente=cuil;
								break;

							case 4:
								printf("¿Desea salir? s-si o n-no:\n");
								fflush(stdin);
								scanf("%c", &salir);
								if (salir=='s')
								{
									printf("Salió del modificador de datos del contribuyente.\n");
								}
								break;
							}
						}
					else
					{
						printf("Error al seleccionar en el menu. Intente más tarde.\n");
						salir='s';
					}
				}
			}
		}while(salir=='n'||opcion!=4);
	}
}

