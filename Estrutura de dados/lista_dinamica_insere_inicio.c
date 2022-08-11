#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
//INSERE NO INÍCIO

typedef struct no{

    int num;
    struct no *prox;
}no;


no* cria_no(){
    no *no1;
    no1 = (no*) malloc(sizeof(no));
    return no1;
}

no* insere(no *lista, int dado){

    no *no1, *aux;
    no1 = cria_no();

    no1->num = dado;    

    if(lista == NULL){ //esse aqui seria o meu ultimo elemento, então a lista vai guardar o meu ultimo elemento
        no1->prox = NULL;
        lista = no1;
        aux = no1;
    }

    else{
        no1->prox = aux; //nesse caso, o aux sempre vai pegando o primeiro elemento
        aux = no1;
    }

    return aux; //no final de tudo eu retorno o primeiro elemento, igual na lista inserindo no final    
}

int imprimir(no *lista){
    
    no *aux = lista;

    while(aux != NULL){
        printf("%d ", aux->num);
        aux = aux->prox;
    }
}


int main(){

    no *lista;
    lista = insere(lista, 5);
    lista = insere(lista, 10);
    lista = insere(lista, 15);
    lista = insere(lista, 20);
    imprimir(lista);

}



//esse exemplo de baixo é quase idêntico, o que muda é que eu n uso o auxiliar, eu n salvo o último elemento
//pq n precisa salvar ele, só precisava salvar se fosse inserindo no final, q eu teria que percorrer até achar o NULL

/*
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
//INSERE NO INÍCIO

typedef struct no{

    int num;
    struct no *prox;
}no;


no* cria_no(){
    no *no1;
    no1 = (no*) malloc(sizeof(no));
    return no1;
}

no* insere(no *lista, int dado){

    no *no1, *aux;
    no1 = cria_no();

    no1->num = dado;    

    if(lista == NULL){ //esse aqui seria o meu ultimo elemento, então a lista vai guardar o meu ultimo elemento
        no1->prox = NULL;
        lista = no1;
    }

    else{
        no1->prox = lista; //nesse caso, o aux sempre vai pegando o primeiro elemento
        lista = no1;
    }

    return lista; //no final de tudo eu retorno o primeiro elemento, igual na lista inserindo no final    
}

int imprimir(no *lista){
    
    no *aux = lista;

    while(aux != NULL){
        printf("%d ", aux->num);
        aux = aux->prox;
    }
}


int main(){

    no *lista;
    lista = insere(lista, 5);
    lista = insere(lista, 10);
    lista = insere(lista, 15);
    lista = insere(lista, 20);
    imprimir(lista);

}*/