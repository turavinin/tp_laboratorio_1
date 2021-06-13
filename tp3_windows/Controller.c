#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "prints.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int exito = -1;
	FILE* file;
	if(pArrayListEmployee != NULL)
	{
		file = fopen(path, "r");
		if(file != NULL)
		{
			exito = parser_EmployeeFromText(file, pArrayListEmployee);
			fclose(file);
		}
	}

	return exito;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int exito = -1;
	FILE* file;
	if(pArrayListEmployee != NULL)
	{
		file = fopen(path, "rb");
		if(file != NULL)
		{
			exito = parser_EmployeeFromText(file, pArrayListEmployee);
			fclose(file);
		}
	}

	return exito;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int exito = -1;
    int largoLL = ll_len(pArrayListEmployee);

    Employee* empleado;
    int id;
    char nombre[LARGO_CHAR];
    int horasTrabajadas;
    int sueldo;

    prints_Header();
    for(int i = 0; i < largoLL; i++)
    {
    	empleado = ll_get(pArrayListEmployee, i);
    	employee_getId(empleado, &id);
    	employee_getNombre(empleado, nombre);
    	employee_getHorasTrabajadas(empleado, &horasTrabajadas);
    	employee_getSueldo(empleado, &sueldo);
    	prints_Employee(id, nombre, horasTrabajadas, sueldo,  0);
    }

    return exito;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int exito = -1;

    FILE* file;
    if(pArrayListEmployee != NULL)
    {
    	file = fopen(path, "w");
    	if(file != NULL)
    	{
    		exito = parser_EmployeeToText(file, pArrayListEmployee);
    		fclose(file);
    	}
    }

    return exito;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int exito = -1;

    FILE* file;
    if(pArrayListEmployee != NULL)
    {
    	file = fopen(path, "wb");
    	if(file != NULL)
    	{
    		exito = parser_EmployeeToText(file, pArrayListEmployee);
    		fclose(file);
    	}
    }

    return exito;
}

