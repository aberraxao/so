#include <stdio.h>
#include "ex4.h"

int main()
{
    int n;
    printf("Tabuada do ? ");
    scanf("%d", &n);
    tabuada(n);
}

void tabuada(int n)
{
    // Escreve a tabuada
    for (int i = 0; i <= 10; i++)
        printf("%d x %d = %d\n", n, i, n * i);
}