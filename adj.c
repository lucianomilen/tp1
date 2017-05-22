#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

#define PESOMAX 9999999

int main() {
        int V, E, F, C;
        int i, j;
        scanf("%d %d %d %d", &V, &E, &F, &C);

        int VV = V + 2;

        int **grafoMatriz = alocaGrafoMatriz(VV);

        i = 0;
        j = 0;

        while (i < E) {
                int a, b, p;
                scanf("%d %d %d", &a, &b, &p);
                grafoMatriz[a][b] = p;
                i++;
        }

        int pos_f[F], pos_c[C];

        for(i = 0; i < F; i++) {
                scanf("%d", &pos_f[i]);
        }

        for(j = 0; j < C; j++) {
                scanf("%d", &pos_c[j]);
        }

        for(i = 0; i < F; i++) {
                grafoMatriz[VV-2][pos_f[i]] = PESOMAX;
        }

        for(j = 0; j < C; j++) {
                grafoMatriz[pos_c[j]][VV-1] = PESOMAX;
        }

        calculaFluxo(grafoMatriz, VV, VV-2, VV-1);
        liberaGrafoMatriz(grafoMatriz, VV);
        return 0;
}
