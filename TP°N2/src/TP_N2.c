/*
 ============================================================================
 Name        : TP_N2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "nexo.h"

#define PassengerLen 2000
#define cantidaddeTipos 5

int main(void) {

	setbuf(stdout, NULL);
	int retorno;
	int flagEntrada = 0;
	int id;

	int opcion;
	sPassenger pasajeros[PassengerLen];
	sTypeofPassangers tiposdePasajeros[cantidaddeTipos] = { { 0, "INFANTE" }, {
			1, "ADULTO" }, { 2, "ANCIANO" }, { 3, "EMBARAZADA" }, { 4,"DISCAPACITADO" } };

	retorno = initPassengers(pasajeros, PassengerLen);

	if (retorno == 0) {

		do {

			opcion =
					IngresarEntero(
							"1)ingresar pasajero.\n2)modificar pasajero.\n3)eliminar pasajero."
							"\n4)mostrar pasajeros.\n5)salir.\neliga una opcion: ");

			switch (opcion) {
			case 1:
				retorno = addPassenger(pasajeros, PassengerLen, &pasajeros->id,
						pasajeros->name, pasajeros->lastName, &pasajeros->price,
						&pasajeros->typePassenger, pasajeros->flycode,
						tiposdePasajeros, cantidaddeTipos);
				switch (retorno) {
				case -1:
					printf("\nError. falta de espacio.\n\n ");
					break;
				case 0:
					printf("\ncarga realizada.\n\n");
					flagEntrada = 1;
					break;

				}
				break;
			case 2:
				if (flagEntrada == 1) {
					id =IngresarEntero("ingrese el id de del pasajero a quiere modificar: ");

					retorno = findPassengerById(pasajeros, PassengerLen, id);

					if(retorno > 0){

						retorno = modifyPassengers(pasajeros, PassengerLen, retorno, tiposdePasajeros, cantidaddeTipos);

						switch(retorno){
						case -1:
							printf("\nerror\n\n");
						break;
						case 0:
							printf("\nmodificacion exitosa\n\n");
							break;

						}
					}
					else{

						printf("\nno se encontro el pasajero\n\n");

					}
				}
				else{

					printf("\npor favor ingrese un pasajero primero.\n\n");

				}
				break;
			case 3:
				if (flagEntrada == 1){

					id = IngresarEntero("ingrese el id de del pasajero a quiere eliminar: ");

					retorno = findPassengerById(pasajeros, PassengerLen, id);

					if(retorno > 0){

						retorno = removePassenger(pasajeros, PassengerLen, retorno);

						switch(retorno){
						case -1:
							printf("\nerror\n\n");
						break;
						case 0:
							printf("\neliminacion exitosa\n\n");
							break;

						}
					}
					else{

						printf("\nno se encontro el pasajero.\n\n");
					}

				}
				else{

					printf("\npor favor ingrese un pasajero primero.\n\n");

				}
				break;
			case 4:

				if (flagEntrada == 1){

					retorno = IngresarEntero("1.Mostrar una lista ordenada por apellido y por tipo de pasajero."
							"\n2.mostrar una lista Total y promedio de los precios de los pasajes, y cuántos pasajeros\n "
							" superan el precio promedio.\n3.Listado de los pasajeros por Código de vuelo y "
							"estados de vuelos ‘ACTIVO’\n"
							"elija una opcion: ");

					switch (retorno) {
						case 1:

							retorno = sortPassengers(pasajeros, PassengerLen);

							if(retorno == -1){

								printf("error");

							}
							else{

								retorno = printPassengers(pasajeros, PassengerLen, tiposdePasajeros, cantidaddeTipos);
							}

							break;
						case 2:

							break;
						case 3:
							break;
						default:
							printf("\nopcion incorrecta.\n\n ");
							break;
						}
						break;
				}
				else{

					printf("\npor favor ingrese un pasajero primero.\n\n");

				}
				break;

			case 5:
				printf("\n\nadios ...");
				break;

			default:
				printf("\nopcion incorrecta\n\n");
				break;
			}

		} while (opcion != 5);
	} else {

		printf("error");
	}

	return 0;
}
