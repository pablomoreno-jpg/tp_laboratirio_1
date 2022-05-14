#include "input.h"

int IngresarEntero(char *mensaje) {

	int entero;

	printf("%s", mensaje);
	scanf("%d", &entero);

	return entero;
}

float IngresarFlotante(char *mensaje) {

	float flotante;

	printf("%s", mensaje);
	scanf("%f", &flotante);

	return flotante;
}

char IngreseUnCaracter(char *mensaje) {

	char caracter;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &caracter);

	return caracter;
}

void IngresarVector(char *mensaje, int vector, int size) {

	for (int i = 0; i < size; i++) {

		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &vector);
	}

}

void IngresarCadena(char mensaje[], char cadena[]) {

	printf("%s", mensaje);
	fflush(stdin);
	gets(cadena);

}

void AcomodarNombre(char cadena[], int sizeCadena) {

	for (int i = 0; i < sizeCadena; i++) {

		if (i == 0) {

			cadena[i] = toupper(cadena[i]);
		} else {

			cadena[i] = tolower(cadena[i]);
		}
	}

}

