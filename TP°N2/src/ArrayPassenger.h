#include <stdio.h>
#include <stdlib.h>
#include "input.h"

#define VACANT 0
#define TAKEN 1


typedef struct {

	int typePassenger; //pk
	char typeP[40];

} sTypeofPassangers;

typedef struct {

	int id; //pk
	char name[51];
	char lastName[51];//fk
	float price;
	char flycode[10];
	int flysStatus;
	int typePassenger; //fk
	int isEmpty;

} sPassenger;


int initPassengers(sPassenger listofPassager[], int arraysLenght);
int addPassenger(sPassenger list[], int len, int *id, char name[],char lastName[], float *price, int *typePassenger, int *flyStatus ,char flycode[],sTypeofPassangers tipe[], int typelen, int idAuto);
int findPassengerById(sPassenger *list, int len, int id);
int modifyPassengers(sPassenger *list, int len, int id,sTypeofPassangers *tipe, int tipelen);
int removePassenger(sPassenger *list, int len, int id);
int sortPassengers(sPassenger *list, int len);
int printPassengers(sPassenger *list, int len,sTypeofPassangers *tipe, int tipelen);
float PromediarPrecio(float precio, int cantidadTotal);
float PromediaryEncotrarPrecio(sPassenger *list, int len);
int CompararPromeido(sPassenger *list, int len,float promedio);
int sortPassengersByCode(sPassenger *list, int len);


