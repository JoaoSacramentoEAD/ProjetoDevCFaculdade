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

    int escolha1, escolha2;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;
    float soma_carta1, soma_carta2;
    char nome_atributo1[50], nome_atributo2[50]; // Para guardar os nomes dos atributos

    // --- Escolha do Primeiro Atributo (sem loop) ---
    printf("\nEscolha o PRIMEIRO atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área (km²)\n");
    printf("3 - PIB (bilhões)\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (hab/km²)\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &escolha1);

    // Validação da primeira escolha
    if (escolha1 < 1 || escolha1 > 5) {
        printf("Erro: Opção inválida para o primeiro atributo (%d). Encerrando.\n", escolha1);
        return 1; // Termina o programa se a entrada for inválida
    }
    printf("-----------------------------------------\n");

    // --- Escolha do Segundo Atributo (Dinâmico, sem loop) ---
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    if (escolha1 != 1) printf("1 - População\n");
    if (escolha1 != 2) printf("2 - Área (km²)\n");
    if (escolha1 != 3) printf("3 - PIB (bilhões)\n");
    if (escolha1 != 4) printf("4 - Pontos Turísticos\n");
    if (escolha1 != 5) printf("5 - Densidade Demográfica (hab/km²)\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha2);

    // Validação da segunda escolha
    if (escolha2 < 1 || escolha2 > 5) {
        printf("Erro: Opção inválida para o segundo atributo (%d). Encerrando.\n", escolha2);
        return 1; // Termina o programa se a entrada for inválida
    }
    if (escolha2 == escolha1) {
        printf("Erro: O segundo atributo (%d) não pode ser igual ao primeiro (%d). Encerrando.\n", escolha2, escolha1);
        return 1; // Termina o programa se for igual à primeira escolha
    }
    printf("-----------------------------------------\n");

    // --- Obter valores e nomes dos atributos escolhidos ---

    // Atributo 1
    switch (escolha1) {
        case 1: valor1_carta1 = (float)populacao; valor1_carta2 = (float)populacao2; sprintf(nome_atributo1, "População"); break;
        case 2: valor1_carta1 = area; valor1_carta2 = area2; sprintf(nome_atributo1, "Área (km²)"); break;
        case 3: valor1_carta1 = pib; valor1_carta2 = pib2; sprintf(nome_atributo1, "PIB (bilhões)"); break;
        case 4: valor1_carta1 = (float)pontos_turisticos; valor1_carta2 = (float)pontos_turisticos2; sprintf(nome_atributo1, "Pontos Turísticos"); break;
        case 5: valor1_carta1 = densidade_populacional; valor1_carta2 = densidade_populacional2; sprintf(nome_atributo1, "Densidade Demográfica"); break;
    }

    // Atributo 2
    switch (escolha2) {
        case 1: valor2_carta1 = (float)populacao; valor2_carta2 = (float)populacao2; sprintf(nome_atributo2, "População"); break;
        case 2: valor2_carta1 = area; valor2_carta2 = area2; sprintf(nome_atributo2, "Área (km²)"); break;
        case 3: valor2_carta1 = pib; valor2_carta2 = pib2; sprintf(nome_atributo2, "PIB (bilhões)"); break;
        case 4: valor2_carta1 = (float)pontos_turisticos; valor2_carta2 = (float)pontos_turisticos2; sprintf(nome_atributo2, "Pontos Turísticos"); break;
        case 5: valor2_carta1 = densidade_populacional; valor2_carta2 = densidade_populacional2; sprintf(nome_atributo2, "Densidade Demográfica"); break;
    }

    // --- Calcular Somas ---
    soma_carta1 = valor1_carta1 + valor2_carta1;
    soma_carta2 = valor1_carta2 + valor2_carta2;

    // --- Exibir Resultados Detalhados ---
    printf("Comparação de cartas com base em DOIS atributos:\n\n");
    printf("Atributos Escolhidos: %s e %s\n\n", nome_atributo1, nome_atributo2);

    // Exibição dos valores individuais
    printf("--- Valores Individuais ---\n");
    printf("Carta 1 (%s - %c):\n", cidade, estado);
    printf("  %s: %.2f\n", nome_atributo1, valor1_carta1);
    printf("  %s: %.2f\n", nome_atributo2, valor2_carta1);
    printf("Carta 2 (%s - %c):\n", cidade2, estado2);
    printf("  %s: %.2f\n", nome_atributo1, valor1_carta2);
    printf("  %s: %.2f\n", nome_atributo2, valor2_carta2);
    printf("\n");

    // Comparação Individual (Apenas para exibição)
    printf("--- Comparação Individual (informativo) ---\n");
    // Atributo 1
    printf("Comparando '%s':\n", nome_atributo1);
    if (escolha1 == 5) { // Densidade Demográfica (menor vence)
        if (valor1_carta1 < valor1_carta2) printf("  Carta 1 (%s) venceria neste atributo.\n", cidade);
        else if (valor1_carta2 < valor1_carta1) printf("  Carta 2 (%s) venceria neste atributo.\n", cidade2);
        else printf("  Empate neste atributo.\n");
    } else { // Outros atributos (maior vence)
        if (valor1_carta1 > valor1_carta2) printf("  Carta 1 (%s) venceria neste atributo.\n", cidade);
        else if (valor1_carta2 > valor1_carta1) printf("  Carta 2 (%s) venceria neste atributo.\n", cidade2);
        else printf("  Empate neste atributo.\n");
    }
     // Atributo 2
    printf("Comparando '%s':\n", nome_atributo2);
     if (escolha2 == 5) { // Densidade Demográfica (menor vence)
        if (valor2_carta1 < valor2_carta2) printf("  Carta 1 (%s) venceria neste atributo.\n", cidade);
        else if (valor2_carta2 < valor2_carta1) printf("  Carta 2 (%s) venceria neste atributo.\n", cidade2);
        else printf("  Empate neste atributo.\n");
    } else { // Outros atributos (maior vence)
        if (valor2_carta1 > valor2_carta2) printf("  Carta 1 (%s) venceria neste atributo.\n", cidade);
        else if (valor2_carta2 > valor2_carta1) printf("  Carta 2 (%s) venceria neste atributo.\n", cidade2);
        else printf("  Empate neste atributo.\n");
    }
    printf("\n");

    // --- Calcular e Exibir Somas ---
    printf("--- Comparação Final pela Soma ---\n");
    printf("Soma Carta 1 (%s): %.2f + %.2f = %.2f\n", cidade, valor1_carta1, valor2_carta1, soma_carta1);
    printf("Soma Carta 2 (%s): %.2f + %.2f = %.2f\n\n", cidade2, valor1_carta2, valor2_carta2, soma_carta2);

    // --- Determinar Vencedor pela Soma ---
    if (soma_carta1 > soma_carta2) {
        printf("Resultado Final: Carta 1 (%s) venceu pela MAIOR SOMA!\n", cidade);
    } else if (soma_carta2 > soma_carta1) {
        printf("Resultado Final: Carta 2 (%s) venceu pela MAIOR SOMA!\n", cidade2);
    } else {
        printf("Resultado Final: EMPATE na soma!\n");
    }

    printf("-----------------------------------------\n");
}
