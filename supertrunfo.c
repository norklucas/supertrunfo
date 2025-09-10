#include <stdio.h>
#include <string.h>

// struct para representar uma carta e otimizar o uso de variaveis
typedef struct {
    char estado;                // Letra de A a H
    char codigoCarta[4];       // 3 caracteres
    char nomeCidade[20];       // Até 20 caracteres
    int populacao;             // Número inteiro
    float area;                // Em km²
    float pib;                 // Em bilhões de reais
    int pontosTuristicos;      // Número inteiro
    float densidadePopulacional; // População / Área
    float pibPerCapita;        // PIB / População
    float somaAtributos;      // Soma dos atributos
} Carta;

int receberDadosCarta(Carta *carta) {
    int c;
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta->estado);
    printf("Digite o codigo da carta (3 caracteres): ");
    scanf("%3s", carta->codigoCarta);
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Digite o nome da cidade (até 20 caracteres): ");
    fgets(carta->nomeCidade, 20, stdin);
    printf("Digite a populacao: ");
    scanf("%d", &carta->populacao);
    printf("Digite a area: ");
    scanf("%f", &carta->area);
    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta->pontosTuristicos);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = '\0'; // Remove /n
    return 0;
}

int exibirDadosCarta(Carta carta) {
    printf("\nInformacoes da Carta:\n");
    printf("Estado: %c\n", carta.estado);
    printf("Codigo da Carta: %s\n", carta.codigoCarta);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    return 0;
}

int somarAtributos(Carta carta) {
    float soma = (float)carta.populacao + carta.area + carta.pib + (float)carta.pontosTuristicos + carta.densidadePopulacional + carta.pibPerCapita;
    return soma;
}

float calcularDensidadePopulacional(int populacao, float area) {
    if (area == 0) return 0;
    return (float)populacao / area;
}
float calcularPibPerCapita(float pib, int populacao) {
    if (populacao == 0) return 0;
    return (float)(pib * 1000000000) / populacao;
}


int main() {
    int conditionWhile = 1;
    int opcaoAtributo = 0;
    int quantidadeAtributos = 0; //não esta sendo usado
    int limiteEscolha = 0;

    //Receber dados das cartas
    Carta carta1, carta2;
    printf("Bem-vindo ao Super Trunfo!\n");
    
    printf ("Digite os dados da Carta 1:\n");
    printf ("-----------------------------------\n");
    receberDadosCarta(&carta1);

    printf ("Digite os dados da Carta 2:\n");
    printf ("-----------------------------------\n");
    receberDadosCarta(&carta2);

    // Calcular densidade populacional e PIB per capita para ambas as cartas
    carta1.densidadePopulacional = calcularDensidadePopulacional(carta1.populacao, carta1.area);
    carta2.densidadePopulacional = calcularDensidadePopulacional(carta2.populacao, carta2.area);
    carta1.pibPerCapita = calcularPibPerCapita(carta1.pib, carta1.populacao);
    carta2.pibPerCapita = calcularPibPerCapita(carta2.populacao, carta2.populacao);
    
    
    while (conditionWhile <= 2)
    {
        // Usuario colhendo atributos para comparar
        printf("Escolha 2 atributos para comparar (1-6):\n");
        if (limiteEscolha != 1) {
            printf("1. Populacao\n");
        }
        if (limiteEscolha != 2) {
            printf("2. Area\n");
        }
        if (limiteEscolha != 3) {
            printf("3. PIB\n");
        }
        if (limiteEscolha != 4) {
            printf("4. Pontos Turisticos\n");
        }
        if (limiteEscolha != 5) {
            printf("5. Densidade Populacional\n");
        }
            printf("0. Nao escolher atributos para comparacao\n");

        printf("Digite o numero do atributo: ");
        scanf("%d", &opcaoAtributo);
        switch (opcaoAtributo)
        {
            case 1:
                // Comparar população
                if (limiteEscolha != 1 ) {

                    printf("carta %.3s população: %d\n", carta1.codigoCarta,carta1.populacao);
                    printf("carta %.3s população: %d\n", carta2.codigoCarta, carta2.populacao);
                    if (carta1.populacao > carta2.populacao) {
                        printf("Carta: %.3s Venceu (%.20s)\n", carta1.codigoCarta, carta1.nomeCidade);
                    } else if (carta1.populacao  < carta2.populacao){
                            printf("Carta: %.3s Venceu (%.20s)\n", carta2.codigoCarta, carta2.nomeCidade);
                    } else {
                        printf("Empate na população!\n");
                    }
                    printf("\n\n");
                    limiteEscolha = 1;
                    conditionWhile++;
                } else {
                    printf("Voce ja escolheu esse atributo, escolha outro.\n");
                }                
                break;
            case 2:
                // Comparar área
                if (limiteEscolha != 2 ) {
                    
                    printf("Carta %.3s Área: %.2f\n", carta1.codigoCarta, carta1.area);
                    printf("Carta %.3s Área: %.2f\n", carta2.codigoCarta, carta2.area);
                    if (carta1.area > carta2.area) {
                        printf("Carta: %.3s Venceu (%.20s)\n", carta1.codigoCarta, carta1.nomeCidade);
                    } else if (carta1.area  < carta2.area){
                            printf("Carta: %.3s Venceu (%.20s)\n", carta2.codigoCarta, carta2.nomeCidade);
                    } else {
                        printf("Empate em Área!\n");
                    }
                    printf("\n\n");
                    limiteEscolha = 2;
                    conditionWhile++;
                } else {
                    printf("Voce ja escolheu esse atributo, escolha outro.\n");
                }
                
                break;
            case 3:
                // Comparar PIB
                if (limiteEscolha != 3 ) {

                    printf("Carta %.3s PIB: %.2f\n", carta1.codigoCarta, carta1.pib);
                    printf("Carta %.3s PIB: %.2f\n", carta2.codigoCarta, carta2.pib);
                    if (carta1.pib > carta2.pib) {
                        printf("Carta: %.3s Venceu (%.20s)\n", carta1.codigoCarta, carta1.nomeCidade);
                    } else if (carta1.pib  < carta2.pib){
                            printf("Carta: %.3s Venceu (%.20s)\n", carta2.codigoCarta, carta2.nomeCidade);
                    } else {
                        printf("Empate em PIB!\n");
                    }
                    printf("\n\n");
                    limiteEscolha = 3;
                    conditionWhile++;
                } else {
                    printf("Voce ja escolheu esse atributo, escolha outro.\n");
                }
                break;
            case 4:
                // Comparar pontos turísticos
                if (limiteEscolha != 4 ) {

                    printf("Carta %.3s Pontos turísticos: %d\n", carta1.codigoCarta, carta1.pontosTuristicos);
                    printf("Carta %.3s Pontos turísticos: %d\n", carta2.codigoCarta, carta2.pontosTuristicos);
                    if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                        printf("Carta: %.3s Venceu (%.20s)\n", carta1.codigoCarta, carta1.nomeCidade);
                    } else if (carta1.pontosTuristicos < carta2.pontosTuristicos){
                            printf("Carta: %.3s Venceu (%.20s)\n", carta2.codigoCarta, carta2.nomeCidade);
                    } else {
                        printf("Empate em Pontos turísticos!\n");
                    }
                    printf("\n\n");
                    limiteEscolha = 4;
                    conditionWhile++;
                } else {
                    printf("Voce ja escolheu esse atributo, escolha outro.\n");
                }
                break;
            case 5:
                // Comparar densidade populacional
                if (limiteEscolha != 5 ) {

                    printf("Carta %.3s Densidade populacional: %.2f\n", carta1.codigoCarta, carta1.densidadePopulacional);
                    printf("Carta %.3s Densidade populacional: %.2f\n", carta2.codigoCarta, carta2.densidadePopulacional);
                    if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
                        printf("Carta: %.3s Venceu (%.20s)\n", carta1.codigoCarta, carta1.nomeCidade);
                    } else if (carta1.densidadePopulacional > carta2.densidadePopulacional){
                            printf("Carta: %.3s Venceu (%.20s)\n", carta2.codigoCarta, carta2.nomeCidade);
                    } else {
                        printf("Empate em Densidade populacional!\n");
                    }
                    printf("\n\n");
                    limiteEscolha = 5;
                    conditionWhile++;
                } else {
                    printf("Voce ja escolheu esse atributo, escolha outro.\n");
                }
                break;
            case 0:
                conditionWhile = 3; // Não escolher atributos para comparação
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
    printf("\n\n");
    //somar atributos
    carta1.somaAtributos = somarAtributos(carta1);
    carta2.somaAtributos = somarAtributos(carta2);


    //Exibir informacoes das cartas
    exibirDadosCarta(carta1);
    exibirDadosCarta(carta2);
    printf("\n\n");
    if (carta1.somaAtributos > carta2.somaAtributos) {
        printf("Carta: %.3s Venceu no total dos atributos (%.20s)\n", carta1.codigoCarta, carta1.nomeCidade);
    } else if (carta1.somaAtributos < carta2.somaAtributos){
        printf("Carta: %.3s Venceu no total dos atributos (%.20s)\n", carta2.codigoCarta, carta2.nomeCidade);
    } else {
        printf("Empate no total dos atributos!\n");
    }

    return 0;
}