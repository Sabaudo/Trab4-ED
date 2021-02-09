#ifndef _SVG_QRY_H_
#define _SVG_QRY_H_

#include "quadTree.h"
#include "arquivos.h"
#include "./elementos/quadra.h"
#include "svg.h"

#define TREE_LEFT_MARGIN 10
#define TREE_TOP_MARGIN 10
#define TREE_Y_SPACING 180
#define TREE_X_SPACING 20
#define TREE_NODE_RADIUS 10
#define TREE_TEXT_SIZE 8

void consulta_dmprbt(char t[32], char sfx[32], char *diretorioSaida, Tree arvoreQuadra, Tree arvoreHidrante, Tree arvoreSemaforo, Tree arvoreRadioBase);

void putSVGNode(FILE *file, double x, int y, char *descricao, char *posicao);

#endif