#include "funciones.h"

int DarDeAlta(eEmpleado lista[], int tamanio) {

	int i;
	int retorno;
	retorno = 0;

	for (i = 0; i <= tamanio; i++) {

		if (lista[i].estavacio != 1) {

			lista[i].id = i;

			lista->nombre = OpeternerNombre("ingrese el nombre del empleado: ", 50);
			lista->salario = Salario("ingrese el salario del empleado: ");

		}

	}

	return retorno;
}
