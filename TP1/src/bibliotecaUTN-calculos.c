/*
 * bibliotecaUTN-calculos.c
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumInt(int* pResultado, int numeroUno, int numeroDos)
{
	*pResultado = numeroUno + numeroDos;
	return 1;
}

int restInt(int* pResultado, int numeroUno, int numeroDos)
{
	*pResultado = numeroUno - numeroDos;
	return 1;
}

int divInt(float* pResultado, int numeroUno, int numeroDos)
{
	int exitoFuncion = 0;
	if(numeroDos != 0)
	{
		*pResultado = (float)numeroUno / numeroDos;
		exitoFuncion = 1;
	}

	return exitoFuncion;
}

int multiInt(int* pResultado, int numeroUno, int numeroDos)
{
	*pResultado = numeroUno * numeroDos;
	return 1;
}

int factorialInt(int numero)
{
	int resultado;

	if(numero == 1 || numero == 0)
	{
		resultado = 1;
	}
	else
	{
		resultado = numero * factorialInt(numero - 1);
	}

	return resultado;
}



