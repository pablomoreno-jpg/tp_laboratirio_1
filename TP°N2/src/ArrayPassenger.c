#include "ArrayPassenger.h"

int initPassengers(sPassenger listofPassager[], int arraysLenght) {

	int rtn = -1;

	if (listofPassager != NULL) {

		if (arraysLenght > 0) {

			rtn = 0;

			for (int i = 0; i < arraysLenght; i++) {

				listofPassager[i].isEmpty = VACANT;
				rtn = 0;

			}
		}
	}

	return rtn;
}


int addPassenger(sPassenger list[], int len, int *id, char name[],
		char lastName[], float *price, int *typePassenger, char flycode[]) {

	int rtn = -1;

	if (list != NULL) {

		if (len > 0) {

			for (int i = 0; i < len; i++) {

				if (list[i].isEmpty == VACANT) {

					*id = IngresarEntero("ingrese el id del pasajero: ");
					IngresarCadena("Nombre del pasajero: ", name);
					AcomodarNombre(name, 51);
					IngresarCadena("Apellido del pasajero: ", lastName);
					AcomodarNombre(lastName, 51);
					*price = IngresarFlotante("precio del vuelo: ");
					*typePassenger = IngresarEntero(
							"ingrese el tipo de pasajero: ");
					IngresarCadena("ingrese el codigo de vuelo: ", flycode);
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

	id = IngresarEntero("Ingrese el id del pasajero: ");

	if (list != NULL) {

		if (len > 0) {

			for (int i = 0; i < len; i++) {

				if (list[i].id == id) {

					rtn = id;

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

int printPassengers(sPassenger *list, int len) {

	int rtn = -1;

	if (list != NULL) {

		if (len > 0) {

			printf(
					"id\t|nombre\t\t|aprellido\t|tipo de pasajero\t|codigo de vuelo\t|precio\n");

			for (int i = 0; i < len; i++) {

				if (list[i].isEmpty == TAKEN) {

					printf("%4d %10s %20s\t\t", list[i].id, list[i].name,
							list[i].lastName);
					switch (list[i].typePassenger) {
					case 0:
						printf("INFANTE");
						break;
					case 1:
						printf("ADULTO");
						break;
					case 2:
						printf("ANCIANO");
						break;
					case 3:
						printf("EMBARAZADA");
						break;
					case 4:
						printf("DISCAPACITADO");
						break;
					default:
						printf("desconcocido");
						break;

					}

					printf("\t%20s\t %20.2f\n", list[i].flycode, list[i].price);

					rtn = 0;

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

/*int initFly(sFlystatus flys[], int arraysflys, sPassenger listofPassager[],
 int arraysLenght) {

 int rtn = -1;

 if (listofPassager != NULL && flys != NULL) {

 if (arraysLenght > 0 && arraysflys > 0) {

 for (int i = 0; i < arraysflys; i++) {

 for (int j = 0; j < arraysLenght; j++) {

 IngresarCadena("ingrese el codigo de vuelo",
 flys[j].flycode);

 if (strcmp(flys[j].flycode, listofPassager[i].flycode)
 == 0) {

 flys[j].flyStaus =IngresarEntero("ingrese el estado del "
 "vuelo 0.cencelado, 1.atrasado, 2.a tiempo");

 rtn = 0;

 }
 }
 }
 }
 }

 return rtn;
 }*/

