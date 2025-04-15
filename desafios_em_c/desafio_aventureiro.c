#include <stdio.h>

int main() {
    
    char ch;
    char estado, estado2;
    char codigo[50], codigo2[50];
    char cidade[50], cidade2[50];
    unsigned long int populacao, populacao2;
    float area, area2;
    float pib, pib2;
    int pontos_turisticos, pontos_turisticos2;
    float densidade_populacional, densidade_populacional2;
    float pib_per_capita, pib_per_capita2;
    float super_poder1, super_poder2; // Variáveis para Super Poder

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

    // Cálculo do Super Poder
    super_poder1 = (float)populacao + area + pib + (float)pontos_turisticos + pib_per_capita + (1.0 / densidade_populacional);
    super_poder2 = (float)populacao2 + area2 + pib2 + (float)pontos_turisticos2 + pib_per_capita2 + (1.0 / densidade_populacional2);

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

    // Comparações (sem if/else)
    int comp_populacao = populacao > populacao2;
    int comp_area = area > area2;
    int comp_pib = pib > pib2;
    int comp_pontos = pontos_turisticos > pontos_turisticos2;
    int comp_densidade = densidade_populacional < densidade_populacional2; // Menor vence
    int comp_pib_per_capita = pib_per_capita > pib_per_capita2;
    int comp_super_poder = super_poder1 > super_poder2;

    // Exibição dos Resultados da Comparação
    printf("\nComparação de Cartas:\n");
    printf("População: Carta %d venceu (%d)\n", 2 - comp_populacao, comp_populacao);
    printf("Área: Carta %d venceu (%d)\n", 2 - comp_area, comp_area);
    printf("PIB: Carta %d venceu (%d)\n", 2 - comp_pib, comp_pib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", 2 - comp_pontos, comp_pontos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", 2 - comp_densidade, comp_densidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n", 2 - comp_pib_per_capita, comp_pib_per_capita);
    printf("Super Poder: Carta %d venceu (%d)\n", 2 - comp_super_poder, comp_super_poder);

}
