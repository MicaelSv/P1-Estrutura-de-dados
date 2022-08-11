#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{   

    char letra[50];
    fgets(letra, 50, stdin);
    
    int tam = strlen(letra);
    int i = 0;
    
    letra[i] = toupper(letra[i]);
    i++;
    
    
    for(i; i < tam - 1; i++){
        
       if(!isalpha(letra[i]) && letra[i] != ' '){
           printf("O nome nao pode ter numeros e nem caracteres especiais");
           exit(0);
       }
        
        if(letra[0] == ' '){
            printf("O nome nao pode comecar com espaço!");
            exit(0);
        }
        
        else if(letra[i - 1] == ' ' && i != 0){
            letra[i] = toupper(letra[i]);
        }
        
        else{
        letra[i] = tolower(letra[i]);
        }
        
    }
    
    printf("%s", letra);


    
    return 0;
}
