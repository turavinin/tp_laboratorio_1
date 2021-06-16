#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "bibliotecaUTN-validaciones.h"

// DEFAULT ID
int defaultId = 0;


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

	if(this != NULL)
	{
		if(id > 0)
		{
			(*this).id = id;
		}
		else if (id == 0)
		{
			(*this).id = defaultId++;
		}
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
int employee_getNextIdFromList(LinkedList* pArrayListEmployee, int* id)
{
	int exito = -1;
	Employee* auxEmployee;
	int largoLL;
	int auxId;

	if(pArrayListEmployee != NULL)
	{
		largoLL = ll_len(pArrayListEmployee);
		auxEmployee = ll_get(pArrayListEmployee, largoLL - 1);
		employee_getId(auxEmployee, &auxId);
		*id = auxId + 1;
	}
	return exito;
}
int employee_setNextIdFromList(LinkedList* pArrayListEmployee, Employee* this)
{
	int exito = -1;
	int id;

	if(pArrayListEmployee != NULL)
	{
		employee_getNextIdFromList(pArrayListEmployee, &id);
		employee_setId(this, id);
	}
	return exito;
}
int employee_addListAndSetId(LinkedList* listFrom, LinkedList* listTo)
{
	int exito = -1;
	int largoLLFrom = ll_len(listFrom);
	int largoLLTo = ll_len(listTo);
	Employee* auxEmployee;

	for(int i = 0; i < largoLLFrom; i++)
	{
		auxEmployee = ll_get(listFrom, i);
		employee_setNextIdFromList(listTo, auxEmployee);
		ll_add(listTo, auxEmployee);
	}

	if(ll_len(listTo) > largoLLTo)
	{
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

int employee_editName(Employee* this, char* mensaje, char* errorMensaje, char* finalErrorMensaje, int maxChar, int maxError)
{
	int exito = -1;
	char auxNombre[LARGO_CHAR];

	if(this != NULL)
	{
		exito = utn_getStringLimited(auxNombre, mensaje, errorMensaje, maxChar, maxError);
		if(exito == 0)
		{
			employee_setNombre(this, auxNombre);
		}
	}

	if(exito == -1)
	{
		printf(finalErrorMensaje);
	}

	return exito;
}
int employee_editHsTrabajadas(Employee* this, char* mensaje, char* errorMensaje, char* finalErrorMensaje, int maxError)
{
	int exito = -1;
	int auxHs;

	if(this != NULL)
	{
		exito = utn_getNumber(&auxHs, mensaje, errorMensaje, maxError);
		if(exito == 0)
		{
			employee_setHorasTrabajadas(this, auxHs);
		}
	}

	if(exito == -1)
	{
		printf(finalErrorMensaje);
	}

	return exito;
}
int employee_editSueldo(Employee* this, char* mensaje, char* errorMensaje, char* finalErrorMensaje, int maxError)
{
	int exito = -1;
	int auxSueldo;

	if(this != NULL)
	{
		exito = utn_getNumber(&auxSueldo, mensaje, errorMensaje, maxError);
		if(exito == 0)
		{
			employee_setSueldo(this, auxSueldo);
		}
	}

	if(exito == -1)
	{
		printf(finalErrorMensaje);
	}

	return exito;
}

int ordenaSueldo(void* empleadoUno, void* empleadoDos)
{
	int retorno;

	if((*(Employee*)empleadoUno).sueldo > (*(Employee*)empleadoDos).sueldo)
	{
		retorno = 1;
	}
	else if((*(Employee*)empleadoUno).sueldo < (*(Employee*)empleadoDos).sueldo)
	{
		retorno = -1;
	}
	else
	{
		retorno = 0;
	}
	return retorno;
}

int ordenaId(void* empleadoUno, void* empleadoDos)
{
	int retorno;

	if((*(Employee*)empleadoUno).id > (*(Employee*)empleadoDos).id)
	{
		retorno = 1;
	}
	else if((*(Employee*)empleadoUno).id < (*(Employee*)empleadoDos).id)
	{
		retorno = -1;
	}
	else
	{
		retorno = 0;
	}
	return retorno;
}

int ordenaHoras(void* empleadoUno, void* empleadoDos)
{
	int retorno;

	if((*(Employee*)empleadoUno).horasTrabajadas > (*(Employee*)empleadoDos).horasTrabajadas)
	{
		retorno = 1;
	}
	else if((*(Employee*)empleadoUno).horasTrabajadas < (*(Employee*)empleadoDos).horasTrabajadas)
	{
		retorno = -1;
	}
	else
	{
		retorno = 0;
	}
	return retorno;
}

int ordenaNombre(void* empleadoUno, void* empleadoDos)
{
	int retorno;

	if(strcmp((*(Employee*)empleadoUno).nombre, (*(Employee*)empleadoDos).nombre) > 0)
	{
		retorno = 1;
	}
	else if(strcmp((*(Employee*)empleadoDos).nombre, (*(Employee*)empleadoUno).nombre) > 0)
	{
		retorno = -1;
	}
	else
	{
		retorno = 0;
	}
	return retorno;
}
