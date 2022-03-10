| Acção | Comando |
| ------- | ----------- |
| Mudar de diretório: | `cd`|
| Criar um diretório: | `mkdir`|
| Mostrar o conteúdo de um ficheiro: | `cat`, `more`, `less`|
| Copiar um ficheiro: | `cp`|
| Mudar o nome a um ficheiro: | `mv`|
| Criar um _link_ para um ficheiro: | `ln -s`|
| Mudar as permissões a um ficheiro: | `chmod`|



## 1. Comandos introdutórios

### 1.1 Experimente os seguintes comandos

| Comando | Utilização |
| ------- | ---------- |
| `pwd` | return working directory name |
| `passwd` |  modify a user's password |
| `date` | display or set date and time |
| `cal` | displays a calendar (and the date of Easter) |
| `w` | display who is logged in and what they are doing |
| `top` | display and update sorted information about processes |
| `stat` | display file status |

 ### 1.2 Crie a seguinte estrutura de diretórios

```bash
bash-3.2$ mkdir aula1
bash-3.2$ mkdir aula1/dados
bash-3.2$ mkdir aula1/fotos
bash-3.2$ mkdir aula1/fotos/2016
bash-3.2$ mkdir aula1/fotos/2017
bash-3.2$ mkdir aula1/programas

bash-3.2$ tree aula1
aula1
├── dados
├── fotos
│   ├── 2016
│   └── 2017
└── programas

bash-3.2$ cd aula1/

bash-3.2$ touch semnada.txt

bash-3.2$ cp /etc/passwd .

bash-3.2$ cp /etc/passwd users.txt

bash-3.2$ mv passwd lista.txt
```

### 1.3 Execute o seguinte comando

```bash
bash-3.2$ ln -s /etc/passwd fich1.txt
bash-3.2$ ls -l
total 32
drwxr-xr-x  4 rfonseca  so  4096 Sep 21 18:04 dados
lrwxr-xr-x  1 rfonseca  so    11 Sep 21 18:07 fich1.txt -> /etc/passwd
drwxr-xr-x  4 rfonseca  so  4096 Sep 21 18:04 fotos
-rw-r--r--  1 rfonseca  so  6946 Sep 21 18:06 lista.txt
drwxr-xr-x  2 rfonseca  so    64 Sep 21 18:04 programas
-rw-r--r--  1 rfonseca  so     0 Sep 21 18:05 semnada.txt
-rw-r--r--  1 rfonseca  so  6946 Sep 21 18:06 users.txt
```

```bash
bash-3.2$ ln -s semnada.txt sn.txt

bash-3.2$ ls -l sn.txt semnada.txt
-rw-r--r--  1 rfonseca  so   0 Sep 21 18:05 semnada.txt
lrwxr-xr-x  1 rfonseca  so  11 Sep 21 18:08 sn.txt -> semnada.txt

bash-3.2$ rm semnada.txt

bash-3.2$ ls -l sn.txt
lrwxr-xr-x  1 rfonseca  so  11 Sep 21 18:08 sn.txt -> semnada.txt

bash-3.2$ cat sn.txt
cat: sn.txt: No such file or directory
```

A remoção do ficheiro original não alterou em nada o link, portanto se tentarmos aceder ao link obtemos um erro de ficheiro inexistente.

## 2. Redirecionamento

### 2.1 Execute a sequência de comandos e verifique os resultados

```bash
bash-3.2$ echo "sistemas operativos"
sistemas operativos

bash-3.2$ echo "sistemas operativos" > so.txt
bash-3.2$ cat so.txt
sistemas operativos

bash-3.2$ echo "sistemas operativos" >> so.txt
bash-3.2$ cat so.txt
sistemas operativos
sistemas operativos

bash-3.2$ cat so.txt | wc
       2       4      40
```

(a) acrescente uma linha com o seu nome ao ficheiro **so.txt**

```bash
bash-3.2$ echo "Ricardo Fonseca" >> so.txt

bash-3.2$ cat so.txt
sistemas operativos
sistemas operativos
Ricardo Fonseca

```

(b) execute um comando que lhe permita contar o número de palavras do seu nome

```bash
bash-3.2$ echo "Ricardo Fonseca" | wc -w
       2
```


### 2.2 Execute os seguintes comandos e verifique os resultados

(a) crie o ficheiro **nomes.txt**, onde deve colocar todos os alunos com “**Maria**” no nome

```bash
bash-3.2$ grep "Maria" /etc/passwd > nomes.txt
```
(b) acrescente a esse ficheiro todos os alunos com “**Pedro**” no nome

```bash
bash-3.2$ grep "Pedro" /etc/passwd >> nomes.txt
```

(c) indique um comando que lhe permita saber quantos alunos ficaram no ficheiro

```bash
bash-3.2$ wc -l nomes.txt
50 nomes.txt
```

### 2.3 Crie o ficheiro notinhas.txt

```bash
bash-3.2$ echo "Aula de sistemas operativos" > notinhas.txt
bash-3.2$ echo "tudo a correr bem" >> notinhas.txt
bash-3.2$ cat notinhas.txt
Aula de sistemas operativos
tudo a correr bem
```

(a) crie um _soft link_ com o nome **notas.txt** para o ficheiro **notinhas.txt**

```bash
bash-3.2$ ln -s notinhas.txt notas.txt
```

(b) acrescente a data e hora atual ao ficheiro **notas.txt**. O que está em **notinhas.txt**?

```bash
bash-3.2$ date >> notas.txt
bash-3.2$ cat notinhas.txt
Aula de sistemas operativos
tudo a correr bem
Mon Sep 21 18:22:55 WEST 2020
```

## 3. Expansão

Verifique o efeito de cada um dos seguintes comandos:

```bash
bash-3.2$ echo *.txt
fich1.txt lista.txt notas.txt notinhas.txt sn.txt so.txt users.txt

bash-3.2$ echo n*.txt
notas.txt notinhas.txt

bash-3.2$ echo s?.txt
sn.txt so.txt

bash-3.2$ echo *s.*
notas.txt notinhas.txt users.txt

bash-3.2$ ls -l *s.*
lrwxr-xr-x  1 rfonseca  so    12 Sep 21 18:22 notas.txt -> notinhas.txt
-rw-r--r--  1 rfonseca  so    76 Sep 21 18:22 notinhas.txt
-rw-r--r--  1 rfonseca  so  6946 Sep 21 18:06 users.txt
```

## 4. Programa em shell

### 4.1 Crie o programa

Utilize o **vi** para criar o ficheiro **p1.sh**, na diretoria **aula1/programas**:

```bash
bash-3.2$ cd aula1/programas
bash-3.2$ vi p1.sh
```

1. Pressionar a tecla `i` para passar para o modo de inserção (INSERT)
2. Usar como um editor de texto normal e inserir o texto do enunciado
3. Quando terminar de inserir o texto pressionar ESC para voltar ao modo normal (NORMAL)
4. Gravar fazendo `:w`
5. Sair fazendo `:q`

(a) verifique que o ficheiro foi bem criado

```bash
bash-3.2$ cat ./p1.sh
#!/bin/bash
echo "Olá malta!"
echo -n "Hora atual: "
echo "Adeus"

bash-3.2$ ls -l
total 4
-rw-r--r--  1 rfonseca  so    73 Sep 21 18:29 p1.sh
```

(b) Execute o ficheiro, tendo em conta que antes lhe deve dar permissões de execução:

```bash
bash-3.2$ chmod +x p1.sh
bash-3.2$ ls -l p1.sh
-rwxr-xr-x  1 rfonseca  so    73 Sep 21 18:29 p1.sh
bash-3.2$ ./p1.sh
Olá malta!
Hora atual: Mon Sep 21 18:33:10 WEST 2020
Adeus

```

### 4.1 Modifique o programa

A nova versão deve indicar o diretório atual e o seu conteúdo. As linhas que começam por `#` são comentários ao código.

```bash
#!/bin/bash
echo "Olá malta!"
echo -n "Hora atual: "
date

# (a) Mostrar nome da directoria atual
echo ""
echo -n "Diretoria atual: "
pwd

# (b) Listar conteúdo da diretoria atual
echo ""
echo "Conteúdo: "
ls
echo ""

echo "Adeus"
```

Correndo agora o programa obtemos:

```bash
bash-3.2$ programas/p1.sh
Olá malta!
Hora atual: Mon Sep 21 18:35:44 WEST 2020

Diretoria atual: /home/rfonseca/aula01/aula1

Conteúdo:
dados	     fotos      notinhas.txt  semnada.txt  so.txt
fich1.txt  lista.txt  programas     sn.txt	     users.txt

Adeus
```



