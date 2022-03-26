#include <stdio.h>

int main()
{
    int a, b;
    printf("Diga dois numeros: ");
    scanf("%d", &a);
    scanf("%d", &b);

    // Soma 2 números
    printf("%d + %d = %d\n", a, b, a + b);

    // Imprime o maior número
    printf("O maior número é %d\n", (a > b) ? a : b);
    
    // Ordena 2 números
    if (a > b)
        printf("%d < %d\n", b, a);
    else if (a < b)
        printf("%d < %d\n", a, b);
    else
        printf("%d = %d\n", a, b);

    return 0;
}