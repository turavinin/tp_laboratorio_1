#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "prints.h"

/** \brief Imprime por consola el header de la tabla
 *
 * \return void
 *
 */
void prints_Header()
{

	int w[7] = {10, 20, 15, 15, 15, 15, 15};
	printf("\n|%-*s|%-*s|%-*s|%-*s|\n", w[0],"ID", w[1],"NOMBRE", w[2],"HS TRABAJADAS", w[3],"SUELDO");
}

/** \brief Imprime empleado con la opción de incluir header o no
 *
 * \param id int
 * \param nombre char*
 * \param horasTrabajadas int
 * \param sueldo int
 * \param opcionEncabezado int
 * \return void
 *
 */
void prints_Employee(int id, char* nombre, int horasTrabajadas, int sueldo, int opcionEncabezado)
{
	int w[7] = {10, 20, 15, 15, 15, 15, 15};
	if(opcionEncabezado == 1)
	{
		printf("\n|%-*s|%-*s|%-*s|%-*s|\n", w[0],"ID", w[1],"NOMBRE", w[2],"HS TRABAJADAS", w[3],"SUELDO");
	}

	printf("|%-*d|%-*s|%-*d|%-*d|\n", w[0], id, w[1], nombre, w[2], horasTrabajadas, w[3], sueldo);
}
