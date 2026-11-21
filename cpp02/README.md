# 📘 CPP Module 02 — Polimorfismo Ad-hoc, Sobrecarga de Operadores e Forma Canônica Ortodoxa

## 🎯 Visão Geral do Módulo
O **CPP Module 02** é o divisor de águas onde a **Forma Canônica Ortodoxa (OCF - Orthodox Canonical Form)** passa a ser obrigatória para todas as classes.

Conceitos-chave abordados:
- **Números de Ponto Fixo (Fixed-Point Numbers)**: Representação fracionária usando inteiros com ponto fixo de 8 bits fracionários (`Q24.8`), oferecendo velocidade de processamento sem a imprevisibilidade de ponto flutuante em sistemas embarcados.
- **Forma Canônica Ortodoxa**:
  1. Construtor Padrão (`Fixed()`)
  2. Construtor de Cópia (`Fixed(const Fixed& other)`)
  3. Operador de Atribuição de Cópia (`Fixed& operator=(const Fixed& rhs)`)
  4. Destrutor (`~Fixed()`)
- **Sobrecarga de Operadores**:
  - Operadores de Comparação: `>`, `<`, `>=`, `<=`, `==`, `!=`
  - Operadores Aritméticos: `+`, `-`, `*`, `/`
  - Incremento e Decremento (Pré e Pós): `++a`, `a++`, `--a`, `a--`
  - Inserção em Stream: `operator<<`
- **Algoritmo BSP (Binary Space Partitioning)**: Determinação se um ponto 2D está estritamente contido no interior de um triângulo usando determinantes 2D (produto vetorial).

---

## 📂 Estrutura de Diretórios

```
cpp02/
├── ex00/   # Minha Primeira Classe na Forma Canônica Ortodoxa
├── ex01/   # Rumo a uma classe de ponto fixo mais útil (int, float, operator<<)
├── ex02/   # Agora estamos falando (Sobrecarga de operadores, min, max)
├── ex03/   # BSP (Binary Space Partitioning com a classe Point)
├── DEFENSE_GUIDE.md   <-- Guia didático completo para defesa e estudo
└── README.md          <-- Documentação técnica
```

---

## 🛠️ Compilação e Execução

Compilação com `c++ -Wall -Wextra -Werror -std=c++98`:
```bash
# ex00: OCF Básico
cd ex00 && make && ./fixed

# ex01: Conversões e Inserção de Fluxo
cd ../ex01 && make && ./useful_fixed

# ex02: Aritmética e Incrementos
cd ../ex02 && make && ./now_we_are_talking

# ex03: Algoritmo BSP
cd ../ex03 && make && ./bsp
```

---

## 🛡️ Validação de Memória
Nenhuma alocação dinâmica é requerida neste módulo, garantindo **0 vazamentos de memória (leaks)** validados com Valgrind.
