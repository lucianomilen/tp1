#ifndef GRAPH
#define GRAPH
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//LUCIANO OTONI MILEN [2012079754]

int bfs(int **grafoAux, int VV, int origem, int destino, int vertices_superiores[]);

void calculaFluxo(int **GrafoMatriz, int VV, int s, int t);

int min(int a, int b);

int **alocaGrafoMatriz(int tamanho);

void liberaGrafoMatriz(int **grafoMatriz, int tamanho);

#endif
