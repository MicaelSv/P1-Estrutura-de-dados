#include <stdio.h>

int main ()
{
    int numero, cifra;

    printf("Digite um número inteiro\n");
    scanf("%i", &numero);

    if (numero >= 0){
    do{
        cifra = numero % 10;
        printf("%i", cifra);
        numero /= 10;
    
    }   while (numero != 0);
    }     

        else if (numero < 0) {
            numero *= -1;
            printf ("-");
    
        do{
        cifra = numero % 10;
        printf("%i", cifra);
        numero /= 10;
        
        } while (numero != 0);
        }
        
    return 0;
}