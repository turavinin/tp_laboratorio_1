#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isNumerical(char* cadena)
{
	int exitoFuncion = 1;

	int i = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				exitoFuncion = 0;
				break;
			}
			i++;
		}
	}

	return exitoFuncion;
}

int getInt(int* pResultado)
{
	int exitoFuncion = 0;
	char buffer[64];
	scanf("%s", buffer);
	if(isNumerical(buffer))
	{
		*pResultado = atoi(buffer);
		exitoFuncion = 1;
	}

	return exitoFuncion;
}

int utn_getNumberLimited(int* pNumero, char* mensaje, char* mensajeError, int numeroMinimo, int numeroMaximo, int reintentosMaximos)
{
	int exitoFuncion = 0;
	int numero;

	while(reintentosMaximos > 0)
	{
		printf(mensaje);
		if(getInt(&numero))
		{
			if(numero <= numeroMaximo && numero >= numeroMinimo)
			{
				break;
			}
		}
		fflush(stdin);
		reintentosMaximos--;
		printf(mensajeError);
	}

	if(reintentosMaximos > 0)
	{
		exitoFuncion = 1;
		*pNumero = numero;
	}

	return exitoFuncion;
}

int utn_getNumber(int* pNumero, char* mensaje, char* mensajeError, int reintentosMaximos)
{
	int exitoFuncion = 0;
	int numero;

	while(reintentosMaximos > 0)
	{
		printf(mensaje);
		if(getInt(&numero))
		{
				break;
		}
		fflush(stdin);
		reintentosMaximos--;
		printf(mensajeError);
	}

	if(reintentosMaximos > 0)
	{
		exitoFuncion = 1;
		*pNumero = numero;
	}

	return exitoFuncion;
}
