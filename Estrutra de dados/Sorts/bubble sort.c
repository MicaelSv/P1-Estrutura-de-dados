#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    
    int i = 0, j = 1, aux;
    int vet[6];
    int tam = 6;

    for(int k = 0; k < 6; k++){
        scanf("%d", &vet[k]);
    }

    while(tam > 0){

        if(j > tam){ //aq verifica se o j chegou no final
            i = 0, j = 1;
            tam -= 1; //aq eu diminuo para eu n olhar sempre mesmo ultimo valor
            //por ex: 2 3 4, de primeira o ultimo valor vai ser 4, dps q eu diminuo, o ultimo valor vai ser 3 e assim vai
        }
        if(vet[i] > vet[j]){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
        j+=1;
        i+=1;
    }

    for(int k = 0; k < 6; k++){
        printf("%d ", vet[k]);
    }


    
}