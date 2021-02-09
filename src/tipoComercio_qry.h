#ifndef TIPOCOMERCIO_QRY_H
#define TIPOCOMERCIO_QRY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pessoa.h"
#include "moradores.h"
#include "tipoComercio.h"
#include "hashTable.h"
#include "comercio.h"
#include "ponto.h"
#include "svg.h"
#include "util.h"
#include "lista.h"
#include  "./elementos/quadra.h"

void consulta_eplg(FILE *aqrTxt, FILE *arqSvg, char *codt, HashTable comercios,double x, double y, double w, double h);

bool verificacao_ponto(double x, double y, double w, double h, Point p);

bool verificacao_ponto_circulo(double x, double y, double r, Point p);


void consulta_catac(FILE *arqTxt, FILE *arqSvg, double x, double y, double r, Tree arvoreQuadra, Tree arvoreHidrante, Tree arvoroSemaforo, Tree arvoreRadioBase, HashTable moradores, HashTable comercios);

void* catac_hidrante(FILE *arqTxt, double x, double y, double r, PosicNo aux, Tree arvoreHidrante, Lista removerHidrante);

void* catac_semaforo(FILE *arqTxt, double x, double y, double r, PosicNo aux, Tree arvoreSemaforo, Lista removerSemaforo);

void* catac_radioBase(FILE *arqTxt, double x, double y, double r, PosicNo aux, Tree arvoreRadioBase, Lista removerRadioBase);

void* catac_quadra(FILE *arqTxt, double x, double y, double r, PosicNo aux, Tree arvoreQuadra, Lista removerQuadra);

void catac_morador(FILE *aqrTxt, double x, double y, double r, HashTable moradores, Lista removerMorador, FILE *arqSvg);

void catac_comercio(FILE *aqrTxt, double x, double y, double r, HashTable comercios, Lista removerComercio, FILE *arqSvg);

bool verificacao_ponto_retangulo(double x, double y, double r, Quadra quadra);









#endif