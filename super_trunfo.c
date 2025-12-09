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
    }else if(carta1 == carta2){
        return 2;
    }
    return 0;
}
//Menor carta ganha
int menorganha(double carta1, double carta2){
    if(carta1 < carta2){
        return 1;
    }else if(carta1 == carta2){
        return 2;
    }
    return 0;
}
//Atribuição de Carta
char *carta(int carta1){
    if(carta1 == 1){
        return "Carta 1";
    }else if(carta1 == 2){
        return "Empate";
    }
    return "Carta 2";
}

// Limpar entrada do buffer para usar o fgets
// Remove caracteres restantes no stdin (como '\n' do scanf) antes de usar fgets
// Excerto pelo primeiro fgets, usar sempre antes de usar fgets novamente
void limpar_buffer(void) {
    int descartar;
    while ((descartar = getchar()) != '\n' && descartar != EOF) {
        ; 
    }
}


// Inicio do programa --------------------------------------------

int main()
{
    printf("\n\n"); //Pulo estético

    //------------------------------------------------------------------------------
    // Declaração de váriaveis para o cadastro de cartas do jogo super trunfo de paises
    char estado1='A',cidade1[100]="São Paulo",codCarta1[5]="A01";
    char estado2='B',cidade2[100]="Rio de Janeiro",codCarta2[5]="B02";

    int populacao1=250100,populacao2=500672;
    int pontos_turisticos1=30,pontos_turisticos2=30;
    int opcao=0;

    float KMquadrado1=348.45,pib1=9801.22, pibpercapita1=0, densidadep1=0;
    float KMquadrado2=194.15,pib2=6729.10, pibpercapita2=0, densidadep2=0;
    float super1=0, super2=0;

    // Declaração de váriaveis de calculos
    float pibbilhao1 = pib1*1000000000; // Tranformando o PIB normal em bilhão
    float pibbilhao2 = pib2*1000000000; // Tranformando o PIB normal em bilhão

    float inversodensidade1 = 1/densidadep1; // Calculo de densidade inversa para Super Poder
    float inversodensidade2 = 1/densidadep2; // Calculo de densidade inversa para Super Poder

    //------------------------------------------------------------------------------
    //Calculos

    // Caclulo de densidade
    densidadep1 = divisao(populacao1,KMquadrado1);
    densidadep2 = divisao(populacao2,KMquadrado2);

    // Calculo de PIB Percapita
    pibpercapita1 = pibbilhao1/ (float) populacao1;
    pibpercapita2 = pibbilhao2/ (float) populacao2;

    // Calculo de super poder
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

    //------------------------------------------------------------------------------
    // Introdução ao Jogo

    printf("Olá jogador! Aqui você vai jogar Super Trunfo de Paises");
    printf("\nEscolha escolha o atributo que vamos comparar:\n");
    
    do
    {

        printf("1- População\n");
        printf("2- Área\n");
        printf("3- PIB\n");
        printf("4- Pontos Turisticos\n");
        printf("5- Densidade Populacional\n");
        printf("ATENÇÃO: Digite apenas o numero\n");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            
            printf("\nO atributo escolhido foi: População\nVamos Comparar");
            printf("\nCarta 1 - %s: tem uma população de %d pessoas",cidade1,populacao1);
            printf("\nCarta 2 - %s: tem uma população de %d pessoas",cidade2,populacao2);

            if (WinPontuacaoPopulacao == 1)
            {
                printf("\nResultado: %s (%s) Venceu",WinCartaPopulacao,cidade1);
            }else if(WinCartaPopulacao == 2){
                printf("\nResultado: Nós temos um empate!");
            }else{
                printf("\nResultado: %s (%s) Venceu",WinCartaPopulacao,cidade2);
            }

            break;
        case 2:
            
            printf("\nO atributo escolhido foi: Área\nVamos Comparar");
            printf("\nCarta 1 - %s: tem uma área de %.2fKm²",cidade1,KMquadrado1);
            printf("\nCarta 2 - %s: tem uma área de %.2fKm²",cidade2,KMquadrado2);

            if (WinPontuacaoKMquadrado == 1)
            {
                printf("\nResultado: %s (%s) Venceu",WinCartaKMquadrado,cidade1);
            }else if(WinCartaPopulacao == 2){
                printf("\nResultado: Nós temos um empate!");
            }else{
                printf("\nResultado: %s (%s) Venceu",WinCartaKMquadrado,cidade2);
            }

            break;
        case 3:            

            printf("\nO atributo escolhido foi: PIB\nVamos Comparar");
            printf("\nCarta 1 - %s: tem um PIB de R$%.2f bilhões",cidade1,pib1);
            printf("\nCarta 2 - %s: tem um PIB de R$%.2f bilhões",cidade2,pib2);

            if (WinPontuacaoPIB == 1)
            {
                printf("\nResultado: %s (%s) Venceu",WinCartaPIB,cidade1);
            }else if(WinPontuacaoPIB == 2){
                printf("\nResultado: Nós temos um empate!");
            }else{
                printf("\nResultado: %s (%s) Venceu",WinCartaPIB,cidade2);
            }

            break;
        case 4:

            printf("\nO atributo escolhido foi: Pontos Turisticos\nVamos Comparar");
            printf("\nCarta 1 - %s: tem um total de %d pontos turisticos",cidade1,pontos_turisticos1);
            printf("\nCarta 2 - %s: tem um total de %d pontos turisticos",cidade2,pontos_turisticos2);

            if (WinPontuacaoPontosT == 1)
            {
                printf("\nResultado: %s (%s) Venceu",WinCartaPontosT,cidade1);
            }else if(WinPontuacaoPontosT == 2){
                printf("\nResultado: Nós temos um empate!");
            }else{
                printf("\nResultado: %s (%s) Venceu",WinCartaPontosT,cidade2);
            }

            break;
        case 5:

            printf("\nO atributo escolhido foi: Densidade Populacional\nVamos Comparar");
            printf("\nCarta 1 - %s: tem um total de %.2fhab/km²",cidade1,densidadep1);
            printf("\nCarta 2 - %s: tem um total de %.2fhab/km²",cidade2,densidadep2);

            if (WinPontuacaoDensidade == 1)
            {
                printf("\nResultado: %s (%s) Venceu",WinCartaDensidade,cidade1);
            }else if(WinPontuacaoDensidade == 2){
                printf("\nResultado: Nós temos um empate!");
            }else{
                printf("\nResultado: %s (%s) Venceu",WinCartaDensidade,cidade2);
            }

            break;
        default:
            printf("\nOpção invalida, digite um numero de 1 a 5 sendo:\n");
        }

    } while (opcao < 1 || opcao > 5);
    
    //------------------------------------------------------------------------------

    //Finalização
    printf("\n\nMuito Obrigado por jogar conosco");
    printf("\nAté mais!");

    printf("\n\n"); //Pular linha de forma estética
    return 0;
}

/*  -----------Comentário Atividade Novato e Aventureiro Tema 2-------------------

    -------A baixo está a entrada de dados usada no tema 2-------------

        // Entrada de dados primeira carta
    printf("\nIniciaremos cadastrando a carta nº1");
    printf("\nQual nome da cidade que deseja cadastrar: \n");
    //scanf("%s",cidade1); -- antiga entrada de dados do tipo string para cidade1
    fgets(cidade1,sizeof(cidade1),stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0'; // remover pulo de linha criado por fgets
    printf("\n\nBoa escolha!\n");
    printf("Agora escolha uma letra de A a H que representará o estado dessa cidade: \n");
    scanf("%c",&estado1);
    printf("\nAgora escolha um código para a carta, precisam ser 2 numeros, por exemplo '00':\n");
    scanf("%s",codCarta1);
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
    //scanf("%s",cidade2); -- antiga entrada de dados do tipo string para cidade2
    limpar_buffer();
    fgets(cidade2,sizeof(cidade2),stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0'; // remover pulo de linha criado por fgets
    printf("\n\nNovamente uma boa escolha!\n");
    printf("Agora escolha uma letra de A a H que representará o estado dessa cidade: \n");
    scanf("%c",&estado2);
    printf("\nAgora escolha um código para a carta, precisam ser 2 numeros, por exemplo '00':\n");
    scanf("%s",codCarta2);
    printf("\nQuantos habitantes existem nessa cidade?\n");
    scanf("%lu",&populacao2);
    printf("\nQual seria o tamanho dessa cidade em km²?\n");
    scanf("%f",&KMquadrado2);
    printf("\nQual o PIB dessa cidade?\n");
    scanf("%f",&pib2);
    printf("\nAgora ultima pergunta. Quantos pontos turisticos tem essa cidade?\n");
    scanf("%d",&pontos_turisticos2);

    ------- A baixo está a demonstração final da atividade notavo de aventureiro do tema 2 ----------

    printf("\n\nOlhe a baixo as cartas que cadastrou");

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

    //Finalização
    printf("\n\nMuito Obrigado por nos ajudar a montar esse jogo");
    printf("\nAté mais!");

*/

/*  -----------Comentário Atividade Avançado Tema 2-------------------
    ------- A baixo está a demonstração final da atividade avançado do tema 2 ----------

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

    //Finalização
    printf("\n\nMuito Obrigado por jogar conosco");
    printf("\nAté mais!");

*/