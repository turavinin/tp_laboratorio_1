#include <stdio.h>
#include <stdlib.h>
#include "mensajesEnConsola.h"
#include "bibliotecaUTN-validaciones.h"
#include "bibliotecaUTN-calculos.h"

#define OPCIONES_INCORRECTAS_MAXIMAS 5

int main(void) {
	setbuf(stdout, NULL);

	// Variable para almacenar la opción elegida del menu
	int limitarIncorrectas = OPCIONES_INCORRECTAS_MAXIMAS;
	int opcionMenu;
	int exitoFuncion;
	int exitoFuncionDivision;

	// Banderas
	int banderaOperandoPrimero = 0;
	int banderaOperandoSegundo = 0;
	int banderaCalculos = 0;
	int banderaResultado = 0;

	// Operandos
	int operandoPrimero;
	int operandoSegundo;

	// Resultados
	int resultadoSuma;
	int resultadoResta;
	float resultadoDivision;
	int resultadoMultip;
	float resultadoFactorial;

	mostrarMensaje("¡Bienvenido al Calculador 3000!\nTodos tus calculos se harán realidad.\n\n");

	do
	{
		exitoFuncion = utn_getNumberLimited(&opcionMenu,
										"\nMENU\n1.Ingresar 1er operando.\n2.Ingresar 2do operando.\n3.Calcular todas las operaciones.\n4.Informar resultados.\n5.Salir.\nSeleccione una opción (ingrese su numero):",
										"\n----- Opción ingresasa es incorrecta ----- \n",
										1, 5, 3);

		if(exitoFuncion)
		{
			switch(opcionMenu)
			{
				case 1:
					if(banderaOperandoPrimero)
					{
						printf("\n----- Elección errónea: ya ingreso el primero operando -----\n");
						limitarIncorrectas--;
					}
					else
					{
						limitarIncorrectas = OPCIONES_INCORRECTAS_MAXIMAS;
						exitoFuncion = utn_getNumber(&operandoPrimero, "Ingrese el primer operando: ", "----- Ingreso incorrecto -----\n", 3);
						banderaOperandoPrimero = 1;
					}
					break;

				case 2:
					if(!banderaOperandoPrimero)
					{
						printf("\n----- Elección errónea: primero debe ingresar el primer operando -----\n");
						limitarIncorrectas--;
					}
					else if(banderaOperandoSegundo)
					{
						printf("----- Elección errónea: ya ingreso el segundo operando operando -----\n");
						limitarIncorrectas--;

					}
					else
					{
						limitarIncorrectas = OPCIONES_INCORRECTAS_MAXIMAS;
						exitoFuncion = utn_getNumber(&operandoSegundo, "Ingrese el segundo operando: ", "----- Ingreso incorrecto -----\n", 3);
						banderaOperandoSegundo = 1;
					}
					break;

				case 3:
					if(!banderaOperandoPrimero || !banderaOperandoSegundo)
					{
						printf("\n----- Elección errónea: primero debe ingresar los operandos -----\n");
						limitarIncorrectas--;
					}
					else if(banderaCalculos)
					{
						printf("\n----- Elección errónea: Ya hizo todos los cálculos -----\n");
						limitarIncorrectas--;
					}
					else
					{
						sumInt(&resultadoSuma, operandoPrimero, operandoSegundo);
						restInt(&resultadoResta, operandoPrimero, operandoSegundo);
						exitoFuncionDivision = divInt(&resultadoDivision, operandoPrimero, operandoSegundo);
						multiInt(&resultadoMultip, operandoPrimero, operandoSegundo);




					}
				} // Termina switch
			} // Sale del if

		// Resta de los limites de incorrectas en caso de que los llamados de funciones devuelvan 0.
		if (exitoFuncion == 0)
		{
			limitarIncorrectas--;
		}
		else if(exitoFuncion == 1) // Vuelve al máximo permitido (tampoco soy malo).
		{
			limitarIncorrectas = OPCIONES_INCORRECTAS_MAXIMAS;
		}

		// Si se llega al máximo permitido de erróres generales, se sale del programa.
		if(limitarIncorrectas == 0)
		{
			printf("\n----- Límites de errores máximos alcanzados. Salida del programa. ----- ");
			opcionMenu = 5;
		}

	}while(opcionMenu != 5);



	return EXIT_SUCCESS;
}
