#include <stdio.h> 
#include <string.h>
#define PESOMAX 9999

  int main() {
    int m[5][5], qf;
	scanf("%d", &qf);
    int i = 0;
    memset(m, 0, sizeof(m[0][0]) * 5 * 5);
    while (i < 5) {
      int a, b, p;
      scanf("%d %d %d", & a, & b, & p);
	  if(a == 2 && b == 4) m[a][b] = PESOMAX;
	  else m[a][b] = p;
      i++;
    }
    int j;
    for (i = 0; i < 5; i++) {
      for (j = 0; j < 5; j++) {
        printf("%d ", m[i][j]);
      }
      printf("\n");
    }
    return 0;
  }
