#include <stdio.h>
#include <string.h>
int main() {
    // Variaveis para armazenar informacoes da carta 01
    char estado = 'A';
    char codigoCarta[4] = "A";
    char nomeCidade[20] = "A";
    int populacao = 0;
    float area = 0.0;
    float pib = 0.0;
    int pontosTuristicos = 0;
    int c = 0;
    // Variaveis para armazenar informacoes da carta 02
    char estado2 = 'B';
    char codigoCarta2[4] = "B";
    char nomeCidade2[20] = "B";
    int populacao2 = 0;
    float area2 = 0.0;
    float pib2 = 0.0;
    int pontosTuristicos2 = 0;
    printf("Bem-vindo ao Super Trunfo!\n");
    //carta 01
    printf("Por favor, insira as informacoes da carta 01:\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado);
    printf("Digite o codigo da carta (3 caracteres): ");
    scanf("%3s", codigoCarta);
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Digite o nome da cidade (até 20 caracteres): ");
    fgets(nomeCidade, 20, stdin);
    printf("Digite a populacao: ");
    scanf("%d", &populacao);
    printf("Digite a area: ");
    scanf("%f", &area);
    printf("Digite o PIB: ");
    scanf("%f", &pib);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos);
    nomeCidade[strcspn(nomeCidade, "\n")] = '\0';
    //carta 02
    printf("Por favor, insira as informacoes da carta 02:\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o codigo da carta (3 caracteres): ");
    scanf("%3s", codigoCarta2);
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Digite o nome da cidade (até 20 caracteres): ");
    fgets(nomeCidade2, 20, stdin);
    printf("Digite a populacao: ");
    scanf("%d", &populacao2);
    printf("Digite a area: ");
    scanf("%f", &area2);
    printf("Digite o PIB: ");
    scanf("%f", &pib2);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0';

    // Exibir informacoes da carta 01
    printf("\nInformacoes da Carta 01:\n");
    printf("Estado: %c\n", estado);
    printf("Codigo da Carta: %s\n", codigoCarta);
    printf("Nome da Cidade: %s\n", nomeCidade);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Pontos Turisticos: %d\n", pontosTuristicos);

    // Exibir informacoes da carta 02
    printf("\nInformacoes da Carta 02:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo da Carta: %s\n", codigoCarta2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turisticos: %d\n", pontosTuristicos2);
    return 0;
}