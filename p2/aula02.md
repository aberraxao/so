# Aula Prática 2

## Introdução

Copie o ficheiro `/home/rfonseca/aula02/lista.txt` para uma diretoria na sua área de trabalho.

### Comandos de processamento de texto:

| Comando | Utilização |
| ------- | ---------- |
| `wc` |  word, line, character, and byte count |
| `tail` | display the last part of a file |
| `head` | display first lines of a file |
| `grep` | file pattern searcher |
| `cut` | cut out selected portions of each line of a file |
| `sort` | sort or merge records (lines) of text and binary files |
| `uniq` | report or filter out repeated lines in a file |
| `tr` | translate characters |
| `sed` | stream editor for filtering and transforming text |
| `awk` | pattern-directed scanning and processing language |


## Parte I

1.1 - Obter o número de linhas do ficheiro

```bash
wc -l  lista.txt
```

1.2 - Mostrar as duas últimas linhas do ficheiro

```bash
tail -n 2 lista.txt
```

1.3 - Mostrar todas as linhas do ficheiro, mas sem as primeiras duas (sem o cabeçalho)

```bash
tail -n +3 lista.txt

tail -n +3 lista.txt > conteudo.txt
```



## Parte II

2.1 - Mostrar as primeiras 3 linhas do ficheiro

```bash
head -n 3 conteudo.txt
```

2.2 - Mostrar as linhas relativas a alunos com numero começado por 5 (cinquenta mil e ...)

```bash
awk '/^5/' conteudo.txt

grep '^5' conteudo.txt
```

2.3 - Mostrar o nome de cada uma das pessoas

```bash
awk '{print $2}' conteudo.txt

cut -f2 -d" " conteudo.txt
```

2.4 - Mostrar o nome e o número

```bash
awk '{print $2,"-", $1}' conteudo.txt

sed 's/\([^ ]*\) \([^ ]*\).*/\2 \1/' conteudo.txt
```

2.5 - Mostrar o nome dos estudantes

```bash
awk '/estudante/ {print $2}' conteudo.txt

grep estudante conteudo.txt | cut -f2 -d" "
```

2.6 - Mostrar o nome dos estudantes do sporting (quem quiser pode fazer do benfica)

```bash
awk '/estudante/ && /sporting/ {print $2}' conteudo.txt

grep estudante conteudo.txt | grep sporting | cut -f2 -d" "
```

2.7 - Mostrar o nome dos estudantes, ordenados por ordem alfabética

```bash
awk '/estudante/ {print $2}' conteudo.txt | sort

grep estudante conteudo.txt | cut -f2 -d" " | sort
```

2.8 - Mostrar a lista de equipas, ordenada e sem repetições

```bash
awk '{print $3}' conteudo.txt | sort | uniq

cat conteudo.txt | cut -f3 -d" " | sort | uniq
```

2.9 - Contar o número de equipas diferentes que estão mencionadas

```bash
awk '{print $3}' conteudo.txt | sort | uniq | wc -l

cat conteudo.txt | cut -f3 -d" " | sort | uniq | wc -l
```

2.10 - Criar um ficheiro a partir deste, no qual "rui" passa a estar com maiúscula

```bash
awk '{sub("rui","Rui")}1' conteudo.txt > Rui.txt

sed 's/rui/Rui/' conteudo.txt > Rui.txt
```

2.11 - Criar um ficheiro com o nome e o número da conta (3.º elemento do NIB)

```bash
awk -F[\ -] '{print $2, $6}' conteudo.txt > contas.txt

awk '{split($4,nib,"-"); print( $2, nib[3]) }' conteudo.txt > contas.txt

cat conteudo.txt | sed "s/.* \(.*\) .* .*\-\(.*\)\-.*/\1 \2/" > contas.txt
```

2.12 - Calcular o maior saldo

```bash
awk 'BEGIN {max = -1} {if ($6 > max) max = $6;} END {print max}' conteudo.txt

cut -f6 -d" " conteudo.txt | sort -n | tail -1
```

2.13  - Ver o nome de quem tem maior saldo

```bash
awk 'BEGIN {max = -1} {if ($6 > max) {max = $6; nome = $2}} END {print nome, max}' conteudo.txt

sort -k 6 -n conteudo.txt | tail -1 | cut -f2,6 -d" "
```

2.14- Calcule o número da linha, cujo início contém a sequência 55002

```bash
awk '/^55002/ {print(NR)}' conteudo.txt

grep -n "^55002" conteudo.txt | cut -f1 -d":"
```

