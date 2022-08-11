#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Equipe: Janio, José Augusto, Micael e Marcos
//Jogo da Velha com Busca Gulosa (greedy algorithm)

typedef struct Jogo{
    int ValorHeuristico;
    char UltimaJogada;
    char JogadaAtual;
}Jogo;

Jogo JogadasPlausiveis[45];
int PaiNaoAusente = -1;
int JogadasNaoFeitasAinda[9] = {1,2,3,4,5,6,7,8,9};
int posicaoatualdoarray = 0;
int SaiaRodada = 1;

char tabuleiro[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; //Tabuleiro com as posições 

void mostrar_tabuleiro_inicial() //Printar o Tabuleiro
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("| %c | ", tabuleiro[i][j]);
        }
        if(i!=2){
            printf("\n-----------------\n");
        }
    }
}

void mostrar_tabuleiro() //Printar o Tabuleiro
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(tabuleiro[i][j]=='O' || tabuleiro[i][j]=='X'){
                printf("| %c | ", tabuleiro[i][j]);
            }
            else{
                printf("|   | ", tabuleiro[i][j]);
            }
        }
        if(i!=2){
            printf("\n-----------------\n");
        }
    }
}

int resultadojogo(int sO, int sX)
{
    if (sO == 3)
    { 
        printf("\nO BOT GANHOU DE VOCE HAHA!.\nFIM DE JOGO!\n");
        return 1;
    }
    else if (sX == 3)
    {
        printf("\nVOCE CONSEGUIU GANHAR DO BOT!!!!.\nFIM DE JOGO!\n");
        return 1;
    }
    return 0;
}

int alguemganhou()
{

    int somaO = 0; int somaX = 0;

    // checar linhas
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabuleiro[i][j] == 'O' ) somaO++;
            else if (tabuleiro[i][j] == 'X') somaX++;
        }

        if (resultadojogo(somaO, somaX)) return 1;
        somaO = somaX = 0;
    }


    // checar colunas
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (tabuleiro[i][j] == 'O') somaO++;
            else if (tabuleiro[i][j] == 'X') somaX++;
        }
        
        if (resultadojogo(somaO, somaX)) return 1;
       somaO = somaX = 0;
    }

    // diagonal principal
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[i][i] == 'O') somaO++;
        else if (tabuleiro[i][i] == 'X') somaO--;
    }
    
    if(resultadojogo(somaO, somaX)) return 1;
    somaO = somaX = 0;

    // diagonal secundária
    for (int i = 3-1; i >=0; i--)
    {
        if (tabuleiro[i][(3-1)-i] == 'O') somaO++;
        else if (tabuleiro[i][(3-1)-i] == 'X') somaO--;
    }
    if(resultadojogo(somaO, somaX)) return 1;

    return 0;
    
}

int JogadaValida(int JogadorJogada) {
    int i,j;
    if(JogadorJogada == 1){
        i=0; j=0;
    }
    else if(JogadorJogada == 2){
        i=0; j=1;
    }
    else if(JogadorJogada == 3){
        i=0; j=2;
    }
    else if(JogadorJogada == 4){
        i=1; j=0;
    }
    else if(JogadorJogada == 5){
        i=1; j=1;
    }
    else if(JogadorJogada == 6){
        i=1; j=2;
    }
    else if(JogadorJogada == 7){
        i=2; j=0;
    }
    else if(JogadorJogada == 8){
        i=2; j=1;
    }
    else if(JogadorJogada == 9){
        i=2; j=2;
    }
    if(JogadorJogada < 1 || JogadorJogada > 9) {
        printf("jogada invalida\n");
        return 0;
    } else if(tabuleiro[i][j] == 'X' || tabuleiro[i][j] == 'O'){
        printf("jogada invalida\n");
        return 0;
    }
    return 1;
}

int GanhamoFamily(int JogadinhadeLado){
    int i, j, k, l, soma = 0;
    char auxtab[3][3];
    if(JogadinhadeLado == 1){
        i=0; j=0;
    }
    else if(JogadinhadeLado == 2){
        i=0; j=1;
    }
    else if(JogadinhadeLado == 3){
        i=0; j=2;
    }
    else if(JogadinhadeLado == 4){
        i=1; j=0;
    }
    else if(JogadinhadeLado == 5){
        i=1; j=1;
    }
    else if(JogadinhadeLado == 6){
        i=1; j=2;
    }
    else if(JogadinhadeLado == 7){
        i=2; j=0;
    }
    else if(JogadinhadeLado == 8){
        i=2; j=1;
    }
    else if(JogadinhadeLado == 9){
        i=2; j=2;
    }
    for(k = 0; k < 3; k++){ //preenchendo o tabuleiro auOiliar + jogada do adversario
        for(l = 0; l < 3; l++){
            if(k == i && l == j){
                auxtab[k][l] = 'O';
            }
            else{
                auxtab[k][l] = tabuleiro[k][l];
            }
        }
    }
    for(i = 0; i < 3; i++){ //verificando as linhas
        soma = 0;
        for(j = 0; j < 3; j++){
            if(auxtab[i][j] == 'O'){
            soma++;
            }

            if(soma == 3){
                return 1;
            }
        }
    }
    soma = 0;
    for(j = 0; j < 3; j++){ //verificando as colunas
        soma = 0;
        for(i = 0; i < 3; i++){
            if(auxtab[i][j] == 'O'){
            soma++;
            }
            if(soma == 3){
                return 1;
            }
        }
    }
    soma = 0;
    for(i = 0; i < 3; i++){ //verificando a diagonal principal
        if(auxtab[i][i] == 'O'){
            soma++;
        }
    }
    if(soma == 3){
        return 1;
    }
    else{
        if(auxtab[0][2] == 'O' && auxtab[1][1] == 'O' && auxtab[2][0] == 'O'){
            return 1;
        }
    }
    return 0;
}

int PerdemoFamily(int JogadinhadeLado){
    int i, j, k, l, soma = 0;
    char auxtab[3][3];
    if(JogadinhadeLado == 1){
        i=0; j=0;
    }
    else if(JogadinhadeLado == 2){
        i=0; j=1;
    }
    else if(JogadinhadeLado == 3){
        i=0; j=2;
    }
    else if(JogadinhadeLado == 4){
        i=1; j=0;
    }
    else if(JogadinhadeLado == 5){
        i=1; j=1;
    }
    else if(JogadinhadeLado == 6){
        i=1; j=2;
    }
    else if(JogadinhadeLado == 7){
        i=2; j=0;
    }
    else if(JogadinhadeLado == 8){
        i=2; j=1;
    }
    else if(JogadinhadeLado == 9){
        i=2; j=2;
    }
    for(k = 0; k < 3; k++){ //preenchendo o tabuleiro auxiliar + jogada do adversario
        for(l = 0; l < 3; l++){
            if(k == i && l == j){
                auxtab[k][l] = 'X';
            }
            else{
                auxtab[k][l] = tabuleiro[k][l];
            }
        }
    }
    for(i = 0; i < 3; i++){ //verificando as linhas
        soma = 0;
        for(j = 0; j < 3; j++){
            if(auxtab[i][j] == 'X'){
            soma++;
            }

            if(soma == 3){
                return 1;
            }
        }
    }
    soma = 0;
    for(j = 0; j < 3; j++){ //verificando as colunas
        soma = 0;
        for(i = 0; i < 3; i++){
            if(auxtab[i][j] == 'X'){
            soma++;
            }

            if(soma == 3){
                return 1;
            }
        }
    }
    soma = 0;
    for(i = 0; i < 3; i++){ //verificando a diagonal principal
        if(auxtab[i][i] == 'X'){
            soma++;
        }
    }
    if(soma == 3){
        return 1;
    }
    else{
        if(auxtab[2][0] == 'X' && auxtab[1][1] == 'X' && auxtab[0][2]  == 'X'){
            return 1;
        }
    }
}

int FazAlgumaCoisaPorFavor(int JogadinhaDeLado){
    int i, j, k, l, soma = 0;
    char auxtab[3][3];
    if(JogadinhaDeLado == 1){
        i=0; j=0;
    }
    else if(JogadinhaDeLado == 2){
        i=0; j=1;
    }
    else if(JogadinhaDeLado == 3){
        i=0; j=2;
    }
    else if(JogadinhaDeLado == 4){
        i=1; j=0;
    }
    else if(JogadinhaDeLado == 5){
        i=1; j=1;
    }
    else if(JogadinhaDeLado == 6){
        i=1; j=2;
    }
    else if(JogadinhaDeLado == 7){
        i=2; j=0;
    }
    else if(JogadinhaDeLado == 8){
        i=2; j=1;
    }
    else if(JogadinhaDeLado == 9){
        i=2; j=2;
    }

    for(k = 0; k < 3; k++){ //preenchendo o tabuleiro auxiliar + nossa JogadinhaDeLado
        for(l = 0; l < 3; l++){
            if(k == i && l == j){
                auxtab[k][l] = 'O';
            }
            else{
                auxtab[k][l] = tabuleiro[k][l];
            }
        }
    }
    if(JogadinhaDeLado == 1 || JogadinhaDeLado == 3 || JogadinhaDeLado == 7 || JogadinhaDeLado == 9){ //aq ele jogou na quina
        for(k = 0; k < 3; k++){ //verificando as linhas
            soma = 0;
            for(l = 0; l < 3; l++){
                if(auxtab[k][l] == 'O'){
                soma++;
                }
                else if(auxtab[k][l] == 'X'){
                soma--;
                }
            }
            if(soma == 2){
                return 4;
            }
        }
        soma = 0;

        for(l = 0; l < 3; l++){ //verificando as colunas
            soma = 0;
            for(k = 0; k < 3; k++){
                if(auxtab[k][l] == 'O'){
                    soma++;
                }

                else if(auxtab[k][l] == 'X'){
                    soma--;
                }
            }
            if(soma == 2){
                return 4;
            }
        }
        return 1;
    }

    else if(JogadinhaDeLado == 5){ //verificando a JogadinhaDeLado do centro

        for(k = 0; k < 3; k++){ //verificando as linhas
            soma = 0;
            for(l = 0; l < 3; l++){
                if(auxtab[k][l] == 'O'){
                    soma++;
                }
                    else if(auxtab[k][l] == 'X'){
                    soma--;
                }
                if(soma != 2){
                    soma = 0;
                    for(l = 0; l < 3; l++){ //verificando as colunas
                        soma = 0;
                        for(k = 0; k < 3; k++){
                            if(auxtab[k][l] == 'O'){
                                soma++;
                            }
                            else if(auxtab[k][l] == 'X'){
                                soma--;
                            }   
                        }
                    }
                    if(soma != 2 && SaiaRodada != 1){
                        return 2;
                    }
                }
            }
        }
    }

    else{
        soma = 0;
        for(k = 0; k < 3; k++){ //verificando as linhas
            soma = 0;
            for(l = 0; l < 3; l++){
                if(auxtab[k][l] == 'O'){
                    soma++;
                }
                    else if(auxtab[k][l] == 'X'){
                    soma--;
                }
            }
            if(soma == 2){
                return 2;
            }
        }
        soma = 0;
        for(l = 0; l < 3; l++){ //verificando as colunas
            soma = 0;
            for(k = 0; k < 3; k++){
                if(auxtab[k][l] == 'O'){
                    soma++;
                }

                else if(auxtab[k][l] == 'X'){
                    soma--;
                }
            }
            if(soma == 2){
                return 2;
            }
        }
        for(k = 0; k < 3; k++){ //jogando em qlqr lugar
            for(l = 0; l < 3; l++){
                if(auxtab[k][l] != 'X' && auxtab[k][l] != 'O'){
                    return 0;
                }
            }
        }
    }
}

void ComputarJogada(int JogadorJogada, int QuemTaJogando, int JogadorNumeroUm, int BotdaCondenacao){ //Computar a jogada no tabuleiro
    int i,j;
    if(JogadorJogada == 1){
        i=0; j=0;
    }
    else if(JogadorJogada == 2){
        i=0; j=1;
    }
    else if(JogadorJogada == 3){
        i=0; j=2;
    }
    else if(JogadorJogada == 4){
        i=1; j=0;
    }
    else if(JogadorJogada == 5){
        i=1; j=1;
    }
    else if(JogadorJogada == 6){
        i=1; j=2;
    }
    else if(JogadorJogada == 7){
        i=2; j=0;
    }
    else if(JogadorJogada == 8){
        i=2; j=1;
    }
    else if(JogadorJogada == 9){
        i=2; j=2;
    }
    
    if(QuemTaJogando==JogadorNumeroUm){
        tabuleiro[i][j] = 'X';
        JogadasPlausiveis[posicaoatualdoarray].JogadaAtual = JogadorJogada;
        JogadasPlausiveis[posicaoatualdoarray].UltimaJogada = PaiNaoAusente;
        PaiNaoAusente = JogadorJogada;
        for(int k=0;k<9;k++){
            if(JogadasNaoFeitasAinda[k] == JogadorJogada){
                JogadasNaoFeitasAinda[k] = -1;
            }
        }
    }
    else if(QuemTaJogando==BotdaCondenacao){
        tabuleiro[i][j] = 'O';
        for(int k=0;k<9;k++){
            if(JogadasNaoFeitasAinda[k] == JogadorJogada){
                JogadasNaoFeitasAinda[k] = -1;
            }
        }
    }
}

int PontuacaoJogada(){
    int i, j=0, Ganhamo=0, Perdemo, FazAlgumaCoisa, melhorjogada, melhorheuristico = -10;
    for(i=posicaoatualdoarray;j<9;i++){
        if(JogadasNaoFeitasAinda!=-1){
            JogadasPlausiveis[i].JogadaAtual = JogadasNaoFeitasAinda[j];
            JogadasPlausiveis[i].UltimaJogada = PaiNaoAusente;
            Ganhamo = GanhamoFamily(JogadasNaoFeitasAinda[j]);
            if(Ganhamo == 1){
                JogadasPlausiveis[i].ValorHeuristico = 100;
            }
            else{
                Perdemo = PerdemoFamily(JogadasNaoFeitasAinda[j]);
                if(Perdemo == 1){
                    JogadasPlausiveis[i].ValorHeuristico = 50;
                }
                else{
                    FazAlgumaCoisa = FazAlgumaCoisaPorFavor(JogadasNaoFeitasAinda[j]);
                    JogadasPlausiveis[i].ValorHeuristico = FazAlgumaCoisa;
                }
            }
            //printf("JA: %d VH: %d\n", JogadasPlausiveis[i].JogadaAtual, JogadasPlausiveis[i].ValorHeuristico);
            if(JogadasPlausiveis[i].ValorHeuristico > melhorheuristico && JogadasPlausiveis[i].JogadaAtual != -1){
                melhorheuristico = JogadasPlausiveis[i].ValorHeuristico;
                melhorjogada = JogadasPlausiveis[i].JogadaAtual;
            }
            posicaoatualdoarray+=1; j++;
        }
        else if (JogadasNaoFeitasAinda==-1){
            j++;
        }
    }
    return melhorjogada;
}

int LinkStart(int JogadorNumeroUm, int BotdaCondenacao){ //Iniciar o jogo
    int ParOuImpar = SaiaRodada%2;
    int JogadorJogada, MelhorJogada, PrazoDeValidade, Vitoria;
    printf("Rodada %d\n", SaiaRodada);
    if(ParOuImpar == JogadorNumeroUm){ //Vez do Jogador
        printf("Digite a sua Jogada: ");
        scanf("%d", &JogadorJogada);
        PrazoDeValidade = JogadaValida(JogadorJogada);
        if(PrazoDeValidade == 0){
            while(1){
                printf("Digite a sua Jogada: ");
                scanf("%d", &JogadorJogada);
                PrazoDeValidade = JogadaValida(JogadorJogada);
                if(PrazoDeValidade == 1){
                    break;
                }
            }
        }
        ComputarJogada(JogadorJogada,JogadorNumeroUm,JogadorNumeroUm,BotdaCondenacao);
        Vitoria = alguemganhou();
        if(Vitoria == 1){
            printf("JOGUEMOS OUTRA VEZ UMA OUTRA HORA! :)\n");
            mostrar_tabuleiro();
            printf("\n\n");
            return 0;
        }
    }
    else if(ParOuImpar == BotdaCondenacao){ //Vez do Bot
        printf("Bot analisando a melhor jogada...\n");
        MelhorJogada = PontuacaoJogada();
        ComputarJogada(MelhorJogada,BotdaCondenacao,JogadorNumeroUm,BotdaCondenacao);
        Vitoria = alguemganhou();
        if(Vitoria == 1){
            printf("JOGUEMOS OUTRA VEZ UMA OUTRA HORA! :)\n");
            mostrar_tabuleiro();
            printf("\n\n");
            return 0;
        }
    }
    mostrar_tabuleiro();
    printf("\n\n");
    if(SaiaRodada!=9){
        SaiaRodada+=1;
        LinkStart(JogadorNumeroUm,BotdaCondenacao);
    }
    else{
        printf("HOUVE UM EMPATE! JOGUEMOS OUTRA VEZ UMA OUTRA HORA! :)\n");
        return 0;
    }
}

int main()
{
    int comecar, BotdaCondenacao, JogadorNumeroUm, DeuVeia;
    printf("Nosso tabuleiro contabiliza as casas da seguinte forma:\n(TENHA ISSO EM MENTE QUANDO FOR FAZER SUA JOGADA!)\n");
    mostrar_tabuleiro_inicial();
    printf("\n\n");
    while(1){
        printf("Deseja ser o primeiro ou o segundo a jogar? (1 ou 2)\n");
        printf("Digite sua escolha: ");
        scanf("%d", &comecar);
        if(comecar == 1){
            JogadorNumeroUm = 1; //JOGADAS IMPARES
            BotdaCondenacao = 0; //JOGADAS PARES
            break;
        }
        else if(comecar == 2){
            JogadorNumeroUm = 0; //JOGADAS PARES
            BotdaCondenacao = 1; //JOGADAS IMPARES
            break;
        }
        else{
            printf("Voce digitou um numero errado, tente de novo!\n");
        }
    }
    DeuVeia = LinkStart(JogadorNumeroUm,BotdaCondenacao);
    printf("TABULEIRO FINAL:\n");
    mostrar_tabuleiro();
    /*
    for(int h=0; h<45; h++){
        printf("%d ", JogadasPlausiveis[h].JogadaAtual);
    }*/
    return 0;
}