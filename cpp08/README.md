# 📘 CPP Module 08 — Contêineres STL, Iteradores e Algoritmos

## 🎯 Visão Geral do Módulo
O **CPP Module 08** é o primeiro módulo onde a **Standard Template Library (STL)** é oficialmente permitida:
- **Algoritmos da STL (`<algorithm>`)**: O uso de algoritmos genéricos de busca e ordenação (`std::find`, `std::sort`, `std::min_element`, `std::max_element`) que operam sobre pares de iteradores (`begin`, `end`).
- **Contêineres Sequenciais**: Diferenças de estrutura de dados interna e complexidade algorítmica entre `std::vector` (array dinâmico contíguo) e `std::list` (lista duplamente ligada).
- **Gerenciamento de Spans e Inserção por Intervalo (`addRange`)**: Manipulação de grandes volumes de dados (mais de 20.000 números) com complexidade de tempo otimizada através de ordenação.
- **Adaptadores de Contêiner e Herança**: O contêiner `std::stack` como adaptador sobre um contêiner subjacente (`this->c`), e a criação da classe `MutantStack` para expor iteradores que a pilha original esconde por design.

---

## 📂 Estrutura de Diretórios

```
cpp08/
├── ex00/   # easyfind (busca genérica em qualquer contêiner STL com std::find)
├── ex01/   # Span (cálculo de menor e maior distância entre milhares de números)
├── ex02/   # MutantStack (herança de std::stack com exposição de iteradores)
├── DEFENSE_GUIDE.md   <-- Guia didático completo para defesa e estudo
└── README.md          <-- Documentação técnica
```

---

## 🛠️ Compilação e Execução

Compilação com `c++ -Wall -Wextra -Werror -std=c++98`:
```bash
# ex00: easyfind
cd ex00 && make && ./easyfind

# ex01: Span (teste com 20.000 números)
cd ../ex01 && make && ./span

# ex02: MutantStack vs std::list
cd ../ex02 && make && ./mutant_stack
```

---

## 🛡️ Validação de Memória
Execução 100% limpa no Valgrind:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./<executavel>
```
Resultado: **0 bytes perdidos em 0 blocos**.
