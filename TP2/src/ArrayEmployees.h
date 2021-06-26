#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

// DEFINES
#define MAX_CHAR_CADENAS 51
#define MAX_ERRORES 3
#define MAX_COL 5
#define MAX_ARR 1000

// STRUCT
typedef struct
{
	int id;
	char name[MAX_CHAR_CADENAS];
	char lastName[MAX_CHAR_CADENAS];
	float salary;
	int sector;
	int isEmpty;
} Employee;

// MAIN FUNCTIONS

/**
 * \brief Populate the array of employees with structures and set its "isEmpty" property to 1.
 * \param (eArr) array employees*.
 * \param (size) int
 * \return 0 (= true) and -1 (=false)
 **/
int initEmployees(Employee* eArr, int size);

/**
 * \brief Perform a search in the array of a free spot.
 * \param (eArr) array employees*.
 * \param (size) int
 * \param (freeSpot) int*
 * \return 0 (= true) and -1 (=false)
 **/
int eEmployee_SearchEmpty(Employee* eArr, int size, int* freeSpot);

/**
 * \brief Add an employee to free spot in the array of employees
 * \param (eArr) array employees*.
 * \param (size) int
 * \param (id) int
 * \param (name[]) char
 * \param (lastName[]) char
 * \param (salary) float
 * \param (sector) int
 * \param (freeSpot) int
 * \return 0 (= true) and -1 (=false)
 **/
int addEmployees(Employee* eArr, int size, int id, char name[], char lastName[], float salary, int sector, int freeSpot);
/**
 * \brief General function of creating a new employee
 * \param (eArr) array employees*.
 * \param (size) int
 * \return 0 (= true) and -1 (=false)
 **/
int eEmployee_Create(Employee* eArr, int size, int* defaultID);
/**
 * \brief Finds employee by id
 * \param (eArr) array employees*.
 * \param (size) int
 * \param (idEmployee) int
 * \param (employeePosition) int*
 * \return 0 (= true) and -1 (=false)
 **/
int findEmployeeById(Employee* eArr, int size, int idEmployee, int* employeePosition);

/**
 * \brief Ask through the console the employee's id
 * \param (idEmployee) int*.
 * \param (message) char*
 * \param (errorMessage) char*
 * \param (messageNotFound) char*
 * \param (eArr) array employees*.
 * \param (size) int
 * \param (maxErrors) int
 * \return 0 (= true) and -1 (=false)
 **/
int getIdEmployee(int* idEmployee, char* message, char* errorMessage, char* messageNotFound, Employee* eArr, int size, int maxErrors);

/**
 * \brief Checks if there is an employee on the list
 * \param (eArr) array employees*.
 * \param (size) int
 * \return 0 (= true) and -1 (=false)
 **/
int checkEmployeeArr(Employee* eArr, int size);

/**
 * \brief Edit the employee's name
 * \param (eArr) array employees*.
 * \param (message) char*
 * \param (errorMessage) char*
 * \param (finalErrorMessage) char*
 * \param (maxChar) int
 * \param (maxErrors) int
 * \param (position) int
 * \return 0 (= true) and -1 (=false)
 **/
int editNameEmployee(Employee* employee, char* message, char* errorMessage, char* finalErrorMessage, int maxChar, int maxErrors, int position);

/**
 * \brief Edit the employee's last name
 * \param (eArr) array employees*.
 * \param (message) char*
 * \param (errorMessage) char*
 * \param (finalErrorMessage) char*
 * \param (maxChar) int
 * \param (maxErrors) int
 * \param (position) int
 * \return 0 (= true) and -1 (=false)
 **/
int editLastNameEmployee(Employee* employee, char* message, char* errorMessage, char* finalErrorMessage, int maxChar, int maxErrors, int position);

/**
 * \brief Edit the employee's salary
 * \param (eArr) array employees*.
 * \param (message) char*
 * \param (errorMessage) char*
 * \param (finalErrorMessage) char*
 * \param (maxErrors) int
 * \param (position) int
 * \return 0 (= true) and -1 (=false)
 **/
int editSalaryEmployee(Employee* employee, char* message, char* errorMessage, char* finalErrorMessage, int maxErrors, int posicion);

/**
 * \brief Edit the employee's sector
 * \param (eArr) array employees*.
 * \param (message) char*
 * \param (errorMessage) char*
 * \param (finalErrorMessage) char*
 * \param (maxErrors) int
 * \param (position) int
 * \return 0 (= true) and -1 (=false)
 **/
int editSectorEmployee(Employee* employee, char* message, char* errorMessage, char* finalErrorMessage, int maxErrors, int posicion);

/**
 * \brief General function of editing employee information
 * \param (eArr) array employees*.
 * \param (size) int
 * \return 0 (= true) and -1 (=false)
 **/
int eEmployee_Edit(Employee* eArr, int size);

/**
 * \brief Removes employee
 * \param (eArr) array employees*.
 * \param (size) int
 * \param (idEmployee) int
 * \return 0 (= true) and -1 (=false)
 **/
int removeEmployee(Employee* eArr, int position);
/**
 * \brief General function of employee removal
 * \param (eArr) array employees*.
 * \param (size) int
 * \return 0 (= true) and -1 (=false)
 **/
int eEmployee_Delete(Employee* eArr, int size);

/**
 * \brief Swaps two employees
 * \param (eArr) array employees*.
 * \param (firstPosition) int
 * \param (secondPosition) int
 * \return 0 (= true) and -1 (=false)
 **/
void swapEmployees(Employee* eArr, int firstPosition, int secondPosition);
/**
 * \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 * \param (eArr) array employees*.
 * \param (size) int
 * \param (order) int [1] indicate UP - [2] indicate DOWN
 * \return 0 (= true) and -1 (=false)
 **/
int sortEmployees(Employee* eArr, int size, int order);

/**
 * \brief Gets the total salary of employees and the average salary
 * \param (eArr) array employees*.
 * \param (size) int
 * \param (totalSalary) float*
 * \param (promedioSalarios) float*
 * \return 0 (= true) and -1 (=false)
 **/
int obtenerTotalSalarios(Employee* eArr, int size, float* totalSalary, float* averageSalary);

/**
 * \brief Gets employees who have higher than average salary
 * \param (eArr) array employees*.
 * \param (size) int
 * \param (contEmployeeHiger) int*
 * \param (avarageSalary) float
 * \return 0 (= true) and -1 (=false)
 **/
int obtenerEmpleadosMayorSalario(Employee* eArr, int size, int* contEmployeeHiger, float avarageSalary, int* posArr);

/**
 * \brief Prints one employee
 * \param (eArr) array employees*.
 **/
void printEmployee(Employee employee);

/**
 * \brief General function that prints to all employees and in the desired order.
 * \param (eArr) array employees*.
 * \param (size) int
 * \param (order) int
 * \return 0 (= true) and -1 (=false)
 **/
int printEmployees(Employee* eArr, int size, int order);

/**
 * \brief Print only the employee table
 * \param (eArr) array employees*.
 * \param (size) int
 * \return 0 (= true) and -1 (=false)
 **/
int printEmployeesTable(Employee* eArr, int size);

/**
 * \brief Prints the info of salaries
 * \param (eArr) array employees*.
 * \param (salary) float
 * \param (avarage) float
 * \param (contHigherSalaryEmployees) int
 * \param (posArr) int*
 * \return 0 (= true) and -1 (=false)
 **/
void printInfoSalary(Employee* eArr, float salary, float avarage, int contHigherSalaryEmployees, int* posArr);

#endif /* ARRAYEMPLOYEES_H_ */
