#include <stdio.h>
#include <string.h>
 
 
// FAÇA UM ALGORITMO QUE RECEBERÁ X NOMES DE CARROS E CONTE QUANTOS CARROS DO MESMO MODELO FORAM VENDIDOS
//receber r, onde r vai ser o numero de vendas, e dps vai ter r linhas com o nome do modelo que foi vendido
 
typedef struct
{
    char modelo[50];
    int vendidos;
}CARROS;
 
void f(CARROS carro[], int x)
{
    for(int i = 0; i < x; i++){
        scanf(" %s", carro[i].modelo);
        carro[i].vendidos = 0;
    }
 
    int r;
 
    scanf("%d", &r);
 
    for(int i = 0; i < r; i++){
        char m[50];
        scanf(" %s", m);
 
        for(int j = 0; j < x; j++){
            if(strcmp(carro[j].modelo, m) == 0){
                carro[j].vendidos++;
            }
        }
    }
 
 
}
 
int main(){
 
    int x;
 
    scanf("%d", &x);
 
    CARROS carro[x];
 
    f(carro, x);
 
    for(int i = 0; i < x; i++){
        printf("%s foram vendidos %d\n", carro[i].modelo, carro[i].vendidos);
    }
 
    return 0;
}