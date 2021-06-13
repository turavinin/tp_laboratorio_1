#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

// NEW EMPLOYEE
Employee* employee_new()
{
	Employee* newEmployee = NULL;
	newEmployee = (Employee*) malloc(sizeof(Employee));

	if(newEmployee != NULL)
	{
		employee_setId(newEmployee, 0);
		employee_setNombre(newEmployee, " ");
		employee_setHorasTrabajadas(newEmployee, 0);
		employee_setSueldo(newEmployee, 0);
	}

	return newEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* newEmployee = employee_new();

	if(newEmployee != NULL)
	{
		employee_setId(newEmployee, atoi(idStr));
		employee_setNombre(newEmployee, nombreStr);
		employee_setHorasTrabajadas(newEmployee,atoi(horasTrabajadasStr));
		employee_setSueldo(newEmployee,atoi(sueldoStr));
	}

	return newEmployee;
}

// GET-SET
int employee_setId(Employee* this,int id)
{
	int exito = -1;

	if(this != NULL && id > 0)
	{
		(*this).id = id;
		exito = 0;
	}

	return exito;
}
int employee_getId(Employee* this,int* id)
{
	int exito = -1;

	if(this != NULL)
	{
		*id = (*this).id;
		exito = 0;
	}

	return exito;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int exito = -1;

	if(this != NULL && strlen(nombre) > 0)
	{
		strcpy((*this).nombre, nombre);
		exito = 0;
	}

	return exito;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int exito = -1;

	if(this != NULL)
	{
		strcpy(nombre, (*this).nombre);
		exito = 0;
	}

	return exito;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int exito = -1;

	if(this != NULL && horasTrabajadas > 0)
	{
		(*this).horasTrabajadas = horasTrabajadas;
		exito = 0;
	}

	return exito;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int exito = -1;

	if(this != NULL)
	{
		*horasTrabajadas = (*this).horasTrabajadas;
		exito = 0;
	}

	return exito;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int exito = -1;

	if(this != NULL && sueldo > 0)
	{
		(*this).sueldo = sueldo;
		exito = 0;
	}

	return exito;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int exito = -1;

	if(this != NULL)
	{
		*sueldo = (*this).sueldo;
		exito = 0;
	}

	return exito;
}





