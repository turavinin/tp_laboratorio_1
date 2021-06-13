#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "prints.h"
int w[7] = {15, 15, 15, 15, 15, 15, 15};

void prints_Header()
{
	printf("\n|%-*s|%-*s|%-*s|%-*s|\n", w[0],"ID", w[1],"NOMBRE", w[2],"HS TRABAJADAS", w[3],"SUELDO");
}

void prints_Employee(int id, char* nombre, int horasTrabajadas, int sueldo, int opcionEncabezado)
{
	if(opcionEncabezado == 1)
	{
		printf("\n|%-*s|%-*s|%-*s|%-*s|\n", w[0],"ID", w[1],"NOMBRE", w[2],"HS TRABAJADAS", w[3],"SUELDO");
	}

	printf("|%-*d|%-*s|%-*d|%-*d|\n", w[0], id, w[1], nombre, w[2], horasTrabajadas, w[3], sueldo);
}
