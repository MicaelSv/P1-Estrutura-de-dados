#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int dividir(int *vet, int inicio, int fim){

    int i, pivo, indice, aux;
    pivo = vet[fim]; 
    indice = inicio;
    
    for(i = inicio; i < fim; i++){
        if(vet[i] <= pivo){ 
            aux = vet[i];
            vet[i] = vet[indice];
            vet[indice] = aux;
            indice++;
        }
    }
    aux = vet[fim];
    vet[fim] = vet[indice];
    vet[indice] = aux; 

    return indice;
}

void quick(int *vet, int inicio, int fim){

    if(inicio < fim){
        int indice = dividir(vet, inicio, fim);
        quick(vet, inicio, indice - 1);
        quick(vet, indice + 1, fim);
    }
}

int main(){

    int vet[8] = {7, 2, 1, 6, 8, 5, 3, 4}, i;
    
    quick(vet, 0, 7);

    for(i = 0; i < 8; i++){
        printf("%d ", vet[i]);
    }
}