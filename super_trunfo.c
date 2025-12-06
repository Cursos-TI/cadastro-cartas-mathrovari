#include <stdio.h>

// Declaração de funções ---------------------------------------

//Realiza divisões
float divisao(float n1, float n2){
    float calculo =  (float) n1/n2;
    return calculo;
}

// Comparação de cartas
// Maior carta ganha
int maiorganha(double carta1, double carta2){
    if(carta1 > carta2){
        return 1;
    }
    return 0;
}
//Menor carta ganha
int menorganha(double carta1, double carta2){
    if(carta1 < carta2){
        return 1;
    }
    return 0;
}
//Atribuição de Carta
char *carta(int carta1){
    if(carta1 == 1){
        return "Carta 1";
    }
    return "Carta 2";
}


// Inicio do programa --------------------------------------------

int main()
{
    printf("\n\n"); //Pulo estético

    // Declaração de váriaveis para o cadastro de cartas do jogo super trunfo de paises
    char estado1='A',cidade1[]="exemplo",codCarta1[]="Z00";
    char estado2='A',cidade2[]="exemplo",codCarta2[]="Z00";

    unsigned long int populacao1=123456,populacao2=123456;
    int pontos_turisticos1=2,pontos_turisticos2=2;

    float KMquadrado1=1.5,pib1=123.34, pibpercapita1=0, densidadep1=0;
    float KMquadrado2=1.5,pib2=123.34, pibpercapita2=0, densidadep2=0;
    float super1=0, super2=0;


    // Introdução ao Jogo
    printf("Olá jogador! Estamos criando um jogo chamado Super Trunfo de Paises");
    printf("e preciso da sua ajuda para cadastrar duas cartas desse jogo.");
    printf("\nApós o cadastro das cartas vou compara-las e te mostrar o vencedor\n");

    // Entrada de dados primeira carta
    printf("\nIniciaremos cadastrando a carta nº1");
    printf("\nQual nome da cidade que deseja cadastrar: ");
    scanf("%s",cidade1);
    printf("\n\n %s ? Boa escolha!\n",cidade1);
    printf("Agora escolha uma letra de A a H que representará o estado dessa cidade: \n");
    scanf(" %c",&estado1);
    printf("\nAgora escolha um código para a carta, precisam ser 2 numeros, por exemplo '00':\n");
    scanf("%s",&codCarta1);
    printf("\nQuantos habitantes existem nessa cidade?\n");
    scanf("%lu",&populacao1);
    printf("\nQual seria o tamanho dessa cidade em kilometros quadrados?\n");
    scanf("%f",&KMquadrado1);
    printf("\nQual o PIB dessa cidade?\n");
    scanf("%f",&pib1);
    printf("\nAgora ultima pergunta. Quantos pontos turisticos tem essa ciadade?\n");
    scanf("%d",&pontos_turisticos1);
    
    // Entrada de dados segunda carta
    printf("\n\nFinalizamos a carta nº1, agora vamos cadastrar a carta nº2");
    printf("\nQual nome da cidade que deseja cadastrar:\n");
    scanf("%s",cidade2);
    printf("\n\n %s ? Novamente uma boa escolha!\n",cidade2);
    printf("Agora escolha uma letra de A a H que representará o estado dessa cidade: \n");
    scanf(" %c",&estado2);
    printf("\nAgora escolha um código para a carta, precisam ser 2 numeros, por exemplo '00':\n");
    scanf("%s",&codCarta2);
    printf("\nQuantos habitantes existem nessa cidade?\n");
    scanf("%lu",&populacao2);
    printf("\nQual seria o tamanho dessa cidade em km²?\n");
    scanf("%f",&KMquadrado2);
    printf("\nQual o PIB dessa cidade?\n");
    scanf("%f",&pib2);
    printf("\nAgora ultima pergunta. Quantos pontos turisticos tem essa cidade?\n");
    scanf("%d",&pontos_turisticos2);

    //Calculos
    float pibbilhao1 = pib1*1000000000; // Tranformando o PIB normal em bilhão
    float pibbilhao2 = pib2*1000000000; // Tranformando o PIB normal em bilhão

    densidadep1 = divisao(populacao1,KMquadrado1);
    densidadep2 = divisao(populacao2,KMquadrado2);
    pibpercapita1 = pibbilhao1/ (float) populacao1;
    pibpercapita2 = pibbilhao2/ (float) populacao2;

    float inversodensidade1 = 1/densidadep1; // Calculo de densidade inversa para Super Poder
    float inversodensidade2 = 1/densidadep2; // Calculo de densidade inversa para Super Poder
    super1 = (float)populacao1+(float)pontos_turisticos1+KMquadrado1+pib1+pibpercapita1+inversodensidade1;
    super2 = (float)populacao2+(float)pontos_turisticos2+KMquadrado2+pib2+pibpercapita2+inversodensidade2; 

    //Comparação das Cartas
    int WinPontuacaoPopulacao = maiorganha(populacao1,populacao2);
    int WinPontuacaoKMquadrado = maiorganha(KMquadrado1,KMquadrado2);
    int WinPontuacaoPIB = maiorganha(pibbilhao1,pibbilhao2);
    int WinPontuacaoPontosT = maiorganha(pontos_turisticos1,pontos_turisticos2);
    int WinPontuacaoDensidade = menorganha(densidadep1,densidadep2);
    int WinPontuacaoPIBPerc = maiorganha(pibpercapita1,pibpercapita2);
    int WinPontuacaoSuper = maiorganha(super1,super2);

    //Definicição de vencedores
    char *WinCartaPopulacao = carta(WinPontuacaoPopulacao);
    char *WinCartaKMquadrado = carta(WinPontuacaoKMquadrado);
    char *WinCartaPIB = carta(WinPontuacaoPIB);
    char *WinCartaPontosT = carta(WinPontuacaoPontosT);
    char *WinCartaDensidade = carta(WinPontuacaoDensidade);
    char *WinCartaPIBPerc = carta(WinPontuacaoPIBPerc);
    char *WinCartaSuper = carta(WinPontuacaoSuper);

    // Mostrar Vencedores 
    printf("\n\nChegou o grande momento de saber quem venceu, veja a comparação a baixo");
    printf("\nComparação das Cartas:\n");
    printf("\nPoplação: %s Venceu (%d)",WinCartaPopulacao,WinPontuacaoPopulacao);
    printf("\nÁrea: %s Venceu (%d)",WinCartaKMquadrado,WinPontuacaoKMquadrado);
    printf("\nPIB: %s Venceu (%d)",WinCartaPIB,WinPontuacaoPIB);
    printf("\nPontos Turisticos: %s Venceu (%d)",WinCartaPontosT,WinPontuacaoPontosT);
    printf("\nDensidade Populacional: %s Venceu (%d)",WinCartaDensidade,WinPontuacaoDensidade);
    printf("\nPIB per Capita: %s Venceu (%d)",WinCartaPIBPerc,WinPontuacaoPIBPerc);
    printf("\nSuper Poder: %s Venceu (%d)",WinCartaSuper,WinPontuacaoSuper);

    printf("\n\n");

    // ---------------------------------------------------------------------------
    // ------------Comentário atividade Novato e Aventureiro-------------------
    // Estou comentando a demostração de dados das cartas dado não saber se era para ficar
    // ativo. Ela esta funcional e foi ajustado para a ativdade Mestre, caso precise

    /*

    printf("\n\nAgora que sabe o vencedor, vou deixar a baixo os dados das cartas que cadastrou");

    printf("\n\nCarta 1:\n");
    printf("Estado: %c\n",estado1);
    printf("Código da carta: %c%s\n",estado1,codCarta1);
    printf("Nome da Cidade: %s\n",cidade1);
    printf("População: %lu\n",populacao1);
    printf("Área: %.2f km²\n",KMquadrado1);
    printf("PIB: R$%.2f bilhões de reais\n",pib1);
    printf("Numero de pontos turisticos: %d\n",pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n",densidadep1);
    printf("PIB per Capita: R$%.2f reais\n",pibpercapita1);
    printf("Super Poder: %.0f",super1);
    
    printf("\n\nCarta 2:\n");
    printf("Estado: %c\n",estado2);
    printf("Código da carta: %c%s\n",estado2,codCarta2);
    printf("Nome da Cidade: %s\n",cidade2);
    printf("População: %lu\n",populacao2);
    printf("Área: %.2f km²\n",KMquadrado2);
    printf("PIB: R$%.2f bilhões de reais\n",pib2);
    printf("Numero de pontos turisticos: %d\n",pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n",densidadep2);
    printf("PIB per Capita: R$%.2f reais\n",pibpercapita2);
    printf("Super Poder: %.0f",super2);

    */

    // ----------------------------------------------------------------------------

    //Finalização
    printf("\n\nMuito Obrigado por jogar conosco");
    printf("\nAté mais!");

    printf("\n\n"); //Pular linha de forma estética
    return 0;
}
