#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int swap(float n[], int cont, int lim, int cont1){

    float aux;

    if(cont == lim){
        printf("%.2f\n%.2f\n%.2f\n%.2f\n", n[0], n[2], n[3], n[1]);
    }

    else if(cont1 == lim){
        cont = cont + 1;
        cont1 = cont + 1;
        swap(n, cont, lim, cont1);
    }
    else{


        if(n[cont] > n[cont1]){
            aux = n[cont];
            n[cont] = n[cont1];
            n[cont1] = aux;
            swap(n, cont, lim, cont1+1);
        }

        else{
        swap(n, cont, lim, cont1 + 1);
        }
}
}

int scn(int n, int cont, float array[]){

    if(cont == n){
        swap(array, 0, n, 1);
    }

    else{
        scanf("%f", &array[cont]);
        scn(n, cont+1, array);
    }
}


int main(){

    int n = 4;
    float num[n];

    scn(n, 0, num);

	return 0;
}