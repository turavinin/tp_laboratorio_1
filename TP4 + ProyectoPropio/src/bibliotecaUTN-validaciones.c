#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

// INT
int isNumerical(char* cadena)
{
	int exitoFuncion = -1;

	int i = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				exitoFuncion = -1;
				break;
			}
			i++;
			exitoFuncion = 0;
		}
	}

	return exitoFuncion;
}
int getInt(int* pResultado)
{
	int exitoFuncion = -1;
	char buffer[64];
	gets(buffer);
	if(isNumerical(buffer) == 0)
	{
		*pResultado = atoi(buffer);
		exitoFuncion = 0;
	}

	return exitoFuncion;
}
int utn_getNumberLimited(int* pNumero, char* mensaje, char* mensajeError, int numeroMinimo, int numeroMaximo, int reintentosMaximos)
{
	int exitoFuncion = -1;
	int numero;

	while(reintentosMaximos > 0)
	{
		printf(mensaje);
		if(getInt(&numero) == 0)
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
		exitoFuncion = 0;
		*pNumero = numero;
	}

	return exitoFuncion;
}
int utn_getNumber(int* pNumero, char* mensaje, char* mensajeError, int reintentosMaximos)
{
	int exitoFuncion = -1;
	int numero;

	while(reintentosMaximos > 0)
	{
		printf(mensaje);
		if(getInt(&numero) == 0)
		{
				break;
		}
		fflush(stdin);
		reintentosMaximos--;
		printf(mensajeError);
	}

	if(reintentosMaximos > 0)
	{
		exitoFuncion = 0;
		*pNumero = numero;
	}

	return exitoFuncion;
}

// FLOAT
int isFloating(char* cadena)
{
	int exitoFuncion = -1;
	int i = 0;
	int banderaFloatPoint = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.' || banderaFloatPoint == 1)) || isspace(cadena[i]))
			{
				exitoFuncion = -1;
				break;
			}

			if(cadena[i] == '.')
			{
				banderaFloatPoint = 1;
			}

			i++;
			exitoFuncion = 0;
		}
	}
	return exitoFuncion;
}
int getFloat(float* pResultado)
{
	int exitoFuncion = -1;
	char buffer[64];
	gets(buffer);
	if(isFloating(buffer) == 0)
	{
		*pResultado = strtof(buffer, NULL);
		exitoFuncion = 0;
	}

	return exitoFuncion;
}
int utn_getFloat(float* pNumero, char* mensaje, char* mensajeError, int reintentosMaximos)
{
	int exitoFuncion = -1;
	float numero;

	while(reintentosMaximos > 0)
	{
		printf(mensaje);
		if(getFloat(&numero) == 0)
		{
				break;
		}
		fflush(stdin);
		reintentosMaximos--;
		printf(mensajeError);
	}

	if(reintentosMaximos > 0)
	{
		exitoFuncion = 0;
		*pNumero = numero;
	}

	return exitoFuncion;
}
int utn_getFloatLimited(float* pNumero, char* mensaje, char* mensajeError, float numeroMin, float numeroMax, int reintentosMax)
{
	int exitoFuncion = -1;
	float numero;

	while(reintentosMax > 0)
	{
		printf(mensaje);
		if(getFloat(&numero) == 0)
		{
			if(numero <= numeroMax && numero >= numeroMin)
			{
				break;
			}
		}
		fflush(stdin);
		reintentosMax--;
		printf(mensajeError);
	}

	if(reintentosMax > 0)
	{
		exitoFuncion = 0;
		*pNumero = numero;
	}

	return exitoFuncion;
}

// CHAR
int utn_getCharDosOpciones(char* pChar, char* mensajeConOpciones, char* mensajeError, char opcionUno, char opcionDos, int reintentosMaximos)
{
	int exitoFuncion = -1;
	char letra;
	opcionUno = tolower(opcionUno);
	opcionDos = tolower(opcionDos);

	printf(mensajeConOpciones);
	fflush(stdin);
	scanf("%c", &letra);
	letra = tolower(letra);

	while(letra != opcionUno && letra != opcionDos && reintentosMaximos > 0)
	{
		reintentosMaximos--;
		if(reintentosMaximos != 0)
		{
			printf(mensajeError);
			printf(mensajeConOpciones);
			fflush(stdin);
			scanf("%c", &letra);
			letra = tolower(letra);
		}
	}

	if(letra == opcionUno)
	{
		*pChar = opcionUno;
		exitoFuncion = 0;
	}
	else if(letra == opcionDos)
	{
		*pChar = opcionDos;
		exitoFuncion = 0;
	}

	return exitoFuncion;
}
int utn_getCharTresOpciones(char* pChar, char* mensajeConOpciones, char* mensajeError, char opcionUno, char opcionDos, char opcionTres, int reintentosMaximos)
{
		int exitoFuncion = -1;
		char letra;
		opcionUno = tolower(opcionUno);
		opcionDos = tolower(opcionDos);
		opcionTres = tolower(opcionTres);

		printf(mensajeConOpciones);
		fflush(stdin);
		scanf("%c", &letra);
		letra = tolower(letra);

		while(letra != opcionUno && letra != opcionDos && letra != opcionTres && reintentosMaximos > 0)
		{
			reintentosMaximos--;
			if(reintentosMaximos != 0)
			{
				printf(mensajeError);
				fflush(stdin);
				printf(mensajeConOpciones);
				scanf("%c", &letra);
				letra = tolower(letra);
			}
		}

		if(letra == opcionUno)
		{
			*pChar = opcionUno;
			exitoFuncion = 0;
		}
		else if(letra == opcionDos)
		{
			*pChar = opcionDos;
			exitoFuncion = 0;
		}else if(letra == opcionTres)
		{
			*pChar = opcionTres;
			exitoFuncion = 0;
		}

		return exitoFuncion;
}

// STRING
int esSpecialChar(char caracter)
{
	int exito = -1;
	if(caracter == '!' || caracter == '@' || caracter == '#' || caracter == '$'
	      || caracter == '%' || caracter == '^' || caracter == '&' || caracter == '*'
	      || caracter == '(' || caracter == ')' || caracter == '-' || caracter == '{'
	      || caracter == '}' || caracter == '[' || caracter == ']' || caracter == ':'
	      || caracter == ';' || caracter == '"' || caracter == '\'' || caracter == '<'
	      || caracter == '>' || caracter == '.' || caracter == '/' || caracter == '?'
	      || caracter == '~' || caracter == '`' )
	{
		exito = 0;
	}

	return exito;
}
int esStringAlpha(char* cadena)
{
	int exitoFuncion = -1;
	int largoCadena = strlen(cadena);
	int i;
	if(cadena != NULL && largoCadena > 0)
	{
		exitoFuncion = 0;
		for(i = 0; i < largoCadena; i++)
		{
			if(isalpha(cadena[i]) == 0)
			{
				exitoFuncion = -1;
				break;
			}
		}
	}

	return exitoFuncion;
}
int esStringAlphaCompuesto(char* cadena)
{

	int exitoFuncion = -1;
	int largoCadena = strlen(cadena);
	int i;
	int banderaEspacio = 0;
	if(cadena != NULL && largoCadena > 0)
	{
		exitoFuncion = 0;
		for(i = 0; i < largoCadena; i++)
		{
			if(!isalpha(cadena[i]) && (isdigit(cadena[i]) || esSpecialChar(cadena[0]) == 0 || isspace(cadena[0]) || (isspace(cadena[i]) && banderaEspacio)))
			{
				exitoFuncion = -1;
				break;
			}

			if(i > 0 && isspace(cadena[i]))
			{
				banderaEspacio = 1;
			}
		}
	}

	return exitoFuncion;
}
int utn_getStringLimited(char* pString, char* mensaje, char* mensajeError, int maximosCaracteres, int maximosErrores)
{
	int exitoFuncion = -1;
	char auxString[200];

	printf(mensaje);
	fflush(stdin);
	gets(auxString);

	while((strlen(auxString) > maximosCaracteres || esStringAlpha(auxString) == -1) && maximosErrores > 0)
	{
		maximosErrores--;
		if(maximosErrores != 0)
		{
			printf(mensajeError);
			printf(mensaje);
			fflush(stdin);
			gets(auxString);
		}
	}

	if(maximosErrores > 0)
	{
		strcpy(pString, auxString);
		exitoFuncion = 0;
	}

	return exitoFuncion;
}
int utn_getStringCompuesto(char* pString, char* msj, char* msjError, int maxChar, int maxErr)
{
	int exito = -1;
	char auxString[200];
	printf(msj);
	fflush(stdin);
	gets(auxString);

	while((strlen(auxString) > maxChar || esStringAlphaCompuesto(auxString) == -1) && maxErr > 0)
	{
		maxErr--;
		if(maxErr != 0)
		{
			printf(msjError);
			printf(msj);
			fflush(stdin);
			gets(auxString);
		}
	}

	if(maxErr > 0)
	{
		strcpy(pString, auxString);
		exito = 0;
	}

	return exito;
}

// MAIL
int isStringMail(char* cadena)
{
	int exitoFuncion = -1;
	int banderaArroba = 0;
	int banderaPunto = 0;
	int largoCadena = strlen(cadena);
	int i;
	if(cadena != NULL && largoCadena > 0)
	{
		//if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.' || banderaFloatPoint == 1))

		printf("\nEntro a if basico.");
		exitoFuncion = 0;
		for(i = 0; i < largoCadena; i++)
		{
			printf("\nCaracter a analizar: %c", cadena[i]);
			if(((isspace(cadena[i]) != 0) ||
			             cadena[i] == '!' || cadena[i] == '#' || cadena[i] == '$' ||
						 cadena[i] == '%' || cadena[i] == '^' || cadena[i] == '&' || cadena[i] == '*' ||
						 cadena[i] == '(' || cadena[i] == ')' || cadena[i] == '-' || cadena[i] == '{' ||
						 cadena[i] == '}' || cadena[i] == '[' || cadena[i] == ']' || cadena[i] == ':' ||
						 cadena[i] == ';' || cadena[i] == '"' || cadena[i] == '\''|| cadena[i] == '<'||
						 cadena[i] == '>' || cadena[i] == '/' || cadena[i] == '?' || cadena[i] == '~' ||
						 cadena[i] == '`') || ((cadena[i] == '.' && banderaPunto == 1) || (cadena[i] == '@' && banderaArroba == 1)))
			{
				printf("\nRechaza caracter: %c", cadena[i]);
				exitoFuncion = -1;
				break;
			} // Termina el if interno

			// Cambia banderas
			if(cadena[i] == '.')
			{
				printf("\nCambia bandera del punto.");
				banderaPunto = 1;
			}

			if(cadena[i] == '@')
			{
				printf("\nCambia bandera del arroba.");
				banderaArroba = 1;
			}

		} // Termina el for

		// Analiza si hubo @ y . (obligatorios en mail)
		if(banderaArroba == 0 || banderaPunto == 0)
		{
			printf("\nNo hay presencia de @ y/o .");
			exitoFuncion = -1;
		}
	}

	return exitoFuncion;
}
int utn_getMailLimited(char* pString, char* mensaje, char* mensajeError, int maximosCaracteres, int reintentosMaximos)
{
	int exitoFuncion = -1;
	char auxString[200];

	printf(mensaje);
	fflush(stdin);
	gets(auxString);

	while((strlen(auxString) > maximosCaracteres || isStringMail(auxString) == -1) && reintentosMaximos > 0)
	{
		reintentosMaximos--;
		if(reintentosMaximos != 0)
		{
			printf(mensajeError);
			fflush(stdin);
			gets(auxString);
		}
	}

	if(reintentosMaximos > 0)
	{
		strcpy(pString, auxString);
		exitoFuncion = 0;
	}

	return exitoFuncion;
}

// CUIL
int isStringCuil(char* cadena)
{
	int exitoFuncion = -1;
	int largoCadena = strlen(cadena);
	int banderaGuion = 0;
	int i;

	if(cadena != NULL && largoCadena > 0)
	{
		exitoFuncion = 0;
		for(i = 0; i < largoCadena; i++)
		{
			if(((isspace(cadena[i]) != 0) || isalpha(cadena[i]) != 0 ||
		             cadena[i] == '!' || cadena[i] == '#' || cadena[i] == '$' || cadena[i] == '@' ||
					 cadena[i] == '%' || cadena[i] == '^' || cadena[i] == '&' || cadena[i] == '*' ||
					 cadena[i] == '(' || cadena[i] == ')' || cadena[i] == '.' || cadena[i] == '{' ||
					 cadena[i] == '}' || cadena[i] == '[' || cadena[i] == ']' || cadena[i] == ':' ||
					 cadena[i] == ';' || cadena[i] == '"' || cadena[i] == '\''|| cadena[i] == '<'||
					 cadena[i] == '>' || cadena[i] == '/' || cadena[i] == '?' || cadena[i] == '~' ||
					 cadena[i] == '`') ||
					 ((cadena[2] != '-' || cadena[11] != '-') || banderaGuion == 3))
			{
				exitoFuncion = -1;
				break;
			}
			if(cadena[i] == '-')
			{
				banderaGuion++;
			}
		}

		// Analiza si hubo '-'
		if(banderaGuion == 0)
		{
			exitoFuncion = -1;
		}

	}

	return exitoFuncion;
}
int utn_getCuil(char* pString, char* mensaje, char* mensajeError, int reintentosMaximos)
{
	int exitoFuncion = -1;
	char auxString[100];
	int maxCuilChar = 13;

	printf(mensaje);
	fflush(stdin);
	gets(auxString);

	while((strlen(auxString) != maxCuilChar || isStringCuil(auxString) == -1) && reintentosMaximos > 0)
	{
		printf(mensajeError);
		printf(mensaje);
		fflush(stdin);
		gets(auxString);
		reintentosMaximos--;
	}

	if(reintentosMaximos > 0)
	{
		strcpy(pString, auxString);
		exitoFuncion = 0;
	}



	return exitoFuncion;
}

// FORMATEADORES
int utn_FormatoNombreCompleto(char* nombre, char* apellido, char* nombreCompleto)
{
	int exitoFuncion = -1;
	int banderaExitos = 0;

	if(strlen(nombre) > 0 && strlen(apellido) > 0)
	{
		strcpy(nombreCompleto, apellido);
		strcat(nombreCompleto, ", ");
		strcat(nombreCompleto, nombre);

		// Cambiar todos los char a minuscula
		strlwr(nombreCompleto);

		for(int i = 0; i < strlen(nombreCompleto); i++)
		{
			if(i == 0 && isspace(nombreCompleto[i]) == 0)
			{
				nombreCompleto[0] = toupper(nombreCompleto[0]);
				banderaExitos++;
			}
			else if(isspace(nombreCompleto[i]) && i < strlen(nombreCompleto) - 1)
			{
				nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
				banderaExitos++;
			}
		}

		if(banderaExitos == 2)
		{
			exitoFuncion = 0;
		}
	}

	return exitoFuncion;
}



















