#include "graph.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//LUCIANO OTONI MILEN [2012079754]

#define PESOMAX 9999999 //variável utilizada para definir o peso infinito das arestas criadas

int min(int a, int b){ //função para retornar o menor valor entre dois inteiros
        if(b < a) return b;
        else return a;
}

int **alocaGrafoMatriz(int tamanho){ //retorna o ponteiro para a matriz alocada
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

void liberaGrafoMatriz(int **grafoMatriz, int tamanho){ //libera a memória alocada para o grafo
        int i;
        for(i = 0; i < tamanho; i++)
                free(grafoMatriz[i]);
        free(grafoMatriz);
}

int bfs(int **grafoAux, int VV, int origem, int destino, int vertices_superiores[]){
        int vertices_visitados[VV];
        int i;
        for (i = 0; i < VV; i++) //zera o vetor de vertices visitados
                vertices_visitados[i] = 0;

        TipoFila *fila = criaFila(); //retorna ponteiro para fila vazia

        insereFila(fila, origem); //insere o vértice de origem passado por parâmetro na fila, ou seja, começa por ele

        vertices_visitados[origem] = 1; //acabou de ser visitado
        vertices_superiores[origem] = 0; //não há nenhum vértice acima da origem

        while (!filaVazia(fila)) //enquanto a fila do BFS não estiver vazia...
        {
                int h = fila->frente->prox->item; //o primeiro item da fila
                removeFila(fila);

                for (i = 0; i < VV; i++)
                {
                        if (vertices_visitados[i] == 0 && grafoAux[h][i] > 0) //se o vértice não tiver sido visitado E se aquela conexão existir:
                        {                                           //se o valor de [h][i] for 0, significa que não existe esta conexão
                                insereFila(fila, i); //insere o elemento na fila do bfs
                                vertices_superiores[i] = h; //o vértice superior do vértice atual é o que foi armazenado no início do processamento da fila
                                vertices_visitados[i] = 1; //o vértice foi visitado!
                        }
                }
        }

        free(fila->frente); //não precisamos mais desta fila
        free(fila);

        return (vertices_visitados[destino]); //retorna para a calcula fluxo se o vértice foi visitado ou não na posição do destino
}

void calculaFluxo(int **grafoMatriz, int VV, int s, int t)
{
        int i, v;

        int **grafoAux = alocaGrafoMatriz(VV); //cria um grafo auxiliar, que no Ford-Fulkerson corresponde ao grafo residual

        for (i = 0; i < VV; i++)
                for (v = 0; v < VV; v++)
                        grafoAux[i][v] = grafoMatriz[i][v]; //copia o grafo original para o auxiliar

        int vertices_superiores[VV]; //lista dos vértices superiores ao atual

        int fluxo_max = 0; //o fluxo sempre inicia como 0

        i = 0;

        while (bfs(grafoAux, VV, s, t, vertices_superiores)) //enquanto o retorno do BFS for 1, ou seja, o vértice destino foi visitado
        {
                int fluxo_caminho = PESOMAX; //o fluxo do caminho começa como o valor "infinito"
                for (v = t; v != s; v = vertices_superiores[v]) //encontra o fluxo máximo no caminho que estamos percorrendo atualmente
                {
                        i = vertices_superiores[v];
                        fluxo_caminho = min(fluxo_caminho, grafoAux[i][v]);
                }

                for (v = t; v != s; v = vertices_superiores[v]) //atribui o valor do fluxo definido pelo grafo auxiliar, invertendo as arestas do caminho percorrido
                {
                        i = vertices_superiores[v];
                        grafoAux[i][v] -= fluxo_caminho;
                        grafoAux[v][i] += fluxo_caminho;
                }

                fluxo_max += fluxo_caminho; //o fluxo máximo deve ser atualizado de acordo com o fluxo de cada caminho
        }

        liberaGrafoMatriz(grafoAux, VV); //não precisamos mais do grafo auxiliar

        printf("%d", fluxo_max); //retorna o fluxo máximo!
}
