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

/// @brief inicializa el campo 'isEmpty' de la estructura que recibe como parametro en 0.
///
/// @param listofPassager: estructura de pasajeros.
/// @param arraysLenght; tamanio del array de la variable sPAssangers.
/// @return devuelve un -1 en caso de error de compilacion o 0 en caso contrario.
int initPassengers(sPassenger listofPassager[], int arraysLenght);

/// @brief pide y carga los campos del array de estructuras sPassanger
///
/// @param list: puntero de estructura sPasanger
/// @param len: tamanio del array de sPassanger
/// @param id: puntero de campo sPasanger
/// @param name: puntero de campo sPasanger
/// @param lastName: puntero de campo sPasanger
/// @param price: puntero de campo sPasanger
/// @param typePassenger: puntero de campo sPasanger
/// @param flyStatus: puntero de campo sPasanger
/// @param flycode; puntero de campo sPasanger
/// @param tipe: estructura para el tipo pasajeros
/// @param typelen: tamanio de la estructura hardcodeada de tipos de pasajeros.
/// @param idAuto contador que se va a cargar en campo id de la primer estructura
/// @return devuelve un -1 en caso de error de compilacion o 0 en caso contrario.
int addPassenger(sPassenger list[], int len, int *id, char name[],char lastName[], float *price, int *typePassenger, int *flyStatus ,char flycode[],sTypeofPassangers tipe[], int typelen, int idAuto);

/// @brief compara la vaiable id que rebice como parametro con el campo del array de
/// estructura que tambienrebibe como parametro.
///
/// @param list: estructura sPassangers
/// @param len: tamanio de la estructura.
/// @param id: varable que se compara con el campo de la estructura '.id'
/// @return devuelve un -1 en caso de error o de no encotrar prantensco entre la variable id y el campo id,
/// devuelve el valor de la varible id en caso de encotrar la similitud.
int findPassengerById(sPassenger *list, int len, int id);

/// @brief modifica uno de los campos del array de estrucuras utilizando como indice la variable id.
///
/// @param list: estrcutra sPasangers
/// @param len: tamanio del array de estrcurta
/// @param id: variable que se va a usar para comparar con el campo id de la variable list
/// @param tipe: estructura para el tipo pasajeros
/// @param tipelen: tamanio de la estructura hardcodeada de tipos de pasajeros.
/// @return devuelvo un -1 en caso de error, 0 en caso de una salida correcta.
int modifyPassengers(sPassenger *list, int len, int id,sTypeofPassangers *tipe, int tipelen);

/// @brief cambia el valor del campo isEmpty del array de la estructura sPasangers que recibe como
/// parametro de 1 a 0 utilizando como indice la varieble id
///
/// @param list: estructura sPassanger
/// @param len: tamanio del array list
/// @param id: variable que se va a usar para comparar con el campo id de la variable list
/// @return devuelve un -1 en caso de error, 0 en caso de una salida correcta.
int removePassenger(sPassenger *list, int len, int id);

/// @brief ordena el array de estrcutra por apellido o por tipo de pasajero en caso de similitudes.
///
/// @param list: estructura sPassanger
/// @param len: tamanio del array list
/// @return devuelve -1 en caso de erro, devuelve 0 en caso de una salida correcta.
int sortPassengers(sPassenger *list, int len);

/// @brief imprime la estructura que recibe como parametro.
///
/// @param list: estructura sPassangers
/// @param len: tamanio del array de list.
/// @param tipe: estrcutura sTypeofPassangers.
/// @param tipelen: tamanio de la estructura tipe.
/// @return devuelve -1 en caso de erro, devuelve 0 en caso de una salida correcta.
int printPassengers(sPassenger *list, int len,sTypeofPassangers *tipe, int tipelen);

/// @brief calcula el promedio de los precio que recibe como parambreos
///
/// @param precio: precio total de vuelos.
/// @param cantidadTotal: cantidad de precios.
/// @return devuelve un -1 en caso de error. devuelve el valor del premedio calculado.
float PromediarPrecio(float precio, int cantidadTotal);

/// @brief buscar y guarda los precios de todos los vuelos en el array de pasajeros para posteriormente
/// calcularo mediante el llamado de otr funcion.
///
/// @param list: estructura sPassanger.
/// @param len: tamanio del array list.
/// @return devuelve un -1 en caso de error, devuele el resultado del promedio calculado.
float PromediaryEncotrarPrecio(sPassenger *list, int len);

/// @brief busca ,y muerstra, en el array de sPassanger cuales son los indices que superar el promedio.
///
/// @param list: estructura sPassanger.
/// @param len: tamanio del array list.
/// @param promedio: variable que se va a utilizar como critero para buscar los precios que superan el promedio.
/// @return devuelve -1 en caso de erro, devuelve 0 en caso de una salida correcta.
int CompararPromeido(sPassenger *list, int len,float promedio);

/// @brief ordena el array de la estructura que recibe por parametro utilizando como critero el estado del
/// vuelo.
///
/// @param list: estructura sPassanger.
/// @param len: tamanio del array list.
/// @return devuelve -1 en caso de erro, devuelve 0 en caso de una salida correcta.
int sortPassengersByCode(sPassenger *list, int len);

