#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct no{
    int num;
    struct no *prev; //ponteiro que aponta pro anterior
    struct no *next; //ponteiro que aponta pro proximo
}no;

no *fim; //crio essa variável global pra pegar o último elemento da lista;

no *cria(){ //criando espaço na memória
    no *novoNo;
    novoNo = (no*) malloc(sizeof(no));
    return novoNo;
}

no *crialista(no *head, int dado){
    
    no *novoNo;
    no *aux;

    novoNo = cria(); //criando um espaço no ponteiro nó, que é um nó 

    novoNo->num = dado; //recebendo o dado
    novoNo->next = NULL; //colocando o ponteiro anterior e proximo como NULL
    novoNo->prev = NULL;

    if(head == NULL){
        head = novoNo;
        aux = head;
    }

    else{
        aux->next = novoNo; //ponteiro proximo do auxiliar vai apontar para o proximo elemento que surgir
        novoNo->prev = aux; //o novo dado que chegou vai ter seu ponteiro anterior apontando para o antigo nó
        aux = novoNo; //e o nosso ponteiro auxiliar vai pegar a posicao atual, que é o ponteiro que chegou
        fim = novoNo; //aqui é a msm coisa, só pra pegar o último elemento que chegar, pra dps printar de tras pra frente
    }

    return head; //NAO ESQUECER DO RETURN!!!!!!!!!!!!!!!!!!
}

int imprimir(no *head){

    no *aux;
    aux = head;


    while(aux != NULL){
        printf("%d ", aux->num);
        aux = aux->next;
    }
}

int imprimir_atras(no *fim){

    while(fim != NULL){
        printf("%d ", fim->num);
        fim = fim->prev;
    }
}

int main(){

   no *head = NULL;

   head = crialista(head, 3);
   head = crialista(head, 6);
   head = crialista(head, 9);
   
   
   imprimir(head);
   printf("\n");
   imprimir_atras(fim);
}