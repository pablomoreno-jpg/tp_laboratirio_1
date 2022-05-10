#include  "funciones.h"

int Sumar(int numeronuo, int numerodos) {

	int sumar;

	sumar = numeronuo + numerodos;

	return sumar;

}

int Restar(int numeronuo, int numerodos) {

	int restar;

	restar = numeronuo - numerodos;

	return restar;
}

float Division(int numerouno, int numerodos) {

	float dividir;

	if (numerouno == 0 && numerodos == 0) {
		printf("error, no es psible dividir entre 0.\n");

	} else {

		dividir = (float) numerouno / numerodos;

	}
	return dividir;
}

int Multiplicar(int numeronuo, int numerodos) {

	int multipliaccion;

	multipliaccion = numeronuo * numerodos;

	return multipliaccion;

}

int Factorial(int numero) {

	int i;
	long int facotorial;

	facotorial = 1;

	if (numero == 0 || numero != (int) numero) {
		printf("no es posible sacar factorial de %d\n", numero);
	} else {

		for (i = 1; i <= numero; i++) {

			facotorial = facotorial * i;

		}
	}
	return facotorial;
}

