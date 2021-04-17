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

#endif /* BIBLIOTECAUTN_VALIDACIONES_H_ */
