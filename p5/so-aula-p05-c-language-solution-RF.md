# Sistemas Operativos - Aula Prática 5

## Introdução à linguagem C

Depois da discussão sobre programação em `shell`, na aula de hoje vamos fazer uma breve introdução à linguagem C que está na base dos sistemas operativos UNIX. Contrariamente à programação em `shell` os programas em `C` não são interpretados, i.e., não são processados por um outro programa (e.g. `/bin/bash`) em tempo de execução.

Para executarmos um programa escrito em `C` devemos em primeiro lugar compilar o programa, o que significa traduzir a linguagem `C` para instruções em código máquina que podem ser executadas diretamente pelo computador/sistema operativo. Estes "binários" são extremamente eficientes, permitindo um processamento mais rápido e utilizando menos memória que outros programas equivalentes noutras linguagens. Em contrapartida, a linguagem `C` é deliberadamente sucinta, o que torna a programação de certas tarefas mais complicada.

A linguagem `C` inclui ainda vários módulos adicionais que podemos utilizar nos nossos programas para expandir a sua funcionalidade. Para utilizarmos as funcionalidades definidas nesses módulos devemos incluir o _header file_ correspondente fazendo `#include <header_name.h>`, e.g.:

```C
// Inclui o header file relativo ao "Standard Input Output"
// que inclui as funções printf(), scanf(), etc.
#include <stdio.h>
```

### Compilar e executar um programa em C

Para compilar e executar um programa em `C` precisaremos então de utilizar um **compilador** para o efeito. Nesta cadeira vamos usar o GCC (<https://gcc.gnu.org>), um compilador gratuito e *open-source* utilizado por milhões de *developers* pelo mundo fora, e que se tornou o compilador de referência para a linguagem `C`.

Crie o seguinte ficheiro:

 `hello_world.c`

```C
#include <stdio.h>
int main() {
    printf("Hello World!\n");
}
```

Compile e execute o programa:

```bash
rfonseca@tigre:~/aula05$ gcc hello_world.c -o hello
rfonseca@tigre:~/aula05$ ./hello
Hello World!
```

O compilador `gcc` transforma então o programa em C (`hello_world.c`) num ficheiro binário (`hello`) e liga automaticamente a permissão de executar para este ficheiro (não sendo portanto necessário recorrer a uma operação do tipo `chmod +x hello`).

## 1. Tipos de dados e impressão

Tal com outras linguagens, o `C` obriga a que as várias tenham um tipo pré-definido que não pode ser alterado em execução. Para a aula de hoje vamos focar-nos em 3 dos tipos básicos do `C`:

* `int` - Define um valor numérico inteiro. Dependendo do sistema pode ter valores na gama `[-32768 .. 32767]` (16 bits) ou `[-2147483648 .. 2147483647]` (32 bits)
* `float` - Define um valor de vírgula flutuante (aproximação a um número real) na gama `~ [1.2E-38 .. 3.4E+38]` (incluindo 0 e sinal)
* `char`- Define um valor do tipo caracter, e.g. `'a'`

Para imprimirmos mensagens e o conteúdo de variáveis utilizamos o comando `printf()`, definido no header `<stdio.h>`. A sintaxe do comando é:

```c
int printf(const char * restrict format, ...);
```

Em que `format` é uma _string_ que especifica o formato do output, incluindo instruções sobre como deve tratado cada um dos valores fornecidos, indicados por "especificadores de conversão" que começam pelo caracter `%`. Por exemplo usando a sintaxe seguinte:

```C
printf("A divisão de %d por %d é %f\n", a, b, r );
```

Informamos o comando `printf()` que pretendemos imprimir a mensagem especificada ("A divisão de ...") e que esta inclui dois números inteiros, `%d`, e um número de vírgula flutuante, `%f`.

### 1.1 Inteiros, números de vírgula flutuante e vectores (arrays)

Compile e execute o seguinte programa:

`ex1.c`

```C
#include <stdio.h>
int main () {
    int a=10, b=3;
    float r;
    int v[4] = {2, 6, -9, 78};
    r = (float)a / b;
    printf("A divisão de %d por %d é %f\n", a, b, r );
  
    int x = (b > 2);
    printf("valor de x : %d\n", x);
}
```

```bash
rfonseca@tigre:~/aula05$ gcc ex1.c -o ex1
rfonseca@tigre:~/aula05$ ./ex1
A divisão de 10 por 3 é 3.333333
valor de x : 1
```

### 1.1.a) Altere a _string_ de formato do `printf()` para que o resultado seja exatamente

`A divisão de    10 por 00003 é 3.33`

O comando `printf()` permite controlar detalhadamente a formatação do _output_ modificando as especificações de conversão:

* `%5d` - Imprime um número inteiro ocupando 5 espaços (alinhado à direita)

* `%05d` - Imprime um número inteiro ocupando 5 espaços preenchendo as casas à esquerda com `0`
* `%4.2f` - Imprime um número de virgula flutuante ocupando 4 espaços no total, incluindo 2 casas decimais.

O resultado pretendido pode ser então obtido fazendo:

```C
printf("A divisão de %5d por %05d é %4.2f\n", a, b, r );
```

### 1.1.b) mostre a 3.ª posição do array `v[]`

Os vários elementos de um array podem ser acedidos utilizando a notação `v[i]`, em que `i` é um número inteiro que especifica a posição dentro do array. Em `C` a primeira posição corresponde a `v[0]`:

```C
#include <stdio.h>

int main () {
    int a =10, b=3;
    float r;
    int v[4] = {2, 6, -9, 78};
    r = (float)a / b;

    // (a) Altere o formato de impressão
    printf("A divisão de %5d por %05d é %4.2f\n", a, b, r );

    int x = (b > 2);
    printf("valor de x : %d\n", x);
 
    // (b) mostre a 3a posição do array
    // Como contamos a partir de 0 a 3.ª posição corresponde ao 2
    printf("valor de v[2] = %d\n", v[2]);
}
```

```bash
rfonseca@tigre:~/aula05$ gcc ex1.c
rfonseca@tigre:~/aula05$ ./a.out
A divisão de    10 por 00003 é 3.33
valor de x : 1
valor de v[2] = -9
```

## 2. Leitura de parâmetros - `scanf()`

A função mais utilizada em `C` para ler valores dos mais diversos tipos a partir da consola (_standard input_ ou `stdin`) é o `scanf()` (`<stdio.h>`):

```C
int scanf(const char *restrict format, ...);
```

Tal como no comando `printf()` o parâmetro `format` especifica o tipo de valores e a sua formatação. Os parâmetros seguintes especificam onde estes valores devem ser guardados, e.g.:

```C
int a;
printf("Diga um numero: ");
scanf("%d", &a);
```

Note-se que o `scanf()` **espera** como parâmetro não a variável onde o valor deve ser guardado, mas sim **o endereço de memória** onde a variável reside, que deve ser obtido utilizando o prefixo `&` antes do nome da variável.

### 2.1 Execute o programa (`ex2.c`) e analise o seu efeito

`ex2.c`

```C
#include <stdio.h>

int main() {
    int a, b;
    printf("Diga dois numeros: ");

    scanf("%d", &a);
    scanf("%d", &b);
    
    printf("%d + %d = %d\n", a, b, a + b );
}
```

```bash
rfonseca@tigre:~/aula05$ gcc ex3.c
rfonseca@tigre:~/aula05$ ./a.out
Diga dois numeros: 12 14
12 + 14 = 26
```

O programa lê 2 números inteiros do _standard input_ ( `stdin` ) e apresenta a sua soma.

## 3. Estruturas de controle `if-then-else`

O `C` implementa estruturas de controle `if-then-else` semelhantes a outras linguagens usando a seguinte sintaxe:

```C
if (condicao) {
   // verdadeiro
} else {
   // falso
}
```

O valor de `condicao` controla que segmento de código é executado, sendo que o valor `0` é considerado como sendo falso, e todos os outros valores como sendo verdadeiros. Note-se ainda que a secção `else` é opcional.

O `C` inclui ainda o chamado "operador condicional" que permite simplificar situações em que o resultado da estrutura é a atribuição de um valor diferente consoante a condição, e.g.

```C
if ( test ) {
    a = 1;
} else {
    a = 2;
}

// equivalente à estrutura anterior 
a = (test) ? 1 : 2;
```

### 3.1 Altere o programa `ex2.c` de forma a

#### 3.1.a) Escrever o maior dos dois números

#### 3.1.b) Escrever os dois números por ordem

```C
#include <stdio.h>

int main() {
    int a, b;
    printf("Diga dois numeros: ");

    scanf("%d", &a);
    scanf("%d", &b);
    
    printf("%d + %d = %d\n", a, b, a + b );
    
    // (a) Escrever o maior número
    printf("O maior número é %d\n", (a>b) ? a : b);
    
    // (b) Escrever os números por ordem
    if ( a > b ) {
        printf("%d, %d\n", b, a);
    } else {
        printf("%d, %d\n", a, b);
    }
}
```

## 4 - Ciclos `while` e `for`

O `C` disponibiliza vários tipos de ciclos, sendo os mais habituais os ciclos `while` e os ciclos `for`.

A sintaxe dos ciclos `while` é a seguinte:

```C
while ( test ) {
   // corpo do ciclo
}
```

Enquanto o valor da expressão `test` for verdadeiro o ciclo será repetido, e.g.:

```C
// Imprime os números de 1 a 5
int a = 1;
while (a <= 5) {
    printf("%d\n",a);
    a++;
}
```

Os ciclos `for` permitem especificar de forma mais compacta a inicialização, teste e incremento do ciclo:

```C
for( expr1; expr2; expr3 ) {
    // corpo do ciclo
}
```

A expressão `expr1` é executada antes do início do ciclo (incialização); o ciclo será repetido enquanto a expressão `expr2` for verdadeira (teste); no final de cada iteração, e antes da `expr2` ser avaliada é executada a `expr3` (incremento). O exemplo anterior ficaria:

```C
for( int a = 1; a <= 5; a++ ) printf("%d\n",a);
```

Note-se que os ciclos `for` do `C` são diferentes dos ciclos `for` em `shell`.  Existe ainda um terceiro tipo de ciclo em `C`, o `do {} while( test )`, fica para exercício perceber o seu funcionamento.

### 4.1 Faça um programa que escreva a tabuada do 5

`ciclo41.c`

```C
#include <stdio.h>

int main () {
    int i = 1;
    while (i <= 10 ) {
        printf(" 5 x %2d = %2d\n", i, 5*i );
        i++;
    }
}
```

### 4.2 Escrever os números de 1 a 100 (dez em cada linha)

`ciclo42.c`

```C
#include <stdio.h>

int main () {
    for( int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++ ) {
            printf("%3d ", i+(10*j)+1);
        }
        printf("\n" );
    }
}
```

### 4.3 Ler 10 números, calcular a média e contar quantos são maiores que a média

`ciclo43.c`

```C
#include <stdio.h>

#define N 10

int main () {
    float buffer[10];

    printf("Introduza %d números:\n", N);

    for(int i=0; i<N; i++) {
        printf("%d : ", i+1);
        scanf( "%f", &buffer[i]);
    }

    float media = buffer[0];
    for(int i=1; i < N; i++) media += buffer[i];
    media /= N;
    printf("Média : %f\n", media );

    int nmaior = 0;
    for(int i=0; i < N; i++)
        if ( buffer[i] > media ) nmaior++;
    printf("Existem %d números maiores que a média\n", nmaior );
}
```

## 5. Funções em C

Uma função é um grupo de instruções que em conjunto realizam alguma tarefa. As funções em `C` podem aceitar um número arbitrário de parâmetros e opcionalmente devolver um resultado no final. Todos os programas em `C` têm pelo menos uma função `main()` que corresponde ao corpo principal do programa.

A sintaxe para a implementação de uma função em `C` é:

```C
tipo_retorno nome_funcao( [lista parametros] ) {
    // corpo da função
}
```

* `tipo_retorno` - identifica o tipo do valor devolvido pela função utilizando o comando `return val;`. Caso a função não retorne nenhum valor devemos especificar como tipo `void`.
* `nome_funcao` - O nome utilizado para chamar a função, fazendo `nome_funcao(...)`
* `lista parametros` - [opcional] A lista dos parâmetros aceites pela função, na forma `tipo1 var1, tipo2 var2, ...`

Por exemplo, uma função que devolva o maior de dois números inteiros poderia ser definida como:

```C
int maxint( int i1, int i2 ) {
    return (i1>i2)?i1:i2;
}

(...)

int a,b;
a = 10;
b = 11;
printf("O valor máximo é %d\n", maxint(a,b));
```

### 5.1 Defina a função `int primoQ(int N)`, que dado um número inteiro devolve verdadeiro, se o número é primo, e falso contrário

```C
/**
 * Verifica se um número é primo
 * @param   n   Número inteiro a verificar
 * @returns 1 se for primo, 0 se não for
 */
int primoQ( int n ) {
    for( int i = 2; i <= n/2; i++ ) {
        if ( n % i == 0 ) return 0;
    }
    return 1;
}
```

### 5.2 Defina a função `int contaprimos(int N)`, que dado um número inteiro, devolve o número de primos até esse número

```C
/**
 * Dado um número inteiro, devolve o número de primos
 * até esse número.
 * @param   n   Número limite
 * @returns número de primos até n
 */
int contaprimos( int n ) {
    int nprimos = 0;
    for( int i = 2; i <= n; i++ ) {
        if ( primoQ(i) ) nprimos++;
    }
    return nprimos;
}
```

### 5.3 Defina a função `int minimo(int v[], int comp)`, que dado um vector de inteiros, devolve o mínimo do vector, de forma imperativa

```C
/**
 * Devolve o valor mínimo num array de inteiros
 * @param   v       Array de inteiros
 * @param   comp    Dimensão do array
 * @returns o valor mínimo no array
 */
int minimo( int v[], int comp ) {
    int min = v[0];
    for( int i = 1; i < comp; i++ )
        if ( v[i] < min ) min = v[i];   
    return min;
}
```

### 5.4 Defina a função `int minimo2(int v[], int comp)`, que faz o mesmo de forma recursiva

```C
/**
 * Devolve o valor mínimo num array de inteiros
 * usando um algoritmo recursivo
 * @param   v       Array de inteiros
 * @param   comp    Dimensão do array
 * @returns o valor mínimo no array
 */
int minimo2( int v[], int comp ) {
    int min = v[0];
    if ( comp > 1 ) {
        int tmp = minimo2( &v[1], comp-1 );
        if ( tmp < min ) min = tmp;
    }
    return min;
}
```

### 5.5 Faça um programa que desenhe um rectângulo

```C
#include <stdio.h>

/**
 * Imprime uma linha com n asteriscos
 * @param   n       Largura da linha
 */
void linha( int n ) {
    for( int i = 0; i < n; i++) printf("*");
    printf("\n");
}

/**
 * Imprime uma linha de dimensão n em que o primeiro
 * e o último caracter são asteriscos, e os restantes
 * caracteres 
 * @param   n       Largura da linha
 */
void col( int n ) {
    printf("*");
    for( int i = 1; i < n-1; i++) printf(" ");
    printf("*\n");
}

int main () {
    int altura = 4;
    int largura = 6;

    linha( largura );
    for( int j = 1; j < altura-1; j++) col( largura );
    linha( largura );
}  
```

### 5.6 Faça um programa que leia 10 números e os escreva por ordem inversa / dizer qual o maior

```C
#include <stdio.h>

#define N 10

/**
 * Devolve o valor máximo num array de inteiros
 * @param   buffer  Array de inteiros
 * @param   size    Dimensão do array
 * @returns         o valor máximo no array
 */
int max( int buffer[], int size ) {
    int max = buffer[0];
    for(int i=1; i<size; i++)
        if ( buffer[i] > max ) max = buffer[i];
    return(max);
}

int main () {
    int buffer[N];

    printf("Introduza %d números:\n", N);

    for(int i=0; i<N; i++) {
        printf("%d : ", i+1);
        scanf( "%i", &buffer[i]);
    }

    printf("\nPor ordem inversa:\n");
    for(int i=N-1; i>0; i--) {
        printf("%d, ", buffer[i]);
    }
    printf("%d\n", buffer[0]);

    // Alínea 4 - Imprimir o maior valor
    printf("Valor máximo: %d\n", max(buffer,N));
}
```

### 5.7 Escrever os números primos entre 1 e 100

```C
#include <stdio.h>

/**
 * Verifica se um número é primo
 * @param   n   Número inteiro a verificar
 * @returns     1 se for primo, 0 se não for
 */
int primoQ( int n ) {
    for( int i = 2; i <= n/2; i++ ) {
        if ( n % i == 0 ) return 0;
    }
    return 1;
}

int main () {
    printf("Números primos entre 1 e 100:\n");
    for( int i = 2; i <= 100; i++) 
        if (primoQ(i)) printf("%3d\n",i);

}
```

### 5.8 Ler 10 números e ordenar

```C
#include <stdio.h>

#define N 10

/**
 * Ordena uma lista de inteiros de forma crescente
 * 
 * Este algoritmo foi implementado de forma a ser o mais simples
 * possível, e não é um bom algoritmo em termos de performance.
 * Para ordenar qualquer array é preferível utilzar as funções
 * `qsort` ou `heapsort` do C
 * 
 * @param   buffer  Array de inteiros a ordenar
 * @param   size    Dimensão do array
 */
void sort( int buffer[], int size ) {

    for( int j = size-1; j > 0; j-- ) {
        for( int i = 0; i < j; i++) {
            if ( buffer[i] > buffer [i+1] ) {
                int tmp = buffer[i];
                buffer[i] = buffer[i+1];
                buffer[i+1] = tmp;
            }
        }
    }
}

int main () {

    int buffer[N];
    printf("Introduza %d números inteiros:\n", N);

    for(int i=0; i<N; i++) {
        printf("%d : ", i+1);
        scanf( "%d", &buffer[i]);
    }

    sort( buffer, N );

    printf("Lista ordenada:\n");
    for(int i=0; i<N-1; i++) 
        printf("%d, ", buffer[i]);
    printf("%d\n", buffer[N-1]);

}
```

## 6 - _Strings_ em C

As _strings_ em C são armazenadas simplesmente como um vector de tipo `char`  terminadas pelo valor `'\0'`, ou seja o valor numérico 0. Por exemplo a string:

`"Sistemas"`

É armazenada em memória da seguinte forma:

_char_ ['S', 'i', 's', 't', 'e', 'm', 'a', 's', __0__]

Ocupando portanto 9 (8+1) espaços de memória. Este vector pode ser inicializado da seguinte forma:

```C
char nome[] = "Sistemas";
```

Atenção que a variável `nome` não contém qualquer informação sobre o tamanho do buffer ou o comprimento da _string_ armazenada; contém apenas o endereço onde está armazenado o primeiro caracter.

Para determinar o comprimento da _string_ podemos usar a função `strnlen()`, incluída no _header_ `<string.h>`. Esta rotina conta todos os caracteres até surgir o valor 0, ou seja poderia ser implementada como:

```C
char nome[] = "Sistemas";
int len = 0;
while (nome[len] != 0) len++;
printf("O comprimento da _string_ '%s' é de %d caracteres\n", nome, len);
```

### 6.1 - Escreva o seguinte programa que pede o primeiro nome, o último nome e a idade

`ex6.c`

```C
#include <stdio.h>
#include <string.h>

int main () {

    // Permite guardar 100 caracteres mais o \0 final
    char nome[101];
    char ultimo[101];
    
    int idade;

    printf("Primeiro nome: ");
    // Com esta sintaxe o scanf lê no máximo 100 caracteres
    scanf("%100s", &nome[0]);
 
    printf("Último nome  : ");
    scanf("%100s", ultimo);
 
    printf("Idade        : ");
    scanf("%i", &idade );
}
```

**Nota**: Quando lemos strings com a função `scanf()`, esta espera o endereço do primeiro caracter da string, que pode ser identificado fazendo `&var[0]` (que é mais claro) ou simplesmente `var` (que é mais compacto). O compilador trata as duas formas da mesma maneira.

#### 6.1.a) Juntar os dois nomes numa _string_ separada por um traço

A função utilizada para juntar duas strings é a função `strncat()`.

#### 6.1.b) Se o resultado for `"ISCTE – IUL"` deve indicar a mensagem `"Nice :)"`

A função utilizada para comparar duas strings é a função `strncmp()`.

#### 6.1.c) Verifique que a alínea (a) pode ser resolvida com a função `snprintf`

`ex6.1.c`

```C
#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main () {

    // Permite guardar 100 caracteres mais o \0 final
    char nome[101];
    char ultimo[101];
    
    int idade;

    printf("Primeiro nome: ");
    // Com esta sintaxe o scanf lê no máximo 100 caracteres
    scanf("%100s", &nome[0]);
 
    printf("Último nome  : ");
    scanf("%100s", ultimo);
 
    printf("Idade        : ");
    scanf("%i", &idade );

/*
   // 6.1.a) Versão strncat
    strncat( nome, " - ", 100 );
    strncat( nome, ultimo, 100 );
    printf("%s\n", nome );
    if ( strncmp( nome, "ISCTE - IUL", 100 ) == 0 )
        printf("Nice :)\n");
*/
  
    // 6.1.c) Versão snprintf
    char completo[101];
    snprintf( completo, 100, "%s - %s", nome, ultimo );
    printf("%s\n", completo );

    // 6.2.b)
   if ( strncmp( completo, "ISCTE - IUL", 100 ) == 0 )
        printf("Nice :)\n");
}
```

### 6.2 -  Processamento de strings

Implemente um programa que leia uma string, conte as vírgulas e transforme as minúsculas em maiúsculas:

`string.c`

```C
#include <stdio.h>
#include <ctype.h>

int main () {
    char buffer[101];

    printf("Introduza _string_ : ");
    scanf("%100[^\n]", buffer);
    
    char* b = &buffer[0];
    int nc = 0;
    while(*b) {
        if ( *b == ',' ) nc++;
        *b = toupper(*b);
        b++;
    }
    
    printf("Em maiúsculas    : %s\n", buffer );
    printf("Núm. de vírgulas : %d\n", nc );
}
```

## Anexo: Leitura de strings

Dada a forma como as strings são armazenadas em C, a sua leitura a partir do _standard input_, que pode corresponder ao teclado ou ao redireccionamento de um outro ficheiro, pode ser realizada sobretudo recorrendo a duas funções distintas: `fgets()` e `scanf()`

### fgets()

A função `fgets()` lê uma linha completa (até encontrar o caracter `'\n'`) a partir de um _stream_. A sintaxe é a seguinte:

```C
 #include <stdio.h>
char *fgets(char * restrict str, int size, FILE * restrict stream);
```

Em que `str` é a _string_ onde é guardado o resultado, `size` a dimensão do buffer onde vamos escrever o resultado e `stream` o canal de onde vamos ler, normalmente `stdin`. Note-se que o caracter  `'\n'` é incluído no resultado:

```txt
Input string [fgets]: Ricardo Fonseca
Resultado:
'R''i''c''a''r''d''o'' ''F''o''n''s''e''c''a''\n'
```

Se este comportamento não for o desejável, devemos substituir esse caracter por `'\0'` para terminar a _string_ mais cedo. O código completo ficaria:

```C
#include <stdio.h>

char buffer[N];
fgets( buffer, N, stdin );
for(int i=0; i < N; i++)
    if (buffer[i]=='\n') { buffer[i]=0; break; }
```

Também é possível recorrer a funções externas, mas neste contexto esta é talvez a maneira mais simples de resolver a situação.

### scanf()

Em alternativa podemos utilizar a função `scanf()`, que já utilizámos para ler números inteiros, com a vantagem de ser possível combinar com a leitura de outros parâmetros. A especificação de um parâmetro de tipo _string_ é feita usando  `%s`:

```C
#include <stdio.h>

char buffer[101];
scanf("%100s", buffer);
```

O número entre o `%` e o `s` especifica o número máximo de caracteres lido e evita _buffer overflows_ (note que deve usar a dimensão do buffer menos 1 para deixar espaço para o caracter  `'\0'` final). Este código tem no entanto uma limitação: o `scanf()` separa os parâmetros por espaços por isso se a _string_ fornecida incluir estes caracteres o resultado pode não ser o esperado:

```txt
Input string [scanf(%100s)]: Ricardo Fonseca
'R''i''c''a''r''d''o'
```

Ou seja, só os caracteres até ao primeiro espaço são considerados. Se quisermos ler todos os caracteres até ao final da linha temos de fazer uma pequena modificação:

```C
scanf("%100[^\n]", buffer);
```

Com esta alteração o `scanf()` lê todos os caracteres até encontrar o caracter `'\n'`:

```txt
Input string [scanf(%100[^\n])]: Ricardo Fonseca
'R''i''c''a''r''d''o'' ''F''o''n''s''e''c''a'
```

### Exemplo

O seguinte programa ilustra todas estas opções. Experimente usando _strings_ com espaços _e.g._ "José Silva".

```C
#include <stdio.h>

/**
 * Imprime o conteúdo duma string, caracter a caracter, substituindo
 * os "caracteres especiais" pela sua "escape sequence" correspondente.
 * A rotina processa no máximo n caracteres.
 * 
 * @param   str     string a imprimir
 * @param   n       Tamanho máximo a processar
 */
void printnstr( const char * str, const int n ) {
    int i = 0;
    while (str[i] && i < n) {
        switch (str[i])
        {
        case '\a': printf("'\\a'"); break;
        case '\b': printf("'\\b'"); break;
        case '\f': printf("'\\f'"); break;
        case '\n': printf("'\\n'"); break;
        case '\r': printf("'\\r'"); break;
        case '\t': printf("'\\t'"); break;
        case '\v': printf("'\\v'"); break;
        
        default: printf("'%c'",str[i]); break;
        }
        i++;
    }
    printf("\n");
}

/*
 * Experimente usando strings com espaços, e.g.:
 * "José Silva"
 */

int main() {
    char buffer[100];

    // Lê a string usando fgets
    printf("Input _string_ [fgets]: ");
    fgets( buffer, 100, stdin );
    printnstr( buffer, 100 );
    // Remove o '\n' do final
    printf("Limpar a string...\n");
    for(int i=0; i < 100; i++)
        if (buffer[i]=='\n') { buffer[i]=0; break; }

    printnstr( buffer, 100 );

    // Lê a string usando scanf(%s)
    printf("\nInput string [scanf(%s)]: ","%99s");
    scanf("%99s", buffer);
    printnstr( buffer, 100 );
    // Este comando é necessário para limpar o input em stdin
    // que não foi processado
    fflush( stdin );

    // Lê a string usando scanf(%[^\n]s);
    printf("\nInput string [scanf(%s)]: ", "%99[^\\n]");
    scanf("%99[^\n]", buffer);
    printnstr( buffer, 100 );
}
```
