#include "menu.h"
#include "funciones.h"

void Opcion(int opcion) {

	int primerNumero;
	int segundoNumero;
	int suma;
	int resta;
	float divicion;
	int multiplicacion;
	int factorialUno;
	int factorialDos;
	int continuar;
	int estado;
	int calculo;

	estado = 0; // la bandera "estado" va a comprobar que se cargaron los 2 operadores en el MenuDeOpciones
	calculo = 0; //la bandera "calculo" va a permirmitir (o no) la muestra de los resultados
	continuar = 1; //permite

	MenuDeOpciones(primerNumero, segundoNumero, estado); //llamado de funcion que va complementar al menu

	fflush(stdin);
	printf("\ningres la opcion que desea: "); // incia pidiendo una de las 5 opciones
	scanf("%d", &opcion);

	while (continuar) {

		switch (opcion) {
		case 1:

			fflush(stdin);
			printf("ingrese el primer operador: ");
			scanf("%d", &primerNumero);
			if (estado < 1) {

				estado = 1; // confirma que se cargo el primer operador
			}
			break;

		case 2:
			if (estado > 0) {

				fflush(stdin);
				printf("ingrese el segundo operador: "); // si el estado es 1, se va a poder pedir e ingresar el segundo operador
				scanf("%d", &segundoNumero);
				estado = 2;

			} else //
			{
				printf(
						"\n(ingrese el primer operador para seguir apropiadamente)\n"); // en caso de que el estado no sea 1
			}
			break;
		case 3:
			if (estado == 2) { //una ves comparada la variable estado, se van a poder calcular los 2 operadores

				printf("la suma de %d + %d\n", primerNumero, segundoNumero);

				suma = Sumar(primerNumero, segundoNumero);

				printf("la resta de %d - %d\n", primerNumero, segundoNumero);

				resta = Restar(primerNumero, segundoNumero);

				printf("la divicion de %d / %d\n", primerNumero, segundoNumero);

				divicion = Division(primerNumero, segundoNumero);

				printf("la multipolicacion de %d * %d\n", primerNumero,
						segundoNumero);

				multiplicacion = Multiplicar(primerNumero, segundoNumero);

				printf("factorial de !%d y factorial de !%d\n", primerNumero,
						segundoNumero);

				factorialUno = Factorial(primerNumero);

				factorialDos = Factorial(segundoNumero);

				calculo = 1;
			} else { //va a pedir el ingreso de alguno de los 2 operadores

				printf(
						"por favor ingrese los 2 operadores para poder cacularlos\n");
			}
			break;
		case 4:
			if (calculo == 1) {

				printf("el resultado de la suma: r= %d\n", suma);
				printf("el resultado de la resta: r= %d\n", resta);
				printf("el resultado de la divicion: r=%f\n", divicion);
				printf("el resultado de la multiplicacion: r=%d\n",multiplicacion);
				printf("el factorial de A(!%d) y de B(!%d) son: Ar= %d y Br=%d ",primerNumero, segundoNumero, factorialUno,factorialDos);

			}else if(primerNumero == 0 && segundoNumero == 0){

				printf("cualquier operacion que se haga entre ceros, siempre va a dar 0 o error");
			}
			else {

				printf("no hay operadores para poder mostrar resultados");

			}

			break;

		case 5:
			printf("\nadios ..."); // salida de la funcion
			continuar = 0;
			break;

		default:
			printf("\ndato incorrecto.....\n\n"); // pedido erroneo de datos
			break;
		}

		if (opcion != 5) {
			MenuDeOpciones(primerNumero, segundoNumero, estado);

			fflush(stdin);
			printf("\ningres la opcion que desea: "); // incia pidiendo una de las 5 opciones
			scanf("%d", &opcion);
		}

	}
}

void MenuDeOpciones(int numero1, int numero2, int estado) {

	printf("ingrese una de las 5 opciones:\n");

	switch (estado) {
	case 0:
		printf("1) el ingreso del operador A =\n");
		printf("2) el ingreso del operador B =\n");
		break;
	case 1:
		printf("1) el ingreso del operador A = %d\n", numero1);
		printf("2) el ingreso del operador B =\n");
		break;
	case 2:
		printf("1) el ingreso del operador A = %d\n", numero1);
		printf("2) el ingreso del operador B = %d\n", numero2);
		break;

	}
	printf("3) calcular todas las operaciones:\n");
	printf("4) informar resultado:\n");
	printf("5) salir.\n");

}
