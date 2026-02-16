#include <stdio.h>

// ---------------- FUNÇÕES ----------------

// Maior carta ganha
int maiorGanha(float v1, float v2) {
    return (v1 > v2) ? 1 : (v1 < v2) ? 2 : 0;
}

// Menor carta ganha (densidade)
int menorGanha(float v1, float v2) {
    return (v1 < v2) ? 1 : (v1 > v2) ? 2 : 0;
}

// Retorna nome da carta vencedora
char *carta(int resultado){
    return (resultado == 1) ? "Carta 1" :
           (resultado == 2) ? "Carta 2" :
           "Empate";
}

// Escolha de atributo
int escolhaatributo(){
    int escolha;
    do{
        printf("Qual atributo vamos comparar?:\n");
        printf("1- População\n");
        printf("2- Área\n");
        printf("3- PIB\n");
        printf("4- Pontos Turisticos\n");
        printf("5- Densidade Populacional\n");
        printf("Digite apenas o numero: ");
        scanf("%d",&escolha);

        if(escolha < 1 || escolha > 5){
            printf("Opção invalida, escolha novamente\n\n");
        }

    }while (escolha < 1 || escolha > 5);

    return escolha;
}

// ---------------- INICIO DO PROGRAMA ----------------

int main()
{
    printf("\n\n");

    // ---------------- DADOS DAS CARTAS ----------------

    char cidade1[100]="São Paulo";
    char cidade2[100]="Rio de Janeiro";

    int populacao1=250100,populacao2=500672;
    int pontos_turisticos1=30,pontos_turisticos2=30;

    float KMquadrado1=348.45,pib1=9801.22, densidadep1=0;
    float KMquadrado2=194.15,pib2=6729.10, densidadep2=0;

    int opcao1=0, opcao2=0; //opções dos jogadores

    float valor1_c1=0, valor2_c1=0; // valores da carta 1
    float valor1_c2=0, valor2_c2=0; // valores da carta 2

    // ---------------- CALCULOS ----------------

    densidadep1 = populacao1 / KMquadrado1;
    densidadep2 = populacao2 / KMquadrado2;

    // ---------------- ESCOLHA DOS ATRIBUTOS ----------------

    printf("Olá jogador! Aqui você vai jogar Super Trunfo de Paises\n");
    printf("Você precisa escolher 2 atributos para compararmos:\n\n");

    opcao1 = escolhaatributo();

    // impedir repetir atributo
    do{
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        opcao2 = escolhaatributo();

        if(opcao2 == opcao1){
            printf("\nVocê não pode escolher o mesmo atributo!\n");
        }

    }while(opcao2 == opcao1);

    // ---------------- SWITCH DO PRIMEIRO ATRIBUTO ----------------

    switch(opcao1){

        case 1:
            valor1_c1 = populacao1;
            valor1_c2 = populacao2;
            break;

        case 2:
            valor1_c1 = KMquadrado1;
            valor1_c2 = KMquadrado2;
            break;

        case 3:
            valor1_c1 = pib1;
            valor1_c2 = pib2;
            break;

        case 4:
            valor1_c1 = pontos_turisticos1;
            valor1_c2 = pontos_turisticos2;
            break;

        case 5:
            valor1_c1 = densidadep1;
            valor1_c2 = densidadep2;
            break;
    }

    // ---------------- SWITCH DO SEGUNDO ATRIBUTO ----------------

    switch(opcao2){

        case 1:
            valor2_c1 = populacao1;
            valor2_c2 = populacao2;
            break;

        case 2:
            valor2_c1 = KMquadrado1;
            valor2_c2 = KMquadrado2;
            break;

        case 3:
            valor2_c1 = pib1;
            valor2_c2 = pib2;
            break;

        case 4:
            valor2_c1 = pontos_turisticos1;
            valor2_c2 = pontos_turisticos2;
            break;

        case 5:
            valor2_c1 = densidadep1;
            valor2_c2 = densidadep2;
            break;
    }

    // ---------------- COMPARAÇÃO INDIVIDUAL ----------------

    int resultado1 = (opcao1 == 5) ?
                     menorGanha(valor1_c1, valor1_c2) :
                     maiorGanha(valor1_c1, valor1_c2);

    int resultado2 = (opcao2 == 5) ?
                     menorGanha(valor2_c1, valor2_c2) :
                     maiorGanha(valor2_c1, valor2_c2);

    // ---------------- SOMA FINAL ----------------

    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    int resultadoFinal = maiorGanha(soma1, soma2);

    // ---------------- EXIBIÇÃO ----------------

    printf("\n\n----- RESULTADO -----\n");

    printf("\nCarta 1 (%s) valores: ", cidade1);

    if(opcao1 == 1 || opcao1 == 4){
        printf("%.0f", valor1_c1);
    }else{
        printf("%.2f", valor1_c1);
    }

    printf(" e ");

    if(opcao2 == 1 || opcao2 == 4){
        printf("%.0f", valor2_c1);
    }else{
        printf("%.2f", valor2_c1);
    }


    printf("\nCarta 2 (%s) valores: ", cidade2);

    if(opcao1 == 1 || opcao1 == 4){
        printf("%.0f", valor1_c2);
    }else{
        printf("%.2f", valor1_c2);
    }

    printf(" e ");

    if(opcao2 == 1 || opcao2 == 4){
        printf("%.0f", valor2_c2);
    }else{
        printf("%.2f", valor2_c2);
    }

    printf("\n\nSoma Carta 1: %.2f", soma1);
    printf("\nSoma Carta 2: %.2f", soma2);

    printf("\n\nResultado Final: %s", carta(resultadoFinal));

    printf("\n\nMuito Obrigado por jogar conosco");
    printf("\nAté mais!\n\n");

    return 0;
}
