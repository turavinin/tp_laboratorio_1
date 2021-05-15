/*
 ============================================================================
 Name        : TP2.c
 Author      : Anton Turavinin
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo Practico N° 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaUTN-validaciones.h"
#include "ArrayEmployees.h"

#define LARGO_ARR 3


int main(void) {
	setbuf(stdout, NULL);

	// Variables
	int exitoFuncion;
	int opcionMenu;
	int existeProximoLibre;
	char salida;

	// Declara array
	Employee arrEmpleado[LARGO_ARR];

	// Inicia empleados
	initEmployees(arrEmpleado, LARGO_ARR);

	do
	{
		exitoFuncion = utn_getNumberLimited(&opcionMenu,
				"\n|-----------------------MENU-------------------------|"
				"\n| 1. ALTAS                                           |"
				"\n| 2. MODIFICAR                                       |"
				"\n| 3. BAJA                                            |"
				"\n| 4. INFORMAR                                        |"
				"\n|----------------------------------------------------|"
				"\n| Seleccione una opción (Ingrese su número): ",
				"\n|    --- ¡LA OPCION INGRESADA ES INCORRECTA! ---     |",
				1, 9, 3);

		if(exitoFuncion == 0)
		{
			switch(opcionMenu)
			{
				case 1:
					do
					{
						exitoFuncion = eEmployee_Alta(arrEmpleado, LARGO_ARR, &existeProximoLibre);
						if(existeProximoLibre != -1 && exitoFuncion == 0)
						{
							utn_getCharDosOpciones(&salida, "    ¿Desea agregar otro empleado? (S / N): ", "Error.", 's', 'n', 3);
						}
						else
						{
							salida = 'n';
						}
					}while(salida != 'n');
					break;
				case 2:
					break;
				case 3:
					eEmployee_Baja(arrEmpleado, LARGO_ARR);
					break;
				case 4:
					printEmployees(arrEmpleado, LARGO_ARR, 1);
					break;
			}
		}

	}while(opcionMenu != 9);

















/*	int i;
	for(i = 0; i < 2; i++)
	{
		eEmployee_Alta(arrEmpleado,
					   LARGO_ARR,
					   "\nIngrese su nombre: ",
					   "Ingrese su apellido: ",
					   "Ingrese su salario: ",
					   "Ingrese su sector: ",
					   "-- Error de carga. ",
					   "---- ERROR AL INGRESAR EMPLEADO ----");
	}

	printEmployees(arrEmpleado, LARGO_ARR);*/

	return EXIT_SUCCESS;
}
