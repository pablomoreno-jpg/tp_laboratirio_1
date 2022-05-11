#include "ArrayPassenger.h"

int initPassengers(sPassenger listofPassager[], int arraysLenght) {

	int rtn = -1;

	if (listofPassager != NULL) {

		if (arraysLenght > 0) {

			for (int i = 0; i < arraysLenght; i++) {

				listofPassager[i].isEmpty = VACANT;
				rtn = 0;

			}
		}
	}

	return rtn;
}

int addPassenger(sPassenger list[], int len, int *id, char name[],
		char lastName[], float *price, int *typePassenger, char flycode[],
		sTypeofPassangers tipe[], int typelen) {

	int rtn = -1;

	if (list != NULL) {

		if (len > 0) {

			for (int i = 0; i < len; i++) {

				if (list[i].isEmpty == VACANT) {

					list[i].id = IngresarEntero("ingrese el id del pasajero: ");
					IngresarCadena("Nombre del pasajero: ", list[i].name);
					AcomodarNombre(list[i].name, 51);
					IngresarCadena("Apellido del pasajero: ", list[i].lastName);
					AcomodarNombre(list[i].lastName, 51);
					list[i].price = IngresarFlotante("precio del vuelo: ");
					for (int j = 0; j < typelen; j++) {

						printf("%d %s\n", tipe[j].typePassenger, tipe[j].typeP);

					}
					list[i].typePassenger = IngresarEntero(
							"ingrese el tipo de pasajero: ");
					IngresarCadena("ingrese el codigo de vuelo: ",
							list[i].flycode);
					list[i].isEmpty = TAKEN;
					rtn = 0;
					break;

				}
			}

		}
	}

	return rtn;
}

int findPassengerById(sPassenger *list, int len, int id) {

	int rtn = -1;

	if (list != NULL) {

		if (len > 0) {

			for (int i = 0; i < len; i++) {

				if (list[i].id == id) {

					rtn = 0;

				}
			}
		}
	}

	return rtn;
}

int removePassenger(sPassenger *list, int len, int id) {

	int rtn = -1;

	if (list != NULL) {

		if (len > 0) {

			id = IngresarEntero("ingrese el id que quiere dar de baja: ");

			for (int i = 0; i < len; i++) {

				if (list[i].id == id) {

					list[i].isEmpty = VACANT;
					rtn = 0;
					break;

				}

			}

		}

	}

	return rtn;
}

int sortPassengers(sPassenger *list, int len, int id) {

	int rtn = -1;
	sPassenger auxiliar;

	if (list != NULL) {

		if (len > 0) {

			for (int i = 0; i < len - 1; i++) {

				for (int j = i + 1; j < len; j++) {

					if (stricmp(list[i].lastName, list[j].lastName) > 0
							&& list[i].typePassenger > list[j].typePassenger) {

						auxiliar = list[i];
						list[i] = list[j];
						list[j] = auxiliar;
						rtn = 0;

					}
				}
			}
		}
	}

	return rtn;
}

int printPassengers(sPassenger *list, int len, sTypeofPassangers *tipe,
		int tipelen) {

	int rtn = -1;

	if (list != NULL) {

		if (len > 0) {

			printf(
					"id\t|nombre\t\t|aprellido\t|tipo de pasajero\t|codigo de vuelo\t|precio\n");

			for (int j = 0; j < tipelen; j++) {

				for (int i = 0; i < len; i++) {

					if (list[i].isEmpty == TAKEN
							&& list[i].typePassenger == tipe[j].typePassenger) {

						printf("%5d %10s %20s\t\t", list[i].id, list[i].name,
								list[i].lastName);

						printf("%5s", tipe[j].typeP);

						printf("\t%10s\t %20.2f\n", list[i].flycode,
								list[i].price);

						rtn = 0;

					}

				}

			}
		}
	}

	return rtn;
}

int sortPassengersByCode(sPassenger *list, int len, int order) {

	int rtn = -1;

	return rtn;
}

