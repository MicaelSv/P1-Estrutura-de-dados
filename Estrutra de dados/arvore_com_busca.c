#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct no{
    int num, tam;
    struct no *esq;
    struct no *dir;
}no;

no *insere(no *raiz, int valor){

    if(raiz == NULL){
        no* novo = (no*) malloc(sizeof(no));
        novo->num = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    else{
        if(valor < raiz->num){
            raiz->esq = insere(raiz->esq, valor);
        }
        if(valor > raiz->num){
            raiz->dir = insere(raiz->dir, valor);
        }
        return raiz;
    }
}

int buscar(no *raiz, int valor){

    if(raiz == NULL){
        printf("O numero %d nao esta contido na arvore\n", valor);
    }
    else{
        if(valor == raiz->num){
            printf("O numero %d esta contido na arvore\n", valor);
        }
        else if(valor < raiz->num){
            buscar(raiz->esq, valor);
        }
        else if(valor > raiz->num){
            buscar(raiz->dir, valor);
        }
    }
}

void imprimir(no *raiz){

    if(raiz != NULL){
        printf("%d \n", raiz->num);
        imprimir(raiz->esq);
        imprimir(raiz->dir);
    }
}

int main(){

    no *raiz = NULL;
    raiz = insere(raiz, 10);
    raiz = insere(raiz, 9);
    raiz = insere(raiz, 11);
    raiz = insere(raiz, 15);
    buscar(raiz, 14);
}