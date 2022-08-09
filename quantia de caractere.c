#include <stdio.h>

int main(void){

    int tamanhoString(char string []);
    char stringUsuario [20];

    printf("Digite uma palavra(string):\n");
    scanf("%s", stringUsuario);

int num = tamanhoString(stringUsuario);

    printf("A palavra %s tem %i caracteres", stringUsuario, num);

    return 0;
}

int tamanhoString(char string []){

    int numcaracteres;

    while(string[numcaracteres] != '\0') {
        ++numcaracteres;
    }++numcaracteres;

    return numcaracteres;
}