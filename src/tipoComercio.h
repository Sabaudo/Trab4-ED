#ifndef TIPOCOMERCIO_H
#define TIPOCOMERCIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
//TAD TIPO DE COMERCIO
typedef void *TipoComercio;


/*
 * Cria uma entidade tipo de comercio com os parametros passados
 * Necessita do comando de criar um tipo de comercio ter sido invocado
 * Retorna um tipo de comercio
 */
TipoComercio criarTipoComercio (char codt[], char descricao[]);


/*
 * Retorna o codt do tipo de um comercio
 */
char* getTipoComercioCodt (TipoComercio sType);


/*
 * Retorna a descrição de um tipo de comercio
 */
=======
typedef void *TipoComercio;

TipoComercio criarTipoComercio (char codt[], char descricao[]);

char* getTipoComercioCodt (TipoComercio sType);

>>>>>>> 600afc673351a5099aedf4c5c72d16e4f5a5c6ca
char* getTipoComercioDesc (TipoComercio sType);

#endif