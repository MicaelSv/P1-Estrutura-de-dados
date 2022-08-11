#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TAM 10

typedef struct{
    char verticesquesaem[TAM];
    int valor[TAM];
    char vertice;
}Graph;

Graph Grafo[TAM];
int tam=0, f=0, cont;
char Charray[TAM];
char Caminho[TAM];

char ProximoPasso(int n){
    cont++;
    if(cont == TAM){
        return;
    }
    int r=0, t=0, menorvalor = 999999;
    char proxpasso = '$';
    for(r=0;r<tam;r++){
        for(t=0;t<tam;t++){
            if(Charray[t] == Grafo[n].verticesquesaem[r] && Charray[t] != '@'){
                if(menorvalor > Grafo[n].valor[r]){
                    menorvalor = Grafo[n].valor[r];
                    proxpasso = Grafo[n].verticesquesaem[r];
                }
            }
        }
    }
    int j=0, p=0;
    for(j=0;j<tam;j++){
        if(proxpasso == Grafo[j].vertice){
            Caminho[f] = proxpasso;
            for(p=0;p<tam;p++){
                if(Charray[p] == proxpasso){
                    Charray[p] = '@';
                }
            }
            f++;
            break;
        }
    }
    ProximoPasso(j);
    return proxpasso;
}

void BuscaGulosa(){
    char character;
    int n=0, p=0;
    printf("Digite aonde devo comecar: ");
    scanf(" %c", &character);
    for(n=0;n<tam;n++){
        if(character == Grafo[n].vertice){
            Caminho[f] = Grafo[n].vertice;
            for(p=0;p<tam;p++){
                if(Charray[p] == character){
                    Charray[p] = '@';
                }
            }
            f++;
            break;
        }
    }
    ProximoPasso(n);
}

void printar(){
    printf("\n");
    int l=0, m=0;
    for(l=0;l<tam;l++){
        printf("Vertice %c tem saida para:\n", Grafo[l].vertice);
        for(m=0;m<TAM;m++){
            if(Grafo[l].verticesquesaem[m] == '@'){
            }
            else{
                printf("%c com valor %d\n", Grafo[l].verticesquesaem[m], Grafo[l].valor[m]);
            }
        }
        printf("\n");
    }
}

void zerarverticesquesaem(){
    int k=0;
    for(k=0;k<TAM;k++){
        Grafo[tam].verticesquesaem[k] = '@';
    }
}

void zerarvalores(){
    int k=0;
    for(k=0;k<TAM;k++){
        Grafo[tam].valor[k] = 0;
    }
}

void inserirvertice(){
    char caracter;
    int i=0, j=0;
    printf("Digite o vertice a ser inserido: ");
    scanf(" %c", &caracter);
    Grafo[tam].vertice = caracter;
    Charray[tam] = caracter;
    printf("%c\n", Charray[tam]);
    printf("Vertice %c adicionado!\n\n", Grafo[tam].vertice);
    zerarverticesquesaem();
    zerarvalores();
    while(i<TAM){
        char aresta;
        int valor;
        printf("Digite o vertice que da para chegar saindo do vertice ou se nao houver mais nenhuma digite 0: ");
        getchar();
        scanf("%c", &aresta);
        if(aresta == '0'){
            break;
        }
        Grafo[tam].verticesquesaem[i] = aresta;
        printf("Vertice %c chega ao vertice %c\n\n", Grafo[tam].vertice, Grafo[tam].verticesquesaem[i]); //caso seja ponderado;
        printf("Digite o valor que esta aresta possui: ");
        scanf("%d", &valor);
        Grafo[tam].valor[i] = valor;
        printf("Aresta %c tem valor igual a %d\n\n", Grafo[tam].verticesquesaem[j], Grafo[tam].valor[j]);
        for(j=0;j<=i;j++){
            printf("Vertice %c chega ao vertice %c com aresta de valor %d \n\n", Grafo[tam].vertice, Grafo[tam].verticesquesaem[j],  Grafo[tam].valor[j]);
        }
        i++;
    }
    tam++;
    return;
}

int main(){
    int opcao;
    while(1){
        printf("Digite a opcao que deseja executar: \n");
        printf("0 - Parar a execucao\n1 - Inserir\n2 - Imprimir\n3 - Realizar a busca de um caminho\n");
        scanf("%d", &opcao);
        if(opcao == 0){ break; }
        else if(opcao == 1){ 
            inserirvertice();
            printf("\n");
        }
        else if(opcao == 2){
            printar();
        }
        else if(opcao == 3){
            BuscaGulosa();
        }
    }
    for(int s=0;s<f;s++){
        printf("Posicao %d do caminho foi no vertice %c\n", s, Caminho[s]);
    }
    return 0;
}