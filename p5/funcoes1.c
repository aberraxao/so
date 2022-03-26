#include <stdio.h>

#include "funcoes.h"

void main()
{
    int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int N = 50;

    printf("Existem %d números primos até %d.\n", contaprimos(N), N);
    printf("O número mínimo é:  %d.\n", minimo(numeros, 10));
    printf("O número mínimo é:  %d.\n", minimo2(numeros, 10));
}

int primoQ(int n)
{
    // Verifica se um número é primo
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int contaprimos(int n)
{
    // Dado um número inteiro, devolve o número de primos até esse número.
    int nprimos = 0;
    for (int i = 2; i <= n; i++)
    {
        if (primoQ(i))
            nprimos++;
    }

    return nprimos;
}

int minimo(int v[], int N)
{
    // Devolve o valor mínimo num array de inteiros
    int min = v[0];
    for (int i = 1; i < N; i++)
        if (v[i] < min)
            min = v[i];

    return min;
}

int minimo2(int v[], int N)
{
    // Devolve o valor mínimo num array de inteiros usando um algoritmo recursivo
    int min = v[0];
    if (N > 1)
    {
        int tmp = minimo2(&v[1], N - 1);
        if (tmp < min)
            min = tmp;
    }

    return min;
}
