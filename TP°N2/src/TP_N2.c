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
#define Vuelostotales 30

int main(void) {

	setbuf(stdout, NULL);
	int retorno;
	float promedio;
	int flagEntrada = 0;
	int flagvuelos = 0;
	int id;

	int opcion;
	sPassenger pasajeros[PassengerLen];
	sFlys vuelos[Vuelostotales];
	sTypeofPassangers tiposdePasajeros[cantidaddeTipos] = { { 0, "INFANTE" },
			{1, "ADULTO" }, { 2, "ANCIANO" }, { 3, "EMBARAZADA" }, { 4,"DISCAPACITADO" } };

	retorno = initPassengers(pasajeros, PassengerLen);
	retorno = initfly(vuelos, Vuelostotales);

	if (retorno == 0) {

		do {

			opcion =
					IngresarEntero("1)ingresar pasajero.\n2)inicializar vuelo\n3)modificar pasajero."
							"\n4)eliminar pasajero.\n5)mostrar pasajeros.\n6)salir.\neliga una opcion: ");

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

				if (flagEntrada == 1){

					retorno = addtfly(vuelos, Vuelostotales, pasajeros, Vuelostotales);

					switch (retorno) {
					case -1:
						printf("\nError. falta de espacio.\n\n ");
						break;
					case 0:
						printf("\nel stado del vuelo se cargo exitosamente.\n\n");
						flagvuelos = 1;
						break;
					}
				}
				else{

					printf("primero ingrese un pasajero");

				}
				break;
			case 3:
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
			case 4:
				if (flagEntrada == 1){

					id = IngresarEntero("ingrese el id de del pasajero a quiere eliminar: ");

					retorno = findPassengerById(pasajeros, PassengerLen, id);

					if(retorno > 0){

						retorno = removePassenger(pasajeros, PassengerLen, retorno,vuelos,Vuelostotales);

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
			case 5:

				if (flagEntrada == 1){

					retorno = IngresarEntero("1.Mostrar una lista Ordenada por apellido."
							"\n2.Mostar el promedio total del precio de los vuelos y pasajeros\n "
							"que superan el promedio total,en caso de haberlos\n"
							"3.Mostar listado de los vuelos activos\n"
							"elija una opcion: ");

					switch (retorno) {
						case 1:

							retorno = sortPassengers(pasajeros, PassengerLen);

							if(retorno == -1){

								printf("\nerror.\n\n");

							}
							else{

								retorno = printPassengers(pasajeros, PassengerLen, tiposdePasajeros, cantidaddeTipos);
							}

							break;
						case 2:

							promedio = PromediaryEncotrarPrecio(pasajeros, PassengerLen);

							printf("el promedio de los precios es de %.2f",promedio);

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
							if(flagvuelos == 1){



							}
							else{

								printf("\ninicialice unn vuelo primero.\n\n");
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

			case 6:
				printf("\n\nadios ...");
				break;

			default:
				printf("\nopcion incorrecta\n\n");
				break;
			}

		} while (opcion != 6);
	} else {

		printf("error");
	}

	return 0;
}
