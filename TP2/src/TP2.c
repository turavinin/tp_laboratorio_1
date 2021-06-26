#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaUTN-validaciones.h"
#include "ArrayEmployees.h"
#define LARGO_ARR 1000


int main(void) {
	setbuf(stdout, NULL);

	// Variables
	int startId = 1;
	int exitoFuncion;
	int opcionMenu;

	// Declara array
	Employee arrEmpleado[LARGO_ARR];

	// Inicia empleados
	initEmployees(arrEmpleado, LARGO_ARR);

	do
	{
		exitoFuncion = utn_getNumberLimited(&opcionMenu,
				"\n|-----------------------MENU-------------------------|"
				"\n| 1. ALTA                                            |"
				"\n| 2. MODIFICAR                                       |"
				"\n| 3. BAJA                                            |"
				"\n| 4. INFORMAR                                        |"
				"\n| 0. SALIR                                           |"
				"\n|----------------------------------------------------|"
				"\n| Seleccione una opción (Ingrese su número): ",
				"\n|    --- ¡LA OPCION INGRESADA ES INCORRECTA! ---     |\n",
				0, 4, 3);

		if(exitoFuncion == 0)
		{
			switch(opcionMenu)
			{
				case 1:
					eEmployee_Create(arrEmpleado, LARGO_ARR, &startId);
					break;
				case 2:
					eEmployee_Edit(arrEmpleado, LARGO_ARR);
					break;
				case 3:
					eEmployee_Delete(arrEmpleado, LARGO_ARR);
					break;
				case 4:
					printEmployees(arrEmpleado, LARGO_ARR, 1);
					break;
			}
		}

	}while(opcionMenu != 0);

	printf("\n|    --- ¡GRACIAS POR UTILIZAR EL PROGRAMA! ---     |\n");

	return EXIT_SUCCESS;
}
