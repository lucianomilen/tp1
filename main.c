#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"
//LUCIANO OTONI MILEN [2012079754]

#define PESOMAX 9999999 //variável utilizada para definir o peso infinito das arestas criadas

int main() {
        int V, E, F, C;
        int i, j;
        scanf("%d %d %d %d", &V, &E, &F, &C);

        int VV = V + 2; //a matriz é criada com 2 vértices a mais, um para ligar a todos as fontes e outro pra todos os destinos

        int **grafoMatriz = alocaGrafoMatriz(VV); //retorna um ponteiro pra uma matriz alocada de tamanho VV

        i = 0;
        j = 0;

        while (i < E) { //lê e armazena os dados na matriz
                int a, b, p;
                scanf("%d %d %d", &a, &b, &p);
                grafoMatriz[a][b] = p;
                i++;
        }

        int pos_f[F], pos_c[C]; //contem as posições onde estão as franquias e os clientes

        for(i = 0; i < F; i++) {
                scanf("%d", &pos_f[i]);
        }

        for(j = 0; j < C; j++) {
                scanf("%d", &pos_c[j]);
        }

        for(i = 0; i < F; i++) { //define peso "infinito" pros vértices do tipo franquia
                grafoMatriz[VV-2][pos_f[i]] = PESOMAX;
        }

        for(j = 0; j < C; j++) { //define peso "infinito" pros vértices do tipo cliente
                grafoMatriz[pos_c[j]][VV-1] = PESOMAX;
        }

        calculaFluxo(grafoMatriz, VV, VV-2, VV-1);

        liberaGrafoMatriz(grafoMatriz, VV); //libera a memória alocada para a matriz

        return 0;
}
