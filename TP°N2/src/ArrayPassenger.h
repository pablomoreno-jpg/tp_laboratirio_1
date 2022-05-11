#include <stdio.h>
#include <stdlib.h>
#include "input.h"

#define VACANT 0
#define TAKEN 1

#define CANCELED 0
#define LATED 1
#define INTIME 2

#define INFANTE 0
#define ADULTO 1
#define ANCIANO 2
#define EMBARAZADA 3
#define DISCAPACITADO 4


typedef struct {

	char flycode[10];
	int flyStaus;
	int isNan;

} sFlystatus;


typedef struct {

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;

} sPassenger;



int initPassengers(sPassenger listofPassager[], int arraysLenght,sFlystatus flys[],int arraysflys);
int addFly(sFlystatus flys[],int arraysflys);
int addPassenger(sPassenger list[], int len, int *id, char name[],
		char lastName[], float *price, int *typePassenger, char flycode[]);
int addPassengers(sPassenger list[],int len);
int findPassengerById(sPassenger *list, int len, int id);
int removePassenger(sPassenger *list, int len, int id);
int sortPassengers(sPassenger *list, int len, int id);
int sortPassengersByCode(sPassenger *list, int len, int order);
int printPassengers(sPassenger *list, int len);
