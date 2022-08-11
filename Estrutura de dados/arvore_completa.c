#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct no{
    int num;
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

no *remover(no *raiz, int valor){
    if(raiz == NULL){
        printf("Valor nao encontrado\n");
        return NULL;
    }
    else{
        if(raiz->num == valor){
            if(raiz->esq == NULL && raiz->dir == NULL){//isso diz que o no que vai ser removido nao tem nenhum filho
                free(raiz);
                return NULL;
            }
            else{
                if(raiz->esq == NULL || raiz->dir == NULL){//no removido com apenas 1 filho
                    no *aux;
                    if(raiz->esq != NULL){
                        aux = raiz->esq;
                    }
                    else{
                        aux = raiz->dir;
                    }
                    free(raiz);
                    return aux;
                }

                else{//no removido com 2 filhos
                    no *aux = raiz->esq;
                    while(aux->dir != NULL){
                        aux = aux->dir;
                    }
                    raiz->num = aux->num;
                    aux->num = valor;
                    raiz->esq = remover(raiz->esq, valor);
                    return raiz;
                }
            }
        }

        else{
            if(valor < raiz->num){ 
                raiz->esq = remover(raiz->esq, valor);
            }
            if(valor > raiz->num){
                raiz->dir = remover(raiz->dir, valor); 
            }
            return raiz;
        }
    }
}

void imprimir(no *raiz){

    if(raiz != NULL){
        imprimir(raiz->esq);
        printf("%d ", raiz->num);
        imprimir(raiz->dir);
    }
}

int main(){

    int op, tamanho = 0;
    no *raiz = NULL;
    no *raiz1 = NULL;
    
    printf("Adicone elementos para a arvore\n");
    while(1){
        scanf("%d", &op);
        if(op != 0){
            raiz = insere(raiz, op);
            tamanho++;
        }
        else{
            break;
        }
    }

    printf("valores da arvore:\n");
    imprimir(raiz);
    printf("\n");

    printf("tamanho antes de remover %d", tamanho);
    printf("\nRemova um valor na arvore: ");
    scanf("%d", &op);

    raiz = remover(raiz, op);
    tamanho-=1;
    printf("\n");
    printf("valores da arvore:\n");
    
    imprimir(raiz);
    printf("\ntamanho %d", tamanho);
}