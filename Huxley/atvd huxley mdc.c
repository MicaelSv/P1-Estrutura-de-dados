#include <stdio.h>

int mdc(int a, int b){
    
    int resto = a % b;

    if(resto == 0){
        return b;
    }
    else{
        return mdc(b, resto);
    }

}

int entrada(int casos, int count){

    int a, b;

    if(count == casos){
        return 0;
    }
    else{
        scanf("%i%i", &a, &b);
        mdc(a, b);
        printf("MDC(%i,%i) = %i\n", a, b, mdc(a, b));
        return entrada(casos, count+1);
    }

}

int main(){

    int casos;
    
    scanf("%i", &casos);
    entrada(casos, 0);
    return 0;
}
