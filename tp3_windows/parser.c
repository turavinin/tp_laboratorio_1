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
	Employee* nuevoEmpleado = NULL;

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

		nuevoEmpleado = employee_newParametros(buffer[0],buffer[1], buffer[2], buffer[3]);
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
	Employee* nuevoEmpleado = NULL;

	fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

	while(!feof(pFile))
	{
		camposStruct = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
		if(camposStruct < CANT_STRUCT)
		{
			break;
		}

		nuevoEmpleado = employee_newParametros(buffer[0],buffer[1], buffer[2], buffer[3]);
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

/** \brief Parsea los datos los datos de los empleados al archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeToText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int exito = -1;
	int largoLL = ll_len(pArrayListEmployee);

	Employee* auxEmployee = NULL;
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

/** \brief Parsea los datos los datos de los empleados al archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeToBin(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int exito = -1;
	int largoLL = ll_len(pArrayListEmployee);

	Employee* auxEmployee = NULL;
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
