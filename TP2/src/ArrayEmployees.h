#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


// DEFINE
#define MAX_CHAR_CADENAS 51
#define MAX_ERRORES 3
#define MAX_COL 5


// ESTRUCTURA
typedef struct
{
	int id;
	char name[MAX_CHAR_CADENAS];
	char lastName[MAX_CHAR_CADENAS];
	float salary;
	int sector;
	int isEmpty;
} Employee;

// FUNCIONES PRINCIPALES
// Set id
void eEmployee_SetId(int* id);
// Init struct
int initEmployees(Employee* eArr, int largoArr);
// Search empty
int eEmployee_SearchEmpty(Employee* eArr, int largoArr, int* posLibre);
// Alta employee
int addEmployees(Employee* eArr, int largoArr, int id, char name[], char lastName[], float salary, int sector, int posLibre);
int eEmployee_Alta(Employee* eArr, int largoArr);
// Buscar employee
int findEmployeeById(Employee* eArr, int largoArr, int idEmployee, int* pPosicionEmployee);
int getIdEmployee(int* idEmployee, char* mensaje, char* mensajeError, char* mensajeNoEncontrado, Employee* eArr, int largoArr, int maxErrores);
int checkEmployeeArr(Employee* eArr, int largoArr);
// Eliminar employee
int removeEmployee(Employee* eArr, int largoArr, int idEmployee);
int eEmployee_Baja(Employee* eArr, int largoArr);
// Sort
void swapEmployees(Employee* eArr, int primeraPos, int segundaPos);
int sortEmployees(Employee* eArr, int largoArr, int order);
// PRINT
void printEmployee(Employee employee);
int printEmployees(Employee* eArr, int largoArr, int orden);
int printEmployeesTable(Employee* eArr, int largoArr, int orden);

int obtenerTotalSalarios(Employee* eArr, int largoArr, float* totalSalarios, float* promedioSalarios);
int obtenerEmpleadosMayorSalario(Employee* eArr, int largoArr, int* contEmpleadosMayorSalario, int promedioSalarios);

// EDITAR
int editNameEmployee(Employee* employee, char* mensajePrimero, char* error, char* errorFinal, int maxChar, int erroresMaximos, int posicion);
int editLastNameEmployee(Employee* employee, char* mensajePrimero, char* error, char* errorFinal, int maxChar, int erroresMaximos, int posicion);
int editSalaryEmployee(Employee* employee, char* mensajePrimero, char* error, char* errorFinal, int erroresMaximos, int posicion);
int editSectorEmployee(Employee* employee, char* mensajePrimero, char* error, char* errorFinal, int erroresMaximos, int posicion);
int editEmployee(Employee* eArr, int largoArr);
#endif /* ARRAYEMPLOYEES_H_ */
