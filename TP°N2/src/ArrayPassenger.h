#include <stdio.h>
#include <stdlib.h>
#include "input.h"

#define VACANT 0
#define TAKEN 1

typedef struct {

	char flycode[10]; //pk
	char status[40];
	int flysStatus;

} sFlystatus;

typedef struct {

	int typePassenger; //pk
	char typeP[40];

} sTypeofPassangers;

typedef struct {

	int id; //pk
	char name[51];
	char lastName[51];
	float price;
	char flycode[10]; //fk
	int typePassenger; //fk
	int isEmpty;

} sPassenger;

int initPassengers(sPassenger listofPassager[], int arraysLenght);
int addPassenger(sPassenger list[], int len, int *id, char name[],
		char lastName[], float *price, int *typePassenger, char flycode[],
		sTypeofPassangers tipe[], int typelen);
int findPassengerById(sPassenger *list, int len, int id);
int removePassenger(sPassenger *list, int len, int id);
int sortPassengers(sPassenger *list, int len, int id);
int sortPassengersByCode(sPassenger *list, int len, int order);
int printPassengers(sPassenger *list, int len,sTypeofPassangers *tipe, int tipelen);
