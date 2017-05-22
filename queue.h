#ifndef QUEUE
#define QUEUE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem *apont;

typedef struct elem {
        int item;
        apont prox;
} TipoElemento;

typedef struct {
        apont frente;
        apont tras;
} TipoFila;

void removeFila(TipoFila *F);

void insereFila(TipoFila *F, int item);

TipoFila *criaFila();

int filaVazia(TipoFila *fila);

#endif
