#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define LARGO_CHAR 128
#define CANT_STRUCT 4

typedef struct
{
    int id;
    char nombre[LARGO_CHAR];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

int employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setNextIdFromList(LinkedList* pArrayListEmployee, Employee* this);
int employee_getNextIdFromList(LinkedList* pArrayListEmployee, int* id);
int employee_addListAndSetId(LinkedList* listFrom, LinkedList* listTo);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_editName(Employee* this, char* mensaje, char* errorMensaje, char* finalErrorMensaje, int maxChar, int maxError);
int employee_editHsTrabajadas(Employee* this, char* mensaje, char* errorMensaje, char* finalErrorMensaje, int maxError);
int employee_editSueldo(Employee* this, char* mensaje, char* errorMensaje, char* finalErrorMensaje, int maxError);

int employee_ordenaSueldo(void* empleadoUno, void* empleadoDos);
int employee_ordenaId(void* empleadoUno, void* empleadoDos);
int employee_ordenaHoras(void* empleadoUno, void* empleadoDos);
int employee_ordenaNombre(void* empleadoUno, void* empleadoDos);


#endif // employee_H_INCLUDED
