#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char num[50];

    scanf(" %s", num);

    int tam;
    tam = strlen(num);

    int i = 0, j = 0;
    

    for(j; j < tam; j++){
        
        if(num[j] == '!' || num[j] == '*' || num[j] == '.' || num[j] == '@'
        || num[j] == '#' || num[j] == '$' || num[j] == '%' || num[j] == '"'
        || num[j] == '(' || num[j] == ')' || num[j] == '_' || num[j] == '['
        || num[j] == ']' || num[j] == '^' || num[j] == '~' || num[j] == '{' || num[j] == '}'
        || num[j] == '<' || num[j] == '>' || num[j] == ':' || num[j] == '?' || num[j] == ';' || num[j] == '/' && num[j+1] == '0'){
            
            printf("Erro");
            exit(0);
        }
    }

    while(i < tam){

        if(num[i] == ','){
            i++;
            while(i < tam){
                if(num[i] != '0'){
                    printf("Numero real");
                    exit(0);
                }
                i++;
            }
        }
        i++;
    }

    if(num[0] == '-'){
        printf("Numero inteiro");
    }

    else{
        printf("Numero natural");
    }


}
