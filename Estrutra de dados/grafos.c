#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2


typedef struct adjacencia{
    int vertice;
    int peso;
    struct adjacencia *prox;
}ADJACENCIA;

typedef struct vertice{
    int peso;
    ADJACENCIA *cab;
}VERTICE;

typedef struct grafo{
    int vertices;
    int arestas;
    VERTICE *adj;
}GRAFO;

ADJACENCIA *criaAdj(int v, int peso){

    ADJACENCIA *temp = (ADJACENCIA*) malloc(sizeof(ADJACENCIA));

    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return temp;
}   


int criaAresta(GRAFO *gr, int vi, int vf, int p){

    ADJACENCIA *novo = criaAdj(vf, p);
    novo->prox = gr->adj[vi].cab;
    gr->adj[vi].cab = novo;
    gr->arestas++;

    return 0;
} 

GRAFO *criaGrafo(int v){
    
    GRAFO *g = (GRAFO*) malloc(sizeof(GRAFO));

    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE*) malloc(v*sizeof(VERTICE));

    int i;

    for(i = 0; i < v; i++){
        g->adj[i].cab = NULL;
    }
    
    return g;
}

void imprime(GRAFO *gr){

    printf("Vertices: %d, Arestas: %d\n", gr->vertices, gr->arestas);

    int i;

    for(i = 0; i < gr->vertices; i++){
        printf("v%d: ", i);
        ADJACENCIA *ad = gr->adj[i].cab;
        while(ad){
            printf("v%d(%d) ", ad->vertice, ad->peso);
            ad = ad->prox;
        }
        printf("\n");
    }
}

void visitaP(GRAFO *g, int u, int *cor){

    //aqui ja verifica se achou o cara antes de pintar em amarelo, vou fazer ainda
    cor[u] = AMARELO;
    ADJACENCIA *v = g->adj[u].cab;

    while(v){
        if(cor[v->vertice] == BRANCO){
            visitaP(g, v->vertice, cor);
            v = v->prox;
        }
    }
    cor[u] = VERMELHO;
}

void profundidade(GRAFO *g){

    int cor[g->vertices];

    int u;

    for(u = 0; u < g->vertices; u++){
        cor[u] = BRANCO;
    }

    for(u = 0; u < g->vertices; u++){
        if(cor[u] == BRANCO){
            visitaP(g, u, cor);
        }
    }


}

int main(){

    GRAFO *gr = criaGrafo(5);

    criaAresta(gr, 0, 1, 2); //grafo, vertice inicial, vertice final, peso
    criaAresta(gr, 1, 2, 4);
    criaAresta(gr, 2, 0, 12);
    criaAresta(gr, 2, 4, 40);
    criaAresta(gr, 3, 1, 3);
    criaAresta(gr, 4, 3, 8);

    imprime(gr);

}