#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "bibliotecaUTN-validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

	// Variables
    int opcionMenu;
    int exitoFuncion;

    // LinkedList Empleados
    LinkedList* listaEmpleados = ll_newLinkedList();

    // Menu
    do{
    	exitoFuncion = utn_getNumberLimited(&opcionMenu,
    					"\n|-------------------------------------MENU---------------------------------------|"
    					"\n| 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).   |"
    					"\n| 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario). |"
    					"\n| 3. Alta de empleado                                                            |"
    					"\n| 4. Modificar datos de empleado                                                 |"
    					"\n| 5. Baja de empleado                                                            |"
    					"\n| 6. Listar empleados                                                            |"
    					"\n| 7. Ordenar empleados                                                           |"
    					"\n| 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).     |"
						"\n| 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).   |"
    					"\n| 10. Salir                                                                      |"
    					"\n|--------------------------------------------------------------------------------|"
    					"\n| Seleccione una opción (ingrese su número): ",
    					"\n|      ---------------- ¡LA OPCION INGRESADA ES INCORRECTA! ----------------     |\n",
    					1, 10, 3);

    	if(exitoFuncion == 0)
    	{
            switch(opcionMenu)
            {
                case 1:
                    controller_loadFromText("./data.csv", listaEmpleados);
                    break;
                case 2:
                	controller_loadFromBinary("./data.bin", listaEmpleados);
                    break;
                case 3:
                	controller_addEmployee(listaEmpleados);
                    break;
                case 4:
                	controller_editEmployee(listaEmpleados);
                    break;
                case 5:
                	controller_removeEmployee(listaEmpleados);
                    break;
                case 6:
                	controller_ListEmployee(listaEmpleados);
                	break;
                case 7:
                	controller_sortEmployee(listaEmpleados);
                	break;
                case 8:
                	controller_saveAsText("./data.csv", listaEmpleados);
                	break;
                case 9:
                	controller_saveAsBinary("./data.bin", listaEmpleados);
                	break;
            }
    	}

    }while(opcionMenu != 10);

    printf("\n|    --- ¡GRACIAS POR UTILIZAR EL PROGRAMA! ---     |\n");

    return 0;
}
