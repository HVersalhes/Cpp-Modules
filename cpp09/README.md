# 📘 CPP Module 09 — STL Avançada: Dicionários, Pilhas e Ordenação de Ford-Johnson

## 🎯 Visão Geral do Módulo
O **CPP Module 09** é o módulo final e definitivo do ecossistema de C++ da Escola 42. Ele exige a aplicação de diferentes contêineres da Standard Template Library (STL) sob uma regra estrita de não-repetição:
> **Regra Crucial do CPP09**: O(s) contêiner(es) utilizado(s) em um exercício não podem ser reutilizados nos exercícios seguintes do módulo!

Nossa arquitetura foi desenhada para cumprir essa regra com perfeição:
- **Exercício 00 (`btc`)**: `std::map<std::string, double>` (Árvore Rubro-Negra / Dicionário balanceado ordenado por data).
- **Exercício 01 (`RPN`)**: `std::stack<int>` (Adaptador LIFO para Notação Polonesa Reversa).
- **Exercício 02 (`PmergeMe`)**: `std::vector<int>` e `std::deque<int>` (Algoritmo Merge-Insertion de Ford-Johnson comparando dois contêineres distintos).

---

## 📂 Estrutura de Diretórios

```
cpp09/
├── ex00/   # Bitcoin Exchange (std::map, busca temporal com upper_bound/lower_bound)
│   ├── data.csv
│   ├── input.txt
│   ├── BitcoinExchange.cpp
│   ├── BitcoinExchange.hpp
│   ├── main.cpp
│   └── Makefile
├── ex01/   # Reverse Polish Notation (std::stack, calculadora de pilha pós-fixada)
│   ├── RPN.cpp
│   ├── RPN.hpp
│   ├── main.cpp
│   └── Makefile
├── ex02/   # PmergeMe (Ford-Johnson Merge-Insertion sort com std::vector e std::deque)
│   ├── PmergeMe.cpp
│   ├── PmergeMe.hpp
│   ├── main.cpp
│   └── Makefile
├── DEFENSE_GUIDE.md   <-- Guia didático completo para defesa e estudo
└── README.md          <-- Documentação técnica
```

---

## 🛠️ Compilação e Execução

Compilação estrita com `c++ -Wall -Wextra -Werror -std=c++98`:

### Exercício 00: Bitcoin Exchange
```bash
cd ex00
make
./btc input.txt
```

### Exercício 01: Reverse Polish Notation
```bash
cd ../ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"    # Saída: 42
./RPN "7 7 * 7 -"                     # Saída: 42
./RPN "1 2 * 2 / 2 * 2 4 - +"         # Saída: 0
./RPN "(1 + 1)"                       # Saída: Error
```

### Exercício 02: PmergeMe
```bash
cd ../ex02
make
./PmergeMe 3 5 9 7 4
./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" " ")
```

---

## 🛡️ Validação de Memória
Todos os 3 projetos foram submetidos ao **Valgrind**:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./<executavel>
```
Resultado: **0 bytes perdidos em 0 blocos (All heap blocks were freed -- no leaks are possible)**.
