# 🎓 CPP08 — Guia Pedagógico de Estudo e Preparação para Defesas

Este guia desvenda a arquitetura da **Standard Template Library (STL)** de C++, comparando a sofisticação dos algoritmos e contêineres com a programação manual que fazíamos em **C puro**.

---

## 🧠 Tabela Comparativa: Do C para o C++

| Em C Puro (ex: Libft / Push_swap) | Em C++98 com STL | O que muda? Revolução de produtividade |
| :--- | :--- | :--- |
| Busca manual com loop `while (arr[i] != x)` | `std::find(c.begin(), c.end(), x)` | O algoritmo é desacoplado do contêiner. Funciona em listas, vetores, deques sem reescrever 1 linha. |
| Realloc manual (`malloc`, cópia e `free`) | `std::vector::push_back` | Gerenciamento automático de capacidade com crescimento geométrico amortizado $O(1)$. |
| QuickSort escrito na mão (`ft_qsort`) | `std::sort(v.begin(), v.end())` | Algoritmo *Introsort* híbrido (QuickSort + HeapSort + InsertionSort) altamente otimizado com garantias de $O(N \log N)$. |
| Pilha manual com ponteiros de nós (`t_stack *top;`) | `std::stack<T>` | Adaptador de contêiner com interface de pilha estrita (`push`, `pop`, `top`). |

---

## 🔍 Análise Detalhada Exercício por Exercício

### 🔹 Exercício 00: `easyfind` (Easy find)

#### 1. Como funciona o algoritmo?
```cpp
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw NotFoundException();
    return it;
}
```
- Usamos `std::find` da biblioteca `<algorithm>`.
- `container.begin()`: aponta para o primeiro elemento.
- `container.end()`: aponta para a posição **logo após o último elemento** (sentinela).
- Se o elemento não existir, `std::find` retorna `container.end()`. Lançamos nossa exceção personalizada!
- Por que usamos `typename T::iterator`?
  Porque `iterator` é um tipo dependente do tipo genérico `T`. O compilador exige a palavra-chave `typename` para entender que `iterator` é um nome de tipo e não um membro estático.

---

### 🔹 Exercício 01: `span` (Span)

#### 1. Cálculo Otimizado de `shortestSpan` e `longestSpan`:
- **Longest Span**: É simplesmente a diferença entre o maior e o menor valor:
  `*std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end())`.
  Complexidade: $O(N)$.
- **Shortest Span**:
  Se comparássemos todos os pares ($N \times N$), teríamos complexidade $O(N^2)$, que travaria com 20.000 números!
  **Solução elegante**:
  1. Criamos uma cópia do vetor e ordenamos com `std::sort` ($O(N \log N)$).
  2. Em um array ordenado, a menor diferença absoluta SEMPRE estará entre **elementos adjacentes**!
  3. Percorremos o vetor ordenado em uma única passada de $O(N)$ subtraindo `v[i+1] - v[i]`.
  Complexidade final: $O(N \log N)$ instantâneo!
- **Inserção em massa com `addRange`**:
  Permite preencher o `Span` passando iteradores de início e fim (`addRange(v.begin(), v.end())`) sem fazer milhares de chamadas isoladas.

---

### 🔹 Exercício 02: `mutant_stack` (Abominação Mutada)

#### 1. O que é um Container Adaptor?
`std::stack` não é um contêiner que gerencia memória diretamente. Ele é um **adaptador** (envoltório) sobre outro contêiner existente (por padrão `std::deque<T>`).
Por design intencional de POO, `std::stack` não fornece iteradores para garantir que o programador só acesse o elemento do topo (`top()`).

#### 2. Como hackeamos a pilha para expor iteradores?
A especificação da biblioteca padrão C++ define que `std::stack` armazena o contêiner subjacente em um membro protegido chamado **`c`**:
```cpp
protected:
    container_type c;
```
Ao herdar publicamente de `std::stack<T>`, nossa classe `MutantStack` tem acesso direto a `this->c`!
Assim, podemos expor os métodos:
```cpp
iterator begin() { return this->c.begin(); }
iterator end() { return this->c.end(); }
```
Dessa forma, mantemos todas as operações nativas da pilha e ainda ganhamos suporte total a iteração padrão STL!

---

## 🧪 Perguntas Comuns de Defesa

- **P: Qual a complexidade de tempo de `std::vector::push_back`?**
  *R: Complexidade amortizada $O(1)$. Quando a capacidade máxima atual é atingida, ele realoca o dobro da capacidade em uma nova região de memória e copia os elementos.*
- **P: Por que `easyfind` não aceita `std::map`?**
  *R: Porque `std::map` é um contêiner associativo chave-valor que possui seu próprio método de busca em árvore binária otimizado `map.find(key)` de complexidade $O(\log N)$, enquanto `std::find` realiza busca linear $O(N)$ em sequências.*

---

## 🚀 Comandos Rápidos de Teste para a Defesa

```bash
# Testar ex00 (vector e list)
cd ex00 && make && ./easyfind && make fclean

# Testar ex01 (com 20.000 números)
cd ../ex01 && make && valgrind --leak-check=full ./span && make fclean

# Testar ex02 (conferir MutantStack vs std::list)
cd ../ex02 && make && valgrind --leak-check=full ./mutant_stack && make fclean
```
