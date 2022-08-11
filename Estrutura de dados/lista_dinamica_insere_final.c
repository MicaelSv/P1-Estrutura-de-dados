#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
//INSERE NO FINAL
typedef struct no{ //se eu n colocar o nome dps que eu digitar struct, o programa vai rodar, mas vai dar warning
    int num;       //se eu colocar o nome no2 dps do nome struct, a struct no *prox teria que ser => struct no2 *prox
    struct no *prox;
}no;

no* cria_no(){
    no *no1;
    no1 = (no*) malloc(sizeof(no));

    return no1;
}

no* insere(no *lista, int dado){

    no *no1;
    no1 = cria_no(); //aq ele recebe o endereço de memória do no1 da func cria_no

    no1->num = dado;

    //essa lista é so pra verificar se o meu primeiro elemento foi adicionado
    if(lista == NULL){ //essa lista é so pra pegar o primeiro elemento
        no1->prox = NULL;
        lista = no1; //pegando o endereço de memoria do 1o elemento da lista
    }

    else{
        no *aux = lista; //aux = lista;

        while(aux->prox != NULL){
            aux = aux->prox;
        }

        no1->prox = NULL;
        aux->prox = no1;

    }

    return lista; //aq eu to retornando a lista pra pegar o primeiro elemento.
}

int imprimir(no *lista){

    no *aux;
    aux = lista;

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
    imprimir(lista);

}