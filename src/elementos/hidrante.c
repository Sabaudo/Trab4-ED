#include"hidrante.h"
struct StHidrante {
    char id[50], tipo[4],corBorda[32],corPreenchimento[32], sw[32];
    double x, y;
};
typedef struct StHidrante *HidranteImp;

Hidrante criaHidrante (char id[], char tipo[], double x, double y, char corPreenchimento[], char corBorda[], char sw[]){
    HidranteImp novo;
    novo = (HidranteImp)malloc(sizeof(struct StHidrante));
    strcpy (novo->id, id);
    novo->x = x;
    novo->y = y;
    strcpy(novo->tipo,"h");
    strcpy (novo->corBorda, corBorda);
    strcpy (novo->corPreenchimento, corPreenchimento);
    strcpy (novo->sw, sw);
    return novo;
}

double getXHid (Hidrante hidrante){
    HidranteImp h;
    h = (HidranteImp) hidrante;
    return h->x; 
}

double getYHid (Hidrante hidrante){
    HidranteImp h;
    h = (HidranteImp) hidrante;
    return h->y; 
}

char* getIDHid (Hidrante hidrante){
    HidranteImp h;
    h = (HidranteImp) hidrante;
    return h->id;
}
char* getTipoHidrante (Hidrante hidrante){
    HidranteImp h;
    h = (HidranteImp) hidrante;
    return h->tipo;
}

char* getcorBordaHid (Hidrante hidrante){
    HidranteImp h;
    h = (HidranteImp) hidrante;
    return h->corBorda;
}

char* getcorPreenchimentoHid (Hidrante hidrante){
    HidranteImp h;
    h = (HidranteImp) hidrante;
    return h->corPreenchimento;
}
char* getSWHid (Hidrante hidrante){
    HidranteImp h;
    h = (HidranteImp) hidrante;
    return h->sw;
}

void freeHidrante (Hidrante hidrante){
    HidranteImp h;
    h = (HidranteImp) hidrante;
    free (h);
}

void getHidranteInformacao(Hidrante hidrante, char *info, char *posic){
    HidranteImp h;
    h = (HidranteImp) hidrante;
    sprintf(info, "%s", h->id);
    sprintf(posic, "(%.2lf, %.2lf)", h->x, h->y);
}