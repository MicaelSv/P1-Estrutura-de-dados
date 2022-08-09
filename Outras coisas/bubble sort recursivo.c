#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int prt(int array[], int cont, int tam){ 
    
    if(cont == tam){
        return 0;
    }

    else{
        printf("%d ", array[cont]);
        prt(array, cont+1, tam);
    }
}


int bubble(int tam, int array[], int cont, int torig){

    int aux;
    
    if(tam == 0){ 
        prt(array, 0, torig);
    }

    else{
         
        if(cont == tam - 1){
            bubble(tam-1, array, cont=0, torig);
        }

        else{
            
            if(array[cont] > array[cont+1]){
            aux = array[cont];
            array[cont] = array[cont+1];
            array[cont+1] = aux; 
            }

        bubble(tam, array, cont+1, torig);
    }
    }

}

int ler(int tam, int array[], int cont, int torig){

    if(cont == tam){
        bubble(tam, array, 0, torig);
    }

    else{
        scanf("%d", &array[cont]);
        ler(tam, array, cont+1, torig);
    }
}

int main(){

    int tam;

    scanf("%d", &tam);
    int array[tam];
    
    ler(tam, array, 0, tam);

}