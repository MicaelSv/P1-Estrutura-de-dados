#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int obs(int i, int j, int i2, int j2, int cont, int max, int realcont){

    if(realcont > j){
        printf("%d %d %d\n", i2, j2, max);
        main();
    }

    else if(i == 1){
        realcont += 1;
        i = realcont;

        if(cont >= max){
            max = cont;
        }

        obs(i, j, i2, j2, cont = 1, max, realcont);
    }

    else if(i % 2 == 0){
        obs(i/2, j, i2, j2, cont+1, max, realcont);
    }

    else{
        obs((i * 3) + 1, j, i2, j2, cont+1, max, realcont);
    }
}




int main() {

    int i, i2, j, j2, rc, aux;

    if(scanf("%d %d", &i, &j) != EOF){

    i2 = i; //salva o valor de i
    j2 = j; //salva o valor de j
    rc = i;
    if(i > j){
        aux = i;
        i = j;
        j = aux;
        rc = i;
        obs(i, j, i2, j2, 1, 1, rc);
    }
    else{
    obs(i, j, i2, j2, 1, 1, rc);
    }
    }
    
    else{
        return 0;
    }

	return 0;
}