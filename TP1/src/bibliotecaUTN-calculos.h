/*
 * bibliotecaUTN-calculos.h
 */

#ifndef BIBLIOTECAUTN_CALCULOS_H_
#define BIBLIOTECAUTN_CALCULOS_H_

/**
 * \brief Toma dos numeros enteros y los suma.
 * \param (pResultado) es un puntero al espacio de memoria donde se dejara el resultado de la suma.
 * \param (numeroUno) primero numero a ser sumado.
 * \param (numeroDos) segundo numero a ser sumado.
 * \return 1 (=true) si se obtuvo el numero, y 0 (=false) si nos.
 * */
int sumInt(int* pResultado, int numeroUno, int numeroDos);

/**
 * \brief Toma dos numeros enteros y los resta.
 * \param (pResultado) es un puntero al espacio de memoria donde se dejara el resultado de la resta.
 * \param (numeroUno) Minuendo.
 * \param (numeroDos) Sustraendo.
 * \return 1 (=true) si se obtuvo el numero.
 * */
int restInt(int* pResultado, int numeroUno, int numeroDos);

/**
 * \brief Toma dos numeros enteros y los divide.
 * \param (pResultado) es un puntero al espacio de memoria donde se dejara el resultado de la división.
 * \param (numeroUno) Dividendo.
 * \param (numeroDos) Divisor.
 * \return 1 (=true) si se obtuvo el numero, y 0 (=false) si numeroDos es 0.
 * */
int divInt(float* pResultado, int numeroUno, int numeroDos);

/**
 * \brief Toma dos numeros enteros y los multiplica.
 * \param (pResultado) es un puntero al espacio de memoria donde se dejara el resultado de la multiplicación.
 * \param (numeroUno) Multiplicando.
 * \param (numeroDos) Multiplicador.
 * \return 1 (=true) si se obtuvo el numero.
 * */
int multiInt(int* pResultado, int numeroUno, int numeroDos);

/**
 * \brief Toma el numero y le saca el factorial.
 * \param (numero) El numero al que se le realiza el factorial.
 * \return Resultado del factorial.
 * */
int factorialInt(int numero);

#endif /* BIBLIOTECAUTN_CALCULOS_H_ */
