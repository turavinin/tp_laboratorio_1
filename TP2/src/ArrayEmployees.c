#include "ArrayEmployees.h"
#include "bibliotecaUTN-validaciones.h"

// TOTAL SALARIOS
float totalSalarios = 0;
float promedioSalarios = 0;
int contEmpleadosMayorSalario = 0;

// PRINTF ARRAY SPACE
int w[MAX_COL] = {15, 15, 15, 15, 15};

// ID AUTOINCREMENTAL
int idEmployee = 0;
void eEmployee_SetId(int* id)
{
	*id = idEmployee++;
}

// INIT ESTRUCTURA
int initEmployees(Employee* eArr, int largoArr)
{
	int exitoFuncion = -1;
	Employee employeeLibre;
	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			eArr[i] = employeeLibre;
			eArr[i].isEmpty = 1;
		}
		exitoFuncion = 0;
	}
	return exitoFuncion;
}

// ADD EMPLEADO
int eEmployee_SearchEmpty(Employee* eArr, int largoArr, int* posLibre)
{
	int exitoFuncion = -1;

	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].isEmpty == 1)
			{
				*posLibre = i;
				exitoFuncion = 0;
				break;
			}
		}

		if(exitoFuncion == -1)
		{
			*posLibre = -1;
		}
	}
	return exitoFuncion;
}
int addEmployees(Employee* eArr, int largoArr, int id, char* name, char* lastName, float salary, int sector, int posLibre)
{
	int exitoFuncion = -1;
	if(eArr != NULL && largoArr > 0)
	{
		eArr[posLibre].id = id;
		strcpy(eArr[posLibre].name, name);
		strcpy(eArr[posLibre].lastName, lastName);
		eArr[posLibre].salary = salary;
		eArr[posLibre].sector = sector;
		eArr[posLibre].isEmpty = 0;
		exitoFuncion = 0;
	}

	return exitoFuncion;
}
int eEmployee_Alta(Employee* eArr, int largoArr, int* existenciaProxLibre)
{
	int exitoFuncion = -1;
	int posLibre;
	int auxProxLibre = *existenciaProxLibre;
	int exito = eEmployee_SearchEmpty(eArr, largoArr, &posLibre);

	if(exito == 0)
	{
		// Variable datos
		char nombre[MAX_CHAR_CADENAS];
		char apellido[MAX_CHAR_CADENAS];
		float salario;
		int sector;

		printf("\n--- INGRESO DE NUEVO EMPLEADO ---");
		if(utn_getStringLimited(nombre, "\n    Ingrese nombre: ", "    // Error de carga //", MAX_CHAR_CADENAS, MAX_ERRORES) == 0 &&
		utn_getStringLimited(apellido, "    Ingrese su apellido: ", "    // Error de carga //", MAX_CHAR_CADENAS, MAX_ERRORES) == 0 &&
		utn_getFloat(&salario, "    Ingrese su salario: ", "    // Error de carga //", MAX_ERRORES) == 0 &&
		utn_getNumber(&sector, "    Ingrese su sector: ", "    // Error de carga //", MAX_ERRORES) == 0)
		{
			int id;
			eEmployee_SetId(&id);
			exito = addEmployees(eArr, largoArr, id, nombre, apellido, salario, sector, posLibre);
			exitoFuncion = 0;
		}
		else
		{
			exito = -1;
		}

		eEmployee_SearchEmpty(eArr, largoArr, &auxProxLibre);
		if(auxProxLibre == -1)
		{
			*existenciaProxLibre = auxProxLibre;
		}
	}

	if(exito != 0)
	{
		printf("\n// ¡NO SE PUDO INGRESAR EMPLEADO!  //\n");
	}

	return exitoFuncion;
}

// FIND EMPLEADO
int findEmployeeById(Employee* eArr, int largoArr, int idEmployee, int* pPosicionEmployee)
{
	int exitoFuncion = -1;

	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].id == idEmployee)
			{
				*pPosicionEmployee = i;
				exitoFuncion = 0;
			}
		}
	}
	return exitoFuncion;
}
int getIdEmployee(int* idEmployee, char* mensaje, char* mensajeError, char* mensajeNoEncontrado, Employee* eArr, int largoArr, int maxErrores)
{
	int exitoFuncion = -1;
	int auxId = -1;

	if(eArr != NULL && largoArr > 0)
	{
		int exito = utn_getNumber(&auxId, mensaje, mensajeError, maxErrores);

		if(exito == 0)
		{
			int i;
			for(i = 0; i < largoArr; i++)
			{
				if(eArr[i].id == auxId)
				{
					*idEmployee = auxId;
					exitoFuncion = 0;
					exito = 0;
					break;
				}
				exito = -1;
			}

			if(exito == -1)
			{
				printf(mensajeNoEncontrado);
			}
		}
	}

	return exitoFuncion;
}
int checkEmployeeArr(Employee* eArr, int largoArr)
{
	int exitoFuncion;
	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].isEmpty == 0)
			{
				exitoFuncion = 0;
				break;
			}
		}
	}
	return exitoFuncion;
}


// EDIT
int editEmployee(Employee* eArr, int largoArr)
{
	int exitoFuncion = -1;
	int exito;
	int opcionModificar;
	int opcionCancelar;
	int idEmployee;

	int existenEmpleados = checkEmployeeArr(eArr, largoArr);
	if(existenEmpleados == 0)
	{
		do
		{
			exito = utn_getNumberLimited(&opcionModificar, // ESTOS MENSAJES DEBERIAN IR EN EL MAIN
										"\n |------------ MODIFICAR ALUMNO --------------|"
										"\n | 1.Modificar nombre                         |"
										"\n | 2.Modificar apellido                       |"
					 	 	 			"\n | 3.Modificar salario                        |"
					            		"\n | 4.Modificar sector                         |"
										"\n | 0.Cancelar                                 |"
					            		"\n |--------------------------------------------|"
										"\n | Selecciones una opcion: "
										"\n |          // OPCION INCORRECTA //           |",
										0, 4, 3);
		} while();

	}



	return exitoFuncion;
}

// REMOVE EMPLOYEE
int removeEmployee(Employee* eArr, int largoArr, int idEmployee)
{
	int exitoFuncion = -1;
	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].id == idEmployee && eArr[i].isEmpty == 0)
			{
				eArr[i].isEmpty = 1;
				exitoFuncion = 0;
			}
		}
	}
	return exitoFuncion;
}
int eEmployee_Baja(Employee* eArr, int largoArr)
{
	int exitoFuncion = -1;
	int exito;
	int auxId;

	if(eArr != NULL && largoArr > 0)
	{
		int existenEmpleados = checkEmployeeArr(eArr, largoArr);
		if(existenEmpleados == 0)
		{
			printEmployeesTable(eArr, largoArr, 1);
			printf("\n--- BAJA DE EMPLEADO ---");
			exito = getIdEmployee(&auxId,
								  "\n    Ingrese ID del Empleado: ",
								  "    --Error.",
								  "    // NO SE ENCONTRO AL EMPLEADO //\n",
								  eArr, largoArr, 3);
			if(exito == 0)
			{
				removeEmployee(eArr, largoArr, auxId);
				printf("    // SE ELIMINO AL EMPLEADO CORRECTAMENTE //\n");
			}
		}
		else
		{
			printf("\n    // NO EXISTEN EMPLEADOS EN LA BASE //\n");
		}
	}

	return exitoFuncion;
}

// SORT
void swapEmployees(Employee* eArr, int primeraPos, int segundaPos)
{
	Employee aux;
	aux = eArr[primeraPos];
	eArr[primeraPos] = eArr[segundaPos];
	eArr[segundaPos] = aux;
}
int sortEmployees(Employee* eArr, int largoArr, int order)
{
	int exitoFuncion = -1;

	if(eArr != NULL && largoArr > 0)
	{
		switch(order)
		{
			int i;
			int j;
			case 1:
				for(i = 0; i < largoArr -1; i++)
				{
					for(j = 1; j < largoArr; j++)
					{
						if(eArr[i].sector > eArr[j].sector ||
						   (eArr[i].sector == eArr[j].sector && strcmp(eArr[i].lastName, eArr[j].lastName) > 0))
						{
							swapEmployees(eArr, i, j);
							exitoFuncion = 0;
						}
					}
				}
				break;
			case 2:
				for(i = 0; i < largoArr -1; i++)
				{
					for(j = 1; j < largoArr; j++)
					{
						if(eArr[i].sector < eArr[j].sector ||
						  (eArr[i].sector == eArr[j].sector && strcmp(eArr[i].lastName, eArr[j].lastName) < 0))
						{
							swapEmployees(eArr, i, j);
							exitoFuncion = 0;
						}
					}
				}
				break;
		}
	}

	return exitoFuncion;
}


// CALCULO SALARIOS
int obtenerTotalSalarios(Employee* eArr, int largoArr, float* totalSalarios, float* promedioSalarios)
{
	int exitoFuncion = -1;
	int i;
	int auxTotal = 0;
	int auxCont = 0;

	if(eArr != NULL && largoArr > 0)
	{
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].isEmpty == 0)
			{
				auxCont++;
				auxTotal += eArr[i].salary;
			}
		}

		*totalSalarios = auxTotal;
		*promedioSalarios = auxTotal / auxCont;
		exitoFuncion = 0;
	}

	return exitoFuncion;
}
int obtenerEmpleadosMayorSalario(Employee* eArr, int largoArr, int* contEmpleadosMayorSalario, int promedioSalarios)
{
	int exitoFuncion = -1;
	int auxEmpleados = 0;
	int i;

	if(eArr != NULL && eArr > 0)
	{
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].salary > promedioSalarios)
			{
				auxEmpleados++;
			}
		}

		*contEmpleadosMayorSalario = auxEmpleados;
		exitoFuncion = 0;
	}
	return exitoFuncion;
}

// PRINT
void printEmployee(Employee employee)
{
	printf("|%-*d|%-*s|%-*s|%-*.2f|%-*d|\n",
			w[0], employee.id, w[1], employee.name, w[2], employee.lastName, w[3], employee.salary, w[4], employee.sector);

}
int printEmployees(Employee* eArr, int largoArr, int orden)
{
	int exitoFuncion = -1;
	float salarios = 0;
	float promedio = 0;
	int cantEmpleadosMayor = 0;

	int existenEmpleados = checkEmployeeArr(eArr, largoArr);
	if(existenEmpleados == 0)
	{
		obtenerTotalSalarios(eArr, largoArr, &salarios, &promedio);
	    obtenerEmpleadosMayorSalario(eArr, largoArr, &cantEmpleadosMayor, promedio);
	    sortEmployees(eArr, largoArr, orden);

	    // int w[MAX_COL] = {15, 15, 15, 15, 15}; // Para imprimir columna se establece arriba
	    		printf("\nTABLA EMPLEADOS");
	    		printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|\n", w[0],"ID", w[1],"NOMBRE", w[2],"APELLIDO", w[3],"SALARIO", w[4],"SECTOR");
	    		int i;
	    		for(i = 0; i < largoArr; i++)
	    		{
	    			if(eArr[i].isEmpty == 0)
	    			{
	    				printEmployee(eArr[i]);
	    			}
	    		}
	    		printf("\n\nINFORMACION SOBRE SALARIOS");
	    		printf("\n|%-*s|%-*s|%-*s\n", w[0],"TOTAL SALARIOS", w[1],"PROM. SALARIOS", w[2],"CANT.EMPLEADOS QUE SUPERAN PROMEDIO");
	    		printf("|%-*.2f|%-*.2f|%-*d\n", w[0], salarios, w[1], promedio, w[2], cantEmpleadosMayor);

	    		exitoFuncion = 0;
	}
	else
	{
		printf("\n    // NO EXISTEN EMEPLEADOS INGRESADOS //\n");
	}


	return exitoFuncion;
}
int printEmployeesTable(Employee* eArr, int largoArr, int orden)
{
	int exitoFuncion = -1;

	int existenEmpleados = checkEmployeeArr(eArr, largoArr);
	if(existenEmpleados == 0)
	{
		// int w[MAX_COL] = {15, 15, 15, 15, 15}; // Para imprimir columna se establece arriba
		printf("\nTABLA EMPLEADOS");
		printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|\n", w[0],"ID", w[1],"NOMBRE", w[2],"APELLIDO", w[3],"SALARIO", w[4],"SECTOR");
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].isEmpty == 0)
			{
				printEmployee(eArr[i]);
			}
		}
	}
	else
	{
		printf("\n    // NO EXISTEN EMEPLEADOS INGRESADOS //\n");
	}


	return exitoFuncion;
}








