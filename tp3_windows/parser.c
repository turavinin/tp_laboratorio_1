#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int exito = -1;
	int camposStruct;
	char buffer[CANT_STRUCT][LARGO_CHAR];

	if(ll_len(pArrayListEmployee) > 0)
	{
		ll_clear(pArrayListEmployee);
	}

	fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
	fflush(stdin);

	while(!feof(pFile))
	{
		camposStruct = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
		if(camposStruct < CANT_STRUCT)
		{
			break;
		}

		Employee* nuevoEmpleado = employee_newParametros(buffer[0],buffer[1], buffer[2], buffer[3]);
		if(nuevoEmpleado != NULL)
		{
			ll_add(pArrayListEmployee, nuevoEmpleado);
		}
		fflush(stdin);
	}

	if(ll_len(pArrayListEmployee) > 0)
	{
		exito = 0;
	}

	return exito;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int exito = -1;
	int camposStruct;
	char buffer[CANT_STRUCT][128];

	fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

	while(!feof(pFile))
	{
		camposStruct = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
		if(camposStruct < CANT_STRUCT)
		{
			break;
		}

		Employee* nuevoEmpleado = employee_newParametros(buffer[0],buffer[1], buffer[2], buffer[3]);
		if(nuevoEmpleado != NULL)
		{
			ll_add(pArrayListEmployee, nuevoEmpleado);
		}

	}

	if(ll_len(pArrayListEmployee) > 0)
	{
		exito = 0;
	}

	return exito;
}

int parser_EmployeeToText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int exito = -1;
	int largoLL = ll_len(pArrayListEmployee);

	Employee* auxEmployee;
	int id;
	char nombre[LARGO_CHAR];
	int hsTrabajadas;
	int sueldo;

	if(pFile != NULL && largoLL > 0)
	{
		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
		for(int i = 0; i < largoLL; i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);
	    	employee_getId(auxEmployee, &id);
	    	employee_getNombre(auxEmployee, nombre);
	    	employee_getHorasTrabajadas(auxEmployee, &hsTrabajadas);
	    	employee_getSueldo(auxEmployee, &sueldo);
	    	fprintf(pFile, "%d, %s, %d, %d\n", id, nombre, hsTrabajadas, sueldo);

		}
		exito = 0;
	}

	return exito;
}

int parser_EmployeeToBin(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int exito = -1;
	int largoLL = ll_len(pArrayListEmployee);

	Employee* auxEmployee;
	int id;
	char nombre[LARGO_CHAR];
	int hsTrabajadas;
	int sueldo;

	if(pFile != NULL && largoLL > 0)
	{
		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
		for(int i = 0; i < largoLL; i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);
	    	employee_getId(auxEmployee, &id);
	    	employee_getNombre(auxEmployee, nombre);
	    	employee_getHorasTrabajadas(auxEmployee, &hsTrabajadas);
	    	employee_getSueldo(auxEmployee, &sueldo);
	    	fprintf(pFile, "%d, %s, %d, %d\n", id, nombre, hsTrabajadas, sueldo);

		}
		exito = 0;
	}

	return exito;
}


/*
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int exito = -1;
	int camposStruct;
	int opcionId;
	LinkedList* auxList = ll_newLinkedList();
	char buffer[CANT_STRUCT][LARGO_CHAR];

	if(ll_len(pArrayListEmployee) > 0)
	{
		utn_getNumberLimited(&opcionId,
				"\n| ---- ATENCION: YA EXISTEN DATOS DE EMPLEADOS EN EL SISTEMA ---- |"
				"\n| ---- DESEA:                                                     |"
				"\n| 1. Reasignar los ID de los empleados guardados en el archivo.   |"
				"\n| 2. Resiganr los ID de los empleados cargados en el sistema.     |"
				"\n| 3. Salir.                                                       |"
				"\n| ----------------------------------------------------------------|"
				"\n| Seleccione una opción (ingrese su número)                       |",
				"\n|          ---- ¡LA OPCION INGRESADA ES INCORRECTA!----           |",
				1, 3, 3);
	}

	if(opcionId != 3)
	{
		if(opcionId == 2)
		{
			auxList = ll_clone(pArrayListEmployee);
		}


		fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
		fflush(stdin);

		while(!feof(pFile) && opcionId != 3)
		{
			camposStruct = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			if(camposStruct < CANT_STRUCT)
			{
				break;
			}

			Employee* nuevoEmpleado = employee_newParametros(buffer[0],buffer[1], buffer[2], buffer[3]);
			if(nuevoEmpleado != NULL)
			{
				if(opcionId == 1)
				{
					employee_setNextIdFromList(pArrayListEmployee, nuevoEmpleado);
					ll_add(pArrayListEmployee, nuevoEmpleado);
				}
				else if(opcionId == 2)
				{

				}

			}
			fflush(stdin);
		}
	}


	if(ll_len(pArrayListEmployee) > 0)
	{
		exito = 0;
	}

	return exito;
}*/
