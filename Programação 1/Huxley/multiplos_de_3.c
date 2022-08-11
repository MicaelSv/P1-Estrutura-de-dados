#include <stdio.h>

int div(int n, int cont, int cont1){
	
	if(n == 0){
		printf("O numero nao possui divisores multiplos de 3!");
	}

    else if(cont > n){
        printf("%i", cont1);
    }
	
    else if(n % cont == 0 && cont % 3 == 0){
        div(n, cont+1, cont1+1);
    }

    else if(cont == n && cont1 == 0){
    	printf("O numero nao possui divisores multiplos de 3!");
	}
    
	else{
        div(n, cont+1, cont1);
    }
    
}

int main(){

    int n;
    scanf("%d", &n);
    div(n, 1, 0);

    return 0;
}
