#include <stdio.h>

void ex1();
void ex2();
void ex3();

int main() {
    // ex1();
    // ex2();
    ex3();
}

void ex1(){
    printf("Este\ntexto\ntorna-se\ncomplexo\0porque\ntem\n\varias\nlinhas");
    int c[5] = {1, 2};
    printf("diana: %d\n", sizeof(c));
}

void ex2(){
    int i=0;
    switch (i)
    {
    case 0: printf("A.");
    case 1: printf("B.");
    default: printf("C.");
    break;
    }
    printf("\n");
}

void ex3(){
    int array[] = {10, 15, 20, 25};
    int i=1;
    int j=2;
    while(i<=j){
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");
}