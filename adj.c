#include <stdio.h> 
#include <string.h>
#define PESOMAX 9999

  int main() {
    int qtdf, qtdc, l, c;
	scanf("%d %d %d %d", &l, &c, &qtdf, &qtdc);
int x = l+2;
int z = c+2;
	int	m[x][z];
    int i = 0;
    memset(m, 0, sizeof(m[0][0]) * x * z);
    while (i < l) {
      int a, b, p;
      scanf("%d %d %d", & a, & b, & p);
	  m[a][b] = p;
      i++;
    }
	//int posf[qtdf], posc[qtdc];
    int j;
	//for(i = 0; i < qtdf; i++)
		//scanf("%d", &posf[i]);
	//for(j = 0; j < qtdc; j++)
		//scanf("%d", &posc[j]);
	m[1][z] = 999;
	m[1][x] = 888;

    for (i = 0; i < x; i++) {
      for (j = 0; j < z; j++) {
        printf("%d ", m[i][j]);
      }
      printf("\n");
    }

	//for(i = 0; i < qtdf; i++)
		//printf("%d\n", posf[i]);
//	for(j = 0; j < qtdc; j++)
	//	printf("%d\n", posc[j]);

    return 0;
  }
