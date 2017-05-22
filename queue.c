#include "queue.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TipoFila *criaFila(){
        TipoFila *fila = (TipoFila*)malloc(sizeof(TipoFila));
        fila->frente = (TipoElemento*)malloc(sizeof(TipoElemento));
        fila->tras = fila->frente;
        fila->frente->prox = NULL;
        return fila;
}

int filaVazia(TipoFila *fila){
        return fila->tras == fila->frente;
}

void insereFila(TipoFila *fila, int item){
        fila->tras->prox = (TipoElemento*)malloc(sizeof(TipoElemento));
        fila->tras = fila->tras->prox;
        fila->tras->item = item;
        fila->tras->prox = NULL;
}

void removeFila(TipoFila *fila){
        apont temp = fila->frente;
        fila->frente = fila->frente->prox;
        free(temp);
}
