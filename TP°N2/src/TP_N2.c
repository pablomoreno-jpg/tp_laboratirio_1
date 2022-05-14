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
	int id;
	float promedio;
	int flagEntrada = 0;
	int idAutomatico = 0;


	int opcion;
	sPassenger pasajeros[PassengerLen];
	sTypeofPassangers tiposdePasajeros[cantidaddeTipos] = { { 0, "VIP" },
			{1, "PREMIUM" }, { 2, "DISCAPACITADO" }, { 3, "ADULTO MAYOR" }, { 4,"NORMAL" } };

	retorno = initPassengers(pasajeros, PassengerLen);

	if (retorno == 0) {

		do {

			opcion =
					IngresarEntero("1)ingresar pasajero.\n2)modificar pasajero."
							"\n3)eliminar pasajero.\n4)mostrar pasajeros.\n5)salir.\neliga una opcion: ");

			switch (opcion) {
			case 1:

				idAutomatico ++;

				retorno = addPassenger(pasajeros, PassengerLen, &pasajeros->id,pasajeros->name, pasajeros->lastName, &pasajeros->price,
						&pasajeros->typePassenger, &pasajeros->flysStatus,pasajeros->flycode,
						tiposdePasajeros, cantidaddeTipos,idAutomatico);
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

					retorno = IngresarEntero("1.Mostrar una lista Ordenada por apellido."
							"\n2.Mostar el promedio total del precio de los vuelos y pasajeros\n "
							"que superan el promedio total,en caso de haberlos\n"
							"3.Mostar listado ordenados por el estado de vuelo\n"
							"elija una opcion: ");

					switch (retorno) {
						case 1:

							retorno = sortPassengers(pasajeros, PassengerLen);

							switch(retorno){
							case -1:
								printf("\nerror.\n\n");
								break;
							default:
								retorno = printPassengers(pasajeros, PassengerLen, tiposdePasajeros, cantidaddeTipos);
								break;
							}

							break;
						case 2:

							promedio = PromediaryEncotrarPrecio(pasajeros, PassengerLen);

							printf("el promedio de los precios es de %.2f\n",promedio);

							if(promedio <= 0){

								printf("\nerro.\n\n");
							}
							else{

								retorno = CompararPromeido(pasajeros, PassengerLen, promedio);

								switch(retorno){
								case -1:
									printf("\nningun pasajero supera el promedio.\n\n");
									break;
								case 0:
									printf("\nson los pasajeros que superar el promedio\n\n");
									break;

								}
							}


							break;
						case 3:
							retorno = sortPassengersByCode(pasajeros, PassengerLen);

							switch(retorno){
							case -1:
								printf("\nerror.\n\n");
								break;
							default:
								retorno = printPassengers(pasajeros, PassengerLen, tiposdePasajeros, cantidaddeTipos);
								break;
							}
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
