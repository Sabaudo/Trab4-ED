#include <stdio.h>
#include <stdlib.h>
#include "casos.h"

struct StCasos{
    double x, y;
    int n;
};
typedef struct StCasos *CasosImp;

Casos criarCasos(double x, double y, double n){
    CasosImp novo;
    novo = (CasosImp)malloc (sizeof (struct StCasos));

    novo->x = x;
    novo->y = y;
    novo->n = n;

    return novo;
}

double getXCasos(Casos caso){
    CasosImp c;
    c =  (CasosImp) caso;
    return c->x; 
}

double getYCasos(Casos caso){
    CasosImp c;
    c =  (CasosImp) caso;
    return c->y; 
}

double getNCasos(Casos caso){
    CasosImp c;
    c =  (CasosImp) caso;
    return c->n; 
}

void freeCasos (Casos caso){
    CasosImp c;
    c = (CasosImp) caso;
    free (c);
}