#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
//Nome: Micael Silva Santos - Questão 2 - variação 1.


/* Essa questão é pra organizar uma fila de atendimento de um hospital com as determinadas prioridades dentro da fila.
utilizando o conceito de fila. */



void zerar(int p0[], int p1[], int p2[], int tam){

    for(int i = 0; i < tam; i++){
        p0[i] = 0, p1[i] = 0, p2[i] = 0;
    }

}

void concatena(int dia[], int p2[], int p1[], int p0[], char nome[]){
    
    int i = 0, l = 0;
    /*esses whiles vão seguir sempre o mesmo estilo, como a ordenção é decrescente
    vou colocando os valores da prioridade 2 até a prioridade 1*/
    
    printf("\nIdades da prioridade 2 na %s:\n", nome);
    while(p2[i] != 0){
        dia[l] = p2[i];
        printf("%d ", dia[l]);
        l++, i++; //a cada passo eu vou incrementando a minha variável L, que está controlando os elementos que chegam na fila
    }
    i = 0;//a cada while eu zero a variável i pra começar do início no próximo array de prioridade
    printf("\nIdades da prioridade 1 na %s:\n", nome);
    while(p1[i] != 0){
        dia[l] = p1[i];
        printf("%d ", dia[l]);
        l++, i++;
    }
    i = 0;
    printf("\nIdades da prioridade 0 na %s:\n", nome);
    while(p0[i] != 0){
        dia[l] = p0[i];
        printf("%d ", dia[l]);
        l++, i++;
    }
    printf("\n");
    printf("Concatenando...\n");
    for(int i = 0; i < l; i++){
        printf("%d ", dia[i]);
    }
    printf("\n\n");
}

void pfila(int fila[]){ //printar a fila

    for(int i = 0; i < 24; i++){
        printf("%d ", fila[i]);
    }
    printf("\n");
}   

void shift(int fila[], int tam){

    for(int i = 0; i < tam; i++){
        fila[i] = fila[i + 1];
    }
}

void remover(int fila[], int tam, int num){

    int aux[tam], i, tamsave = tam, j = 0;

    for(i = 0; i < tam; i++){//zerando todos os valores da minha fila auxiliar
        aux[i] = 0;
    }
    
    while(j < tam){
        
        /*se o elemento da minha fila for diferente da idade que eu quero excluir,eu coloco o elemento numa fila auxiliar, 
        ando a minha fila principal e repito o mesmo passo até achar o elemento que eu quero excluir*/
        if(fila[0] != num){ 
            aux[j] = fila[0];
            shift(fila, tamsave);
            j++;
        }
        
        /*se cair nesse else é pq é o elemento que eu quero tirar da fila, então eu não vou colocar ele na minha fila auxiliar,
        pq depois eu vou passar os valores da minha fila auxiliar pra minha fila principal*/
        else{
            shift(fila, tamsave);
        }
        tamsave--;
    }
    
    tamsave = tam - 1; //como eu tirei uma idade da minha fila, então o tamanho diminuiu

    for(i = 0; i < tam - 1; i++){ //aqui eu apenas coloco os valores na minha fila principal
        fila[i] = aux[0];
        shift(aux, tamsave);
        tamsave--;
    }
    
}

void prioridades(int dia[], int tam1, char nome[]){
    
    int j = 0, p0[24], p1[24], p2[24], tam = tam1, indice0 = 0, indice1 = 0, indice2 = 0, num;
    
    for(int i = 0; i < 24; i++){ //zerando meus arrays de prioridades
        p0[i] = 0, p1[i] = 0, p2[i] = 0;
    }
    
    while(j < 24){ //aqui ja começa a ordenar por prioridade, cada idade vai entrar em um array da sua prioridade

            if(dia[0] < 5 || dia[0] >= 80){ //prioridade 0, logo, vai entrar no p0
                p0[indice0] = dia[0];
                indice0+=1;
            }

            else if(dia[0] < 16 || dia[0] >= 60 && dia[0] < 80){ //prioridade 1, p1
                p1[indice1] = dia[0];
                indice1+=1;
            }
            
            else{ //prioridade 2, p2
                p2[indice2] = dia[0];
                indice2+=1;
            }
            
            shift(dia, tam1); //essa função faz a fila andar
            j++;
            tam1--;
    }
    
    //após eu organizar as idades em cada prioridade, vou concatenar tudo e colocar em um só array
    //por isso criei a função concatena
    concatena(dia, p2, p1, p0, nome);

    printf("Se alguém saiu da fila na %s, digite a idade da pessoa, se não, digite 0:\n", nome);
    scanf("%d", &num);

    if(num != 0){
    remover(dia, tam, num); //aqui eu removo um elemento da fila
    }

    /*como eu preenchei os arrays de cada prioridade(p0, p1, p2), após eu terminar o dia, eu tenho que zerar eles pra receber
    as idades dos próximos dias, por isso criei essa função que zera todos os elemntos do array*/
    zerar(p0, p1, p2, 24);
}

void prints(int dia[], char nomedia[]){

    printf("%s:\n", nomedia);
    for(int i = 0; i < 24; i++){ //daqui por diante, to printando como as idades ficaram dps da concatenação
        if(dia[i] != 0){ //verificando se a idade é 0, se for 0 é pq eu não tenho mais idade pra printar.
            printf("%d ", dia[i]);
        }   
        else{
            printf("\n");
            break;
        }         
    }
}

void oldprint(int dia[], char nomes[]){
    /*essa função printa a fila antiga, antes de ser ordenada, ou seja, vai printar após eu terminar
    de dar as entradas de cada dia*/
    int i = 0;
    printf("\n");
    while(dia[i] != 0){
        if(i == 0){printf("%s:\n", nomes);}
        printf("%d ", dia[i]);
        i++;
    }
    printf("\n\n");
}


int entradas(int dia[], int cont, char nome[]){

    printf("%s:\n", nome);
    for(int i = 0; i < 24; i++){
        scanf("%d", &dia[i]);
        if(dia[i] != 0){ //verificando se a idade é válida, se for, conta mais 1 no tamanho da fila
        cont++;
            pfila(dia); //função pra printar a fila
        }
                
        else{
            break;
        }
    }
    
    return cont; //aqui retorna o tamanho da fila no dia
}

int main(){
    
    int segunda[24], terca[24], quarta[24], quinta[24], sexta[24], num;
    int i = 0, tam_fila = 0, indice0 = 0, indice1 = 0, indice2 = 0, tamanho1, tamanho2, tamanho3, tamanho4, tamanho5;

    for(i = 0; i < 24; i++){
        segunda[i] = 0, terca[i] = 0, quarta[i] = 0, quinta[i] = 0, sexta[i] = 0;
    }

    printf("\tComece a inserir as idades dos pacientes\n");
    printf("Se deseja parar de inserir os pacientes em qualquer um dos dias, digite o numero 0\n\n");
    tamanho1 = entradas(segunda, 0, "Segunda"), tamanho2 = entradas(terca, 0, "Terca");
    tamanho3 = entradas(quarta, 0, "Quarta"), tamanho4 = entradas(quinta, 0, "Quinta");
    tamanho5 = entradas(sexta, 0, "Sexta");
            
    oldprint(segunda, "Segunda"), oldprint(terca, "Terca"), oldprint(quarta, "Quarta"), oldprint(quinta, "Quinta"), oldprint(sexta, "Sexta");
    //aqui eu to printando as entradas de todos os dias sem estarem ordenadas
    prioridades(segunda, tamanho1, "segunda-feira"); prioridades(terca, tamanho2, "terça-feira"); 
    prioridades(quarta, tamanho3, "quarta-feira"), prioridades(quinta, tamanho4, "quinta-feira"), prioridades(sexta, tamanho5, "sexta-feira");
    //aqui eu ja ordeno cada dia
    printf("\n\n");
    printf("Após todas as filas serem ordenadas por prioridades, ficaria desse jeito:\n");
    prints(segunda, "Segunda"), prints(terca, "Terça"); prints(quarta, "Quarta"), prints(quinta, "Quinta"), prints(sexta, "Sexta");

    for(i = 0; i < 24; i++){
        segunda[i] = 0, terca[i] = 0, quarta[i] = 0, quinta[i] = 0, sexta[i] = 0;
    }

}