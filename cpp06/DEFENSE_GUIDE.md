# 🎓 CPP06 — Guia Pedagógico de Estudo e Preparação para Defesas

Este guia explica os **4 Casts de C++**, comparando-os com o perigoso cast implícito/explícito de **C puro** (`(tipo)valor`).

---

## 🧠 Tabela Comparativa: Cast em C vs Casts em C++

| Em C Puro | Em C++98 | Qual a diferença? Por que C++ criou 4 operadores? |
| :--- | :--- | :--- |
| `int i = (int)3.14;` | `static_cast<int>(3.14)` | **Verificação em tempo de compilação**: O compilador impede conversões sem sentido que poderiam corromper dados. |
| `uintptr_t u = (uintptr_t)ptr;` | `reinterpret_cast<uintptr_t>(ptr)` | **Perigo explícito**: O nome longo e feio serve de alerta visual no código: "estou manipulando bits brutos sem conversão matemática". |
| Não existe (em C não há classes polimórficas) | `dynamic_cast<Derived*>(base_ptr)` | **Verificação em tempo de execução**: Consulta a `vtable` para checar se o objeto na memória realmente pertence à classe esperada. |
| `char *p = (char*)const_p;` | `const_cast<char*>(const_p)` | **Eliminação de const**: É o único cast que consegue remover o modificador `const`. |

---

## 🔍 Análise Detalhada Exercício por Exercício

### 🔹 Exercício 00: `convert` (Conversão de Tipos Escalares)

#### 1. O que este exercício ensina?
- Detecção e conversão de strings para os 4 tipos escalares fundamentais: `char`, `int`, `float`, `double`.
- Tratamento de pseudo-literais da IEEE 754: `-inff`, `+inff`, `nanf`, `-inf`, `+inf`, `nan`.
- Detecção de overflow com `<climits>` e `<cfloat>`.
- Uso de `static_cast` para conversões válidas.

#### 2. Casos Especiais:
- Se for `nan` ou `nanf`: char e int são "impossíveis", float é `nanf`, double é `nan`.
- Se o valor numérico for 42:
  - char: `'*'` (código ASCII 42)
  - int: `42`
  - float: `42.0f`
  - double: `42.0`
- Se o char for < 32 ou > 126 (e não for estourado): imprime `Non displayable`.

---

### 🔹 Exercício 01: `serialize` (Serialização)

#### 1. O que é `uintptr_t`?
- É um tipo inteiro não assinado definido em `<stdint.h>` que possui exatamente a **mesma largura em bits que um ponteiro** na arquitetura da máquina (32 bits em x86, 64 bits em x64).
- Ele garante que nenhum bit seja perdido ao converter um ponteiro para número inteiro e depois de volta para ponteiro!

#### 2. O que faz o `reinterpret_cast`?
Ele não altera um único bit na memória! Ele apenas diz ao compilador: "trate este endereço de memória como se fosse um número inteiro não assinado".
Ao chamar `deserialize(uintptr_t raw)` com `reinterpret_cast<Data*>(raw)`, restauramos o ponteiro exato original.

---

### 🔹 Exercício 02: `identify` (Identificar Tipo Real com dynamic_cast)

#### 1. Como o `dynamic_cast` funciona com PONTEIROS?
```cpp
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
}
```
Se o objeto apontado por `p` for do tipo `A` (ou herdado de `A`), o cast tem sucesso e retorna o ponteiro.
Se **NÃO for**, ele retorna `NULL` (sem lançar exceções).

#### 2. Como o `dynamic_cast` funciona com REFERÊNCIAS?
```cpp
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception&) {}
}
```
Como referências **não podem ser nulas em C++**, o `dynamic_cast` não pode retornar NULL quando o cast falha!
Em vez disso, ele **lança uma exceção do tipo `std::bad_cast`**!
Por isso usamos blocos `try/catch`.

#### 3. Pergunta de ouro da defesa:
- **P: Por que a classe `Base` precisa ter ao menos um método `virtual` para o `dynamic_cast` funcionar?**
  *R: Porque o `dynamic_cast` precisa inspecionar as informações de tipo em tempo de execução (RTTI) armazenadas na `vtable`. Se uma classe não tiver nenhum método virtual, ela não possui `vtable`, e o compilador gera um erro de compilação!*

---

## 🚀 Comandos Rápidos de Teste para a Defesa

```bash
# Testar ex00 com vários tipos
cd ex00 && make
./convert "0"
./convert "nan"
./convert "42.0f"
./convert "-inff"
make fclean

# Testar ex01
cd ../ex01 && make && ./serialize && make fclean

# Testar ex02 (testar identificação por ponteiro e referência)
cd ../ex02 && make && ./identify && make fclean
```
