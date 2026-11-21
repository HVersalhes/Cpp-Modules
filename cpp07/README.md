# 📘 CPP Module 07 — Templates e Programação Genérica

## 🎯 Visão Geral do Módulo
O **CPP Module 07** introduz a **Programação Genérica** em C++ através de **Templates**:
- **Templates de Funções (`template <typename T>`)**: Criação de funções que operam de forma idêntica sobre qualquer tipo de dado que suporte as operações requeridas (`swap`, `min`, `max`).
- **Templates de Ordem Superior (`iter`)**: Funções genéricas que iteram sobre arrays de qualquer tipo e executam funções chamáveis sobre cada elemento.
- **Templates de Classes (`template <typename T> class Array`)**: Construção de contêineres dinâmicos genéricos do zero, implementando a Forma Canônica Ortodoxa, gerenciamento seguro de memória com `new[]` e sobrecarga de `operator[]` com checagem de limites e exceções.
- **Instanciação em Tempo de Compilação**: Como o compilador gera código de máquina específico para cada tipo usado, eliminando o overhead de tempo de execução e preservando a segurança de tipos (*type safety*).

---

## 📂 Estrutura de Diretórios

```
cpp07/
├── ex00/   # whatever (swap, min, max genéricos)
├── ex01/   # iter (iteração genérica sobre arrays)
├── ex02/   # Array (classe template de contêiner de array dinâmico em OCF)
├── DEFENSE_GUIDE.md   <-- Guia didático completo para defesa e estudo
└── README.md          <-- Documentação técnica
```

---

## 🛠️ Compilação e Execução

Compilação com `c++ -Wall -Wextra -Werror -std=c++98`:
```bash
# ex00: swap, min, max
cd ex00 && make && ./whatever

# ex01: iterador funcional
cd ../ex01 && make && ./iter

# ex02: Classe de Array Genérico com 750 elementos e testes de bounds
cd ../ex02 && make && ./array
```

---

## 🛡️ Validação de Memória
Execução 100% limpa com **Valgrind**:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./<executavel>
```
Resultado: **0 bytes perdidos em 0 blocos**.
