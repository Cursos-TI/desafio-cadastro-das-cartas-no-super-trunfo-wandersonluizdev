#include <stdio.h>
#include <string.h>

// Função para exibir o nome do atributo
const char* nomeAtributo(int op) {
    switch(op) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade populacional";
        case 6: return "PIB per capita";
        default: return "Atributo desconhecido";
    }
}

// Função para recuperar o valor do atributo 
float valorAtributo(int op, int populacao, float area, float pib, int pontos, float densidade, float pibpercapita) {
    switch(op) {
        case 1: return populacao;
        case 2: return area;
        case 3: return pib;
        case 4: return pontos;
        case 5: return densidade;
        case 6: return pibpercapita;
        default: return 0.0;
    }
}

int main() {
    // **** CARTA 01 ----
    char estado1[20], codigocarta1[20], nomecidade1[50];
    int populacao1, pontosturisticos1;
    float area1, pib1, densidadepo1, pibpercapita1;
    // Cadastrando
    printf("Código da Carta: ");
    scanf("%s", codigocarta1);  
    printf("Estado: ");
    scanf("%s", estado1);    
    printf("Nome da Cidade: ");
    scanf("%s", nomecidade1);
    printf("Populacao: ");
    scanf("%d", &populacao1); 
    printf("Area: ");
    scanf("%f", &area1); 
    printf("PIB: ");
    scanf("%f", &pib1);
    printf("Pontos Turisticos: ");
    scanf("%d", &pontosturisticos1); 
    densidadepo1 = (float) populacao1 / area1;
    pibpercapita1 = (float) pib1 / populacao1;
    printf("*** CARTA 1 ***\n");
    printf("Código: %s\tEstado: %s\tCidade: %s\n", codigocarta1, estado1, nomecidade1);
    printf("Populacao: %d\tArea: %.2f\tPIB: %.2f\n", populacao1, area1, pib1);
    printf("Pontos Turisticos: %d\n", pontosturisticos1);
    printf("Densidade populacional: %.2f hab/km²\tPIB per capita: %.2f\n", densidadepo1, pibpercapita1);

    // *** CARTA 02 ***
    char estado2[20], codigocarta2[20], nomecidade2[50];
    int populacao2, pontosturisticos2;
    float area2, pib2, densidadepo2, pibpercapita2;
    printf("Código da Carta: ");
    scanf("%s", codigocarta2);  
    printf("Estado: ");
    scanf("%s", estado2);    
    printf("Nome da Cidade: ");
    scanf("%s", nomecidade2);
    printf("Populacao: ");
    scanf("%d", &populacao2); 
    printf("Area: ");
    scanf("%f", &area2); 
    printf("PIB: ");
    scanf("%f", &pib2); 
    printf("Pontos Turisticos: ");
    scanf("%d", &pontosturisticos2); 
    densidadepo2 = (float) populacao2 / area2;
    pibpercapita2 = (float) pib2 / populacao2;
    printf("*** CARTA 2 ***\n");
    printf("Código: %s\tEstado: %s\tCidade: %s\n", codigocarta2, estado2, nomecidade2);
    printf("Populacao: %d\tArea: %.2f\tPIB: %.2f\n", populacao2, area2, pib2);
    printf("Pontos Turisticos: %d\n", pontosturisticos2);
    printf("Densidade populacional: %.2f hab/km²\tPIB per capita: %.2f\n", densidadepo2, pibpercapita2);

    // * ESCOLHA DINÂMICA DOS ATRIBUTOS *
    int atributo1=-1, atributo2=-1, valido;
    do {
        printf("Escolha o PRIMEIRO atributo para comparação:\n");
        printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade populacional\n6. PIB per capita\nOpção: ");
        scanf("%d", &atributo1);
        if (atributo1<1 || atributo1>6) {
            printf("Opção inválida!\n");
            valido=0;
        } else {
            valido=1;
        }
    } while (!valido);

    do {
        printf("Escolha o SEGUNDO atributo para comparação (diferente do primeiro):\n");
        for (int i=1; i<=6; i++) {
            if (i==atributo1) continue;
            printf("%d. %s\n", i, nomeAtributo(i));
        }
        printf("Opção: ");
        scanf("%d", &atributo2);
        if (atributo2<1 || atributo2>6 || atributo2==atributo1) {
            printf("Opção inválida!\n");
            valido=0;
        } else {
            valido=1;
        }
    } while (!valido);

    // *** RECUPERA OS VALORES ***
    float valores_carta1[7], valores_carta2[7];
    valores_carta1[1]=populacao1;         valores_carta2[1]=populacao2;
    valores_carta1[2]=area1;              valores_carta2[2]=area2;
    valores_carta1[3]=pib1;               valores_carta2[3]=pib2;
    valores_carta1[4]=pontosturisticos1;  valores_carta2[4]=pontosturisticos2;
    valores_carta1[5]=densidadepo1;       valores_carta2[5]=densidadepo2;
    valores_carta1[6]=pibpercapita1;      valores_carta2[6]=pibpercapita2;

    // *** COMPARAÇÃO INDIVIDUAL DOS ATRIBUTOS ***
    int resultado1, resultado2;
    // Densidade: menor vence (caso 5)
    resultado1 = (atributo1==5)
        ? (valores_carta1[atributo1] < valores_carta2[atributo1] ? 1 : (valores_carta1[atributo1] > valores_carta2[atributo1] ? 2 : 0))
        : (valores_carta1[atributo1] > valores_carta2[atributo1] ? 1 : (valores_carta1[atributo1] < valores_carta2[atributo1] ? 2 : 0));
    resultado2 = (atributo2==5)
        ? (valores_carta1[atributo2] < valores_carta2[atributo2] ? 1 : (valores_carta1[atributo2] > valores_carta2[atributo2] ? 2 : 0))
        : (valores_carta1[atributo2] > valores_carta2[atributo2] ? 1 : (valores_carta1[atributo2] < valores_carta2[atributo2] ? 2 : 0));

    // *** SOMA DOS ATRIBUTOS ***
    float soma1 = valores_carta1[atributo1] + valores_carta1[atributo2];
    float soma2 = valores_carta2[atributo1] + valores_carta2[atributo2];

    // *** EXIBIÇÃO ORGANIZADA DOS RESULTADOS ***
    printf("*** RESULTADO DA COMPARAÇÃO ***\n");
    printf("Cidades: %s x %s\n", nomecidade1, nomecidade2);
    printf("Atributos usados: %s e %s\n", nomeAtributo(atributo1), nomeAtributo(atributo2));
    printf("Valores dos atributos:\n");
    printf("%s: %.2f / %.2f\n", nomecidade1, valores_carta1[atributo1], valores_carta1[atributo2]);
    printf("%s: %.2f / %.2f\n", nomecidade2, valores_carta2[atributo1], valores_carta2[atributo2]);
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", nomecidade1, soma1);
    printf("%s: %.2f\n", nomecidade2, soma2);

    // *** DECISÃO FINAL ***
    if (soma1 > soma2) {
        printf("Vencedor: %s 🏆\n", nomecidade1);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s 🏆\n", nomecidade2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
