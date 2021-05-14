#include "Contribuyentes.h"

int main(void) {
	setbuf(stdout, NULL);

	eContribuyente contribuyente[CANTIDAD];

	int opcion;
	char salir;
	int menu;
	int flagCarga=0;
	int flagId=0;

	initContribuyentes(contribuyente, CANTIDAD);

	do
	{
		menu=utn_getNumero(&opcion,"MENÚ DE OPCIONES:\n\n [1] Alta Contribuyentes\n [2] Modificar contribuyente\n [3] Baja Contribuyentes\n", "No ingresó una opción válida. Vuelve a intentarlo.\n", 1, 9, 10);
		if(menu==0)
		{
			switch (opcion)
			{
				case 1: //Alta contribuyente
					cargaDatosContribuyente(contribuyente, CANTIDAD, &flagCarga, &flagId);
				break;

				case 2: //Modificar datos del contribuyente
					 if(flagCarga==0)
					 {
						 printf("No se han ingresado contribuyentes.\n");
					 }
					 else
					 {
						 menuModificador(contribuyente, CANTIDAD);
					 }
					 break;

				case 3: //Baja contribuyente
					 if(flagCarga==0)
					 {
						 printf("No se han ingresado ningún contribuyente.\n");
					 }
					 else
					 {
						 darBaja(contribuyente, CANTIDAD);
						 revizarIsEmpty(contribuyente, CANTIDAD, &flagCarga);
					 }
					 break;

				case 4:
					 if(flagCarga==0)
					 {
					 }
					 else
					 {
					 }
					 break;

				case 5:
					break;

				case 6:
					break;

				case 7:
					break;

				case 8:
					break;

				case 9:
					printf("¿Desea salir? s-si o n-no:\n");
					fflush(stdin);
					scanf("%c", &salir);
					if (salir=='s')
					{
						printf("Terminó el programa.\n");
					}
				break;
			}
		}
		else
		{
			printf("Error al seleccionar en el menu. Intente más tarde.\n");
			salir='s';
		}

	}while(salir=='n'||opcion!=9);

	return EXIT_SUCCESS;
}




