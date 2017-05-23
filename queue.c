#include "queue.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//LUCIANO OTONI MILEN [2012079754]

TipoFila *criaFila(){ //ponteiro para fila
        TipoFila *fila = (TipoFila*)malloc(sizeof(TipoFila)); //aloca incialmente para o tamanho do TipoFila
        fila->frente = (TipoElemento*)malloc(sizeof(TipoElemento)); //aloca para o ponteiro da frente o tamanho de um elemento
        fila->tras = fila->frente; // = fila vazia
        fila->frente->prox = NULL; //não há ninguém atrás da frente na fila
        return fila;
}

int filaVazia(TipoFila *fila){ // = fila vazia
        return fila->tras == fila->frente;
}

void insereFila(TipoFila *fila, int item){ //insere um elemento atrás da fila, alocando memória para o novo item
        fila->tras->prox = (TipoElemento*)malloc(sizeof(TipoElemento));
        fila->tras = fila->tras->prox; //a fila ganha um novo elemento...
        fila->tras->item = item; //aqui
        fila->tras->prox = NULL; //ninguém atrás do último da fila
}

void removeFila(TipoFila *fila){
        apont temp = fila->frente; //salva um ponteiro para o primeiro da fila
        fila->frente = fila->frente->prox; //o primeiro da fila agora virou o próximo
        free(temp); //libera o ponteiro
}
