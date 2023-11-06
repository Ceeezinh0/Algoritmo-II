# Programas sobre Listas Encadeadas

Este repositório contém cinco programas em linguagem C que demonstram diferentes conceitos.

## Programa 1: Alocação Dinâmica

O arquivo `Vetor Dinamicamente alocado.c` mostra como alocar memória dinamicamente em C e preencher um vetor com valores fornecidos pelo usuário. O programa também imprime os valores do vetor e libera a memória alocada no final.

## Programa 2: Lista Encadeada Ordenada

### Descrição
O arquivo `Lista Encadeada Ordenada.c` implementa uma lista encadeada ordenada em C. Ele define uma estrutura de nó para a lista e inclui funções para criar uma lista vazia, incluir elementos na lista de forma ordenada, mostrar os elementos da lista e contar os elementos da lista.

### Estrutura da Lista e Declaração de Tipo
- É definida uma estrutura `struct reg` para representar um nó da lista. Cada nó contém um valor inteiro `info` e um ponteiro para o próximo nó, chamado `prox`.
- É definido um tipo de ponteiro `no` para esta estrutura.

### Função `cria_lista`
- `void cria_lista (no *lista)`: Esta função cria uma lista vazia, inicializando um ponteiro para nó como `NULL`.

### Função `mostra_lista`
- `void mostra_lista (no lista)`: Esta função recebe um nó como argumento e exibe os elementos da lista encadeada, percorrendo-a a partir desse nó e imprimindo os valores.

### Função `inclui_ordenada`
- `void inclui_ordenada (no *lista, int info)`: Esta função insere um elemento na lista de forma ordenada.
- Ela aloca memória para um novo nó, preenche-o com o valor `info` e o insere no local apropriado na lista para mantê-la ordenada.

### Função `conta_elementos`
- `int conta_elementos (no lista)`: Esta função conta o número de elementos na lista, percorrendo a lista e incrementando um contador para cada elemento encontrado.

### Programa Principal
- No programa principal (`main`), uma lista é criada chamando `cria_lista`.
- Em um loop, o usuário insere números inteiros, que são inseridos na lista usando `inclui_ordenada`.
- Após cada inserção, a lista é exibida e o usuário é solicitado a continuar ou não.
- O programa continua até que o usuário decida não continuar.
- Finalmente, a lista completa é exibida.

## Programa 3: Lista Simplesmente Encadeada

### Descrição
O arquivo `Lista_Simplesmente_Encadeada.c` implementa uma lista simplesmente encadeada em C, onde os elementos são inseridos no final da lista. Este programa é uma variação do Programa 2, focado em demonstrar uma lista simplesmente encadeada.

### Estrutura da Lista e Declaração de Tipo
- É definida uma estrutura `struct reg` para representar um nó da lista. Cada nó contém um valor inteiro `info` e um ponteiro para o próximo nó, chamado `prox`.
- É definido um tipo de ponteiro `no` para esta estrutura.

### Função `cria_lista`
- `void cria_lista (no *lista)`: Esta função cria uma lista vazia, inicializando um ponteiro para nó como `NULL`.

### Função `inclui_final`
- `void inclui_final (no *lista, int info)`: Esta função insere um elemento no final da lista.
- Ela aloca memória para um novo nó, preenche-o com o valor `info` e o insere no final da lista.

### Função `mostra_lista`
- `void mostra_lista (no lista)`: Esta função recebe um nó como argumento e exibe os elementos da lista encadeada, percorrendo-a a partir desse nó e imprimindo os valores.

### Função `conta_elementos`
- `int conta_elementos (no lista)`: Esta função conta o número de elementos na lista, percorrendo a lista e incrementando um contador para cada elemento encontrado.

### Programa Principal
- No programa principal (`main`), uma lista é criada chamando `cria_lista`.
- Em um loop, o usuário insere números inteiros, que são inseridos no final da lista usando `inclui_final`.
- Após cada inserção, o usuário decide se deseja continuar ou não.
- O programa continua até que o usuário decida não continuar.
- Finalmente, a lista completa é exibida, juntamente com a contagem de elementos nela.

## Programa 4: Lista Duplamente Encadeada

### Descrição
O arquivo `Lista_Duplamente_Encadeada.c` implementa uma lista duplamente encadeada em C. Neste programa, cada nó da lista contém um valor inteiro e dois ponteiros, um para o próximo nó (encadeamento direito) e outro para o nó anterior (encadeamento esquerdo).

### Estrutura da Lista e Declaração de Tipo
- É definida uma estrutura `struct reg` para representar um nó da lista duplamente encadeada. Cada nó contém um valor inteiro `info`, um ponteiro para o próximo nó (`prox`) e um ponteiro para o nó anterior (`ant`).
- É definido um tipo de ponteiro `no` para esta estrutura.

### Função `cria_lista_dupla`
- `void cria_lista_dupla (no *lista)`: Esta função cria uma lista duplamente encadeada vazia, inicializando um ponteiro para nó como `NULL`.

### Função `insere_dupla`
- `void insere_dupla (no *lista, int info)`: Esta função insere um elemento no início da lista duplamente encadeada.
- Ela aloca memória para um novo nó, preenche-o com o valor `info`, atualiza os ponteiros apropriados para refletir a inserção no início e torna o novo nó como o primeiro da lista.

### Função `mostra_lista_dupla`
- `void mostra_lista_dupla (no lista)`: Esta função recebe um nó como argumento e exibe os elementos da lista duplamente encadeada, percorrendo-a a partir desse nó e imprimindo os valores.

### Programa Principal (Lista Duplamente Encadeada)
- No programa principal (`main`), uma lista duplamente encadeada é criada chamando `cria_lista_dupla`.
- Em um loop, o usuário insere números inteiros, que são inseridos no início da lista usando `insere_dupla`.
- Após cada inserção, a lista é exibida e o usuário é solicitado a continuar ou não.
- O programa continua até que o usuário decida não continuar.
- Finalmente, a lista duplamente encadeada completa é exibida.

## Programa 5: Lista Circular Simplesmente Encadeada

### Descrição
O arquivo `Lista_Circular_Simplesmente_Encadeada.c` implementa uma lista circular simplesmente encadeada em C. Neste programa, a lista forma um loop, onde o último nó aponta de volta para o primeiro nó.

### Estrutura da Lista e Declaração de Tipo
- É definida uma estrutura `struct reg` para representar um nó da lista circular simplesmente encadeada. Cada nó contém um valor inteiro `info` e um ponteiro para o próximo nó, que é sempre um loop de volta para o primeiro nó.
- É definido um tipo de ponteiro `no` para esta estrutura.

### Função `cria_lista_circular`
- `void cria_lista_circular (no *lista)`: Esta função cria uma lista circular simplesmente encadeada vazia, inicializando um ponteiro para nó como `NULL`.

### Função `insere_circular`
- `void insere_circular (no *lista, int info)`: Esta função insere um elemento no final da lista circular simplesmente encadeada.
- Ela aloca memória para um novo nó, preenche-o com o valor `info` e faz o último nó apontar para o novo nó, mantendo o loop da lista.

### Função `mostra_lista_circular`
- `void mostra_lista_circular (no lista)`: Esta função recebe um nó como argumento e exibe os elementos da lista circular simplesmente encadeada, percorrendo-a a partir desse nó e imprimindo os valores.

### Programa Principal (Lista Circular Simplesmente Encadeada)
- No programa principal (`main`), uma lista circular simplesmente encadeada é criada chamando `cria_lista_circular`.
- Em um loop, o usuário insere números inteiros, que são inseridos no final da lista usando `insere_circular`.
- Após cada inserção, a lista é exibida e o usuário é solicitado a continuar ou não.
- O programa continua até que o usuário decida não continuar.
- Finalmente, a lista circular simplesmente encadeada completa é exibida.

## Execução

Para executar qualquer um dos programas, siga estas etapas:

1. Compile o programa: `gcc nome_do_programa.c -o nome_do_programa`.
2. Execute o programa: `./nome_do_programa`.

Os programas interagem com o usuário para realizar as operações correspondentes.

---

Sinta-se à vontade para explorar e executar esses programas para entender melhor os conceitos mostrados.
