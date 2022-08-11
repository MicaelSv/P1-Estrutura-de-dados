#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Esse mergesort ta com problema

void merge(int *esq, int *dir, int tamesq, int tamdir, int *vet){

    int i, j, k;
    i = j = k = 0;

    while(i < tamesq && j < tamdir){ //i = indice da esquerda, j = indice da direita, k = indice do vetor principal
        if(esq[i] <= dir[i]){
            vet[k] = esq[i];
            i += 1;
        }
        else{
            vet[k] = dir[j];
            j += 1;
        }
        k++;
    }

    while(i < tamesq){
        vet[k] = esq[i];
        i += 1;
        k += 1;
    }
    while(j < tamdir){
        vet[k] = dir[j];
        j += 1;
        k += 1;
    }
}

void mergesort(int *vet, int tam){

    int metade, metade2, i, aux;

    if(tam < 2){
        return;
    }
    //printf("%d ", tam);
    metade = tam/2;
    metade2 = tam - metade;

    int esq[metade];
    int dir[metade2];

    for(i = 0; i < metade; i++){//ou metade
        esq[i] = vet[i];
    }

    for(i = metade; i < tam; i++){//ou tam
        aux = i - metade;
        dir[aux] = vet[i];
        printf("%d ", dir[aux]);
    }

    mergesort(esq, metade);
    mergesort(dir, metade2);
    merge(esq, dir, metade, metade2, vet);
}

int main(){
    int vet[8] = {2, 4, 1, 6, 8, 5, 3, 7}, i;

    mergesort(vet, 8);

    for(i = 0; i < 8; i++){
        //printf("%d ", vet[i]);
    }
}    