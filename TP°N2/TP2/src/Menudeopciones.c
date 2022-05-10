#include "Menudeopciones.h"
#define TAM 2000

int Menu(void) {

	eEmpleado empleado;
	int retorno;
	int eleccion;
	int continuacion;

	continuacion = 1;
	retorno = 0;

	Opciones();

	printf("elija que queiere hacer con el empleado: ");
	fflush(stdin);
	scanf("%d", &eleccion);

	do {
		switch (eleccion) {
		case 1:
			DarDeAlta(&empleado, TAM);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			printf("Adios ... ");
			continuacion = 0;
			break;
		default:
			printf("eleccion invalida, eliga una opcion predeterminada ");
			break;
		}
	} while (continuacion == 1);

	return retorno;
}

void Opciones(void) {

	printf("1) Dar de Alta\n");
	printf("2) Modificar\n");
	printf("3) Dar de baja\n");
	printf("4) informar\n");
	printf("5) salir\n");

}
