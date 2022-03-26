#include <stdio.h>
#include "ex4.h"

int main()
{
    int n, w, h;

    printf("Tabuada do ? ");
    scanf("%d", &n);
    tabuada(n);

    printf("Retângulo w = ");
    scanf("%d", &w);
    printf("Retângulo h = ");
    scanf("%d", &h);
    retangulo(w, h);
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