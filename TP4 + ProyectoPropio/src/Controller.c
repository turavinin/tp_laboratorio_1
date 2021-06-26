#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "prints.h"
#include "bibliotecaUTN-validaciones.h"
#define MAX_ERRORES 3

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
	int opcionId = 0;
	LinkedList* auxList = ll_newLinkedList();

	FILE* file;
	if(pArrayListEmployee != NULL)
	{
		file = fopen(path, "r");
		if(file != NULL)
		{
			if(ll_len(pArrayListEmployee) > 0)
			{
				exito = utn_getNumberLimited(&opcionId,
						"\n| ---- ATENCION: YA EXISTEN DATOS DE EMPLEADOS EN EL SISTEMA ---- |"
						"\n| ---- DESEA:                                                     |"
						"\n| 1. Reasignar los ID de los empleados guardados en el archivo.   |"
						"\n| 2. Resiganr los ID de los empleados cargados en el sistema.     |"
						"\n| 3. Cargar el archivo y sobrescribir los datos.                  |"
						"\n| 4. Salir.                                                       |"
						"\n| ----------------------------------------------------------------|"
						"\n| Seleccione una opción (ingrese su número): ",
						"\n|          ---- ¡LA OPCION INGRESADA ES INCORRECTA!----           |",
						1, 4, 3);

				if(exito == -1)
				{
					opcionId = -1;
				}
			}

			if(opcionId == 1)
			{
				auxList = ll_clone(pArrayListEmployee);
				exito = parser_EmployeeFromText(file, auxList);
				if(exito == 0)
				{
					exito = employee_addListAndSetId(auxList, pArrayListEmployee);
				}
				fclose(file);
			}
			else if(opcionId == 2)
			{
				auxList = ll_clone(pArrayListEmployee);
				exito = parser_EmployeeFromText(file, pArrayListEmployee);
				if(exito == 0)
				{
					exito = employee_addListAndSetId(auxList, pArrayListEmployee);
					if(exito == 0)
					{
						pArrayListEmployee = ll_clone(auxList);
					}
				}
				fclose(file);
			}
			else if (opcionId == 3 || opcionId == 0)
			{
				exito = parser_EmployeeFromText(file, pArrayListEmployee);
				fclose(file);
			}
			else if(opcionId == 4)
			{
				printf("\n ---- CARGA DE DATOS CANCELADA ---- \n");
			}
		}
	}

	if(exito == -1)
	{
		printf("\n ---- NO FUE POSIBLE CARGAR EL ARCHIVO ---- \n");
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
	int opcionId = 0;
	LinkedList* auxList = ll_newLinkedList();

	FILE* file;
	if(pArrayListEmployee != NULL)
	{
		file = fopen(path, "rb");
		if(file != NULL)
		{
			if(ll_len(pArrayListEmployee) > 0)
			{
				utn_getNumberLimited(&opcionId,
						"\n| ---- ATENCION: YA EXISTEN DATOS DE EMPLEADOS EN EL SISTEMA ---- |"
						"\n| ---- DESEA:                                                     |"
						"\n| 1. Reasignar los ID de los empleados guardados en el archivo.   |"
						"\n| 2. Resiganr los ID de los empleados cargados en el sistema.     |"
						"\n| 3. Cargar el archivo y sobrescribir los datos.                  |"
						"\n| 4. Salir.                                                       |"
						"\n| ----------------------------------------------------------------|"
						"\n| Seleccione una opción (ingrese su número): ",
						"\n|          ---- ¡LA OPCION INGRESADA ES INCORRECTA!----           |",
						1, 4, 3);
			}

			if(opcionId == 1)
			{
				auxList = ll_clone(pArrayListEmployee);
				exito = parser_EmployeeFromText(file, auxList);
				if(exito == 0)
				{
					exito = employee_addListAndSetId(auxList, pArrayListEmployee);
				}
				fclose(file);
			}
			else if(opcionId == 2)
			{
				auxList = ll_clone(pArrayListEmployee);
				exito = parser_EmployeeFromText(file, pArrayListEmployee);
				if(exito == 0)
				{
					exito = employee_addListAndSetId(auxList, pArrayListEmployee);
					if(exito == 0)
					{
						pArrayListEmployee = ll_clone(auxList);
					}
				}
				fclose(file);
			}
			else if (opcionId == 3 || opcionId == 0)
			{
				exito = parser_EmployeeFromText(file, pArrayListEmployee);
				fclose(file);
			}
			else
			{
				printf("\nCARGA DE DATOS DEL ARCHIVO CANCELADA.");
			}
		}
	}

	if(exito == -1)
	{
		printf("\nNO SE PUDO CARGAR EL ARCHIVO");
	}

	return exito;
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

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int exito = -1;
	Employee* newEmployee;
	int auxId = 1;
	char auxNombre[LARGO_CHAR];
	int auxHsTrabajdas;
	int auxSueldo;

	newEmployee = employee_new();

	printf("\n| AGREGAR EMPLEADO ------------------------|\n");
	if(utn_getStringCompuesto(auxNombre,
			"| Ingrese el nombre: ",
			"| -- Ingreso incorrecto --\n",
			LARGO_CHAR, MAX_ERRORES) == 0 &&
			utn_getNumber(&auxHsTrabajdas,
					"| Ingrese las horas trabajadas: ",
					"| -- Ingreso incorrecto --\n",
					MAX_ERRORES) == 0 &&
					utn_getNumber(&auxSueldo,
							"| Ingrese el sueldo: ",
							"| -- Ingreso incorrecto --\n",
							MAX_ERRORES) == 0)
	{
		if(ll_len(pArrayListEmployee) > 0)
		{
			employee_getNextIdFromList(pArrayListEmployee, &auxId);
		}

		if(employee_setId(newEmployee, auxId) == 0 &&
		employee_setNombre(newEmployee, auxNombre) == 0 &&
		employee_setHorasTrabajadas(newEmployee, auxHsTrabajdas) == 0 &&
		employee_setSueldo(newEmployee, auxSueldo) == 0)
		{
			exito = ll_add(pArrayListEmployee, newEmployee);
		}

		if(exito == 0)
		{
			printf("\n|EMPLEADO DADO DE ALTA:");
			employee_getId(newEmployee, &auxId);
			prints_Employee(auxId, auxNombre, auxHsTrabajdas, auxSueldo, 1);
		}
	}

	if(exito != 0)
	{
		printf("\n// ¡NO SE PUDO DAR DE ALTA AL EMPLEADO!  //\n");
	}

	return exito;
}

/** \brief Pide al usuario el ID del empleado por consola y devulve por parametro su INDEX.
 *
 * \param pArrayListEmployee LinkedList*
 * \param mensaje char*
 * \param mensajeError char*
 * \param mensajeNoEncontrado char*
 * \param index int*
 * \param maxErrores int
 * \return int (-1 => si hubo errores // 0 => si salió bien)
 *
 */
int controller_getPosByIdFromConsole(LinkedList* pArrayListEmployee, char* mensaje, char* mensajeError, char* mensajeNoEncontrado, int* index, int maxErrores)
{
	int exito = -1;
	int exitoLocal = -1;
	int auxId;
	int largoLL;
	Employee* auxEmployee;
	if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
	{
		exitoLocal = utn_getNumber(&auxId, mensaje, mensajeError, maxErrores);

		if(exitoLocal == 0)
		{
			largoLL = ll_len(pArrayListEmployee);
			for(int i = 0; i < largoLL; i++)
			{
				exitoLocal = -1;
				auxEmployee = ll_get(pArrayListEmployee, i);
				if((*auxEmployee).id == auxId)
				{
					*index = i;
					exito = 0;
					exitoLocal = 0;
					break;
				}
			}

			if(exitoLocal == -1)
			{
				printf(mensajeNoEncontrado);
			}
		}
	}

	return exito;
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
    int exito = -1;
    int opcionEditar;
    int indexEmployee;
    Employee* employee;

    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
    {
    	do
    	{
    		exito = utn_getNumberLimited(&opcionEditar,
    				"\n| MODIFICAR EMPLEADO ------------------------|"
    				"\n| 1.Modificar nombre                         |"
    				"\n| 2.Modificar horas trabajadas               |"
    				"\n| 3.Modificar sueldo                         |"
    				"\n| 4.Cancelar                                 |"
    				"\n|--------------------------------------------|"
    				"\n| Selecciones una opcion: ",
					"\n|          // OPCION INCORRECTA //           |",
					1, 4, MAX_ERRORES);

    		if(exito == 0 && opcionEditar != 4)
    		{
    			controller_ListEmployee(pArrayListEmployee);
    			exito =  controller_getPosByIdFromConsole(pArrayListEmployee,
    					"\n| Ingrese el ID del empleado: ",
						"| -- Error.",
						"\n\n   ---- NO SE ENCONTRO AL EMPLEADO BUSCADO ----   \n\n", &indexEmployee, MAX_ERRORES);

    			if(exito == 0)
    			{
    				employee = ll_get(pArrayListEmployee, indexEmployee);
    				switch(opcionEditar)
    				{
    				case 1:
    					employee_editName(employee,
    							"| Ingrese el nuevo nombre del empleado: ",
								"| -- Error.\n",
								"\n\n    ---- NO FUE POSIBLE EDITAR EL NOMBRE. INTENE DE NUEVO. ----\n\n",
								LARGO_CHAR, MAX_ERRORES);
    					opcionEditar = 4;
    					break;
    				case 2:
    					employee_editHsTrabajadas(employee,
    							"| Ingrese las nuevas horas trabajadas: ",
								"| -- Error.\n",
								"\n\n    ---- NO FUE POSIBLE EDITAR EL NOMBRE. INTENE DE NUEVO. ----\n\n",
								MAX_ERRORES);
    					opcionEditar = 4;
    					break;
    				case 3:
    					employee_editSueldo(employee,
    							"| Ingrese el nuevo sueldo: ",
								"| -- Error.\n",
								"\n\n    ---- NO FUE POSIBLE EDITAR EL NOMBRE. INTENE DE NUEVO. ----\n\n",
								MAX_ERRORES);
    					opcionEditar = 4;
    					break;
    				}
    			}
    		}
    	} while(exito != 0 || opcionEditar != 4);

    	if(exito != 0)
    	{
    		printf("\n\n    ---- NO FUE POSIBLE MODIFICAR AL EMPLEADO ----\n\n");
    		system("pause");
    	}
    	else
    	{
    		printf("\n| EL EMPLEADO FUE EDITADO CORRECTAMENTE:");
    		prints_Employee((*employee).id, (*employee).nombre, (*employee).horasTrabajadas, (*employee).sueldo, 1);
    		printf("\n");
    		system("pause");
    	}

    }
	else
	{
		printf("\n    ---- NO SE ENCONTRO EMPLEADO EN LA BASE ----\n\n");
		system("pause");
	}

    return exito;
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
    int exito = -1;
    int index;
    char confirmacion = 'n';

    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
    {
    	controller_ListEmployee(pArrayListEmployee);
    	exito =  controller_getPosByIdFromConsole(pArrayListEmployee,
    	    					"\n| Ingrese el ID del empleado a eliminar: ",
    							"| -- Error.",
    							"\n\n   ---- NO SE ENCONTRO AL EMPLEADO BUSCADO ----   \n\n", &index, MAX_ERRORES);

    	if(exito == 0)
    	{
    		exito = utn_getCharDosOpciones(&confirmacion,
    				"|¿Confirma la eliminación del empleado? (S / N): ",
					"| -- Ingreso incorrecto --\n",
					's', 'n', MAX_ERRORES);

    		if(confirmacion == 's')
    		{
    			if(employee_delete(ll_get(pArrayListEmployee, index)) == 0 && ll_remove(pArrayListEmployee, index) == 0 )
    			{
        	    	printf("\n\n   ---- SE ELIMINO CORRECTAMENTE AL EMPELADO ----   \n\n");
            		system("pause");
    			}
    		}
    	}
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
    int exito = -1;
    int opcionOrdenar;

    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
    {
    	do
    	{
    		exito = utn_getNumberLimited(&opcionOrdenar,
    				"\n| ORDENAR EMPLEADOS -------------------------|"
    				"\n| 1.Ordenar por ID                           |"
    				"\n| 2.Ordenar por NOMBRE                       |"
    				"\n| 3.Ordenar por HS TRABAJADAS                |"
    				"\n| 4.Ordenar por SUELDO                       |"
    				"\n| 5.Salir                                    |"
    				"\n|--------------------------------------------|"
    				"\n| Selecciones una opcion: ",
					"\n|          // OPCION INCORRECTA //           |",
					1, 5, MAX_ERRORES);

    		if(exito == 0 && opcionOrdenar != 5)
    		{
    			switch(opcionOrdenar)
    			{
    			case 1:
    				ll_sort(pArrayListEmployee, employee_ordenaId, 1);
    				opcionOrdenar = 5;
    				break;
    			case 2:
    				ll_sort(pArrayListEmployee, employee_ordenaNombre, 1);
    				opcionOrdenar = 5;
    				break;
    			case 3:
    				ll_sort(pArrayListEmployee, employee_ordenaHoras, 1);
    				opcionOrdenar = 5;
    				break;
    			case 4:
    				ll_sort(pArrayListEmployee, employee_ordenaSueldo, 1);
    				opcionOrdenar = 5;
    				break;
    			}


    		}
    	} while(exito != 0 || opcionOrdenar != 5);
    }

    if(exito != 0)
    {
		printf("\n    ---- NO FUE POSIBLE ORDENAR A LOS EMPLEADOS ----\n\n");
		system("pause");
    }

    return exito = 0;
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
    int opcionGuardado = 0;

    FILE* file;
    if(pArrayListEmployee != NULL)
    {
    	if(ll_len(pArrayListEmployee) == 0)
    	{
    		exito = utn_getNumberLimited(&opcionGuardado,
    				"\n| ---- ATENCION: NO HAY NINGUN DATO EN EL SISTEMA ---- |"
    				"\n| ---- DESEA:                                          |"
    				"\n| 1. Sobreescribir archivo                             |"
    				"\n| 2. Cancelar                                          |"
    				"\n| -----------------------------------------------------|"
    				"\n| Seleccione una opción (ingrese su número): ",
					"\n|  ---- ¡LA OPCION INGRESADA ES INCORRECTA!----        |",
					1, 2, 3);

    		if(exito == -1)
    		{
    			opcionGuardado = -1;
    		}

    	}

		if(opcionGuardado == 1 || opcionGuardado == 0)
		{
			file = fopen(path, "w");
			if(file != NULL)
			{
				exito = parser_EmployeeToText(file, pArrayListEmployee);
				fclose(file);
			}
		}
    }

    return exito;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin(modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int exito = -1;
	int opcionGuardado = 0;

	FILE* file;
	if(pArrayListEmployee != NULL)
	{
		if(ll_len(pArrayListEmployee) == 0)
		{
			exito = utn_getNumberLimited(&opcionGuardado,
					"\n| ---- ATENCION: NO HAY NINGUN DATO EN EL SISTEMA ---- |"
					"\n| ---- DESEA:                                          |"
					"\n| 1. Sobreescribir archivo                             |"
					"\n| 2. Cancelar                                          |"
					"\n| -----------------------------------------------------|"
					"\n| Seleccione una opción (ingrese su número): ",
					"\n|  ---- ¡LA OPCION INGRESADA ES INCORRECTA!----        |",
					1, 2, 3);

			if(exito == -1)
			{
				opcionGuardado = -1;
			}

		}

		if(opcionGuardado == 1 || opcionGuardado == 0)
		{
			file = fopen(path, "wb");
			if(file != NULL)
			{
				exito = parser_EmployeeToBin(file, pArrayListEmployee);
				fclose(file);
			}
		}
	}

	return exito;
}


