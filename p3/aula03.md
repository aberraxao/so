# Aula Prática 3

### 0.1 Introdução

Utilize o `vi` ou outro editor de texto para criar o ficheiro `p1.sh`

```bash
#!/bin/bash
echo "consegui"
date
cal
pwd
echo "adeus"
```

```bash
rfonseca@tigre:~$ cd aula03
rfonseca@tigre:~/aula03$ vi p1.sh
```

Dê permissões de execução ao ficheiro:

```bash
rfonseca@tigre:~/aula03$ chmod +x p1.sh
```
Depois de dar permissões de execução ao ficheiro, execute os comandos da seguinte sequência e explique os resultados obtidos.

```
rfonseca@tigre:~/aula03$ ./p1.sh 
consegui
Mon Sep 21 16:19:16 WEST 2020
   September 2020
Su Mo Tu We Th Fr Sa
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30

/home/rfonseca/aula03
adeus
```
Quando não indicamos o "_path_" até ao comando a _shell_ não o consegue encontrar, mesmo que esteja na mesma directoria:

```
rfonseca@tigre:~/aula03$ p1.sh
-bash: p1.sh: command not found
```

Se adicionarmos a directoria `.` (que representa a directoria local) à variável `PATH` global, então o comando já é encontrado:

```
rfonseca@tigre:~/aula03$ PATH=$PATH:.
rfonseca@tigre:~/aula03$ echo $PATH
/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/opt/bin:.
rfonseca@tigre:~/aula03$ p1.sh
consegui
Mon Sep 21 16:26:54 WEST 2020
   September 2020
Su Mo Tu We Th Fr Sa
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30

/home/rfonseca/aula03
adeus
```

### 0.2 Variáveis

Verifique o resultado de cada um dos seguintes comandos

```bash
rfonseca@tigre:~/aula03$ echo $USER
rfonseca

rfonseca@tigre:~/aula03$ so="Sistemas Operativos"

rfonseca@tigre:~/aula03$ x=3

rfonseca@tigre:~/aula03$ echo $so $x
Sistemas Operativos 3

rfonseca@tigre:~/aula03$ echo $so$x
Sistemas Operativos3

rfonseca@tigre:~/aula03$ echo $so3

rfonseca@tigre:~/aula03$ echo ${so}3
Sistemas Operativos3

rfonseca@tigre:~/aula03$ echo $x+10
3+10

rfonseca@tigre:~/aula03$ echo $(($x+10))
13

```

## 1. Argumentos

Crie o script `verargs` e dê-lhe permissões de execução:

```bash
#!/bin/bash
echo "Arg1: $1"
echo "Arg2: $2"
echo "Arg4: $4"
echo "Arg11: ${11}"
echo "eu sou o $0 e foram usados $# argumentos"
```

```bash
rfonseca@tigre:~/aula03$ chmod +x verargs
rfonseca@tigre:~/aula03$ ./verargs
Arg1:
Arg2:
Arg4:
Arg11:
eu sou o ./verargs e foram usados 0 argumentos
```
Experimente o script anterior das seguintes formas:

```bash
rfonseca@tigre:~/aula03$ ./verargs alberto bruno carlos dalila e f g h i j k l
Arg1: alberto
Arg2: bruno
Arg4: dalila
Arg11: k
eu sou o ./verargs e foram usados 12 argumentos

rfonseca@tigre:~/aula03$ ./verargs 1 2 3 4 5 6 7 8 9 10 11 12
Arg1: 1
Arg2: 2
Arg4: 4
Arg11: 11
eu sou o ./verargs e foram usados 12 argumentos

rfonseca@tigre:~/aula03$ ./verargs ~
Arg1: /home/rfonseca
Arg2:
Arg4:
Arg11:
eu sou o ./verargs e foram usados 1 argumentos

rfonseca@tigre:~/aula03$ ./verargs *
Arg1: p1.sh
Arg2: verargs
Arg4:
Arg11:
eu sou o ./verargs e foram usados 2 argumentos

rfonseca@tigre:~/aula03$ ./verargs eu sou o $USER
Arg1: eu
Arg2: sou
Arg4: rfonseca
Arg11:
eu sou o ./verargs e foram usados 4 argumentos

rfonseca@tigre:~/aula03$ ./verargs "eu sou o $USER"
Arg1: eu sou o rfonseca
Arg2:
Arg4:
Arg11:
eu sou o ./verargs e foram usados 1 argumentos

rfonseca@tigre:~/aula03$ ./verargs 'eu sou o $USER'
Arg1: eu sou o $USER
Arg2:
Arg4:
Arg11:
eu sou o ./verargs e foram usados 1 argumentos

rfonseca@tigre:~/aula03$ ./verargs $NADA nao existe
Arg1: nao
Arg2: existe
Arg4:
Arg11:
eu sou o ./verargs e foram usados 2 argumentos

rfonseca@tigre:~/aula03$ ./verargs "$NADA" pode existir
Arg1:
Arg2: pode
Arg4:
Arg11:
eu sou o ./verargs e foram usados 3 argumentos

```

## 2. Estruturas de controlo

### 2.1. Crie o script `nomes.sh`

```bash
#!/bin/bash
echo -n "diga o nome: "
read nome
if echo $nome >> nomes.txt ; then
	echo "o nome $nome foi guardado"
else
	echo "Problemas ao guardar $nome"
fi
```

```bash
rfonseca@tigre:~/aula03$ chmod +x nomes.sh
```



__2.1.(a)__ Execute o programa várias vezes e verifique o conteúdo do ficheiro `nomes.txt`:

```bash
rfonseca@tigre:~/aula03$ ./nomes.sh
diga o nome: Ricardo
o nome Ricardo foi guardado

rfonseca@tigre:~/aula03$ cat nomes.txt
Ricardo

rfonseca@tigre:~/aula03$ ./nomes.sh
diga o nome: João
o nome João foi guardado

rfonseca@tigre:~/aula03$ ./nomes.sh
diga o nome: Rui
o nome Rui foi guardado

rfonseca@tigre:~/aula03$ cat nomes.txt
Ricardo
João
Rui
```
__2.1.(b)__ Retire as permissões de escrita ao ficheiro `nomes.txt`, execute novamente o _script_ e comente o resultado obtido.

```bash
rfonseca@tigre:~/aula03$ chmod -w nomes.txt

rfonseca@tigre:~/aula03$ ./nomes.sh
diga o nome: Ana
./nomes.sh: line 4: nomes.txt: Permission denied
Problemas ao guardar Ana
```

Uma vez que não temos permissão de escrita sobre o ficheiro `nomes.txt` o _script_ falha com um erro `Permission denied`.

### 2.2 Crie o script `verifica.sh`

```bash
#!/bin/bash
if [ -f $1 ]; then
	  echo "$1 existe"
else
	  echo "$1 não existe"
fi
```

```bash
rfonseca@tigre:~/aula03$ chmod +x verifica.sh
```



__2.2.(a)__ Qual é o resultado de execução dos seguintes comandos?

```bash
rfonseca@tigre:~/aula03$ ./verifica.sh maria
maria não existe

rfonseca@tigre:~/aula03$ ./verifica.sh verifica.sh
verifica.sh existe

```

__2.2.(b)__ Altere o _script_ de forma a que, caso o ficheiro exista, indique também se é executável.

Alterando o código de `verifica.sh` para:

```bash
#!/bin/bash
if [ -f $1 ]; then
    echo "$1 existe"
    if [ -x $1 ]; then
	      echo "e é executável"
    fi
else
    echo "$1 não existe"
fi

```

temos agora:

```bash
bash-3.2$ ./verifica.sh nomes.txt
nomes.txt existe

bash-3.2$ ./verifica.sh verifica.sh
verifica.sh existe
e é executável
```

No entanto o script ainda pode ser melhorado porque se o chamarmos sem nenhum parâmetro acontece isto:

```
rfonseca@tigre:~/aula03$ ./verifica.sh
 existe
e é executável
```

Uma versão melhorada que verifica que temos exatamente um parâmetro na linha de comandos pode ser:

```bash
#!/bin/bash
if [ $# -eq 1 ]; then
    if [ -f $1 ]; then
        echo "$1 existe"
        if [ -x $1 ]; then
              echo "e é executável"
        fi
    else
        echo "$1 não existe"
    fi
else
    echo "SYNTAX: $0 <filename>"
fi
```

 _Nota_: A variável `$#` contém o número de parâmetros fornecidos.

Se testarmos agora o programa obtemos:

```
rfonseca@tigre:~/aula03$ ./verifica.sh 
SYNTAX: ./verifica.sh <filename>
rfonseca@tigre:~/aula03$ ./verifica.sh ricardo
ricardo não existe
rfonseca@tigre:~/aula03$ ./verifica.sh verifica.sh 
verifica.sh existe
e é executável
```



### 3. Crie o script `tabuada.sh` que permite escrever a tabuada de um número entre 1 e 9

_nota_: O caracter `#` cria um comentário de uma linha.

__Versão 0__: Não valida o parâmetro fornecido

```bash
#!/bin/bash

# Imprime a tabuada entre 1 e 10
i=1
while [ $i -le 10 ]; do
    echo " $1 x $i = $(($1*$i))"
    i=$(( $i+1 ))
done
```



__Versão 1__: Garante que o parâmetro fornecido é um número inteiro entre 1 e 9

```bash
#!/bin/bash

# Verifica se exactamente 1 parametro foi fornecido
if [ $# -ne 1 ]; then
    echo "Utilização: $ tabuada.sh valor"
    echo "em que valor deve ser um número inteiro entre 1 e 9"
    exit -1
fi

# Verifica se o parâmetro é um número inteiro
if ! [[ "$1" =~ ^[0-9]+$ ]]; then
    echo "Erro, o valor deve ser um número inteiro positivo"
    exit -2
fi

# Verifica se o valor está entre 1 e 9
if (( $1 < 1 || $1 > 9 )); then
    echo "Erro, o valor deve ser entre 1 e 9"
    exit -3
fi

# Imprime a tabuada entre 1 e 10
i=1
while [ $i -le 10 ]; do
    echo " $1 x $i = $(($1*$i))"
    i=$(( $i+1 ))
done
```

```
rfonseca@tigre:~/aula03$ ./tabuada.sh 7
 7 x 1 = 7
 7 x 2 = 14
 7 x 3 = 21
 7 x 4 = 28
 7 x 5 = 35
 7 x 6 = 42
 7 x 7 = 49
 7 x 8 = 56
 7 x 9 = 63
 7 x 10 = 70
```



### 4. Teste o script `case.sh`

`case.sh`

```bash
#!/bin/bash

echo "eis o que posso dizer sobre o $1"
case $1 in
    boavista) echo "Porto";;
    sporting|benfica) echo "Lisboa";;
    iscte*) echo "Fica em Lisboa";;
    *) echo "desconheço a cidade";;
esac
```



```bash
rfonseca@tigre:~/aula03$ ./case.sh boavista
eis o que posso dizer sobre o boavista
Porto

rfonseca@tigre:~/aula03$ ./case.sh sporting
eis o que posso dizer sobre o sporting
Lisboa

rfonseca@tigre:~/aula03$ ./case.sh iscte
eis o que posso dizer sobre o iscte
Fica em Lisboa

rfonseca@tigre:~/aula03$ ./case.sh algarve
eis o que posso dizer sobre o algarve
desconheço a cidade

rfonseca@tigre:~/aula03$ ./case.sh almada
eis o que posso dizer sobre o almada
desconheço a cidade

rfonseca@tigre:~/aula03$ ./case.sh
eis o que posso dizer sobre o
desconheço a cidade
```

**O que acontece se não usar argumentos?**

No caso de não se usar argumentos é feito um _match_ com a última opção `*`, que funciona para todas as opções que não estejam identificadas acima.

### 5. Verifique a execução do script `for.sh`

`for.sh`

```bash
#!/bin/bash
for i in a maria 1 $1 2 "Pedro e Paulo" *.sh; do
    echo "Elemento: $i"
done
```

```
rfonseca@tigre:~/aula03$ ./for.sh
Elemento: a
Elemento: maria
Elemento: 1
Elemento: 2
Elemento: Pedro e Paulo
Elemento: case.sh
Elemento: for.sh
Elemento: nomes.sh
Elemento: p1.sh
Elemento: tabuada.sh
Elemento: verifica.sh
```

 ### 6. Desenvolva o programa `guess.sh`

O programa deve gerar um número aleatório, usando a variável `$RANDOM`, e pedir ao utilizador para adivinhar esse número. A cada tentativa, o programa deverá indicar se o número introduzido é "muito pequeno", "muito grande" ou se "acertou". No final deverá ser indicado o número de tentativas usadas.

```bash
#!/bin/bash

# Gerar número aleatório entre 1 e 100
n=$(( $RANDOM % 100 + 1 ))

# Número da tentativa
i=1

echo "Estou a pensar num número entre 1 e 100. Quer adivinhar?"
echo ""

# Continuar o loop até o utilizador adivinhar
while :; do
    echo "Introduza a sua tentativa #$i (0 para desistir):"
    read guess

    # Se acertar ou desistir sair do loop
    if [[ $guess == $n  ||  $guess == 0 ]]; then
        break
    fi

    if (( guess < n )); then
        echo "muito pequeno"
    else
        echo "muito grande"
    fi

    i=$(( i + 1 ))
done

if (( guess == 0 )); then
    echo "Não adivinhou em $i tentativas, o número era $n."
else
    echo "Parabéns, acertou em $i tentativas!"
fi
```

_Nota_:

De acordo com a _manpage_ do `bash`, relativamente à variável `$RANDOM`: "__RANDOM__ Each time this parameter is referenced, a random integer between 0 and 32767 is generated.  (...)"

Para convertermos este número num número entre 1 e _M_ podemos utlizar a operação `%` que devolve o resto de uma divisão inteira e somar 1, _i.e._, `n=$(( $RANDOM % $M + 1 ))` 

