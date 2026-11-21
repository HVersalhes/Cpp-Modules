# 🎓 CPP02 — Guia Pedagógico de Estudo e Preparação para Defesas

Este guia desvenda com palavras simples a matemática e a arquitetura de C++ ensinadas no CPP02, comparando cada detalhe com a linguagem C.

---

## 🧠 Tabela Comparativa: Do C para o C++

| Em C Puro | Em C++98 | O que muda? Por que é superior? |
| :--- | :--- | :--- |
| `int valor;` com operações manuais `valor << 8` | `class Fixed;` com encapsulamento completo | O programador manipula o número como se fosse um tipo primitivo (`a * b`), e a classe cuida do deslocamento de bits internamente. |
| Funções com nomes diferentes: `add_fixed(a, b)`, `mul_fixed(a, b)` | Sobrecarga de Operadores: `a + b`, `a * b` | **Sintaxe natural e expressiva**: o C++ permite estender os operadores da linguagem para tipos personalizados. |
| Cópia manual de structs: `memcpy(&dest, &src, sizeof(t_obj));` | Construtor de Cópia e `operator=` | **Cópia profunda e segura**: permite que a classe execute lógica de cópia personalizada sem riscos de clonar ponteiros acidentalmente. |
| `printf("%f\n", fixed_to_float(a));` | `std::cout << a << std::endl;` | Sobrecarga do `operator<<` para streams `std::ostream`. |

---

## 🔍 Análise Detalhada Exercício por Exercício

### 🔹 O que é Ponto Fixo (Fixed Point)?
Em computação, números fracionários geralmente são armazenados em **ponto flutuante** (`float`/`double`, padrão IEEE 754). No entanto:
- Pontos flutuantes consomem mais ciclos de CPU e energia em microcontroladores sem FPU (Floating Point Unit).
- Pontos flutuantes podem introduzir erros de arredondamento imprevisíveis.
No **Ponto Fixo**, reservamos um número fixo de bits para a parte inteira e um número fixo para a parte fracionária.
No nosso projeto, usamos **8 bits fracionários**:
$$\text{Número em Ponto Fixo} = \text{Valor Real} \times 2^8 = \text{Valor Real} \times 256$$
Para converter de volta para float:
$$\text{Valor Real} = \frac{\text{RawBits}}{256.0f}$$

---

### 🔹 Exercício 00: `fixed` (Primeira Classe Canônica Ortodoxa)

#### 1. Os 4 Pilares da Forma Canônica Ortodoxa (OCF):
1. **Construtor Padrão (`Fixed()`)**: Inicializa o objeto do zero (`_rawBits = 0`).
2. **Construtor de Cópia (`Fixed(const Fixed& other)`)**: Cria um novo objeto inicializado como cópia de um objeto existente (`Fixed b(a);`).
3. **Operador de Atribuição (`operator=`)**: Sobrescreve um objeto **já existente** com os dados de outro (`b = a;`). Deve tratar auto-atribuição (`this != &rhs`).
4. **Destrutor (`~Fixed()`)**: Executado quando o ciclo de vida do objeto se encerra.

#### 2. Pergunta de Defesa:
- **P: Qual a diferença entre Construtor de Cópia e Operador de Atribuição?**
  *R: O Construtor de Cópia é chamado na criação de um NOVO objeto: `Fixed b = a;` ou `Fixed b(a);`. O Operador de Atribuição é chamado em um objeto que JÁ EXISTIA: `Fixed b; b = a;`.*

---

### 🔹 Exercício 01: `useful_fixed` (Conversões e Inserção de Fluxo)

#### 1. Matemática das Conversões:
- **De `int` para `Fixed`**:
  `_rawBits = n << 8;` (multiplica por 256).
- **De `float` para `Fixed`**:
  `_rawBits = roundf(f * (1 << 8));` (multiplica por 256 e arredonda com precisão).
- **De `Fixed` para `float`**:
  `return (float)_rawBits / (1 << 8);` (divide por 256.0).
- **De `Fixed` para `int`**:
  `return _rawBits >> 8;` (divide por 256 descartando a fração).

#### 2. Sobrecarga do `operator<<`:
Por que não é uma função membro da classe `Fixed`?
Porque o operando da esquerda é `std::ostream&`, e não `Fixed`. Como não podemos modificar a classe padrão da biblioteca C++, implementamos como função livre que recebe `(std::ostream& out, const Fixed& rhs)`.

---

### 🔹 Exercício 02: `now_we_are_talking` (Operadores Aritméticos e Incrementos)

#### 1. Como funcionam a Multiplicação e Divisão de Ponto Fixo?
Se multiplicarmos dois números que já possuem 8 bits de escala:
$$(A \times 256) \times (B \times 256) = (A \times B) \times 256^2$$
O resultado fica com escala dupla ($256^2$). Portanto, precisamos deslocar 8 bits para a direita (`>> 8`) para restaurar a escala original!
Além disso, fazemos o cast intermediário para `long long` para evitar estouro de 32 bits no produto.

#### 2. Pré-incremento vs Pós-incremento:
- **Pré-incremento (`++a`)**:
  `Fixed& operator++();`
  Incrementa imediatamente o bit bruto e retorna uma referência a `*this`.
- **Pós-incremento (`a++`)**:
  `Fixed operator++(int);`
  O parâmetro fantasma `int` é a convenção do C++ para diferenciar a assinatura.
  Criamos uma cópia temporária do estado anterior, incrementamos `*this`, e retornamos a cópia por valor!

---

### 🔹 Exercício 03: `bsp` (Binary Space Partitioning)

#### 1. Como funciona a detecção do ponto no triângulo?
Usamos o **produto vetorial 2D (determinante)**.
Para um segmento orientado de $A$ para $B$, o produto vetorial com o vetor de $A$ para $P$ indica de que lado da reta o ponto $P$ está (à esquerda ou à direita).
$$\text{crossProduct}(A, B, P) = (P_x - B_x)(A_y - B_y) - (A_x - B_x)(P_y - B_y)$$
Se o ponto $P$ estiver estritamente dentro do triângulo, ele estará do **mesmo lado** em relação a todas as 3 arestas ($AB, BC, CA$).
Portanto, os 3 produtos vetoriais devem ter todos sinal positivo ou todos sinal negativo!
Se algum for exatamente zero, o ponto está na borda ou vértice, devendo retornar `false` conforme exigido no subject.

---

## 🧪 Comandos Rápidos de Teste para a Defesa

```bash
# Testar ex00
cd ex00 && make && ./fixed && make fclean

# Testar ex01
cd ../ex01 && make && ./useful_fixed && make fclean

# Testar ex02
cd ../ex02 && make && ./now_we_are_talking && make fclean

# Testar ex03 (verificação de posições no BSP)
cd ../ex03 && make && ./bsp && make fclean
```
