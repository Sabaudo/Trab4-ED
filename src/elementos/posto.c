#include"posto.h"
struct StPosto {
    char tipo[4],corBorda[32],corPreenchimento[32];
    double x, y;
};

typedef struct StPosto *PostoImp;

Posto criarPosto(double x, double y, char corPreenchimento[], char corBorda[]){
    PostoImp novo;
    novo = (PostoImp) malloc (sizeof (struct StPosto));
    novo->x = x;
    novo->y = y;
    strcpy(novo->tipo,"sp");
    strcpy (novo->corBorda, corBorda);
    strcpy (novo->corPreenchimento, corPreenchimento);
    return novo;
}

double getXPosto (Posto posto){
    PostoImp p;
    p = (PostoImp) posto;
    return p->x; 
}

double getYPosto (Posto posto){
    PostoImp p;
    p = (PostoImp) posto;
    return p->y; 
}

char* getcorBordaPosto (Posto posto){
    PostoImp p;
    p = (PostoImp) posto;
    return p->corBorda;
}
char* getcorPreenchimentoPosto (Posto posto){
    PostoImp p;
    p = (PostoImp) posto;
    return p->corPreenchimento;
}


void freePosto (Posto posto){
    PostoImp p;
    p = (PostoImp) posto;
    free (p);
}