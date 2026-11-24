<div align="center">

# 🚀 42 C++ Modules (CPP00 - CPP09)
### *Programação Orientada a Objetos (POO) em C++98*

[![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr)
[![C++98](https://img.shields.io/badge/C%2B%2B-98-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://en.cppreference.com/w/cpp/98)
[![Milestone](https://img.shields.io/badge/Milestone-4-blueviolet?style=for-the-badge)](https://42.fr)
[![Milestone](https://img.shields.io/badge/Milestone-5-blueviolet?style=for-the-badge)](https://42.fr)
[![Status](https://img.shields.io/badge/Status-Completed%20100%25-brightgreen?style=for-the-badge)]()
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)

<p align="center">
  Coleção completa dos 10 módulos de <b>C++</b> da <b>Escola 42</b>.<br>
  O objetivo desta trilha é introduzir gradualmente os pilares do paradigma de <b>Programação Orientada a Objetos (POO)</b>, partindo da transição da linguagem C para os conceitos fundamentais do padrão <b>C++98</b> até estruturas de dados avançadas e algoritmos da <b>Standard Template Library (STL)</b>.
</p>

---

</div>

## 📌 Sumário

- [Visão Geral & Diretrizes 42](#-visão-geral--diretrizes-42)
- [Regras Gerais de Desenvolvimento](#-regras-gerais-de-desenvolvimento)
- [Forma Canônica Ortodoxa (OCF)](#-forma-canônica-ortodoxa-ocf)
- [Estrutura dos Módulos](#-estrutura-dos-módulos)
- [Tabela de Progresso & Exercícios](#-tabela-de-progresso--exercícios)
- [Como Compilar e Executar](#-como-compilar-e-executar)
- [Boas Práticas e Validação de Memória](#-boas-práticas-e-validação-de-memória)
- [Instruções de Avaliação e Aprendizado](#-instruções-de-avaliação-e-aprendizado)

---

## 🧭 Visão Geral & Diretrizes 42

A jornada nos módulos de C++ é progressiva. Cada módulo constrói e aprofunda conceitos introduzidos nos módulos anteriores:

```
[CPP00] Namespaces, Classes, Membros, Streams I/O, Inicialização
   │
   ▼
[CPP01] Alocação Dinâmica (new/delete), Referências, Ponteiros para Membros
   │
   ▼
[CPP02] Polimorfismo Ad-hoc, Sobrecarga de Operadores, Forma Canônica Ortodoxa
   │
   ▼
[CPP03] Herança (Simples e Múltipla / Diamante)
   │
   ▼
[CPP04] Polimorfismo por Subtipo, Classes Abstratas e Interfaces
   │
   ▼
[CPP05] Tratamento de Exceções (try, catch, throw)
   │
   ▼
[CPP06] Casts em C++ (static_cast, dynamic_cast, reinterpret_cast, const_cast)
   │
   ▼
[CPP07] Templates (Funções genéricas e Classes genéricas)
   │
   ▼
[CPP08] Contêineres Templatizados, Iteradores e Algoritmos da STL
   │
   ▼
[CPP09] STL Aplicada (Resolução de problemas com Contêineres Dedicados)
```

---

## ⚙️ Regras Gerais de Desenvolvimento

De acordo com o regulamento oficial dos módulos C++ da 42:

- **Compilador e Flags**: Todo o código deve ser compilado com `c++` e as flags rigorosas:
  ```bash
  c++ -Wall -Wextra -Werror -std=c++98
  ```
- **Nomenclatura**:
  - Diretórios de exercícios: `ex00`, `ex01`, ..., `exn`.
  - Nomes de classes em **UpperCamelCase** (ex: `Fixed`, `Bureaucrat`, `ClapTrap`).
  - Arquivos nomeados de acordo com a classe: `NomeDaClasse.hpp` e `NomeDaClasse.cpp`.
- **Proibições estritas**:
  - ❌ Proibido o uso de `*printf()`, `*alloc()` e `free()` (use `std::cout`, `std::cin`, `new` e `delete`).
  - ❌ Proibido `using namespace <nome>` e a palavra-chave `friend` (salvo indicação contrária explícita).
  - ❌ **Proibido o uso de qualquer contêiner ou algoritmo da STL do Módulo 00 até o Módulo 07!** A STL só é liberada a partir do **Módulo 08**.
  - ❌ Proibida qualquer biblioteca C++11 ou superior (incluindo `Boost`).
- **Headers & Includes**:
  - Cada cabeçalho deve ter **Include Guards** (`#ifndef`, `#define`, `#endif`).
  - Cada header deve ser autônomo (incluir suas dependências).
  - Não implementar definições de funções em arquivos `.hpp` (com exceção de funções/classes template).
- **Sem Norminette**: O C++ não possui verificação da ferramenta `norminette`, porém código legível, limpo e bem identado é critério de avaliação entre pares.

---

## 🧱 Forma Canônica Ortodoxa (OCF)

A partir do **Módulo 02**, toda classe projetada deve seguir a **Forma Canônica Ortodoxa** (*Orthodox Canonical Form*), a menos que haja orientação explícita em contrário. Ela é composta obrigatoriamente por 4 elementos:

```cpp
class Example {
    public:
        Example();                              // 1. Construtor Padrão
        Example(const Example &other);          // 2. Construtor de Cópia
        Example &operator=(const Example &rhs); // 3. Operador de Atribuição de Cópia
        virtual ~Example();                     // 4. Destrutor (virtual se polimórfico)
};
```

---

## 📂 Estrutura dos Módulos

```text
.
├── cpp00/          # Namespaces, classes, funções membro, streams stdio, static, const
│   ├── ex00/       # Megaphone
│   ├── ex01/       # Minha Incrível Agenda Telefônica (PhoneBook & Contact)
│   └── ex02/       # O Emprego Dos Seus Sonhos (Account)
├── cpp01/          # Alocação de memória, ponteiros para membros, referências, switch
│   ├── ex00/       # BraiiiiiiinnnzzzZ (Zombie)
│   ├── ex01/       # Moar brainz! (zombieHorde)
│   ├── ex02/       # HI THIS IS BRAIN (Ponteiros vs Referências)
│   ├── ex03/       # Unnecessary violence (Weapon, HumanA, HumanB)
│   ├── ex04/       # Sed is for losers (Manipulação de arquivos)
│   ├── ex05/       # Harl 2.0 (Ponteiros para funções membro)
│   └── ex06/       # Harl filter (Declaração switch)
├── cpp02/          # Polimorfismo ad-hoc, sobrecarga de operadores, OCF
│   ├── ex00/       # Minha Primeira Classe em Forma Canônica Ortodoxa (Fixed)
│   ├── ex01/       # Rumo a uma classe de ponto fixo mais útil
│   ├── ex02/       # Agora sim estamos conversando (Sobrecarga de operadores)
│   └── ex03/       # BSP (Binary Space Partitioning / Ponto no Triângulo)
├── cpp03/          # Herança
│   ├── ex00/       # Aaaaand... OPEN! (ClapTrap)
│   ├── ex01/       # Serena, my love! (ScavTrap)
│   ├── ex02/       # Repetitive work (FragTrap)
│   └── ex03/       # Now it's weird! (DiamondTrap - Herança Múltipla/Virtual)
├── cpp04/          # Polimorfismo de subtipo, classes abstratas, interfaces
│   ├── ex00/       # Polimorfismo (Animal, Dog, Cat, WrongAnimal)
│   ├── ex01/       # I don’t want to set the world on fire (Deep Copy vs Shallow Copy)
│   ├── ex02/       # Classe Abstrata (AAnimal, Funções Virtuais Puras)
│   └── ex03/       # Interface & Recapitulação (AMateria, Character, MateriaSource)
├── cpp05/          # Repetição e Exceções
│   ├── ex00/       # Mommy, when I grow up, I want to be a bureaucrat! (Bureaucrat)
│   ├── ex01/       # Form up, maggots! (Form / AForm)
│   ├── ex02/       # No, you need form 28B, not 28C... (Formulários Concretos)
│   └── ex03/       # At least this beats coffee-making (Intern)
├── cpp06/          # Casts em C++
│   ├── ex00/       # Conversão de tipos escalares (ScalarConverter / static_cast)
│   ├── ex01/       # Serialização (Serializer / reinterpret_cast)
│   └── ex02/       # Identificação de tipo real (Base / dynamic_cast)
├── cpp07/          # Templates
│   ├── ex00/       # Funções template (swap, min, max)
│   ├── ex01/       # Iter (Template function com callbacks)
│   └── ex02/       # Array (Template class para array dinâmico)
├── cpp08/          # Contêineres templatizados, iteradores, algoritmos
│   ├── ex00/       # Easy find (Algoritmos STL para contêineres)
│   ├── ex01/       # Span (Armazenamento de N números com distâncias)
│   └── ex02/       # Mutated abomination (MutantStack - Stack com Iteradores)
└── cpp09/          # STL (Standard Template Library)
    ├── ex00/       # Bitcoin Exchange (std::map para séries temporais)
    ├── ex01/       # Reverse Polish Notation (std::stack para cálculo RPN)
    └── ex02/       # PmergeMe (Algoritmo Ford-Johnson / Merge-Insert com 2 contêineres)
```

---

## 📊 Tabela de Progresso & Exercícios

| Módulo | Exercício | Nome / Descrição | Conceito Central | Status | Guia de Defesa |
| :---: | :---: | :--- | :--- | :---: | :---: |
| [**CPP00**](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp00/README.md) | `ex00` | Megaphone | `std::cout`, argumentos da CLI | [x] Concluído | [Guia CPP00](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp00/DEFENSE_GUIDE.md) |
| | `ex01` | PhoneBook | Classes, atributos privados, `std::cin` | [x] Concluído | |
| | `ex02` | Account | Atributos e métodos `static`, logs | [x] Concluído | |
| [**CPP01**](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp01/README.md) | `ex00` | BraiiiiiiinnnzzzZ | Heap vs Stack, `new` e `delete` | [x] Concluído | [Guia CPP01](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp01/DEFENSE_GUIDE.md) |
| | `ex01` | Moar brainz! | Alocação de arrays de objetos (`new[]`/`delete[]`) | [x] Concluído | |
| | `ex02` | HI THIS IS BRAIN | Ponteiros vs Referências | [x] Concluído | |
| | `ex03` | Unnecessary violence | Composição, referências em atributos | [x] Concluído | |
| | `ex04` | Sed is for losers | Streams de arquivo (`std::ifstream`, `std::ofstream`) | [x] Concluído | |
| | `ex05` | Harl 2.0 | Ponteiros para funções membro | [x] Concluído | |
| | `ex06` | Harl filter | Instrução `switch` e fallthrough deliberado | [x] Concluído | |
| [**CPP02**](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp02/README.md) | `ex00` | Fixed Base | Forma Canônica Ortodoxa básica | [x] Concluído | [Guia CPP02](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp02/DEFENSE_GUIDE.md) |
| | `ex01` | Fixed Useful | Ponto fixo em ponto flutuante e inteiros | [x] Concluído | |
| | `ex02` | Fixed Operators | Sobrecarga de operadores aritméticos/comparação | [x] Concluído | |
| | `ex03` | BSP | Particionamento Binário de Espaço (Geometria 2D) | [x] Concluído | |
| [**CPP03**](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp03/README.md) | `ex00` | ClapTrap | Criação de classe base | [x] Concluído | [Guia CPP03](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp03/DEFENSE_GUIDE.md) |
| | `ex01` | ScavTrap | Herança simples, construtores derivados | [x] Concluído | |
| | `ex02` | FragTrap | Cadeia de herança | [x] Concluído | |
| | `ex03` | DiamondTrap | Herança em diamante e herança virtual | [x] Concluído | |
| [**CPP04**](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp04/README.md) | `ex00` | Polymorphism | Funções virtuais, polimorfismo dinâmico | [x] Concluído | [Guia CPP04](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp04/DEFENSE_GUIDE.md) |
| | `ex01` | Deep Copy | Cópia profunda com membros alocados | [x] Concluído | |
| | `ex02` | Abstract Class | Classes abstratas e funções virtuais puras | [x] Concluído | |
| | `ex03` | Interface & Recap| Interfaces puras, inventário de Materias | [x] Concluído | |
| [**CPP05**](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp05/README.md) | `ex00` | Bureaucrat | `std::exception`, blocos `try`/`catch` | [x] Concluído | [Guia CPP05](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp05/DEFENSE_GUIDE.md) |
| | `ex01` | Form | Formulários e validação por exceção | [x] Concluído | |
| | `ex02` | Concrete Forms | Hierarquia de exceções e ações polimórficas | [x] Concluído | |
| | `ex03` | Intern | Padrão Factory com tratamento de erros | [x] Concluído | |
| [**CPP06**](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp06/README.md) | `ex00` | ScalarConverter | `static_cast` e conversão de literais | [x] Concluído | [Guia CPP06](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp06/DEFENSE_GUIDE.md) |
| | `ex01` | Serializer | `reinterpret_cast` para serialização de ponteiros | [x] Concluído | |
| | `ex02` | Identify Real Type | `dynamic_cast` e identificação em tempo de execução | [x] Concluído | |
| [**CPP07**](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp07/README.md) | `ex00` | Template Functions | Funções template (`swap`, `min`, `max`) | [x] Concluído | [Guia CPP07](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp07/DEFENSE_GUIDE.md) |
| | `ex01` | Iter | Função template com iteração e callbacks | [x] Concluído | |
| | `ex02` | Array | Classe template para manipulação de array | [x] Concluído | |
| [**CPP08**](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp08/README.md) | `ex00` | Easy find | Algoritmos de busca em contêineres STL | [x] Concluído | [Guia CPP08](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp08/DEFENSE_GUIDE.md) |
| | `ex01` | Span | Gerenciamento de intervalos em contêineres | [x] Concluído | |
| | `ex02` | MutantStack | Tornando `std::stack` iterável com iteradores | [x] Concluído | |
| [**CPP09**](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp09/README.md) | `ex00` | Bitcoin Exchange | `std::map`, parsing de CSV e lookup temporal | [x] Concluído | [Guia CPP09](file:///home/hcosta/Documentos/42cursus/milestone%204/cpp-modules/cpp09/DEFENSE_GUIDE.md) |
| | `ex01` | RPN Calculator | `std::stack` para Notação Polonesa Reversa | [x] Concluído | |
| | `ex02` | PmergeMe | Merge-Insert Sort (Ford-Johnson) com 2 contêineres | [x] Concluído | |

---

## 🛠️ Como Compilar e Executar

Cada exercício possui seu próprio `Makefile` autônomo com as regras padrão: `all`, `clean`, `fclean` e `re`.

```bash
# Navegar até o diretório do exercício desejado
cd cpp00/ex00

# Compilar o programa
make

# Executar
./megaphone "shhhhh... I think the students are asleep..."

# Limpar arquivos objeto
make clean

# Limpar executáveis e objetos
make fclean

# Recompilar do zero
make re
```

---

## 🔍 Boas Práticas e Validação de Memória

Para garantir a ausência de vazamentos de memória (*memory leaks*) ou acessos inválidos, execute os programas com o **Valgrind**:

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./<nome_do_executavel> [argumentos]
```

Ou compile localmente adicionando flags de sanitização de memória durante o teste:
```bash
-fsanitize=address -g
```
*(Lembre-se de remover a flag `-fsanitize` antes da entrega final para respeitar rigorosamente a compilação padrão pedida pela 42).*

---

## 🧠 Instruções de Avaliação e Aprendizado

> [!IMPORTANT]
> **Filosofia de Aprendizado da 42**:
> - O verdadeiro valor dos módulos de C++ reside na capacidade de **raciocinar e internalizar** a Programação Orientada a Objetos.
> - O uso de IA deve ser direcionado para tirar dúvidas conceituais, **nunca para copiar soluções prontas**.
> - Durante a avaliação por pares (*peer-evaluation*), modificações no código ao vivo podem ser solicitadas pelos avaliadores para atestar o domínio real das escolhas de design e da linguagem.
> - Converse com seus colegas, discuta decisões arquiteturais e aprenda na prática!

---

<div align="center">
  <sub>Desenvolvido como parte do currículo da <b>Escola 42</b>.</sub>
</div>
