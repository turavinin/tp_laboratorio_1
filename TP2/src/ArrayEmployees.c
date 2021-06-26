#include "ArrayEmployees.h"
#include "bibliotecaUTN-validaciones.h"
#include <stdio.h>
#include <stdlib.h>

// INIT
int initEmployees(Employee* eArr, int size)
{
	int functionSuccess = -1;
	Employee freeEmployee;
	if(eArr != NULL && size > 0)
	{
		for(int i = 0; i < size; i++)
		{
			eArr[i] = freeEmployee;
			eArr[i].isEmpty = 1;
		}
		functionSuccess = 0;
	}
	return functionSuccess;
}

// ADD
int eEmployee_SearchEmpty(Employee* eArr, int size, int* freeSpot)
{
	int functionSuccess = -1;

	if(eArr != NULL && size > 0)
	{
		for(int i = 0; i < size; i++)
		{
			if(eArr[i].isEmpty == 1)
			{
				*freeSpot = i;
				functionSuccess = 0;
				break;
			}
		}

		if(functionSuccess == -1)
		{
			*freeSpot = -1;
		}
	}
	return functionSuccess;
}
int addEmployees(Employee* eArr, int size, int id, char* name, char* lastName, float salary, int sector, int freeSpot)
{
	int functionSuccess = -1;
	if(eArr != NULL && size > 0)
	{
		eArr[freeSpot].id = id;
		strcpy(eArr[freeSpot].name, name);
		strcpy(eArr[freeSpot].lastName, lastName);
		eArr[freeSpot].salary = salary;
		eArr[freeSpot].sector = sector;
		eArr[freeSpot].isEmpty = 0;
		functionSuccess = 0;
	}

	return functionSuccess;
}
int eEmployee_Create(Employee* eArr, int size, int* defaultID)
{
	int functionSuccess = -1;
	int localSuccess = -1;
	int freeSpot = 0;
	int auxID = *defaultID;

	// Aux variables
	char auxName[MAX_CHAR_CADENAS];
	char auxLastName[MAX_CHAR_CADENAS];
	float auxSalary;
	int auxSector;

	localSuccess = eEmployee_SearchEmpty(eArr, size, &freeSpot);
	if(localSuccess == 0 && freeSpot != -1)
	{
		localSuccess = -1;
		printf("\n| AGREGAR EMPLEADO ------------------------|");
		if(utn_getStringCompuesto(auxName,
				"\n| Ingrese el nombre(s): ",
				"| -- Ingreso incorrecto --\n",
				MAX_CHAR_CADENAS, MAX_ERRORES) == 0 &&
				utn_getStringCompuesto(auxLastName,
						"| Ingrese el apellido(s): ",
						"| -- Ingreso incorrecto --\n",
						MAX_CHAR_CADENAS, MAX_ERRORES) == 0 &&
						utn_getFloat(&auxSalary,
								"| Ingrese el salario: ",
								"| -- Ingreso incorrecto --\n", MAX_ERRORES) == 0 &&
								utn_getNumber(&auxSector,
										"| Ingrese el sector: ",
										"| -- Ingreso incorrecto --\n",
										MAX_ERRORES) == 0)
		{
			localSuccess = addEmployees(eArr, size, auxID, auxName, auxLastName, auxSalary, auxSector, freeSpot);
			*defaultID = auxID + 1;
			functionSuccess = 0;
		}
	}


	if(freeSpot == -1)
	{
		printf("\n// ¡ESPACIO EN LA MEMORIA INSUFICIENTE!  //");
	}

	if(functionSuccess != 0)
	{
		printf("\n// ¡NO SE PUDO INGRESAR EMPLEADO!  //\n");
	}

	return functionSuccess;

}

// FIND
int findEmployeeById(Employee* eArr, int size, int idEmployee, int* employeePosition)
{
	int functionSuccess = -1;
	int auxPos;

	if(eArr != NULL && size > 0)
	{
		for(int i = 0; i < size; i++)
		{
			if(eArr[i].id == idEmployee)
			{
				auxPos = i;
				*employeePosition = auxPos;
				functionSuccess = 0;
				break;
			}
		}
	}
	return functionSuccess;
}
int getIdEmployee(int* idEmployee, char* message, char* errorMessage, char* messageNotFound, Employee* eArr, int size, int maxErrors)
{
	int functionSuccess = -1;
	int localSuccess = -1;
	int auxId = -1;

	if(eArr != NULL && size > 0)
	{
		localSuccess = utn_getNumber(&auxId, message, errorMessage, maxErrors);

		if(localSuccess == 0)
		{
			for(int i = 0; i < size; i++)
			{
				if(eArr[i].id == auxId && eArr[i].isEmpty == 0)
				{
					*idEmployee = auxId;
					functionSuccess = 0;
					localSuccess = 0;
					break;
				}
				localSuccess = -1;
			}

			if(localSuccess == -1)
			{
				printf(messageNotFound);
			}
		}
	}

	return functionSuccess;
}
int checkEmployeeArr(Employee* eArr, int size)
{
	int functionSuccess;
	if(eArr != NULL && size > 0)
	{
		for(int i = 0; i < size; i++)
		{
			if(eArr[i].isEmpty == 0)
			{
				functionSuccess = 0;
				break;
			}
		}
	}
	return functionSuccess;
}

// EDIT
int editNameEmployee(Employee* employee, char* message, char* errorMessage, char* finalErrorMessage, int maxChar, int maxErrors, int position)
{
	int functionSuccess = -1;
	char name[maxChar];
	int localSuccess = utn_getStringCompuesto(name, message, errorMessage, maxChar, maxErrors);

	if(localSuccess == 0)
	{
		strcpy(employee[position].name, name);
		functionSuccess = 0;
	}
	else{
		printf(finalErrorMessage);
	}

	return functionSuccess;
}
int editLastNameEmployee(Employee* employee, char* message, char* errorMessage, char* finalErrorMessage, int maxChar, int maxErrors, int position)
{
	int functionSuccess = -1;
	char lastName[maxChar];
	int localSuccess = utn_getStringCompuesto(lastName, message, errorMessage, maxChar, maxErrors);

	if(localSuccess == 0)
	{
		strcpy(employee[position].lastName, lastName);
		functionSuccess = 0;
	}
	else{
		printf(finalErrorMessage);
	}

	return functionSuccess;
}
int editSalaryEmployee(Employee* employee, char* message, char* errorMessage, char* finalErrorMessage, int maxErrors, int position)
{
	int functionSuccess = -1;
	float newSalary;
	int localSuccess = utn_getFloat(&newSalary, message, errorMessage, maxErrors);

	if(localSuccess == 0)
	{
		employee[position].salary = newSalary;
		functionSuccess = 0;
	}
	else{
		printf(finalErrorMessage);
	}

	return functionSuccess;
}
int editSectorEmployee(Employee* employee, char* message, char* errorMessage, char* finalErrorMessage, int maxErrors, int position)
{
	int functionSuccess = -1;
	int newSector;
	int localSuccess = utn_getNumber(&newSector, message, errorMessage, maxErrors);

	if(localSuccess == 0)
	{
		employee[position].sector = newSector;
		functionSuccess = 0;
	}
	else{
		printf(finalErrorMessage);
	}

	return functionSuccess;
}
int eEmployee_Edit(Employee* eArr, int size)
{
	int functionSuccess = -1;
	int localSuccess;
	int editOption;
	int idEmployee;
	int positionEmployee;

	int employeeExists = checkEmployeeArr(eArr, size);
	if(employeeExists == 0)
	{
		do
		{
			localSuccess = utn_getNumberLimited(&editOption,
										"\n| MODIFICAR EMPLEADO ------------------------|"
										"\n| 1.Modificar nombre                         |"
										"\n| 2.Modificar apellido                       |"
					 	 	 			"\n| 3.Modificar salario                        |"
					            		"\n| 4.Modificar sector                         |"
										"\n| 0.Cancelar                                 |"
					            		"\n|--------------------------------------------|"
										"\n| Selecciones una opcion: ",
										"\n|          // OPCION INCORRECTA //           |",
										0, 4, MAX_ERRORES);

			if(localSuccess == 0 && editOption != 0)
			{
				printEmployeesTable(eArr, size);
				localSuccess = getIdEmployee(&idEmployee,
									       "\n| Ingrese el ID del empleado: ",
						                   "| -- Error.",
										   "\n\n    // NO SE ENCONTRO AL EMPLEADO BUSCADO //\n\n",
										   eArr, size, MAX_ERRORES);
				if(localSuccess == 0)
				{
					findEmployeeById(eArr, size, idEmployee, &positionEmployee);
					switch(editOption)
					{
						case 1:
							editNameEmployee(eArr,
											"\n| Ingrese el nuevo nombre del empleado: ",
											"| -- Error.",
											"\n\n    // NO FUE POSIBLE EDITAR EL NOMBRE. INTENE DE NUEVO. //\n\n",
											MAX_CHAR_CADENAS, MAX_ERRORES, positionEmployee);
							editOption = 0;
							break;
						case 2:
							editLastNameEmployee(eArr,
											     "\n| Ingrese el nuevo apellido del empleado: ",
												 "| -- Error.",
												 "\n\n    // NO FUE POSIBLE EDITAR EL APELLIDO. INTENE DE NUEVO. //\n\n",
												 MAX_CHAR_CADENAS, MAX_ERRORES, positionEmployee);
							editOption = 0;
							break;
						case 3:
							editSalaryEmployee(eArr,
										      "\n| Ingrese el nuevo salario del empleado: ",
											  "| -- Error.",
											  "\n\n    // NO FUE POSIBLE EDITAR EL SALARIO. INTENE DE NUEVO. //\n\n",
											  MAX_ERRORES, positionEmployee);
							editOption = 0;
							break;
						case 4:
							editSectorEmployee(eArr,
									          "\n| Ingrese el nuevo sector del empleado: ",
											  "| -- Error.",
											  "\n\n    // NO FUE POSIBLE EDITAR EL SECTOR. INTENE DE NUEVO. //\n\n",
											  MAX_ERRORES, positionEmployee);
							editOption = 0;
							break;
					}
				}
			}
		} while(editOption != 0 || localSuccess != 0);

		if(localSuccess != 0)
		{
			printf("\n\n    // NO FUE POSIBLE MODIFICAR AL EMPLEADO //\n\n");
		}
		else
		{
			functionSuccess = 0;
			printf("| EL EMPLEADO FUE EDITADO CORRECTAMENTE.\n\n");
		}
	}
	else
	{
		printf("\n\n    // NO SE ENCONTRO EMPLEADOS EN LA BASE //\n\n");
	}



	return functionSuccess;
}

// REMOVE
int removeEmployee(Employee* eArr, int position)
{
	int functionSuccess = -1;
	if(eArr != NULL)
	{
		eArr[position].isEmpty = 1;
		functionSuccess = 0;
	}
	return functionSuccess;
}
int eEmployee_Delete(Employee* eArr, int size)
{
	int functionSuccess = -1;
	int localSuccess;
	int auxId;
	int existenEmpleados = -1;
	int positionEmployee;

	if(eArr != NULL && size > 0)
	{
		existenEmpleados = checkEmployeeArr(eArr, size);
		if(existenEmpleados == 0)
		{
			printEmployeesTable(eArr, size);
			printf("\n| BAJA DE EMPLEADO");
			localSuccess = getIdEmployee(&auxId,
								  "\n| Ingrese ID del Empleado: ",
								  "\n| --Error.",
								  "\n\n    // NO SE ENCONTRO AL EMPLEADO EN LA BASE //\n\n",
								  eArr, size, 3);
			if(localSuccess == 0)
			{
				if(findEmployeeById(eArr, size, auxId, &positionEmployee) == 0 &&
				removeEmployee(eArr, positionEmployee) == 0)
				{
					printf("| SE ELIMINO AL EMPLEADO CORRECTAMENTE //\n");
					localSuccess = 0;
				}

			}

			if(localSuccess != 0)
			{
				printf("| NO FUE POSIBLE ELIMINAR AL EMPLEADO //\n");
			}
		}
		else
		{
			printf("\n\n    // NO SE ENCONTRO EMPLEADOS EN LA BASE.\n\n");
		}
	}

	return functionSuccess;
}

// SORT
void swapEmployees(Employee* eArr, int firstPosition, int secondPosition)
{
	Employee aux;
	aux = eArr[firstPosition];
	eArr[firstPosition] = eArr[secondPosition];
	eArr[secondPosition] = aux;
}
int sortEmployees(Employee* eArr, int size, int order)
{
	int functionSuccess = -1;

	if(eArr != NULL && size > 0)
	{
		switch(order)
		{
			case 1:
				for(int i = 0; i < size -1; i++)
				{
					for(int j = 1; j < size; j++)
					{
						if(strcmp(eArr[i].lastName, eArr[j].lastName) < 0 ||
								(strcmp(eArr[i].lastName, eArr[j].lastName) == 0 && eArr[i].sector < eArr[j].sector))
						{
							swapEmployees(eArr, i, j);
							functionSuccess = 0;
						}
					}
				}
				break;
			case 2:
				for(int i = 0; i < size -1; i++)
				{
					for(int j = 1; j < size; j++)
					{
						if(strcmp(eArr[i].lastName, eArr[j].lastName) < 0 ||
								(strcmp(eArr[i].lastName, eArr[j].lastName) == 0 && eArr[i].sector < eArr[j].sector))
						{
							swapEmployees(eArr, i, j);
							functionSuccess = 0;
						}
					}
				}
				break;
		}
	}

	return functionSuccess;
}

// CALCULATE
int obtenerTotalSalarios(Employee* eArr, int size, float* totalSalary, float* averageSalary)
{
	int functionSuccess = -1;
	int i;
	float auxTotal = 0;
	int auxCont = 0;

	if(eArr != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			if(eArr[i].isEmpty == 0)
			{
				auxCont++;
				auxTotal += eArr[i].salary;
			}
		}

		*totalSalary = auxTotal;
		*averageSalary = auxTotal / auxCont;
		functionSuccess = 0;
	}

	return functionSuccess;
}
int obtenerEmpleadosMayorSalario(Employee* eArr, int size, int* contEmployeeHiger, float avarageSalary, int* posArr)
{
	int functionSuccess = -1;
	int auxEmployee = 0;
	int i;
	int j = 0;

	if(eArr != NULL && eArr > 0)
	{
		for(i = 0; i < size; i++)
		{
			if(eArr[i].isEmpty == 0 && eArr[i].salary > avarageSalary)
			{
				*(posArr + j) = i;
				auxEmployee++;
				j++;
			}
		}

		*contEmployeeHiger = auxEmployee;
		functionSuccess = 0;
	}
	return functionSuccess;
}

// PRINT
void printEmployee(Employee employee)
{
	int w[MAX_COL] = {15, 15, 15, 15, 15};
	printf("|%-*d|%-*s|%-*s|%-*.2f|%-*d|\n",
			w[0], employee.id, w[1], employee.name, w[2], employee.lastName, w[3], employee.salary, w[4], employee.sector);

}
int printEmployees(Employee* eArr, int size, int order)
{
	int functionSuccess = -1;
	int printOption;
	float salary = 0;
	float avarage = 0;
	int contHigherSalaryEmployees = 0;
	int* auxArr = (int*) malloc(sizeof(int) * MAX_ARR);

	int employeeExists = checkEmployeeArr(eArr, size);
	if(employeeExists == 0)
	{

		functionSuccess = utn_getNumberLimited(&printOption,
						"\n| INFORMES -----------------------------------------------------------------------------|"
						"\n| 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector           |"
						"\n| 2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio. |"
						"\n| 3. Cancelar                                                                           |"
						"\n|---------------------------------------------------------------------------------------|"
						"\n| Seleccione una opción (Ingrese su número): ",
						"\n|    --- ¡LA OPCION INGRESADA ES INCORRECTA! ---     |\n",
						0, 3, 3);

		if(functionSuccess == 0 && printOption != 3)
		{
			switch(printOption)
			{
			case 1:
				sortEmployees(eArr, size, order);
				printEmployeesTable(eArr, size);
				break;
			case 2:
				obtenerTotalSalarios(eArr, size, &salary, &avarage);
				obtenerEmpleadosMayorSalario(eArr, size, &contHigherSalaryEmployees, avarage, auxArr);
				printInfoSalary(eArr, salary, avarage, contHigherSalaryEmployees, auxArr);
				break;
			}
		}
	}
	else
	{
		printf("\n\n    // NO SE ENCONTRO EMPLEADOS EN LA BASE //\n\n");
	}


	return functionSuccess;
}
int printEmployeesTable(Employee* eArr, int size)
{
	int functionSuccess = -1;
	int w[MAX_COL] = {15, 15, 15, 15, 15};

	int employeeExists = checkEmployeeArr(eArr, size);
	if(employeeExists == 0)
	{
		printf("\n|TABLA EMPLEADOS");
		printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|\n", w[0],"ID", w[1],"NOMBRE", w[2],"APELLIDO", w[3],"SALARIO", w[4],"SECTOR");
		for(int i = 0; i < size; i++)
		{
			if(eArr[i].isEmpty == 0)
			{
				printEmployee(eArr[i]);
			}
		}
	}
	else
	{
		printf("\n\n    // NO SE ENCONTRO EMPLEADOS EN LA BASE //\n\n");
	}


	return functionSuccess;
}
void printInfoSalary(Employee* eArr, float salary, float avarage, int contHigherSalaryEmployees, int* posArr)
{
	int w[MAX_COL] = {15, 15, 15, 15, 15};
	char nombreCompleto[MAX_CHAR_CADENAS];
	int j;



	printf("\n\n|INFORMACION SOBRE SALARIOS");
	printf("\n|%-*s|%-*s|%-*s\n", w[0],"TOTAL SALARIOS", w[1],"PROM. SALARIOS", w[2],"CANT.EMPLEADOS QUE SUPERAN PROMEDIO");
	printf("|%-*.2f|%-*.2f|%-*d\n", w[0], salary, w[1], avarage, w[2], contHigherSalaryEmployees);

	printf("|%-*s\n", w[0],"\n|EMPLEADOS QUE SUPERAN PROMEDIO:");
	for(int i = 0; i < contHigherSalaryEmployees; i++)
	{
		j = posArr[i];
		utn_FormatoNombreCompleto(eArr[j].name, eArr[j].lastName, nombreCompleto);
		printf("|%-*s\n", w[0], nombreCompleto);
	}
}







