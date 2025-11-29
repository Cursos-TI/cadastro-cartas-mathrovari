#include <stdio.h>

int main()
{    
    // Declaração de váriaveis para o cadastro de cartas do jogo super trunfo de paises
    
    // Cadastro de caracteristicas da cartas
    // Estado, cidade e código da carta
    char estado1='A',cidade1[]="exemplo",codCarta1[]="Z00";
    char estado2='A',cidade2[]="exemplo",codCarta2[]="Z00";

    // População do local e pontos numero de ponstos turisticos que o mesmo possui
    int populacao1=123456,pontos_turisticos1=2;
    int populacao2=123456,pontos_turisticos2=2;

    // Tamanho do local em Km quadrado e PIB 
    float KMquadrado1=1.5,pib1=123.34;
    float KMquadrado2=1.5,pib2=123.34;

    // Introdução ao Jogo
    printf("\n\n"); // Pulo de linha estetico
    printf("Olá jogador! Estamos criando um jogo chamado Super Trunfo de Paises\n");
    printf("Preciso da sua ajuda para cadastrar duas cartas desse jogo, vamos começar\n");

    // Entrada de dados primeira carta
    printf("\nIniciaremos cadastrando a carta nº1");
    printf("\nQual nome da cidade que deseja cadastrar: ");
    scanf("%s",cidade1);
    printf("\n%s? Boa escolha!\n",cidade1);
    printf("Agora escolha uma letra de A a H que representará o estado dessa cidade: \n");
    scanf(" %c",&estado1);
    printf("\nAgora escolha um código para a carta, precisam ser 2 numeros, por exemplo '00':\n");
    scanf("%s",codCarta1);
    printf("\nQuantos habitantes existem nessa cidade?\n");
    scanf("%d",&populacao1);
    printf("\nEstamos quase acabando. Qual seria o tamanho dessa cidade em kilometros quadrados?\n");
    scanf("%f",&KMquadrado1);
    printf("\nQual o PIB dessa cidade?\n");
    scanf("%f",&pib1);
    printf("\nAgora a ultima pergunta. Quantos pontos turisticos tem essa ciadade?\n");
    scanf("%d",&pontos_turisticos1);
    
    // Entrada de dados segunda carta
    printf("\n\nFinalizamos a carta nº1, agora vamos cadastrar a carta nº2");
    printf("\nQual nome da cidade que deseja cadastrar:\n");
    scanf("%s",cidade2);
    printf("\n\n %s ? Novamente uma boa escolha!\n",cidade2);
    printf("Agora escolha uma letra de A a H que representará o estado dessa cidade: \n");
    scanf(" %c",&estado2);
    printf("\nAgora escolha um código para a carta, precisam ser 2 numeros, por exemplo '00':\n");
    scanf("%s",codCarta2);
    printf("\nQuantos habitantes existem nessa cidade?\n");
    scanf("%d",&populacao2);
    printf("\nQual seria o tamanho dessa cidade em km²?\n");
    scanf("%f",&KMquadrado2);
    printf("\nQual o PIB dessa cidade?\n");
    scanf("%f",&pib2);
    printf("\nAgora a ultima pergunta. Quantos pontos turisticos tem essa cidade?\n");
    scanf("%d",&pontos_turisticos2);

    // Área para exibição dos dados da cidade
    
    printf("\nFinalizamos o cadastro das cartas, de uma olhada como ficou");

    // Exibição Carta 1
    printf("\n\nCarta 1:\n");
    printf("Estado: %c\n",estado1);
    printf("Código da carta: %c%s\n",estado1,codCarta1);
    printf("Nome da Cidade: %s\n",cidade1);
    printf("População: %d de pessoas\n",populacao1);
    printf("Área: %.2f km²\n",KMquadrado1);
    printf("PIB: R$%.2f milhoes de reais\n",pib1);
    printf("Numero de pontos turisticos: %d\n",pontos_turisticos1);
    
    // Exibição Carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n",estado2);
    printf("Código da carta: %c%s\n",estado2,codCarta2);
    printf("Nome da Cidade: %s\n",cidade2);
    printf("População: %d de pessoas\n",populacao2);
    printf("Área: %.2f km²\n",KMquadrado2);
    printf("PIB: R$%.2f milhoes de reais\n",pib2);
    printf("Numero de pontos turisticos: %d\n",pontos_turisticos2);
    
    //Finalização
    printf("\n\nMuito Obrigado por nos ajudar a criar esse jogo");
    printf("\nAté mais!");

    printf("\n\n"); //Pular linha de forma estética
    return 0;
}
