#include "graph.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PESOMAX 9999999

int min(int a, int b){
        if(b < a) return b;
        else return a;
}

int **alocaGrafoMatriz(int tamanho){
        int i, j;
        int **grafoMatriz = (int**)malloc(tamanho * sizeof(int*));
        for(i = 0; i < tamanho; i++) {
                grafoMatriz[i] = (int*) malloc(tamanho * sizeof(int));
        }
        for(i = 0; i < tamanho; i++)
                for(j = 0; j < tamanho; j++)
                        grafoMatriz[i][j] = 0;
        return grafoMatriz;
}

void liberaGrafoMatriz(int **grafoMatriz, int tamanho){
        int i;
        for(i = 0; i < tamanho; i++)
                free(grafoMatriz[i]);
        free(grafoMatriz);
}

int bfs(int **grafoAux, int VV, int origem, int destino, int vertices_superiores[]){
        int vertices_visitados[VV];
        int i;
        for (i = 0; i < VV; i++)
                vertices_visitados[i] = 0;

        TipoFila *fila = criaFila();

        insereFila(fila, origem);

        vertices_visitados[origem] = 1;
        vertices_superiores[origem] = 0;

        while (!filaVazia(fila))
        {
                int h = fila->frente->prox->item;
                removeFila(fila);

                for (i = 0; i < VV; i++)
                {
                        if (vertices_visitados[i] == 0 && grafoAux[h][i] > 0)
                        {
                                insereFila(fila, i);
                                vertices_superiores[i] = h;
                                vertices_visitados[i] = 1;
                        }
                }
        }

        free(fila->frente);
        free(fila);

        return (vertices_visitados[destino]);
}

void calculaFluxo(int **grafoMatriz, int VV, int s, int t)
{
        int i, v;

        int **grafoAux = alocaGrafoMatriz(VV);

        for (i = 0; i < VV; i++)
                for (v = 0; v < VV; v++)
                        grafoAux[i][v] = grafoMatriz[i][v];

        int vertices_superiores[VV];

        int fluxo_max = 0;

        i = 0;

        while (bfs(grafoAux, VV, s, t, vertices_superiores))
        {
                int fluxo_caminho = PESOMAX;
                for (v = t; v != s; v = vertices_superiores[v])
                {
                        i = vertices_superiores[v];
                        fluxo_caminho = min(fluxo_caminho, grafoAux[i][v]);
                }

                for (v = t; v != s; v = vertices_superiores[v])
                {
                        i = vertices_superiores[v];
                        grafoAux[i][v] -= fluxo_caminho;
                        grafoAux[v][i] += fluxo_caminho;
                }

                fluxo_max += fluxo_caminho;
        }
        liberaGrafoMatriz(grafoAux, VV);
        printf("%d", fluxo_max);
}
