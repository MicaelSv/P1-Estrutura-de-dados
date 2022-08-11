#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

    int vet[5], i, indice, aux, j = 1, tam = 0;
    
    for(i = 0; i < 5; i++){
        scanf("%d", &vet[i]);
    }
    i = 0;

    while(i < 5){
        if(vet[i] > vet[j]){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            
            if(i != 0){
            i--;
            j--;
            }
        }

        else{
            i++;
            j++;
        }
    }

    for(i = 0; i < 5; i++){
        printf("%d ", vet[i]);
    }

}