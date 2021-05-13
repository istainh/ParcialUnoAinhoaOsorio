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
		menu=utn_getNumero(&opcion,"MENÚ DE OPCIONES:\n\n [1] Alta Contribuyentes\n", "No ingresó una opción válida. Vuelve a intentarlo.\n", 1, 9, 10);
		if(menu==0)
		{
			switch (opcion)
			{
				case 1:
					cargaDatosContribuyente(contribuyente, CANTIDAD, &flagCarga, &flagId);
				break;

				case 2:
					 if(flagCarga==0)
					 {
					 }
					 else
					 {
					 }
					 break;

				case 3:
					 if(flagCarga==0)
					 {
					 }
					 else
					 {
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




