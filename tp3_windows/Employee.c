#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "bibliotecaUTN-validaciones.h"

/** \brief Inicializa a la estructura employee.
 *
 * \return Employee*
 *
 */
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
/** \brief Inicializa con parametros a la estructura employee.
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
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

int employee_delete(Employee* this)
{
	int exito = -1;
	if(this != NULL)
	{
		free(this);
		exito = 0;
	}
	return exito;
}

/** \brief Le asigna un id al empleado.
 *
 * \param this Employee*
 * \param id int

 * \return int (-1 => fallo // 0 => exito)
 *
 */
int employee_setId(Employee* this,int id)
{
	int exito = -1;

	if(this != NULL)
	{
		if(id > 0)
		{
			(*this).id = id;
			exito = 0;
		}
	}

	return exito;
}

/** \brief Obtiene el ID del empleado.
 *
 * \param this Employee*
 * \param id int*

 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Calcula el siguiente ID consecutivo a asignar segun la lista pasada.
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int*

 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Setea el siguiente ID consecutivo a asignar segun la lista pasada.
 *
 * \param pArrayListEmployee LinkedList*
 * \param this Employee*

 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Pasa lo empleados de una lista a otra reasignando los ID.
 *
 * \param listFrom LinkedList*
 * \param listTo LinkedList*

 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Le asigna un NOMBRE al empleado.
 *
 * \param this Employee*
 * \param nombre char*

 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Obtiene el NOMBRE del empleado.
 *
 * \param this Employee*
 * \param nombre char*

 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Le asigna las HORAS TRABAJADAS al empleado.
 *
 * \param this Employee*
 * \param horasTrabajadas int

 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Obtiene las HORAS TRABAJADAS del empleado.
 *
 * \param this Employee*
 * \param horasTrabajadas int*

 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Le asigna el SUELDO al empleado.
 *
 * \param this Employee*
 * \param sueldo int

 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Obtiene el SUELDO del empleado.
 *
 * \param this Employee*
 * \param sueldo int*

 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Pide el nombre por consola y se lo cambia al empleado
 *
 * \param this Employee*
 * \param char char*
 * \param errorMensaje char*
 * \param finalErrorMensaje char*
 * \param maxChar int
 * \param maxError int

 * \return int (-1 => fallo // 0 => exito)
 *
 */
int employee_editName(Employee* this, char* mensaje, char* errorMensaje, char* finalErrorMensaje, int maxChar, int maxError)
{
	int exito = -1;
	char auxNombre[LARGO_CHAR];

	if(this != NULL)
	{
		exito = utn_getStringCompuesto(auxNombre, mensaje, errorMensaje, maxChar, maxError);
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

/** \brief Pide las hs trabajadas por consola y se las cambia al empleado
 *
 * \param this Employee*
 * \param char char*
 * \param errorMensaje char*
 * \param finalErrorMensaje char*
 * \param maxError int

 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Pide el sueldo por consola y se lo cambia al empleado
 *
 * \param this Employee*
 * \param char char*
 * \param errorMensaje char*
 * \param finalErrorMensaje char*
 * \param maxError int

 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Funcion de ordenamiento por SUELDO
 *
 * \param empleadoUno void*
 * \param empleadoDos void*
 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Funcion de ordenamiento por ID
 *
 * \param empleadoUno void*
 * \param empleadoDos void*
 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Funcion de ordenamiento por HS TRABAJADAS
 *
 * \param empleadoUno void*
 * \param empleadoDos void*
 * \return int (-1 => fallo // 0 => exito)
 *
 */
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

/** \brief Funcion de ordenamiento por NOMBRE
 *
 * \param empleadoUno void*
 * \param empleadoDos void*
 * \return int (-1 => fallo // 0 => exito)
 *
 */
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
