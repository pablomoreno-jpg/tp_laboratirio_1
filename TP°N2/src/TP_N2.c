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

int main(void) {

	setbuf(stdout, NULL);
	int retorno;

	int opcion;
	sPassenger pasajeros[PassengerLen];
	sTypeofPassangers tiposdePasajeros[5] = { { 0, "INFANTE" }, { 1, "ADULTO" },
			{ 2, "ANCIANO" }, { 3, "EMBARAZADA" }, { 4, "DISCAPACITADO" } };

	retorno = initPassengers(pasajeros, PassengerLen);

	if (retorno == 0) {

		do {

			opcion =
					IngresarEntero(
							"1)ingresar pasajero.\n2)mostrar lista de pasajeros.\n3)buscar id.\n"
							"4)eliminat id\neliga una opcion: ");

			switch (opcion) {
			case 1:
				retorno = addPassenger(pasajeros, PassengerLen, &pasajeros->id,
						pasajeros->name, pasajeros->lastName, &pasajeros->price,
						&pasajeros->typePassenger, pasajeros->flycode,
						tiposdePasajeros, 5);
				switch (retorno) {
				case -1:
					printf("\nError. falta de espacio.\n\n ");
					break;
				case 0:
					printf("\n\ncarga realizada.\n\n");
					break;

				}
				break;
			case 2:

				retorno = printPassengers(pasajeros, PassengerLen,
						tiposdePasajeros, 5);

				switch (retorno) {
				case -1:
					printf("\nErro. no hay pasajeros....\n\n ");
					break;
				case 0:
					printf("\n\ncarga realizada.\n\n");
					break;

				}

				break;

			case 3:

				retorno = IngresarEntero("Ingrese un id: ");
				retorno = findPassengerById(pasajeros, PassengerLen, retorno);

				switch (retorno) {
				case -1:
					printf("\nno se econotro el id\n\n ");
					break;
				case 0:
					printf("\n\nel id esta cargado.\n\n");
					break;
				}
				break;

			case 4:
				retorno = IngresarEntero("Ingrese el id que quiera eliminar: ");
				retorno = removePassenger(pasajeros, PassengerLen, retorno);

				switch (retorno) {
				case -1:
					printf("\nno se econotro el id\n\n ");
					break;
				case 0:
					printf("\n\eliminacion realizada.\n\n");
					break;
				}
				break;
				break;

			case 0:
				printf("adios ...");
				break;

			}

		} while (opcion != 0);
	} else {

		printf("error");
	}

	return 0;
}
