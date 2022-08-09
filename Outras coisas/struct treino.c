#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char nome[20];
    int ano;
    double nota;
}filme;


void ler(filme* filmes12){

    scanf("%s %d %lf", filmes12[0].nome, &filmes12[0].ano, &filmes12[0].nota);
}

int main(){

    //tipo da struct e dps coloca o nome da variável que a gnt quer usar
    filme filmes[3];

    ler(filmes);
    
    printf("nome: %s\nano: %d\nnota: %lf", filmes[0].nome, filmes[0].ano, filmes[0].nota);
    
    return 0;
}

/*typedef struct
{
    char nome[20];
    int ano;
    double nota;
}filme;


void ler(filme* filmes12){

    scanf("%s %d %lf", &filmes12->nome, &filmes12->ano, &filmes12->nota);
}

int main(){

    //tipo da struct e dps coloca o nome da variável que a gnt quer usar
    filme filmes;

    ler(&filmes);
    
    printf("nome: %s\nano: %d\nnota: %lf", filmes.nome, filmes.ano, filmes.nota);
    
    return 0;
}*/