#ifndef TIPOCOMERCIO_H
#define TIPOCOMERCIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *TipoComercio;

TipoComercio criarTipoComercio (char codt[], char descricao[]);

char* getTipoComercioCodt (TipoComercio sType);

char* getTipoComercioDesc (TipoComercio sType);

#endif