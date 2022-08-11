#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
    int indPai;
    char Label;
}No;

No arvore[10];

int insereNo(int tam){
    char element, pai2;
    if(tam==9){
        printf("Arvore cheia! Nao e possivel adicionar nenhum novo elemento!\n");
    }
    else{
        if(tam==-1){
            printf("Forneca o valor do elemento a ser inserido: ");
            scanf(" %c", &element); 
            tam = tam+1;
            arvore[tam].indPai = -1; //senpai = -1;
            arvore[tam].Label = element; //atribuindo elemento;
            printf("Elemento %c inserido!\n", arvore[tam].Label);
            return tam;
        }
        else{
            printf("Forneca o valor do elemento a ser inserido: ");
            scanf(" %c", &element);
            printf("Forneca o valor do pai a ser inserido: ");
            scanf(" %c", &pai2);
            for(int i=0;i<=tam;i++){ 
                if(arvore[i].Label == pai2){
                    tam = tam+1;
                    arvore[tam].indPai = i; //senpai = -1;
                    arvore[tam].Label = element; //atribuindo elemento;
                    printf("Elemento %c inserido!\n", arvore[tam].Label);
                    return tam; 
                }
            }
            printf("Elemento senpai definido, logo nao pode ser inserido!\n");
            return tam;
        }
    }
    return tam;
}

int removeNo(int tam){
    char element;
    int i, j;
    if(tam==-1){
        printf("Arvore vazia! Nao e possivel remover nenhum elemento!\n");
    }
    else{
        printf("Forneca o valor a ser removido: ");
        scanf(" %c", &element);
        printf("%c", element);
        for(i=0;i==tam;i++){
            if(arvore[i].Label == element){
                for(j=0;j==tam;j++){
                    if(i==arvore[j].indPai){ //0 = -1, 1 = 0, 2 = 1 //esse for é apenas pra verificar os filhos do no
                        arvore[j].indPai = arvore[i].indPai;
                    }
                }
                for(j=i;j==tam;j++){ //antes tava j = tam, o que n fazia sentido
                    arvore[j].indPai = arvore[j+1].indPai;
                    arvore[j].Label = arvore[j+1].Label;
                }
                tam = tam-1;
                return tam;
            }
        }
        printf("Elemento nao removido, pois nao foi encontrado!\n");
    }
}

int ElePertence(int tam){
    char element;
    int i;
    if(tam==-1){
        printf("Arvore vazia! Nao e possivel procurar o elemento!\n");
    }
    else{
        printf("Forneca o valor a ser procurado: ");
        scanf(" %c", &element);
        for(i=0;i<=tam;i++){
            if(arvore[i].Label == element){
                printf("elemento %c pertence a arvore!\n", element);
                return tam;
            }
        }
        printf("Elemento nao pertence, pois nao foi encontrado!\n");
    }
}

int imprimir(int tam, int ind){
    int i, j, flag;
    if(tam==-1){
        printf("()");
    }
    else{
        flag = 0;
        for(i=0;i<=tam;i++){
            if(arvore[i].indPai == ind){
                flag+=1;
                printf("( %c )", arvore[i].Label);
                for(j=0;j<=tam;j++){
                    if(arvore[j].indPai == i){
                        imprimir(tam,j);
                    }
                } 
            }
        }
        if(flag >= 0){
            printf("( %c )", arvore[ind].Label);
        }
        return tam;
    }
}

int main(){
    int tam = -1; //arvore sem elementos;
    int option;
    while(1){
        printf("1 -> inserir\n2 -> remover\n3 -> pertence\n4 -> imprimir\n");
        printf("Digite a opcao: ");
        scanf("%d", &option);
        getchar();
        if(option==1){
            tam = insereNo(tam);
        }
        else if(option==2){
            tam = removeNo(tam);
        }
        else if(option==3){
            tam = ElePertence(tam);
        }
        else if(option==4){
            tam = imprimir(tam,-1);
        }
    }
}