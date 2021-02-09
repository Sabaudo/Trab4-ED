#ifndef __casos__
#define __casos__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TAD CASOS
typedef void *Casos;

/*
*   cria uma lista de casos
*   necessita de que o comando ci tenha sido chamado
*   retorna o caso dentro criado
*/
Casos criarCasos(double x, double y, double n);

/*
*   busca o X do caso
*   necessita de um caso criado
*   retorna o X do caso
*/
double getXCasos(Casos caso);

/*
*   busca o Y do caso
*   necessita de um caso criado
*   retorna o Y do caso
*/
double getYCasos(Casos caso);

/*
*   busca o N do caso
*   necessita de um caso criado
*   retorna o N do caso
*/
double getNCasos(Casos caso);

/*
*   libera um objeto caso da memoria  
*   necessita de um caso criado
*   nao retorna nada
*/
void freeCasos (Casos caso);

#endif