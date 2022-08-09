#include <stdio.h>

int t(int v[], int i, int in){
  
    if(i == 10){
        printf("%i", in);
    }
    else{
        scanf("%i", &v[i]);
        
        if(v[i] > v[in]){
        i++;
        in = i;
        t(v, i, in);
        }
        
        else{
        t(v, i+1, in);
        }
    }
}

int main(){

    int vet[10], x;
    
    t(vet, 0, 0);

    return 0;
}