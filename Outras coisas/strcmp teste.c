#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//strcmp verifica se uma string é igual a outra
//ela vai olhar caractere por caractere

char string1[20];
char string2[20];

scanf("%s %s", string1, string2);

//se o tam da 1a string for maior que o da segunda, ele retorna -1
//se o tam da 2a string for maior que o da primeria, ele retorna 1

if(strcmp(string1, string2) == 0){ //ele retorna 0 pq diz que não tem nenhuma diferença, ou seja, as 2 strings sao iguais
    printf("nao tem diferenca");
}


if(strcmp(string1, "padaria") == 0){ //ele retorna 0 pq diz que não tem nenhuma diferença, ou seja, as 2 strings sao iguais
    printf("nao tem diferenca\n");
}

else{
    printf("nao eh padaria\n");
}


/*#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    
    char string1[20];
    char string2[20];
    
    scanf("%s %s", string1, string2);
    
    aqui ele compara se uma string for tal palavra, e outra string for tal palavra, vc faz tal coisa
    
   if(strcmp(string1, "guerreiro") == 0 && strcmp(string2, "arqueiro") == 0){    
       printf("nao tem diferenca");
    }

   else{
       printf("nao entrou");
   }
    return 0;
}
*/

return 0;

