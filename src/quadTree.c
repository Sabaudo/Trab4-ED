#include <stdio.h>
#include <stdlib.h>
#include "quadTree.h"
#include "elementos/quadra.h"
#include "elementos/forma.h"
#include "elementos/texto.h"
#include "elementos/hidrante.h"
#include "elementos/semaforo.h"
#include "elementos/radioBase.h"
#include "elementos/casos.h"
#include "elementos/casosDentro.h"
#include "util.h"
#include "svg.h"
#include "consultas.h"

typedef struct no{
  ItemNode coisa;
  double x,y;
  struct no *Ne;/*Nordeste*/
  struct no *Nw;/*Noroeste*/
  struct no *Se;/*Sudeste*/
  struct no *Sw;/*Sudoeste*/
}noh;

typedef struct _arvore{
  struct no *inicio;
  int tam;
  int comp;
}arvore;

Tree createTree(){
  arvore *arv;
  arv = (arvore *)malloc(sizeof(arvore));
  arv->inicio = NULL;
  arv->tam = 0;
  arv->comp=0;

  return (Tree)arv;
}

int sizeTree(Tree arv){
  arvore *a;
  a = (arvore*)arv;
  return a->tam;
}

void insertTree(Tree arv,ItemNode obj,double x,double y){
  arvore *a;
  noh *n;
  noh *aux;
  PosicNo p;

  a = (arvore*)arv;
  aux = a->inicio;

  if(a->inicio != NULL)
    insertTreeAux(arv,obj,aux,x,y);
  else
    p = insertTreeInicio(arv,obj,x,y);
}

int insertTreeAux(Tree arv,ItemNode obj,PosicNo nohArv,double x,double y){
  arvore *a;
  noh *n;
  noh *aux;

  aux = (noh*)nohArv;
  a = (arvore*)arv;

  if(aux == NULL)
    return 1;
  else if(x <= aux->x && y >= aux->y){
    a->comp++;
    insertTreeNe(a,obj,aux,x,y);
    return 0;
  }
  else if(x <= aux->x && y <= aux->y){
    a->comp++;
    insertTreeSe(a,obj,aux,x,y);
    return 0;
  }
  else if(x >= aux->x && y >= aux->y){
    a->comp++;
    insertTreeNw(a,obj,aux,x,y);
    return 0;
  }
  else if(x >= aux->x && y <= aux->y){
    a->comp++;
    insertTreeSw(a,obj,aux,x,y);
    return 0;
  }
}

int insertTreeNe(Tree arv,ItemNode obj,PosicNo nohArv,double x, double y){
  arvore *a;
  noh *n;
  noh *aux;

  a = (arvore*)arv;
  n = (noh*)nohArv;
  if(n->Ne == NULL){
    aux = (noh *)malloc(sizeof(noh));
    aux->coisa = obj;
    aux->x = x;
    aux->y = y;
    aux->Ne = NULL;
    aux->Nw = NULL;
    aux->Se = NULL;
    aux->Sw = NULL;
    n->Ne = aux;
    a->tam++;
    return 1;
  }
  else
    insertTreeAux(arv,obj,n->Ne,x,y);
}

int insertTreeSe(Tree arv,ItemNode obj,PosicNo nohArv,double x,double y){
  arvore *a;
  noh *n;
  noh *aux;

  a = (arvore*)arv;
  n = (noh*)nohArv;
  if(n->Se == NULL){
    aux = (noh *)malloc(sizeof(noh));
    aux->coisa = obj;
    aux->x = x;
    aux->y = y;
    aux->Ne = NULL;
    aux->Nw = NULL;
    aux->Se = NULL;
    aux->Sw = NULL;
    n->Se = aux;
    a->tam++;
    return 1;
  }
  else
    insertTreeAux(arv,obj,n->Se,x,y);
}

int insertTreeNw(Tree arv,ItemNode obj,PosicNo nohArv,double x, double y){
  arvore *a;
  noh *n;
  noh *aux;

  a = (arvore*)arv;
  n = (noh*)nohArv;
  if(n->Nw == NULL){
    aux = (noh *)malloc(sizeof(noh));
    aux->coisa = obj;
    aux->x = x;
    aux->y = y;
    aux->Ne = NULL;
    aux->Nw = NULL;
    aux->Se = NULL;
    aux->Sw = NULL;
    n->Nw = aux;
    a->tam++;
    return 1;
  }
  else
    insertTreeAux(arv,obj,n->Nw,x,y);
}

int insertTreeSw(Tree arv,ItemNode obj,PosicNo nohArv,double x, double y){
  arvore *a;
  noh *n;
  noh *aux;

  a = (arvore*)arv;
  n = (noh*)nohArv;
  if(n->Sw == NULL){
    aux = (noh *)malloc(sizeof(noh));
    aux->coisa = obj;
    aux->x = x;
    aux->y = y;
    aux->Ne = NULL;
    aux->Nw = NULL;
    aux->Se = NULL;
    aux->Sw = NULL;
    n->Sw = aux;
    a->tam++;
    return 1;
  }
  else
    insertTreeAux(arv,obj,n->Sw,x,y);
}
PosicNo insertTreeInicio(Tree arv,ItemNode obj,double x, double y){
  arvore *a;
  noh *n;

  a = (arvore *)arv;
  n = (noh *)malloc(sizeof(noh));
  n->coisa = obj;
  n->Ne = NULL;
  n->Nw = NULL;
  n->Se = NULL;
  n->Sw = NULL;
  n->x = x;
  n->y = y;

  a->inicio = n;
  a->tam++;
  return (PosicNo)n;
}

ItemNode getElement(Tree arv,PosicNo nohArv){
  noh *n;
  ItemNode forma;
  PosicNo pos;

  pos = nohArv;
  n = (noh*)pos;
  if(n == NULL){
    //printf("null getElement\n");
    return NULL;
  }
  forma = n->coisa;

  return forma;
}

PosicNo getFirstElementTree(Tree arv){
  arvore *a;
  PosicNo pos;
  a = (arvore*)arv;

  if(a->inicio != NULL){
    return (PosicNo)a->inicio;
  }
  pos = NULL;
  return pos;
}

double getXQuadTree(Tree arv,PosicNo nohArv){
  arvore *a;
  noh *n;
  a = (arvore*)arv;
  n = (noh*)nohArv;
  if(a->inicio == NULL){
    return 0;
  }
  else
    return n->x;
}

double getYQuadTree(Tree arv,PosicNo nohArv){
  arvore *a;
  noh *n;
  a = (arvore*)arv;
  n = (noh*)nohArv;
  if(a->inicio == NULL){
    return 0;
  }
  else
    return n->y;
}

int getQuadrante(Tree arv,PosicNo nohArv,PosicNo nohArv2){
  arvore *a;
  noh *n,*n2;
  n = (noh*)nohArv;
  n2 = (noh*)nohArv2;

  if(n == NULL)
      return 0;
  if(n->Ne == n2)
    return 1;
  else if(n->Nw == n2)
    return 2;
  else if(n->Se == n2)
    return 3;
  else if(n->Sw == n2)
    return 4;
}

int removeTree(Tree arv,PosicNo nohArv){
  
  int q;
  arvore *a;
  noh *p=NULL,*n,*aux;

  a = (arvore*)arv;
  aux = a->inicio;
  n = (noh*)nohArv;

  if(aux != n){
    p = procurarPai(arv,aux,nohArv);
  
    q = getQuadrante(arv,p,n);
   
    if(q == 1)
      p->Ne = NULL;
    else if(q == 2)
      p->Nw = NULL;
    else if(q == 3)
      p->Se = NULL;
    else if(q == 4)
      p->Sw = NULL;
  }
  else{
    a->inicio = NULL;
    a->tam--;
  }


  reinsere(a,n,nohArv);
  n = NULL;
  return 1;
}

PosicNo procurarPai(Tree arv,PosicNo inicio,PosicNo nohArv){
  noh *aux=NULL;

  if(leafNe(arv,inicio) == 1){
    if(getNe(arv,inicio) == nohArv){
      aux = inicio;
      return aux;
    }
    if(aux == NULL)
      aux = procurarPai(arv,getNe(arv,inicio),nohArv);
  }

  if(leafNw(arv,inicio) == 1){
    if(getNw(arv,inicio) == nohArv){
      aux = inicio;
      return aux;
    }
    if(aux == NULL)
      aux = procurarPai(arv,getNw(arv,inicio),nohArv);
  }

  if(leafSe(arv,inicio) == 1){
    if(getSe(arv,inicio) == nohArv){
      aux = inicio;
      return aux;
    }
    if(aux == NULL)
      aux = procurarPai(arv,getSe(arv,inicio),nohArv);
  }

  if(leafSw(arv,inicio) == 1){
    if(getSw(arv,inicio) == nohArv){
      aux = inicio;
      return aux;
    }
    if(aux == NULL)
      aux = procurarPai(arv,getSw(arv,inicio),nohArv);
  }
  return aux;

}

void reinsere(Tree arv,PosicNo nohArv,PosicNo nohArv2){
  arvore *a;
  noh *n;
  ItemNode obj;
  double x,y;
  char *tipo;
  

  a = (arvore*)arv;
  n = (noh*)nohArv;

  if(leafSe(arv,nohArv) == 1){
    reinsere(arv,n->Se,nohArv2);
  }

  if(leafNw(arv,nohArv) == 1){
    reinsere(arv,n->Nw,nohArv2);
  }
  if(leafNe(arv,nohArv) == 1){
    reinsere(arv,n->Ne,nohArv2);
  }

  if(leafSw(arv,nohArv) == 1){
    reinsere(arv,n->Sw,nohArv2);
  }
 

  if(n != (noh*)nohArv2){
    obj = n->coisa;
    x = n->x;
    y = n->y;

    insertTree(arv,obj,x,y);
  }
  free(n);
  a->tam--;
}

PosicNo getNe(Tree arv,PosicNo nohArv){
  noh *n;
  PosicNo pos;
  pos = nohArv;

  n = (noh*)pos;
  if(n->Ne == NULL){
    pos = NULL;
  }
  else{
    n = n->Ne;
    pos = (PosicNo )n;
  }
  return pos;
}

PosicNo getNw(Tree arv,PosicNo nohArv){
  noh *n;
  PosicNo pos;
  pos = nohArv;

  n = (noh*)pos;
  if(n->Nw == NULL){
    pos = NULL;
  }
  else{
    n = n->Nw;
    pos = (PosicNo )n;
  }
  return pos;
}

PosicNo getSe(Tree arv,PosicNo nohArv){
  noh *n;
  PosicNo pos;
  pos = nohArv;

  n = (noh*)pos;
  if(n->Se == NULL){
    pos = NULL;
  }
  else{
    n = n->Se;
    pos = (PosicNo )n;
  }
  return pos;
}

PosicNo getSw(Tree arv,PosicNo nohArv){
  noh *n;
  PosicNo pos;
  pos = nohArv;

  n = (noh*)pos;
  if(n->Sw == NULL){
    pos = NULL;
  }
  else{
    n = n->Sw;
    pos = (PosicNo )n;
  }
  return pos;
}

int isLeaf(Tree arv,PosicNo nohArv){
  noh *n;

  n = (noh*)nohArv;
  if(n->Ne == NULL && n->Nw == NULL && n->Se == NULL && n->Sw){
    return 1;
  }
  else{
    return 0;
  }
}

int leafNe(Tree arv,PosicNo nohArv){
  noh *n;

  n = (noh*)nohArv;
  if(n == NULL){

    return 0;
  }
  else if(n->Ne == NULL){

    return 0;
  }
  else{
    return 1;
  }
}

int leafNw(Tree arv,PosicNo nohArv){
  noh *n;

  n = (noh*)nohArv;
  if(n == NULL){
    return 0;
  }
  else if(n->Nw == NULL){
    return 0;
  }
  else{
    return 1;
  }
}

int leafSe(Tree arv,PosicNo nohArv){
  noh *n;

  n = (noh*)nohArv;
  if(n == NULL){
    return 0;
  }
  else if(n->Se == NULL){
    return 0;
  }
  else{
    return 1;
  }
}

int leafSw(Tree arv,PosicNo nohArv){
  noh *n;

  n = (noh*)nohArv;
  if(n == NULL){
    return 0;
  }
  else if(n->Sw == NULL){
    return 0;
  }
  else{
    return 1;
  }
}

int getComp(Tree arv){
  arvore *a;
  noh *n;

  a = (arvore*)arv;
  return a->comp;
}

void desmatamento(Tree arv){
  arvore *a;
  noh *n;
  a = (arvore*)arv;
  n = a->inicio;
  freeTree(a,n);
}

void freeTree(Tree arv,PosicNo nohArv){
  noh *n;
  n = (noh*)nohArv;

  if(leafNe(arv,n) == 1){
    freeTree(arv,n->Ne);
  }

  if(leafNw(arv,n) == 1){
    freeTree(arv,n->Nw);
  }

  if(leafSe(arv,n) == 1){
    freeTree(arv,n->Se);
  }

  if(leafSw(arv,n) == 1){
    freeTree(arv,n->Sw);
  }
  free(n);
  n = NULL;

}

int processarTree(Tree arv,PosicNo nohArv,Escrever escreverEquip,FILE *arq){
  ItemNode info;

  if(nohArv == NULL){
    return 0;
  }

  if(leafNe(arv,nohArv) == 1){
    processarTree(arv,getNe(arv,nohArv),escreverEquip,arq);
  }

  if(leafNw(arv,nohArv) == 1){
    processarTree(arv,getNw(arv,nohArv),escreverEquip,arq);
  }

  if(leafSe(arv,nohArv) == 1){
    processarTree(arv,getSe(arv,nohArv),escreverEquip,arq);
  }

  if(leafSw(arv,nohArv) == 1){
    processarTree(arv,getSw(arv,nohArv),escreverEquip,arq);
  }

  info = getElement(arv,nohArv);
  escreverEquip(arq,info);
}

void* percorrer_Quadra_QD(Tree arvoreAux,char id[],PosicNo n){

  if(strcmp(id,getCEPQuadra(getElement(arvoreAux,n)))==0){
    return n;
  }
    
  ItemNode resposta = NULL;

  if(leafNe(arvoreAux,n) == 1)
    resposta = percorrer_Quadra_QD(arvoreAux,id,getNe(arvoreAux,n));

    if(resposta != NULL){
      return resposta;
    }

    if(leafNw((arvoreAux),n) == 1)
    resposta = percorrer_Quadra_QD(arvoreAux,id,getNw(arvoreAux,n));

    if(resposta != NULL){
      return resposta;
    }

  if(leafSe((arvoreAux),n) == 1)
    resposta = percorrer_Quadra_QD(arvoreAux,id,getSe(arvoreAux,n));

    if(resposta != NULL){
      return resposta;
    }

  if(leafSw((arvoreAux),n) == 1)
    resposta = percorrer_Quadra_QD(arvoreAux,id,getSw(arvoreAux,n));

    if(resposta != NULL){
      return resposta;
    }

    return NULL;
}

void* percorrer_Forma_QD(Tree arvoreAux,char id[],PosicNo n){

  if(getElement(arvoreAux,n) == NULL ){
    return NULL;
  }

  if(strcmp(id,getIdForma(getElement(arvoreAux,n)))==0){
    return n;
  }

  ItemNode resposta = NULL;

  if(leafNe(arvoreAux,n) == 1)
    resposta = percorrer_Forma_QD(arvoreAux,id,getNe(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  if(leafNw((arvoreAux),n) == 1)
    resposta = percorrer_Forma_QD(arvoreAux,id,getNw(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  if(leafSe((arvoreAux),n) == 1)
    resposta = percorrer_Forma_QD(arvoreAux,id,getSe(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  if(leafSw((arvoreAux),n) == 1)
    resposta = percorrer_Forma_QD(arvoreAux,id,getSw(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  return NULL;
}

void* percorrer_Texto_QD(Tree arvoreAux,char id[],PosicNo n){

   if(getElement(arvoreAux,n) == NULL ){
    return NULL;
  }
   
  if(strcmp(id,getIdForma(getElement(arvoreAux,n)))==0){
    return n;
  }

  ItemNode resposta = NULL;

  if(leafNe(arvoreAux,n) == 1)
    resposta = percorrer_Texto_QD(arvoreAux,id,getNe(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  if(leafNw((arvoreAux),n) == 1)
    resposta = percorrer_Texto_QD(arvoreAux,id,getNw(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  if(leafSe((arvoreAux),n) == 1)
    resposta = percorrer_Texto_QD(arvoreAux,id,getSe(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  if(leafSw((arvoreAux),n) == 1)
    resposta = percorrer_Texto_QD(arvoreAux,id,getSw(arvoreAux,n));

  if(resposta != NULL){
    return resposta;

  } 
  return NULL;
}

void* percorrer_Hidrante_QD(Tree arvoreAux,char id[],PosicNo n){

  if(strcmp(id,getIDHid(getElement(arvoreAux,n)))==0){
    return n;
  }

  ItemNode resposta = NULL;

  if(leafNe(arvoreAux,n) == 1)
    resposta = percorrer_Hidrante_QD(arvoreAux,id,getNe(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  if(leafNw((arvoreAux),n) == 1)
      resposta = percorrer_Hidrante_QD(arvoreAux,id,getNw(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  if(leafSe((arvoreAux),n) == 1)
    resposta = percorrer_Hidrante_QD(arvoreAux,id,getSe(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  if(leafSw((arvoreAux),n) == 1)
    resposta = percorrer_Hidrante_QD(arvoreAux,id,getSw(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }
  
  return NULL;
}

void* percorrer_Semaforo_QD(Tree arvoreAux,char id[],PosicNo n){

  if(strcmp(id,getIDSema(getElement(arvoreAux,n)))==0){
    return n;
  }

  ItemNode resposta = NULL;

  if(leafNe(arvoreAux,n) == 1)
    resposta = percorrer_Semaforo_QD(arvoreAux,id,getNe(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  if(leafNw((arvoreAux),n) == 1)
    resposta = percorrer_Semaforo_QD(arvoreAux,id,getNw(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  if(leafSe((arvoreAux),n) == 1)
    resposta = percorrer_Semaforo_QD(arvoreAux,id,getSe(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  if(leafSw((arvoreAux),n) == 1)
    resposta = percorrer_Semaforo_QD(arvoreAux,id,getSw(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  return NULL;
}

void* percorrer_RB_QD(Tree arvoreAux,char id[],PosicNo n){

  if(strcmp(id,getIDRB(getElement(arvoreAux,n)))==0){
    return n;
  }

  ItemNode resposta = NULL;

  if(leafNe(arvoreAux,n) == 1)
    resposta = percorrer_RB_QD(arvoreAux,id,getNe(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  if(leafNw((arvoreAux),n) == 1)
    resposta = percorrer_RB_QD(arvoreAux,id,getNw(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  if(leafSe((arvoreAux),n) == 1)
    resposta = percorrer_RB_QD(arvoreAux,id,getSe(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }
  if(leafSw((arvoreAux),n) == 1)
    resposta = percorrer_RB_QD(arvoreAux,id,getSw(arvoreAux,n));

  if(resposta != NULL){
    return resposta;
  }

  return NULL;
}

void* encontrarElementoArvores (char id[], Tree arvoreQuadra, Tree arvoreHidrante, Tree arvoreSemaforo, Tree arvoreRadioBase){
  PosicNo elemento;

  elemento = percorrer_Quadra_QD(arvoreQuadra, id, getFirstElementTree(arvoreQuadra));
  if(elemento == NULL){
    elemento = percorrer_Hidrante_QD(arvoreHidrante, id, getFirstElementTree(arvoreHidrante));

  }
  else {
    return getElement(arvoreQuadra, elemento);
  }
  if(elemento == NULL){
    elemento = percorrer_Semaforo_QD(arvoreSemaforo, id, getFirstElementTree(arvoreSemaforo));
  }
  else  {
    return getElement(arvoreHidrante, elemento);
    
  }

  if(elemento ==NULL){
    elemento = percorrer_RB_QD(arvoreRadioBase, id, getFirstElementTree(arvoreRadioBase));
  }
  else {
    return getElement(arvoreSemaforo, elemento);
  }
  return getElement(arvoreRadioBase, elemento);
}

void* dq_percorrer_arvore(Tree arvoreAux, double x, double y, double r, FILE *txt, FILE* svg2, bool verificador, PosicNo aux, Lista listaQuadra_2){
  Quadra quadra;
  quadra = getElement(arvoreAux, aux);

  int cont=0;

  if(true){
    if(distanciaEuclidiana(x, y, getXQuadra(quadra), getYQuadra(quadra)) <= r){
      cont++;
    }
    if(distanciaEuclidiana (x, y, getXQuadra(quadra) + getWQuadra(quadra), getYQuadra(quadra)) <= r){
      cont++;
    }
    if(distanciaEuclidiana (x, y, getXQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= r){
      cont++;
    }
    if(distanciaEuclidiana (x, y, getXQuadra (quadra) + getWQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= r){
      cont++;
    }
    if(cont == 4){
      fprintf(txt, "Cep removido: %s\n", getCEPQuadra(quadra));
      insert(listaQuadra_2, quadra, "q");
      if(verificador){
        svg_imprimir_quadArrend(svg2, quadra);
      }
    }
  }
  cont=0;

  ItemNode resposta = NULL;

  if(leafNe(arvoreAux,aux) == 1)
    resposta = dq_percorrer_arvore(arvoreAux,x, y ,r, txt, svg2,verificador, getNe(arvoreAux,aux), listaQuadra_2);

  if(resposta != NULL){
    return resposta;
  }

  if(leafNw((arvoreAux),aux) == 1)
    resposta = dq_percorrer_arvore(arvoreAux, x, y, r, txt, svg2,verificador, getNw(arvoreAux,aux), listaQuadra_2);

  if(resposta != NULL){
    return resposta;
  }

  if(leafSe((arvoreAux),aux) == 1)
    resposta = dq_percorrer_arvore(arvoreAux,x, y,r, txt, svg2,verificador, getSe(arvoreAux,aux), listaQuadra_2);

  if(resposta != NULL){
    return resposta;
  }

  if(leafSw((arvoreAux),aux) == 1)
    resposta = dq_percorrer_arvore(arvoreAux,x,y,r, txt, svg2,verificador, getSw(arvoreAux,aux), listaQuadra_2);

  if(resposta != NULL){
    return resposta;
  }

  return NULL;
}

void* percorrer_CBQ(Tree arvoreQuadra, double x, double y, double r, char corBorda[], FILE *txt, FILE* svg2, PosicNo aux){
  Quadra quadra;
  quadra = getElement(arvoreQuadra, aux);
  int cont=0;

  if(true){
    if(distanciaEuclidiana(x, y, getXQuadra(quadra), getYQuadra(quadra)) <= r){
      cont++;
    }
    if(distanciaEuclidiana (x, y, getXQuadra(quadra) + getWQuadra(quadra), getYQuadra(quadra)) <= r){
      cont++;
    }
    if(distanciaEuclidiana (x, y, getXQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= r){
      cont++;
    }
    if(distanciaEuclidiana (x, y, getXQuadra (quadra) + getWQuadra (quadra), getYQuadra (quadra) + getHQuadra (quadra)) <= r){
      cont++;
    }
    if (cont == 4){
      setcorBordaQuadra(quadra, corBorda);
      fprintf(txt, "Cep da quadra alterada: %s\n", getCEPQuadra(quadra));
    }
  }
  cont=0;

  ItemNode resposta = NULL;

  if(leafNe(arvoreQuadra,aux) == 1)
    resposta = percorrer_CBQ(arvoreQuadra,x, y ,r, corBorda, txt, svg2, getNe(arvoreQuadra,aux));

  if(resposta != NULL){
    return resposta;
  }

  if(leafNw((arvoreQuadra),aux) == 1)
    resposta = percorrer_CBQ(arvoreQuadra, x, y, r, corBorda, txt, svg2, getNw(arvoreQuadra,aux));

  if(resposta != NULL){
    return resposta;
  }

  if(leafSe((arvoreQuadra),aux) == 1)
    resposta = percorrer_CBQ(arvoreQuadra,x, y, r, corBorda, txt, svg2, getSe(arvoreQuadra,aux));

  if(resposta != NULL){
    return resposta;
  }

  if(leafSw((arvoreQuadra),aux) == 1)
    resposta = percorrer_CBQ(arvoreQuadra,x, y, r, corBorda, txt, svg2, getSw(arvoreQuadra,aux));

  if(resposta != NULL){
    return resposta;
  }

  return NULL;
}

void* percorrer_CAR(FILE* aux_txt, FILE* txt, Tree arvoreQuadra, PosicNo aux, double x, double y, double h, double w, Lista listaQuadra){
  double areaQuadra = 0;
  int cont = 0;
  char aq[32], a[32];
  Quadra quadra;

  quadra = getElement(arvoreQuadra, aux);
  Forma ret = criarForma("0", "r", x, y, 0, w, h, "black", "none", "1.0");

  if(true){
    if(getXQuadra (quadra) > x && getXQuadra (quadra) < x + w && getYQuadra (quadra) > y && getYQuadra (quadra) < y + h){
      cont++;
    }
    if(getXQuadra (quadra) + getWQuadra (quadra) > x && getXQuadra (quadra) + getWQuadra (quadra) < x + w && getYQuadra (quadra) > y && getYQuadra (quadra) < y + h){
      cont++;
    }
    if(getXQuadra (quadra) > x && getXQuadra (quadra) < x + w && getYQuadra (quadra) + getHQuadra (quadra) > y && getYQuadra (quadra) + getHQuadra (quadra) < y + h){
      cont++;
    }
    if(getXQuadra (quadra) + getWQuadra (quadra) > x && getXQuadra (quadra) + getWQuadra (quadra) < x + w && getYQuadra (quadra) + getHQuadra (quadra) > y && getYQuadra (quadra) + getHQuadra (quadra) < y + h){
      cont++;
    }
    if(cont == 4) {
      insert(listaQuadra, quadra, "q");
      areaQuadra = getHQuadra(quadra) * getWQuadra(quadra);
      sprintf(aq, "%.2lf", areaQuadra);
      Texto text = criarTexto("0", "t", (getXQuadra(quadra) + getWQuadra(quadra)/2), 
      (getYQuadra(quadra) + getHQuadra(quadra)/2), "white", "black", aq);
      svg_imprimirTexto(aux_txt, text);
      fprintf(txt, "cep quadra:%s, area: %lf\n", getCEPQuadra(quadra), areaQuadra);
      freeTexto(text);
    }
  }
  cont = 0;

  ItemNode resposta = NULL;

  if(leafNe(arvoreQuadra, aux) == 1)
    resposta = percorrer_CAR(aux_txt, txt, arvoreQuadra, getNe(arvoreQuadra, aux), x, y, h, w, listaQuadra);

  if(resposta != NULL) {
    return resposta;
  }

  if(leafNw((arvoreQuadra), aux) == 1)
    resposta = percorrer_CAR(aux_txt, txt, arvoreQuadra, getNw(arvoreQuadra, aux), x, y, h, w, listaQuadra);

  if(resposta != NULL) {
    return resposta;
  }

  if(leafSe((arvoreQuadra), aux) == 1)
    resposta = percorrer_CAR(aux_txt, txt, arvoreQuadra, getSe(arvoreQuadra, aux), x, y, h, w, listaQuadra);

  if(resposta != NULL) {
    return resposta;
  }

  if(leafSw((arvoreQuadra), aux) == 1)
    resposta = percorrer_CAR(aux_txt, txt, arvoreQuadra, getSw(arvoreQuadra, aux), x, y, h, w, listaQuadra);
      
  if(resposta != NULL) {
    return resposta;
  }

  return  NULL;
}

void* soc_posto_conversao(Tree arvorePosto,PosicNo aux,Lista listaPosto){
  Posto posto;
  posto = getElement(arvorePosto, aux);

  if(posto == NULL){
    return NULL;
  }
  insert(listaPosto, posto, "ps");

  ItemNode resposta = NULL;

  if(leafNe(arvorePosto,aux) == 1)
    resposta = soc_posto_conversao(arvorePosto, getNe(arvorePosto,aux), listaPosto);

  if(resposta != NULL){
    return resposta;
  }

  if(leafNw((arvorePosto),aux) == 1)
    resposta = soc_posto_conversao(arvorePosto, getNw(arvorePosto,aux), listaPosto);


  if(resposta != NULL){
    return resposta;
  }

  if(leafSe((arvorePosto),aux) == 1)
    resposta = soc_posto_conversao(arvorePosto, getSe(arvorePosto,aux), listaPosto);

  if(resposta != NULL){
    return resposta;
  }

  if(leafSw((arvorePosto),aux) == 1)
    resposta = soc_posto_conversao(arvorePosto, getSw(arvorePosto,aux), listaPosto);

  if(resposta != NULL){
    return resposta;
  }

  return NULL;
}

void* ci_casos_conversao(Tree arvoreCasos,PosicNo aux,Lista listaCasos){
  Posto posto;
  posto = getElement(arvoreCasos, aux);
  insert(listaCasos, posto, "ca");

  ItemNode resposta = NULL;

  if(leafNe(arvoreCasos,aux) == 1)
    resposta = ci_casos_conversao(arvoreCasos, getNe(arvoreCasos,aux), listaCasos);

  if(resposta != NULL){
    return resposta;
  }

  if(leafNw((arvoreCasos),aux) == 1)
    resposta = ci_casos_conversao(arvoreCasos, getNw(arvoreCasos,aux), listaCasos);


  if(resposta != NULL){
    return resposta;
  }

  if(leafSe((arvoreCasos),aux) == 1)
    resposta = ci_casos_conversao(arvoreCasos, getSe(arvoreCasos,aux), listaCasos);

  if(resposta != NULL){
    return resposta;
  }

  if(leafSw((arvoreCasos),aux) == 1)
    resposta = ci_casos_conversao(arvoreCasos, getSw(arvoreCasos,aux), listaCasos);

  if(resposta != NULL){
    return resposta;
  }

  return NULL;
}

void* percorrer_Quadra_dd(Tree arvoreQuadra, PosicNo aux, double x, double w, double y, double h) {
  Forma retangulo = criarForma("0", "r", x, y, 0, w, h, "black", "white", "1.0");
  Quadra quadra = getElement(arvoreQuadra, aux);
  extern double numQuadrasDentro;
  int cont = 0;

    if(true){
      if(getXQuadra (quadra) >= x && getXQuadra (quadra) <= x + w && getYQuadra (quadra) >= y && getYQuadra (quadra) <= y + h){
        cont++;
      }
      if(getXQuadra (quadra) + getWQuadra (quadra) >= x && getXQuadra (quadra) + getWQuadra (quadra) <= x + w && getYQuadra (quadra) >= y && getYQuadra (quadra) <= y + h){
        cont++;
      }
      if(getXQuadra (quadra) >= x && getXQuadra (quadra) <= x + w && getYQuadra (quadra) + getHQuadra (quadra) >= y && getYQuadra (quadra) + getHQuadra (quadra) <= y + h){
        cont++;
      }
      if(getXQuadra (quadra) + getWQuadra (quadra) >= x && getXQuadra (quadra) + getWQuadra (quadra) <= x + w && getYQuadra (quadra) + getHQuadra (quadra) >= y && getYQuadra (quadra) + getHQuadra (quadra) <= y + h){
        cont++;
      }

      if(cont == 4){
        numQuadrasDentro++;
      }

    }
    ItemNode resposta = NULL;

    if(leafNe(arvoreQuadra, aux) == 1)
      resposta = percorrer_Quadra_dd(arvoreQuadra, getNe(arvoreQuadra, aux), x, w, y, h);

    if(resposta != NULL) {
      return resposta;
    }

    if(leafNw(arvoreQuadra, aux) == 1)
      resposta = percorrer_Quadra_dd(arvoreQuadra, getNw(arvoreQuadra, aux), x, w, y, h);

    if(resposta != NULL) {
      return resposta;
    }

    if(leafSe(arvoreQuadra, aux) == 1)
      resposta = percorrer_Quadra_dd(arvoreQuadra, getSe(arvoreQuadra, aux), x, w, y, h);

    if(resposta != NULL) {
      return resposta;
    }

    if(leafSw(arvoreQuadra, aux) == 1)
      resposta = percorrer_Quadra_dd(arvoreQuadra, getSw(arvoreQuadra, aux), x, w, y, h);

    if(resposta != NULL) {
      return resposta;
    }

  return NULL;
}

void* inputSombraQuadras(Tree arvoreQuadra, PosicNo aux, FILE* svg, double densidadeQuadra, double x, double y, double w, double h){
  int cont = 0;
  Quadra quadra = getElement(arvoreQuadra, aux);

  if(true){
    if(getXQuadra (quadra) >= x && getXQuadra (quadra) <= x + w && getYQuadra (quadra) >= y && getYQuadra (quadra) <= y + h){
    cont++;
    }

    if(getXQuadra (quadra) + getWQuadra (quadra) >= x && getXQuadra (quadra) + getWQuadra (quadra) <= x + w && getYQuadra (quadra) >= y && getYQuadra (quadra) <= y + h){
      cont++;
    }

    if(getXQuadra (quadra) >= x && getXQuadra (quadra) <= x + w && getYQuadra (quadra) + getHQuadra (quadra) >= y && getYQuadra (quadra) + getHQuadra (quadra) <= y + h){
      cont++;
    }

    if(getXQuadra (quadra) + getWQuadra (quadra) >= x && getXQuadra (quadra) + getWQuadra (quadra) <= x + w && getYQuadra (quadra) + getHQuadra (quadra) >= y && getYQuadra (quadra) + getHQuadra (quadra) <= y + h){
      cont++;
    }

    if(cont == 4){
      if(densidadeQuadra >= 10 && densidadeQuadra < 500){
      svg_drop_shadow(svg, getXQuadra(quadra)+5, getYQuadra(quadra)+5, getWQuadra(quadra), getHQuadra(quadra), "#FFFF00", "#FFFF00", "#FFFF00");
      }

      if(densidadeQuadra >= 500 && densidadeQuadra < 1500){
        svg_drop_shadow(svg, getXQuadra(quadra)+5, getYQuadra(quadra)+5, getWQuadra(quadra), getHQuadra(quadra), "#FF9955", "#FF9955", "#FF9955");
      }

      if(densidadeQuadra >= 1500 && densidadeQuadra < 3000){
        svg_drop_shadow(svg, getXQuadra(quadra)+5, getYQuadra(quadra)+5, getWQuadra(quadra), getHQuadra(quadra), "#FF0000", "#FF0000", "#FF0000");
      }

      if(densidadeQuadra >= 3000 && densidadeQuadra < 4500){
        svg_drop_shadow(svg, getXQuadra(quadra)+5, getYQuadra(quadra)+5, getWQuadra(quadra), getHQuadra(quadra), "#FF00CC", "#FF00CC", "#FF00CC");
      }

      if(densidadeQuadra >= 4500 && densidadeQuadra < 6000){
        svg_drop_shadow(svg, getXQuadra(quadra)+5, getYQuadra(quadra)+5, getWQuadra(quadra), getHQuadra(quadra), "#6600FF", "#6600FF", "#6600FF");
      }
      
      if(densidadeQuadra >= 6000){
        svg_drop_shadow(svg, getXQuadra(quadra)+5, getYQuadra(quadra)+5, getWQuadra(quadra), getHQuadra(quadra), "#A02C5A", "#A02C5A", "#A02C5A");
      }

    }

  }

  cont = 0;
  ItemNode resposta = NULL;

  if(leafNe(arvoreQuadra, aux) == 1)
    resposta = inputSombraQuadras(arvoreQuadra, getNe(arvoreQuadra, aux), svg, densidadeQuadra, x, y, w, h);

  if(resposta != NULL) {
    return resposta;
  }

  if(leafNw(arvoreQuadra, aux) == 1)
    resposta = inputSombraQuadras(arvoreQuadra, getNw(arvoreQuadra, aux), svg, densidadeQuadra, x, y, w, h);

  if(resposta != NULL) {
    return resposta;
  }

  if(leafSe(arvoreQuadra, aux) == 1)
    resposta = inputSombraQuadras(arvoreQuadra, getSe(arvoreQuadra, aux), svg, densidadeQuadra, x, y, w, h);


  if(resposta != NULL) {
    return resposta;
  }

  if(leafSw(arvoreQuadra, aux) == 1)
    resposta = inputSombraQuadras(arvoreQuadra, getSw(arvoreQuadra, aux),svg, densidadeQuadra, x, y, w, h);

  if(resposta != NULL) {
    return resposta;
  }

  return NULL;
}


