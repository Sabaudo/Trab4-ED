#include"radioBase.h"
struct StRadioBase {
    char cep[50], tipo[4],corBorda[32],corPreenchimento[32], sw[20];
    double x, y;
};

typedef struct StRadioBase *RadioBaseImp;

RadioBase criaRadioBase (char cep[], char tipo[], double x, double y, char corPreenchimento[], char corBorda[], char sw[]){
    RadioBaseImp novo;
    novo = (RadioBaseImp) malloc (sizeof (struct StRadioBase));
    strcpy (novo->cep, cep);
    novo->x = x;
    novo->y = y;
    strcpy(novo->tipo,"rb");
    strcpy(novo->corBorda, corBorda);
    strcpy(novo->corPreenchimento, corPreenchimento);
    strcpy(novo->sw, sw);
    return novo;
}

double getXRB (RadioBase radioBase){
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    return rb->x; 
}

double getYRB (RadioBase radioBase){
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    return rb->y; 
}

char* getIDRB (RadioBase radioBase){
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    return rb->cep;
}

char* getTipoRB (RadioBase radioBase){
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    return rb->tipo;
}

char* getcorBordaRB (RadioBase radioBase){
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    return rb->corBorda;
}

char* getcorPreenchimentoRB (RadioBase radioBase){
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    return rb->corPreenchimento;
}

char* getSWRB (RadioBase radioBase){
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    return rb->sw;
}
void freeRadioBase (RadioBase radioBase){
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    free (rb);
}

void getRBInformacao(RadioBase radioBase, char *info, char *posic){
    RadioBaseImp rb;
    rb = (RadioBaseImp) radioBase;
    sprintf(info, "%s", rb->cep);
    sprintf(posic, "(%.2lf, %.2lf)", rb->x, rb->y);
}