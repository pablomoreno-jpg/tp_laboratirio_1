/*
 ============================================================================
 Name        : TP_N2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "input.h"
#define PassengerLen 2000
#define Flyslen 50

int main(void) {

	setbuf(stdout, NULL);
	int retorno;

	int opcion;
	sPassenger pasajeros[PassengerLen];

	retorno = initPassengers(pasajeros, PassengerLen);

	if (retorno == 0) {

		do {

			opcion = IngresarEntero("1.ingresar pasajero.\neliga una opcion: ");

			switch (opcion) {
			case 1:
				retorno = addPassenger(pasajeros, PassengerLen, &pasajeros->id,
						pasajeros->name, pasajeros->lastName, &pasajeros->price,
						&pasajeros->typePassenger, pasajeros->flycode);
				switch (retorno) {
				case -1:
					printf("\nErro. falta de espacio.\n\n ");
					break;
				case 0:
					printf("\n\ncarga realizada.\n\n");
					break;

				}
				break;
			case 2:

				retorno = printPassengers(pasajeros, PassengerLen);

				switch (retorno) {
				case -1:
					printf("\nErro. falta de espacio.\n\n ");
					break;
				case 0:
					printf("\n\ncarga realizada.\n\n");
					break;

				}

				break;

			case 3:
				break;

			case 0:
				printf("adios ...");
				break;

			}

		} while (opcion != 0);
	} else {

		printf("error");
	}

	return EXIT_SUCCESS;
}
