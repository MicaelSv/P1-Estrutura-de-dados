#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    /*Bin sort
    ele so pode ser usado se os numeros forem menores do que a qntd do vetor, ex:
    se eu tiver um vetor de tam 6, so posso ter numeros de 0 a 5.
    2 4 0 5 3 1, eu começo com o i = 0, e verifico se o meu vet[i] é diferente de vet[vet[i]], ex:
    i = 0, vet[i] = 2, verifico se 2 é diferente de vet[vet[i]] = 0, como é diferente, então eu troco.
    qnd for igual, eu somo a variável i, e vou fazendo isso até o meu i chegar na ultima posicao.*/ 
    
    int i = 0, j, aux;
    int vet[6];
    int tam = 6;
    for(int k = 0; k < 6; k++){
        scanf("%d", &vet[k]);
    }

    while(i < 6){
        
        j = vet[i];
        if(vet[i] != vet[vet[i]]){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
        else{
            i++;
        }
    }

    for(int k = 0; k < 6; k++){
        printf("%d ", vet[k]);
    }


    
}