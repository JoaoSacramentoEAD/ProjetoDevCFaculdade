#include <stdio.h>

int main() {
    
    char ch;
    char estado, estado2;
    char codigo[50], codigo2[50];
    char cidade[50], cidade2[50];
    int populacao, populacao2;
    float area, area2;
    float pib, pib2;
    int pontos_turisticos, pontos_turisticos2;
    float densidade_populacional, densidade_populacional2;
    float pib_per_capita, pib_per_capita2;

    printf("Digite a letra do estado da carta 1: ");
    scanf("%c", &estado);
    printf("Digite o código do estado da carta 1: ");
    scanf("%s", &codigo);
    printf("Digite a cidade da carta 1: ");
    scanf("%s", &cidade);
    printf("Digite a população total da carta 1: ");
    scanf("%d", &populacao);
    printf("Digite a area total da carta 1(km²): ");
    scanf("%f", &area);
    printf("Digite o pib da carta 1(bilhões): ");
    scanf("%f", &pib);
    printf("Digite a quantidade de pontos turisticos da carta 1: ");
    scanf("%d", &pontos_turisticos);
    ch = getchar();

    printf("Digite a letra do estado da carta 2: ");
    scanf("%c", &estado2);
    printf("Digite o código do estado da carta 2: ");
    scanf("%s", &codigo2);
    printf("Digite a cidade da carta 2: ");
    scanf("%s", &cidade2);
    printf("Digite a população total da carta 2: ");
    scanf("%d", &populacao2);
    printf("Digite a area total da carta 2(km²): ");
    scanf("%f", &area2);
    printf("Digite o pib da carta 2(bilhões): ");
    scanf("%f", &pib2);
    printf("Digite a quantidade de pontos turisticos da carta 2: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculos
    densidade_populacional = (float)populacao / area;
    pib_per_capita = (pib * 1000000000.0) / populacao;
    densidade_populacional2 = (float)populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000.0) / populacao2;

    printf("Carta 1: \n");
    printf("Estado: %c\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome da cidade: %s\n", cidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhoes de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita);
    printf("-----------------------------------------\n");
    printf("Carta 2: \n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional2);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita2);
    printf("-----------------------------------------\n");

    int escolha;
    printf("\nEscolha o atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área (km²)\n");
    printf("3 - PIB (bilhões)\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (hab/km²)\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);
    printf("-----------------------------------------\n");

    printf("Comparação de cartas:\n\n");

    switch (escolha) {
        case 1: // População
            printf("Atributo: População\n");
            printf("Carta 1 - %s (%c): %d\n", cidade, estado, populacao);
            printf("Carta 2 - %s (%c): %d\n\n", cidade2, estado2, populacao2);
            if (populacao > populacao2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if (populacao < populacao2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 2: // Área
            printf("Atributo: Área (km²)\n");
            printf("Carta 1 - %s (%c): %.2f\n", cidade, estado, area);
            printf("Carta 2 - %s (%c): %.2f\n\n", cidade2, estado2, area2);
            if (area > area2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if (area < area2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 3: // PIB
            printf("Atributo: PIB (bilhões)\n");
            printf("Carta 1 - %s (%c): %.2f\n", cidade, estado, pib);
            printf("Carta 2 - %s (%c): %.2f\n\n", cidade2, estado2, pib2);
            if (pib > pib2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if (pib < pib2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("Carta 1 - %s (%c): %d\n", cidade, estado, pontos_turisticos);
            printf("Carta 2 - %s (%c): %d\n\n", cidade2, estado2, pontos_turisticos2);
            if (pontos_turisticos > pontos_turisticos2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if (pontos_turisticos < pontos_turisticos2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 5: // Densidade Demográfica (menor vence)
            printf("Atributo: Densidade Demográfica (hab/km²)\n");
            printf("Carta 1 - %s (%c): %.2f\n", cidade, estado, densidade_populacional);
            printf("Carta 2 - %s (%c): %.2f\n\n", cidade2, estado2, densidade_populacional2);
            if (densidade_populacional < densidade_populacional2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade);
            } else if (densidade_populacional > densidade_populacional2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
    printf("-----------------------------------------\n");
}
