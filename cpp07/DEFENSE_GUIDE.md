# 🎓 CPP07 — Guia Pedagógico de Estudo e Preparação para Defesas

Este guia explica o funcionamento interno de **Templates em C++**, comparando a programação genérica com as macros e ponteiros genéricos `void*` de **C puro**.

---

## 🧠 Tabela Comparativa: Do C para o C++

| Em C Puro | Em C++98 | Qual a diferença? Por que Templates são revolucionários? |
| :--- | :--- | :--- |
| Macros: `#define MAX(a, b) ((a) > (b) ? (a) : (b))` | `template <typename T> const T& max(const T& a, const T& b)` | Macros não possuem checagem de tipo e causam efeitos colaterais catastróficos com incrementos (`MAX(a++, b)` incrementa duas vezes!). Templates têm **type safety total**! |
| Ponteiros genéricos: `void* ptr;` | Parâmetros de tipo genérico: `T* data;` | `void*` perde todas as informações de tipo; qualquer cast errado causa falha de segmentação. Templates geram código fortemente tipado para cada tipo. |
| Duplicação manual de código: `swap_int`, `swap_str`, `swap_float` | Uma única definição: `swap(T& a, T& b)` | O compilador gera a versão necessária automaticamente quando você usa. |
| Arrays crus em C sem proteção de limites (`arr[999]` acessa memória inválida) | `Array<T>` com sobrecarga de `operator[]` | Se o índice for negativo ou maior/igual a `size()`, uma exceção é lançada imediatamente! |

---

## 🔍 Análise Detalhada Exercício por Exercício

### 🔹 Exercício 00: `whatever` (Comece com algumas funções)

#### 1. O que este exercício ensina?
- Sintaxe de templates de função: `template <typename T>`.
- Como implementar `swap`, `min` e `max`.
- **Por que templates devem ficar no arquivo `.hpp`?**
  Ao contrário de funções comuns, templates não geram código binário compilado imediatamente. Eles são apenas uma "fôrma de bolo". O compilador precisa ver a definição completa do template no ponto em que ele é instanciado em cada unidade de tradução! Se você colocar o corpo em um `.cpp` separado, o linker acusará erro de referência indefinida (*undefined reference*).

---

### 🔹 Exercício 01: `iter` (Iter)

#### 1. O que este exercício ensina?
- Função genérica que recebe um array de tamanho `size_t` e uma função/functor a ser aplicada em cada elemento.
- Suporte a referências constantes e não constantes:
```cpp
template <typename T, typename Func>
void iter(T* array, const size_t length, Func func) {
    if (!array) return;
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}
```
Usando dois parâmetros de template (`typename T, typename Func`), o compilador deduz perfeitamente tanto o tipo dos elementos quanto o protótipo da função (mesmo que seja um ponteiro de função comum ou uma função template instanciada).

---

### 🔹 Exercício 02: `array` (Array Genérico em Forma Canônica)

#### 1. O que este exercício ensina?
- Construção de uma estrutura de dados de array genérica do zero.
- Forma Canônica Ortodoxa com templates.
- Alocação dinâmica com inicialização padrão:
  `_data = new T[n]();`
  Os parênteses `()` garantem que tipos primitivos (como `int`, `float`) sejam inicializados com 0 em vez de lixo de memória!
- **Cópia Profunda Obrigatória**:
  Modificar um array copiado NUNCA deve alterar o array original.
- **Sobrecarga de `operator[]` const e não-const**:
  ```cpp
  T& operator[](unsigned int index);             // Para leitura e escrita
  const T& operator[](unsigned int index) const; // Para objetos constantes (apenas leitura)
  ```
  Se o índice estiver fora dos limites (`index >= _size`), lança exceção!

---

## 🧪 Perguntas Comuns de Defesa

- **P: Qual a diferença entre `typename` e `class` na declaração de templates (`template <typename T>` vs `template <class T>`)?**
  *R: Para parâmetros de template simples, são 100% sinônimos e têm exatamente o mesmo efeito. No entanto, `typename` é obrigatório para indicar tipos dependentes (como `typename T::iterator`).*
- **P: Templates tornam o programa mais lento?**
  *R: Não! Em tempo de execução, o desempenho é idêntico ao de código escrito manualmente para aquele tipo específico. Pode haver apenas um pequeno aumento no tamanho do binário final (*code bloat*) se muitos tipos diferentes forem usados.*

---

## 🚀 Comandos Rápidos de Teste para a Defesa

```bash
# Testar ex00
cd ex00 && make && ./whatever && make fclean

# Testar ex01
cd ../ex01 && make && ./iter && make fclean

# Testar ex02 (teste do subject com 750 números e exceções)
cd ../ex02 && make && valgrind --leak-check=full ./array && make fclean
```
