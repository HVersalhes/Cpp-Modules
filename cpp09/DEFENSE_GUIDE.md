# 🎓 CPP09 — Guia Pedagógico de Estudo e Preparação para Defesas

Este guia explica detalhadamente a matemática, os contêineres e os algoritmos do **CPP09**, comparando cada escolha com o desenvolvimento em **C puro** e preparando você para gabaritar a avaliação final.

---

## 🧠 Tabela Comparativa: Do C para o C++

| Em C Puro | Em C++98 (CPP09) | Vantagem Arquitetural |
| :--- | :--- | :--- |
| Busca em tabela de histórico: array linear de structs ($O(N)$) | `std::map::upper_bound` ($O(\log N)$) | Árvore Rubro-Negra auto-balanceada que encontra a data exata ou a data anterior mais próxima instantaneamente. |
| Pilha manual com listas encadeadas (`t_node`) | `std::stack<int>` | Encapsulamento LIFO limpo com operações `push`, `pop`, `top`. |
| MergeSort simples em C ($O(N \log N)$ com muitas cópias) | Ford-Johnson Merge-Insertion | Minimiza o número estrito de **comparações** matemáticas usando a sequência de números de Jacobsthal. |

---

## 🔍 Análise Detalhada Exercício por Exercício

### 🔹 Exercício 00: `btc` (Bitcoin Exchange)

#### 1. O que este exercício ensina?
- Manipulação do contêiner associativo ordenado `std::map<std::string, double>`.
- Como datas no formato ISO 8601 (`YYYY-MM-DD`) possuem **ordem lexicográfica idêntica à ordem cronológica**.
- Método `upper_bound(date)`:
  - Retorna o primeiro elemento com chave estritamente **maior** que a data procurada.
  - Ao decrementar o iterador (`--it`), obtemos exatamente a data procurada (se existir) ou a **data mais próxima anterior**!
- Validação estrita de datas no calendário gregoriano (dias válidos por mês e anos bissextos).
- Validação de valores entre 0 e 1000.

---

### 🔹 Exercício 01: `RPN` (Reverse Polish Notation)

#### 1. O que é Notação Polonesa Reversa (Postfix)?
Na notação infixa tradicional da matemática, os operadores ficam entre os operandos: `(3 + 4) * 2`.
Na Notação Polonesa Reversa (pós-fixada), os operadores vêm **após** os operandos: `3 4 + 2 *`.
A grande vantagem da RPN na ciência da computação é que ela **não necessita de parênteses nem de regras de precedência de operadores**.

#### 2. Mecânica com `std::stack`:
- Ao ler um número (dígito de 0 a 9): empilha (`push`).
- Ao ler um operador (`+`, `-`, `*`, `/`):
  1. Desempilha o operando direito `b = top()`.
  2. Desempilha o operando esquerdo `a = top()`.
  3. Calcula `a <op> b`.
  4. Empilha o resultado.
- Ao final da expressão, a pilha deve conter **exatamente 1 elemento** (o resultado). Qualquer outro estado significa expressão malformada (`Error`).

---

### 🔹 Exercício 02: `PmergeMe` (Algoritmo de Ordenação de Ford-Johnson)

#### 1. O que é o Algoritmo de Ford-Johnson (Merge-Insertion Sort)?
Desenvolvido em 1959 por Lester Ford Jr. e Selmer Johnson, é um algoritmo híbrido cujo objetivo primordial é **minimizar o número total de comparações entre elementos**, superando até mesmo o MergeSort tradicional em quantidade de comparações para $N$ pequeno a médio.

#### 2. Os 5 Passos do Algoritmo:
1. **Emparelhamento**: Agrupa os $N$ elementos em pares de 2. Se $N$ for ímpar, guarda o elemento solitário (*straggler*).
2. **Comparação de Pares**: Em cada par $(x, y)$, garante que $a_i \ge b_i$.
3. **Ordenação Recursiva**: Extrai a lista de elementos maiores ($a_1, a_2, \dots$) e a ordena recursivamente usando o próprio Ford-Johnson.
4. **Cadeia Principal e Cadeia Pendente**:
   - Cadeia Principal (*Main Chain*): Inicializada com $b_1, a_1, a_2, \dots, a_k$. O elemento $b_1$ já entra no início sem nenhuma comparação, pois já sabemos que $b_1 \le a_1$!
   - Cadeia Pendente (*Pend Chain*): Os elementos restantes $b_2, b_3, \dots, b_k$.
5. **Inserção Binária na Ordem de Jacobsthal**:
   Os elementos da cadeia pendente são inseridos na cadeia principal usando **busca binária** (`std::lower_bound`).
   A ordem de inserção NÃO é sequencial (1, 2, 3...)! A ordem segue os **Números de Jacobsthal**:
   $$J_0=0, J_1=1, J_2=1, J_3=3, J_4=5, J_5=11, J_6=21, J_7=43 \dots$$
   Grupos de inserção:
   - Primeiro: $b_1$ (inserido gratuitamente).
   - Segundo grupo ($J_3 \to J_2+1$): $b_3, b_2$.
   - Terceiro grupo ($J_4 \to J_3+1$): $b_5, b_4$.
   - Quarto grupo ($J_5 \to J_4+1$): $b_{11}, b_{10}, b_9, b_8, b_7, b_6$.
   **Por que isso é genial?**
   Porque quando você insere $b_k$, o tamanho da cadeia principal até o ponto limite é de no máximo $2^m - 1$. Isso significa que a busca binária atinge exatamente a profundidade máxima da árvore de decisão sem desperdiçar comparações!
6. Por fim, se havia um elemento ímpar (*straggler*), ele é inserido via busca binária.

#### 3. Diferença de Desempenho: `std::vector` vs `std::deque`:
- `std::vector`: Memória contígua em um único buffer linear. Excelente localidade de cache (*cache locality*), mas inserções no meio (`insert`) exigem deslocamento de memória (`memmove`).
- `std::deque`: Alocação em pedaços de blocos (*chunks* de tamanho fixo) indexados por uma tabela de ponteiros. Permite inserções rápidas no início (`push_front`) sem realocar tudo, mas tem custo extra de indireção nos acessos aleatórios.

---

## 🧪 Perguntas de Defesa da Banca

- **P: Por que usamos `upper_bound - 1` em vez de `lower_bound` no exercício do Bitcoin?**
  *R: `lower_bound` retorna o primeiro elemento $\ge$ chave. Se a data exata não existir, ele retorna uma data POSTERIOR à solicitada, o que exigiria verificação extra. `upper_bound` retorna o primeiro elemento $>$ chave; ao decrementar uma posição (`--it`), garantimos que estamos sempre na data exata ou na data anterior mais próxima!*
- **P: Por que o Ford-Johnson é mais eficiente em comparações do que o QuickSort?**
  *R: Porque o QuickSort escolhe pivôs que podem desbalancear as partições e gasta comparações redundantes. O Ford-Johnson agrupa em pares e usa inserção por Jacobsthal para garantir que a busca binária sempre caia em intervalos ideais de potências de 2.*

---

## 🚀 Comandos Rápidos de Teste para a Defesa

```bash
# Testar ex00
cd ex00 && make && ./btc input.txt && make fclean

# Testar ex01 (RPN)
cd ../ex01 && make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "2 3 + 4 *"
make fclean

# Testar ex02 (PmergeMe com sequência pequena e com 3000 números)
cd ../ex02 && make
./PmergeMe 3 5 9 7 4
./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" " ")
valgrind --leak-check=full ./PmergeMe 9 8 7 6 5 4 3 2 1
make fclean
```
