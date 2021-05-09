/*
 * bibliotecaUTN-validaciones.h
 */
#ifndef BIBLIOTECAUTN_VALIDACIONES_H_
#define BIBLIOTECAUTN_VALIDACIONES_H_

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param Cadena de caracteres a ser validada
 * \return Retorna 1 (=true) si la cadena es numerica, y 0 (=false) si no lo es.
 * */
int isNumerical(char* cadena);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado es un puntero al espacio de memoria donde se dejará el resultado de la funcion.
 * \return Retorna 1 (=true) si la cadena es numerica, y 0 (=false) si no lo es.
 * */
int getInt(int* pResultado);

/**
 * \brief Solicita un numero al usuario , leuego de verificarlo devuelve el resultado.
 * \param (pNumero) es un puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param (mensaje) es el mensaje a ser mostrado.
 * \param (mensajeError) es el mensaje de error a ser mostrado.
 * \param (numeroMinimo) es el numero minimo a ser aceptado.
 * \param (numeroMaximo) es el numero maximo a ser aceptado.
 * \param (reintentosMaximos) son los reintentos maximos de inresos erroneos que se permiten.
 * \return 1 (=true) si se obtuvo el numero, y 0 (=false) si nos.
 * */
int utn_getNumberLimited(int* pNumero, char* mensaje, char* mensajeError, int numeroMinimo, int numeroMaximo, int reintentosMaximos);

/**
 * \brief Solicita un numero al usuario , leuego de verificarlo devuelve el resultado.
 * \param (pNumero) es un puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param (mensaje) es el mensaje a ser mostrado.
 * \param (mensajeError) es el mensaje de error a ser mostrado.
 * \param (numeroMinimo) es el numero minimo a ser aceptado.
 * \param (numeroMaximo) es el numero maximo a ser aceptado.
 * \param (reintentosMaximos) son los reintentos maximos de inresos erroneos que se permiten.
 * \return 1 (=true) si se obtuvo el numero, y 0 (=false) si nos.
 * */
int utn_getNumber(int* pNumero, char* mensaje, char* mensajeError, int reintentosMaximos);

/**
 * \brief Verifica si la cadena ingresada es floating
 * \param Cadena de caracteres a ser validada
 * \return Retorna 0 (=true) si la cadena es floating, y -1 (=false) si no lo es.
 * */
int isFloating(char* cadena);

/**
 * \brief Pide un numero por consola, analiza si es float y devuelve por refrencia el float.
 * \param pResultado es un puntero al espacio de memoria donde se dejará el resultado de la funcion.
 * \return Retorna 0 (=true) si la cadena es float, y -1 (=false) si no lo es.
 * */
int getFloat(float* pResultado);

/**
 * \brief Solicita un numero al usuario , luego de verificarlo devuelve el resultado por ref.
 * \param (pNumero) es un puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param (mensaje) es el mensaje a ser mostrado.
 * \param (numeroMaximo) es el numero maximo a ser aceptado.
 * \param (reintentosMaximos) son los reintentos maximos de inresos erroneos que se permiten.
 * \return 0 (=true) si se obtuvo el numero, y -1 (=false) si no lo es.
 **/
int utn_getFloat(float* pNumero, char* mensaje, char* mensajeError, int reintentosMaximos);

/**
 * \brief Solicita un numero al usuario , luego de verificarlo devuelve el resultado float.
 * \param (pNumero) es un puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param (mensaje) es el mensaje a ser mostrado.
 * \param (mensajeError) es el mensaje de error a ser mostrado.
 * \param (numeroMinimo) es el numero float minimo a ser aceptado.
 * \param (numeroMaximo) es el numero float maximo a ser aceptado.
 * \param (reintentosMaximos) son los reintentos maximos de ingresos erroneos que se permiten.
 * \return 0 (=true) si se obtuvo el numero, y -1 (=false) si nos.
 * */
int utn_getFloatLimited(float* pNumero, char* mensaje, char* mensajeError, float numeroMin, float numeroMax, int reintentosMax);

/**
 * \brief Solicita un char al usuario restringiendo las opciones a dos.
 * \param (pIntChar) Puntero que devuelve 1 si lo ingresado fue la primera opción. Devuelve 2 si fue la segunda.
 * \param (mensajeConOpciones) es el mensaje con las opciones a ser mostrado.
 * \param (mensajeError) es el mensaje de error a ser mostrado.
 * \param (opcionUno) la primera opcion char.
 * \param (opcionDos) la segunda opcion char.
 * \param (reintentosMaximos) son los reintentos maximos de inresos erroneos que se permiten.
 * \return 0 (=true) si se obtuvo el numero, y -1 (=false).
 * */
int utn_getCharDosOpciones(char* pChar, char* mensajeConOpciones, char* mensajeError, char opcionUno, char opcionDos, int reintentosMaximos);

/**
 * \brief Solicita un char al usuario restringiendo las opciones a tres.
 * \param (pIntChar) Puntero que devuelve 1 si lo ingresado fue la primera opción. Devuelve 2 si fue la segunda.
 * \param (mensajeConOpciones) es el mensaje con las opciones a ser mostrado.
 * \param (mensajeError) es el mensaje de error a ser mostrado.
 * \param (opcionUno) la primera opcion char.
 * \param (opcionDos) la segunda opcion char.
 * \param (opcionTres) la tercera opcion char.
 * \param (reintentosMaximos) son los reintentos maximos de inresos erroneos que se permiten.
 * \return 0 (=true) si se obtuvo el numero, y -1 (=false).
 * */
int utn_getCharTresOpciones(char* pChar, char* mensajeConOpciones, char* mensajeError, char opcionUno, char opcionDos, char opcionTres, int reintentosMaximos);

/**
 * \brief Verifica si la cadena ingresada es alfabetica
 * \param Cadena de caracteres a ser validada
 * \return Retorna 0 (=true) si la cadena es floating, y -1 (=false) si no lo es.
 * */
int esStringAlpha(char* cadena);

/**
 * \brief Verifica si la cadena ingresada es alfabetica y compuesta
 * \param Cadena de caracteres a ser validada
 * \return Retorna 0 (=true) si la cadena es floating, y -1 (=false) si no lo es.
 * */
int esStringAlphaCompuesto(char* cadena);

/**
 * \brief Solicita al usuario una cadena de caracteres. Hay limitacion de largo.
 * \param (pIntChpStringar) Puntero al string a devolver.
 * \param (mensaje) es el mensaje a mostrar.
 * \param (mensajeError) es el mensaje de error a ser mostrado.
 * \param (maximosCaracteres) maximos caracteres aceptados para la cadena.
 * \param (maximosErrores) maximos errores aceptados.
 * \return 0 (=true) si se obtuvo el numero, y -1 (=false) si no.
 * */
int utn_getStringLimited(char* pString, char* mensaje, char* mensajeError, int maximosCaracteres, int maximosErrores);

/**
 * \brief Solicita al usuario una cadena de caracteres compuesta. Hay limitacion de largo.
 * \param (pIntChpStringar) Puntero al string a devolver.
 * \param (mensaje) es el mensaje a mostrar.
 * \param (mensajeError) es el mensaje de error a ser mostrado.
 * \param (maximosCaracteres) maximos caracteres aceptados para la cadena.
 * \param (maximosErrores) maximos errores aceptados.
 * \return 0 (=true) si se obtuvo el numero, y -1 (=false) si no.
 * */
int utn_getStringCompuesto(char* pString, char* msj, char* msjError, int maxChar, int maxErr);

/**
 * \brief Verifica si la cadena ingresada es alfanumerica y tiene características de email.
 * \param Cadena de caracteres a ser validada
 * \return Retorna 0 (=true) si la cadena es floating, y -1 (=false) si no lo es.
 * */
int isStringMail(char* cadena);

/**
 * \brief Solicita al usuario una cadena de caracteres de mail. Hay limitacion de largo.
 * \param (pIntChpStringar) Puntero al string a devolver.
 * \param (mensaje) es el mensaje a mostrar.
 * \param (mensajeError) es el mensaje de error a ser mostrado.
 * \param (maximosCaracteres) maximos caracteres aceptados para la cadena.
 * \param (maximosErrores) maximos errores aceptados.
 * \return 0 (=true) si se obtuvo el numero, y -1 (=false) si no.
 * */
int utn_getMailLimited(char* pString, char* mensaje, char* mensajeError, int maximosCaracteres, int reintentosMaximos);

#endif /* BIBLIOTECAUTN_VALIDACIONES_H_ */
