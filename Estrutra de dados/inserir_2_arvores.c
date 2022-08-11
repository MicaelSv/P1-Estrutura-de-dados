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

/*int buscar(no *raiz, int valor){

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
}*/

void imprimir(no *raiz){

    if(raiz != NULL){
        printf("%d ", raiz->num);
        imprimir(raiz->esq);
        imprimir(raiz->dir);
    }
}

int main(){

    int op;
    no *raiz = NULL;
    no *raiz1 = NULL;
    
    printf("Adicone elementos para a 1a arvore\n");
    while(1){
        scanf("%d", &op);
        if(op != 0){
            raiz = insere(raiz, op);
        }
        else{
            break;
        }
    }

    printf("Adicone elementos para a 2a arvore\n");
    while(1){
        scanf("%d", &op);
        if(op != 0){
            raiz1 = insere(raiz1, op);
        }
        else{
            break;
        }
    }

    printf("valores da 1a arvore:\n");
    imprimir(raiz);
    printf("\n");
    printf("valores da 2a arvore:\n");
    imprimir(raiz1);
    printf("\n");
}