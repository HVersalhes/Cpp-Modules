# 📘 CPP Module 00 — Namespaces, Classes, Membros, Streams I/O e Static

## 🎯 Visão Geral do Módulo
O **CPP Module 00** marca a transição oficial da programação imperativa e procedural em **C** para o paradigma de **Programação Orientada a Objetos (POO)** em **C++98**.

O objetivo fundamental deste módulo é desconstruir os vícios do C puro (como uso de `printf`, structs desprotegidas e manipulação manual de buffers com arrays de caracteres) e introduzir:
- **Namespaces** (`std::`) e resolução de escopo (`::`).
- **Streams padrão de Entrada/Saída** (`std::cin`, `std::cout`, `std::endl`).
- **Encapsulamento com Classes** (diferença entre `class` e `struct`, modificadores de acesso `private` e `public`).
- **Manipulação moderna de texto** com `std::string` e formatação com `<iomanip>`.
- **Membros e Métodos Estáticos** (`static` attributes e `static` methods), gerenciando estado compartilhado da classe.

---

## 📂 Estrutura de Diretórios

```
cpp00/
├── ex00/
│   ├── Makefile
│   └── megaphone.cpp
├── ex01/
│   ├── Contact.cpp
│   ├── Contact.hpp
│   ├── Makefile
│   ├── PhoneBook.cpp
│   ├── PhoneBook.hpp
│   └── main.cpp
├── ex02/
│   ├── Account.cpp
│   ├── Account.hpp
│   ├── Makefile
│   └── tests.cpp
├── DEFENSE_GUIDE.md   <-- Guia pedagógico completo para defesa e estudo
└── README.md          <-- Documentação técnica do módulo
```

---

## 🛠️ Exercícios e Compilação

Todos os projetos compilam rigorosamente sob o padrão **C++98** com as flags exigidas pela Escola 42:
`-Wall -Wextra -Werror -std=c++98`.

### Exercício 00: Megaphone
Transforma todos os argumentos de linha de comando em letras maiúsculas. Se nenhum argumento for passado, imprime uma mensagem padrão de ruído.
```bash
cd ex00
make
./megaphone "shhhhh... I think the students are asleep..."
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
./megaphone
```

### Exercício 01: My Awesome PhoneBook
Uma agenda de contatos interativa em linha de comando que gerencia até 8 contatos em formato de buffer circular:
- Comandos suportados: `ADD`, `SEARCH`, `EXIT`.
- Validação estrita: campos vazios não são permitidos.
- Formatação em tabela: 4 colunas com largura de 10 caracteres, alinhadas à direita e truncadas com ponto final (`.`).
- Tratamento seguro de `EOF` (Ctrl+D) sem loops infinitos.
```bash
cd ex01
make
./phonebook
```

### Exercício 02: The Job of Your Dreams
Engenharia reversa da classe `Account` com base no arquivo de cabeçalho `Account.hpp` e no log de execução original `19920104_091532.log`:
- Rastreamento de contas bancárias, saldo total, total de depósitos e saques através de atributos estáticos.
- Timestamps gerados com `<ctime>`.
```bash
cd ex02
make
./bank_tests
```

---

## 🛡️ Validação de Memória
Nenhum dos exercícios do Módulo 00 utiliza alocação dinâmica com `new`/`delete`. Todas as instâncias vivem na stack ou no escopo de classe, garantindo **0 vazamentos de memória**.
Para verificar com Valgrind:
```bash
valgrind --leak-check=full ./phonebook
```
