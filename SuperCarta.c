#include <stdio.h>
int main(){
    char carta1[3], carta2[3];
    char estado1 ='M', estado2 ='S';
    char cidade1[20], cidade2[20];
    int populacao1, populacao2;
    float PIB1, PIB2;
    float Area1, Area2;
    int pontos1, pontos2;
    float DP1, DP2;
    float PIBPC1, PIBPC2;
    float SuperPoder1, SuperPoder2;
    int Resultado = SuperPoder1 > SuperPoder2;
    int opcao;
    int primeiroAtributo, segundoAtributo;
    int resultado1, resultado2;
    
    
    printf("Carta 1:\n");
    scanf("%s", &carta1);
    printf("Estado 1: %c\n", estado1);
    printf("Cidade 1:\n");
    scanf("%s", &cidade1);
    printf("Populacao 1:\n");
    scanf("%d", &populacao1);
    printf("PIB 1:\n");
    scanf("%f", &PIB1);
    printf("Área em km² 1:\n");
    scanf("%f", &Area1);
    printf("Pontos turísticos 1:\n");
    scanf("%d", &pontos1);

    DP1 = (float) populacao1 / Area1;
    PIBPC1 = (float) PIB1 / populacao1;

    printf("DP1: %f\n", DP1);
    printf("PIBPC1: %f\n", PIBPC1);

    SuperPoder1 = (float) populacao1 + Area1 + PIB1 + pontos1 + PIBPC1 + 1 / DP1;

    printf("Super Poder 1: %f\n", SuperPoder1);

    printf("Carta 2:\n");
    scanf("%s", &carta2);
    printf("Estado 2: %c\n", estado2);
    printf("Cidade 2:\n");
    scanf("%s", &cidade2);
    printf("Populacao 2:\n");
    scanf("%d", &populacao2);
    printf("PIB 2:\n");
    scanf("%f", &PIB2);
    printf("Área em km² 2:\n");
    scanf("%f", &Area2);
    printf("Pontos turísticos 2:\n");
    scanf("%d", &pontos2);

    DP2 = (float) populacao2 / Area2;
    PIBPC2 = (float) PIB2 / populacao2;

    printf("DP2: %f\n", DP2);
    printf("PIBPC2: %f\n", PIBPC2);

    SuperPoder2 = (float) populacao2 + Area2 + PIB2 + pontos2 + PIBPC2 + 1 / DP2;

    printf("Super Poder 2: %f\n", SuperPoder2);

    printf("O resultado das cartas é: %d\n", Resultado);

    if (SuperPoder1 > SuperPoder2){
        printf("Carta 1 venceu!\n");
    }else {
        printf("Carta 2 venceu!\n");
    }
    
    printf("Comparação dos estados 1 e 2:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - Densidade Populacional\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Escolha (1 a 5):\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("Opção 1: População 1, População 2\n");
        if (estado1, estado2){
        printf("Estados 1: %c\n", estado1);
        printf("Estados 2: %c\n", estado2);
    }
     if (populacao1 > populacao2){   
        printf("População 1 venceu! %d\n", populacao1);
    } else if (populacao1 < populacao2){
        printf("População 2 venceu! %d\n", populacao2);
    } else {
        printf("Empate!\n");
    } 
        
        break;
    
    case 2:
        printf("Opção 2: Area1, Area2\n");
        if (Area1 > Area2){
        printf("Área 1 venceu! %.2f\n", Area1);
    } else if (Area1 < Area2){
        printf("Área 2 venceu! %.2f\n", Area2);
    } else {
        printf("Empate!\n");
    }
        break;
    
    case 3:
        printf("Opção 3: PIB1, PIB2\n");
        if (PIB1 > PIB2){
        printf("PIB 1 venceu! %.2f\n", PIB1);
    } else if (PIB1 < PIB2){
        printf("PIB 2 venceu! %.2f\n", PIB2);
    } else {
        printf("Empate!\n");
    }
        break;
    
    case 4:
        printf("Opção 4: pontos1, pontos2\n");
        
     if (pontos1 > pontos2){
        printf("Pontos 1 venceu! %d\n", pontos1);
    } else if (pontos1 < pontos2){
        printf("Pontos 2 venceu! %d\n", pontos2);
    } else {
        printf("Empate!\n");
    }
        break;

    case 5:
        printf("Opção 5: DP1, DP2\n");
        if (DP1 < DP2){
        printf("DP 1 venceu! %.2f\n", DP1);
    } else if (DP1 > DP2){
        printf("DP 2 venceu! %.2f\n", DP2);
    } else {
        printf("Empate!\n");

    }
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }
    
    
    printf("Comparação final dos estados:\n");
    printf("Escolha o primeiro atributo\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - Densidade Populacional\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Escolha uma comparação:\n");
    scanf("%d", &primeiroAtributo);

    switch (primeiroAtributo)
    {
    case 1:
       
        if ((resultado1 == populacao1 > populacao2 ? 1 : 0))
        {
            printf("População 1 venceu! %d\n", populacao1);
        } else if ((resultado1 == populacao1 < populacao2 ? 1 : 0))
        {
            printf("População 2 venceu! %d\n", populacao2);
        } else {
            printf("Empate!\n");
        }
        break;
    
    case 2:
        if ((resultado1 == Area1 > Area2 ? 1 : 0))
        {
            printf("Área 1 venceu! %f\n", Area1);
        } else if ((resultado1 == Area1 < Area2 ? 1 : 0))
        {
            printf("Área 2 venceu! %f\n", Area2);
        } else {
            printf("Empate!\n");
        }
        break;
    
    case 3:
        if ((resultado1 == PIB1 > PIB2 ? 1 : 0))
        {
            printf("Pib 1 venceu! %f\n", PIB1);
        } else if ((resultado1 == PIB1 < PIB2 ? 1 : 0))
        {
            printf("Pib 2 venceu! %f\n", PIB2);
        } else {
            printf("Empate!\n");
        }
        break;
    
    case 4:
       if ((resultado1 == pontos1 > pontos2 ? 1 : 0))
        {
            printf("Pontos 1 venceu! %d\n", pontos1);
        } else if ((resultado1 == pontos1 < pontos2 ? 1 : 0))
        {
            printf("Pontos 2 venceu! %d\n", pontos2);
        } else {
            printf("Empate!\n");
        }
        break;
    
    case 5:
        if ((resultado1 == DP1 < DP2 ? 1 : 0))
        {
            printf("DP 1 venceu! %f\n", DP1);
        } else if ((resultado1 == DP1 > DP2 ? 1 : 0))
        {
            printf("DP 2 venceu! %d\n", DP2);
        } else {
            printf("Empate!\n");
        }
        break;
    
    default:
        printf("Opção inválida!\n");
        break;
    }

    

    printf("Escolha o segundo atributo\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - Densidade Populacional\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Escolha uma comparação:\n");
    scanf("%d", &segundoAtributo);


    switch (segundoAtributo)
    {
    case 1:
        
        if ((resultado2 == populacao1 > populacao2 ? 1 : 0))
        {
            printf("População 1 venceu! %d\n", populacao1);
        } else if ((resultado1 == populacao1 < populacao2 ? 1 : 0))
        {
            printf("População 2 venceu! %d\n", populacao2);
        } else {
            printf("Empate!\n");
        }
        break;
    
    case 2:
        if ((resultado2 == Area1 > Area2 ? 1 : 0))
        {
            printf("Área 1 venceu! %f\n", Area1);
        } else if ((resultado1 == Area1 < Area2 ? 1 : 0))
        {
            printf("Área 2 venceu! %f\n", Area2);
        } else {
            printf("Empate!\n");
        }
        break;
    
    case 3:
        if ((resultado2 == PIB1 > PIB2 ? 1 : 0))
        {
            printf("Pib 1 venceu! %f\n", PIB1);
        } else if ((resultado1 == PIB1 < PIB2 ? 1 : 0))
        {
            printf("Pib 2 venceu! %f\n", PIB2);
        } else {
            printf("Empate!\n");
        }
        break;
    
    case 4:
       if ((resultado2 == pontos1 > pontos2 ? 1 : 0))
        {
            printf("Pontos 1 venceu! %d\n", pontos1);
        } else if ((resultado1 == pontos1 < pontos2 ? 1 : 0))
        {
            printf("Pontos 2 venceu! %d\n", pontos2);
        } else {
            printf("Empate!\n");
        }
        break;
    
    case 5:
        if ((resultado2 == DP1 < DP2 ? 1 : 0))
        {
            printf("DP 1 venceu! %f\n", DP1);
        } else if ((resultado1 == DP1 > DP2 ? 1 : 0))
        {
            printf("DP 2 venceu! %d\n", DP2);
        } else {
            printf("Empate!\n");
        }
        break;
    
    default:
        printf("Opção inválida!\n");
        break;
    }

    if (resultado1 > resultado2)
    {
        printf("estado 1 venceu! %c\n", estado1);
    } else if (resultado1 < resultado2)
    {
        printf("estado 2 venceu! %c\n", estado2);
    } else {
        printf("Empate!\n");
    }
    
    
    return 0;

    
    
    
    

  
    

    

    
   
}
