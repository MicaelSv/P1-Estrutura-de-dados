#include <stdio.h>

struct horario{
    int horas, minutos, segundos;
};

int main(){

    struct horario agora;
   
    agora.horas = 19;
    agora.minutos = 50;
    agora.segundos = 30;

    printf("%i:%i:%i\n", agora.horas, agora.minutos, agora.segundos);

    struct horario teste(struct horario x);
    teste(agora);
    
    return 0;
}
struct horario teste(struct horario x){

    x.horas = 100, x.minutos = 100, x.segundos = 100;
    
    printf("%i:%i:%i\n", x.horas, x.minutos, x.segundos);

    return x;
}