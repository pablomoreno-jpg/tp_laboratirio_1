/*
 * Menudeopciones.h
 *
 *  Created on: 4 oct. 2021
 *      Author: pablo
 */

#ifndef MENUDEOPCIONES_H_
#define MENUDEOPCIONES_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int estavacio;

}eEmpleado;

int Menu (void);
void Opciones (void);


#endif /* MENUDEOPCIONES_H_ */
