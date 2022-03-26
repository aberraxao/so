#include <stdio.h>
#include "ex4.h"

int main()
{

    /*
    int n;
    printf("Tabuada do ? ");
    scanf("%d", &n);
    tabuada(n);
    */
    /*
    int w, h;
    printf("Retângulo w = ");
    scanf("%d", &w);
    printf("Retângulo h = ");
    scanf("%d", &h);
    retangulo(w, h);
    */

    numeros10();
    // numeros100();
}

void tabuada(int n)
{
    // Escreve a tabuada
    for (int i = 0; i <= 10; i++)
        printf("%d x %d = %d\n", n, i, n * i);
}

void retangulo(int w, int h)
{
    // Desenha um retângulo com um dado comprimento w e uma altura h
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            if (j == 0 || j == w - 1 || i == 0 || i == h - 1)
                printf("x");
            else
                printf(" ");
        printf("\n");
    }
}

void numeros10()
{
    // Lê 10 números e escreve-os por ordem inversa
    int N = 10;
    int n[N];

    printf("Escreva %d números:\n", N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &n[i]);
    }

    printf("\nPor ordem inversa:\n");
    for (int i = N; i > 0; i--)
        printf("%d", n[i - 1]);

    printf("\nO número máximo é: %d\n", maior(n, N));

    float med = media(n, N);
    printf("A média é: %f\n", med);

    int nmaior = 0;
    for (int i = 0; i < N; i++)
        if (n[i] > med)
            nmaior++;
    printf("Existem %d números maiores que a média\n", nmaior);

    sort(n, N );
    printf("Lista ordenada:\n");
    for(int i=0; i<N; i++) 
        printf("%d ", n[i]);
    printf("\n");
}

void sort(int numeros[], int N)
{
    // Ordena N números
    for (int j = N - 1; j > 0; j--)
        for (int i = 0; i < j; i++)
            if (numeros[i] > numeros[i + 1])
            {
                int tmp = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = tmp;
            }
}

float media(int numeros[], int N)
{
    // Calcula a média de N números
    float media = numeros[0];
    for (int i = 1; i < N; i++)
        media += numeros[i];
    media /= N;

    return media;
}

int maior(int numeros[], int N)
{
    // Calcula o maior de N números
    int max = 0;
    for (int i = 0; i < N; i++)
        if (numeros[i] > max)
            max = numeros[i];

    return max;
}

void numeros100()
{
    printf("Escreve os números de 1 a 100, 10 em cada linha:\n");
    for (int i = 1; i <= 100; i++)
    {
        printf("%d ", i);
        if (i % 10 == 0)
            printf("\n");
    }

    printf("\nEscreve os números primos entre 1 e 100\n");
    for (int i = 2; i <= 100; i++)
        if (primoQ(i) == 1)
            printf("%d ", i);
}

int primoQ(int N)
{
    // Verifica se um número é primo
    for (int i = 2; i <= N / 2; i++)
    {
        if (N % i == 0)
            return 0;
    }
    return 1;
}
