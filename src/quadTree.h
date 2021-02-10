#ifndef QUADTREE_H
#define QUADTREE_H
#include <stdbool.h>



/*
  -Tree é um tipo que cria e possibilita a criação de arvores
*/
typedef void* Tree;


/*
  -Lista de auxilio
 */
typedef void* Lista;


/*
  -Item é um item da arvore
*/
typedef void* ItemNode;
/*
  -PosicNo é um nó que aponta para uma determinada posição da arvore
*/
typedef void* PosicNo;

typedef void(* getEquipamento)(void*);

typedef void(* getCoordX)(void*);

typedef void(* getCoordY)(void*);

typedef void (* Escrever)(FILE*,void*);

//Numero de quadras dentro do retangulo passado pelo comando dd no .geo
double numQuadrasDentro;


/*
  Cria uma Arvore e retorna Tree
*/
Tree createTree();

/*
  -Retorna o tamanho da tree
  -arv: Tree genérica
*/
int sizeTree(Tree arv);

/*
  Insere um item na Arvore
  -arv é uma Tree(arvore)
  -obj é um item a ser inserido na arvore
  -x é a coordenada x do item
  -y é a coordenada y do item
*/
void insertTree(Tree arv,ItemNode obj,double x,double y);

/*
  Insere um item no inicio da Arvore
  -arv: Arvore Genérica
  -obj: Objeto a ser inserido
  -x: Coordenada x do objeto
  -y: Coordenada y do objeto
*/
PosicNo insertTreeInicio(Tree arv,ItemNode obj,double x, double y);

/*
  Procura um nó para inserir o item(seja em Ne,Nw,Se ou Sw)
  -arv: Arvore Genérica
  -obj: Objeto a ser inserido
  -nohArv: Nó atual da arvore
  -x: Coordenada x do objeto
  -y: Coordenada y do objeto
*/
int insertTreeAux(Tree arv,ItemNode obj,PosicNo nohArv,double x,double y);

/*
  -Insere um Item a Ne do nó atual
  -arv: Arvore Genérica
  -obj: Objeto a ser inserido
  -nohArv: Nó atual da arvore
  -x: Coordenada x do objeto
  -y: Coordenada y do objeto
*/

int insertTreeNe(Tree arv,ItemNode obj,PosicNo nohArv,double x, double y);

/*
  -Insere um Item a Se do nó atual
  -arv: Arvore Genérica
  -obj: Objeto a ser inserido
  -nohArv: Nó atual da arvore
  -x: Coordenada x do objeto
  -y: Coordenada y do objeto
*/
int insertTreeSe(Tree arv,ItemNode obj,PosicNo nohArv,double x,double y);

/*
  -Insere um Item a Nw do nó atual
  -arv: Arvore Genérica
  -obj: Objeto a ser inserido
  -nohArv: Nó atual da arvore
  -x: Coordenada x do objeto
  -y: Coordenada y do objeto
*/
int insertTreeNw(Tree arv,ItemNode obj,PosicNo nohArv,double x, double y);

/*
  -Insere um Item a Sw do nó atual
  -arv: Arvore Genérica
  -obj: Objeto a ser inserido
  -nohArv: Nó atual da arvore
  -x: Coordenada x do objeto
  -y: Coordenada y do objeto
*/
int insertTreeSw(Tree arv,ItemNode obj,PosicNo nohArv,double x, double y);


/*
  -Retorna o item desejado
  -arv: Arvore genérica
  -nohArv: Nó em que está o item
*/
ItemNode getElement(Tree arv,PosicNo nohArv);

/*
  -Retorna o primeiro elemento da QuadTree
*/
PosicNo getFirstElementTree(Tree arv);

/*
  -Retorna a coordenada x do nó nohArv
*/
double getXQuadTree(Tree arv,PosicNo nohArv);

/*
  -Retorna a coordenada y do nó nohArv
*/
double getYQuadTree(Tree arv,PosicNo nohArv);

/*
  -Retorna o quadrante em que está o nohArv2
  -arv: Arvore genérica
  -nohArv: Nó pai
  -nohArv2: nó a ser observado
*/
int getQuadrante(Tree arv,PosicNo nohArv,PosicNo nohArv2);


/*
  Remove um item da Arvore, com o nó sendo 'nohArv'
*/
int removeTree(Tree arv,PosicNo nohArv);

/*
  -Procura o nó Pai de um determinado nó
  -arv: Arvore genérica
  -inicio: Provavel nó pai
  -nohArv: Nó a ser comparado
*/
PosicNo procurarPai(Tree arv,PosicNo inicio,PosicNo nohArv);

/*
  -Função que após a remoção de um determinado elemento, faz a reinserção na QuadTree
*/
void reinsere(Tree arv,PosicNo nohArv,PosicNo nohArv2);

/*
  Retorna o nó a Ne
  -arv: Arvore genérica
  -nohArv: Nó atual
*/
PosicNo getNe(Tree arv,PosicNo nohArv);

/*
  Retorna o nó a Nw
  -arv: Arvore genérica
  -nohArv: Nó atual
*/
PosicNo getNw(Tree arv,PosicNo nohArv);

/*
  Retorna o nó a Se
  -arv: Arvore genérica
  -nohArv: Nó atual
*/
PosicNo getSe(Tree arv,PosicNo nohArv);

/*
  -Retorna o nó a Sw
  -arv: Arvore genérica
  -nohArv: Nó atual
*/
PosicNo getSw(Tree arv,PosicNo nohArv);

/*
  -Função que verifica se o nó é uma folha
*/
int isLeaf(Tree arv,PosicNo nohArv);

/*
  -Verifica se existe nó a Ne
*/
int leafNe(Tree arv,PosicNo nohArv);

/*
  -Verifica se existe nó a Nw
*/
int leafNw(Tree arv,PosicNo nohArv);

/*
  -Verifica se existe nó a Se
*/
int leafSe(Tree arv,PosicNo nohArv);

/*
  -Verifica se existe nó a Sw
*/
int leafSw(Tree arv,PosicNo nohArv);

int getComp(Tree arv);

/*
  -Função que desaloca a QuadTree
  -arv: Arvore a ser desalocada
*/
void desmatamento(Tree arv);

/*
  -Desaloca um determinado nó
  -nohArv: Nó a ser desalocado
*/
void freeTree(Tree arv,PosicNo nohArv);


/*
 * Processa uma arvore, lendo suas informações e as colocando no svg
 * Necessita das informações necessárias terem sido passsadas
 */
int processarTree(Tree arv,PosicNo nohArv,Escrever escreverEquip,FILE *arq);


/*
 * Percorre a arvore de quadras
 * Nao retorna nada
 */
void* percorrer_Quadra_QD(Tree arvoreAux,char id[],PosicNo n);


/*
 * Percorre a arvore de formas(circulo ou retangulo)
 * Nao retorna nada
 */
void* percorrer_Forma_QD(Tree arvoreAux,char id[],PosicNo n);


/*
 * Percorre a arvore de textos
 * Nao retorna nada
 */
void* percorrer_Texto_QD(Tree arvoreAux,char id[],PosicNo n);


/*
 * Percorre a arvore de hidrantes
 * Nao retorna nada
 */
void* percorrer_Hidrante_QD(Tree arvoreAux,char id[],PosicNo n);


/*
 * Percorre a arvore de semaforos
 * Nao retorna nada
 */
void* percorrer_Semaforo_QD(Tree arvoreAux,char id[],PosicNo n);


/*
 * Percorre a arvore de radio-base
 * Nao retorna nada
 */
void* percorrer_RB_QD(Tree arvoreAux,char id[],PosicNo n);



/*
 * Percorre as arvores e encontra o elemento desejado
 * Nao retorna nada
 */
void* encontrarElementoArvores (char id[], Tree arvoreQuadra, Tree arvoreHidrante, Tree arvoreSemaforo, Tree arvoreRadioBase);


/*
 * Percorre a arvore de quadras a partir do comando dq do .qry
 * Nao retorna nada
 */
void* dq_percorrer_arvore(Tree arvoreQuadra, double x, double y, double r, FILE *txt, FILE* svg2, bool verificador, PosicNo aux, Lista listaPosicNo);


/*
 * Percorre a arvore de quadras a partir do comando cbq do .qry
 * Nao retorna nada
 */
void* percorrer_CBQ(Tree arvoreQuadra, double x, double y, double r, char corBorda[], FILE *txt, FILE* svg2, PosicNo aux);


/*
 * Percorre a arvore de quadras a partir do comando car do .qry
 * Nao retorna nada
 */
void* percorrer_CAR(FILE* aux, FILE* txt, Tree arvoreQuadra, PosicNo noh, double x, double y, double h, double w, Lista listaQuadra);


/*
 * Percorre a arvore de quadras a partir do comando soc do .qry
 * Nao retorna nada
 */
void* soc_posto_conversao(Tree arvorePosto,PosicNo aux,Lista listaPosto);



/*
 * Percorre a arvore de quadras a partir do comando ci do .qry
 * Nao retorna nada
 */
void* ci_casos_conversao(Tree arvoreCasos,PosicNo aux,Lista listaCasos);



/*
 * Percorre a arvore de quadras a partir do comando dd do .geo
 * Nao retorna nada
 */
void* percorrer_Quadra_dd(Tree arvoreQuadra, PosicNo aux, double x, double w, double y, double h);



/*
 * Percorre a arvore de quadras a partir do comando dd do .geo
 * Insere sombras nas quadras que estão dentro do retangulo dado
 * Nao retorna nada
 */
void* inputSombraQuadras(Tree arvoreQuadra, PosicNo aux, FILE* svg, double densidadeQuadra, double x, double y, double w, double h);


#endif