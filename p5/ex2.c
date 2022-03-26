#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

#include "ex2.h"

int main()
{
    ex2();
    // ex2_aula();
    return 0;
}

void ex2()
{
    char primeiro_nome[101], ultimo_nome[101], nome[202];
    int idade;

    printf("Primeiro nome: ");
    scanf("%100s", primeiro_nome);

    printf("Último nome: ");
    scanf("%100s", ultimo_nome);
    
    printf("Idade: ");
    scanf("%d", &idade);

    /*
    // 2a
    strncat(primeiro_nome, " - ", 100);
    strncat(primeiro_nome, ultimo_nome, 100);
    printf("Nome completo: %s\n", primeiro_nome);
    */

    // 2b
    if (strcmp(nome, "ISCTE - IUL") == 0)
    {
        printf("Nice :)\n");
    }

    // 2c
    snprintf(nome, 204, "%s - %s", primeiro_nome, ultimo_nome);
    printf("Nome completo: %s\n", nome);
    printf("A minha idade é %d\n", idade);

    // 3 NOTE: Use '' for chars
    int i=0, nb_virgulas=0;
    while(nome[i] != 0){
        if(nome[i] == ',')
            nb_virgulas++;
        nome[i] = toupper(nome[i]);
        i++;
    }

    printf("Número de vírgulas: %d\n", nb_virgulas);
    printf("Nome em maiúsculas : %s\n", nome);
}

void ex2_aula()
{
    char primeiro[100];
    char ultimo[100];

    printf("Primeiro nome: ");
    // scanf("%s", &primeiro);
    fgets(primeiro, 100, stdin);
    primeiro[strlen(primeiro) - 1] = '\0';

    printf("Último nome: ");
    fgets(ultimo, 100, stdin);
    ultimo[strlen(ultimo) - 1] = '\0';

    printf("O meu nome é %s %s.\n", primeiro, ultimo);
}