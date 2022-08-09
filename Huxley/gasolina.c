#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

float a, form, form1, form2;
float a1 = 1.90, g1 = 2.50, d1 = 1.66;
char b = ('A', 'G', 'D');

scanf("%f\n%c", &a, &b);

if(b == 'A'){
    if(a <= 20){
    form = a1 * a;
    form1 = form * 0.03;
    form2 = form - form1;
    printf("R$ %.2f", form2);
    }
else if(a > 20){
    form = a1 * a;
    form1 = form * 0.05;
    form2 = form - form1;
    printf("R$ %.2f", form2);
}
}

if(b == 'G'){
    if(a <= 20){
    form = g1 * a;
    form1 = form * 0.04;
    form2 = form - form1;
    printf("R$ %.2f", form2);
    }
else if(a > 20){
    form = g1 * a;
    form1 = form * 0.06;
    form2 = form - form1;
    printf("R$ %.2f", form2);
}
}
    
if(b == 'D'){
    if(a <= 25){
    form = d1 * a;
    printf("R$ %.2f", form);
    }
else if(a > 25){
    form = d1 * a;
    form1 = form * 0.04;
    form2 = form - form1;
    printf("R$ %.2f", form2);

}
}
return 0;
}
