#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*Selection Sort
eu vou pegar o meu i que comeca em 0, e ver se ele é maior do que o j que comeca em 1, se for, eu vou ter que ver
se tem outro numero menor do que o j, ai eu coloco um while pra percorrer, se tiver, eu pego o indice;
apos isso, eu faço a troca dos vetores, e somo a minha variavel i a cada passo.*/ 

int main(){
    int vet[5], i, j = 1, k, aux;

    for(i = 0; i < 5; i++){
        scanf("%d", &vet[i]);
    }
    i = 0;

    while(i < 5){
        if(vet[i] >= vet[j]){
            aux = j;
            while(aux < 5){
                if(vet[aux] <= vet[j]){
                    j = aux;
                }
                aux++;
            }
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;

        i+=1;
        j = i + 1;
        }

        else if(j == 5){
            i++;
            j = i + 1;
        }
        else{
        j++;
        }
    }

    for(i = 0; i < 5; i++){
        printf("%d ", vet[i]);
    }
}