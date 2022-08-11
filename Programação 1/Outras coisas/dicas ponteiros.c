#include <stdio.h> 

//& pega o endereco de memoria
//se eu declaro um ponteiro p (*p), se eu fizer *p eh pra pegar o conteudo do ponteiro, ja se eu fizer p, eh o endereço de memoria
void perm(int *p, int *q) { 

    int x = 10;  
    *p = *q + x; 
    *q = *p + 1;

    printf("funcao perm = %d %d\n", *p, *q); //17, 18
}

void main(void){ 

    int a = 3, b = 7; 
    perm(&a,&b);
    /*porem se eu fizesse *p = &a, e quisesse passar o ponteiro p por parametro, nao precisaria do &, pois o p sem o * ja trabalha
    com enderenco de memoria, entao ficaria ->  perm(p, *b) */ 
    printf("funcao main = %d %d", a, b); 
}

/*
int main()
{
    int *p, *r, s = 2;
    
    r = &s; //aq eu colo o & pq o "S" não o ponteiro
    p = r; //como o "R" é um ponteiro, eu nao preciso colocar o &
    
    *p = 5;
    
    printf("%d", *p); //aq vai sair 5

    return 0;
}*/
