# 🎓 CPP04 — Guia Pedagógico de Estudo e Preparação para Defesas

Este guia explica a mecânica do **Polimorfismo Dinâmico**, **Classes Abstratas** e **Interfaces** em C++, comparando com o que tínhamos em C e preparando você para gabaritar a avaliação.

---

## 🧠 Tabela Comparativa: Do C para o C++

| Em C Puro | Em C++98 | O que muda? Revolução da POO |
| :--- | :--- | :--- |
| `switch (shape->type) { case DOG: ... }` | `animal->makeSound();` | **Polimorfismo**: O código não precisa saber qual animal específico é. O compilador resolve dinamicamente em tempo de execução via **vtable**. |
| Ponteiros de funções em structs (`struct { void (*sound)(); }`) | Funções virtuais (`virtual void makeSound();`) | C++ automatiza a tabela de ponteiros de funções (chamada `vtable`), embutindo um ponteiro oculto `vptr` em cada instância. |
| Clones manuais copiando structs e buffers | `virtual AMateria* clone() const = 0;` | Padrão **Prototype**: cada classe derivada sabe exatamente como alocar e clonar a si mesma. |
| Structs vazias ou typedefs sem regras | Interfaces puras (`class ICharacter`) | Contrato estrito garantido pelo compilador. Nenhuma classe filha compila a menos que implemente todos os métodos exigidos. |

---

## 🔍 Análise Detalhada Exercício por Exercício

### 🔹 Exercício 00: `polymorphism` (Polymorphism)

#### 1. Como funciona a Vtable (Virtual Table)?
- Quando uma classe possui ao menos um método `virtual`, o compilador adiciona um atributo oculto à classe: o **`vptr`** (virtual table pointer).
- O `vptr` aponta para a `vtable` daquela classe específica (uma tabela estática com endereços das funções).
- Ao chamar `animal->makeSound()`, o programa consulta:
  1. O ponteiro `vptr` da instância real na memória.
  2. A entrada correspondente a `makeSound` na `vtable`.
  3. Executa a função do `Dog` ou `Cat`, mesmo que o tipo da variável seja `const Animal*`!

#### 2. Por que o `WrongCat` não funciona?
No `WrongAnimal`, `makeSound()` **não é virtual**.
Portanto, o compilador realiza **vinculação estática (early binding)** com base apenas no tipo do ponteiro (`WrongAnimal*`). Ele nem olha o que está na memória e chama diretamente o som genérico de `WrongAnimal`!

#### 3. A regra de ouro do Destrutor Virtual:
Se a classe base tiver destrutor comum (`~Animal()`), ao fazer:
```cpp
Animal* a = new Dog();
delete a;
```
O compilador só chamará `~Animal()`, e o destrutor de `Dog` será ignorado! Se `Dog` alocasse memória na heap, haveria vazamento.
Ao declarar `virtual ~Animal()`, o destrutor entra na `vtable`, garantindo que `~Dog()` seja chamado primeiro e `~Animal()` depois!

---

### 🔹 Exercício 01: `brain` (I don’t want to set the world on fire)

#### 1. Cópia Rasa (Shallow Copy) vs Cópia Profunda (Deep Copy):
- **Cópia Rasa**: Apenas copia o endereço do ponteiro `_brain`. Dois cachorros passam a apontar para o **mesmo cérebro** na heap. Ao destruir o primeiro, o segundo fica com um ponteiro pendente (*dangling pointer*); ao destruir o segundo, ocorre **double free**!
- **Cópia Profunda**: Aloca um **novo `Brain` independente** na heap (`new Brain(*other._brain)`) e copia o conteúdo das 100 ideias uma a uma. Cada cachorro é dono exclusivo do seu cérebro.

---

### 🔹 Exercício 02: `abstract_animal` (Abstract class)

#### 1. O que torna uma classe abstrata?
A presença de ao menos um **método virtual puro**:
```cpp
virtual void makeSound() const = 0;
```
A sintaxe `= 0` diz ao compilador: "esta classe base não possui implementação própria deste método; qualquer classe filha concreta DEVE implementá-lo".
Consequência:
```cpp
AAnimal test; // ERRO de compilação! Impossível instanciar classe abstrata.
```

---

### 🔹 Exercício 03: `materia` (Interface & recap)

#### 1. O que é uma Interface em C++98?
C++ não possui a palavra-chave `interface` (como Java ou C#). Em C++, uma interface é modelada como uma **classe puramente abstrata**:
- Contém apenas métodos virtuais puros (`= 0`).
- Não possui atributos de dados (apenas comportamento).
- Possui destrutor virtual: `virtual ~ICharacter() {}`.

#### 2. Regras Críticas do Inventário:
- O personagem possui 4 slots (`_inventory[4]`).
- `equip(AMateria* m)`: preenche o primeiro slot livre (de 0 a 3).
- `unequip(int idx)`: **NÃO pode deletar** a Materia! O slot é desvinculado (`NULL`), e o endereço fica sob responsabilidade do chamador (para evitar memory leak).
- Cópia do personagem deve ser profunda: ao clonar um personagem, cada Materia equipada no seu inventário é clonada com `.clone()`.

---

## 🧪 Perguntas de Defesa que os Avaliadores Fazem:

- **P: O que acontece na memória durante a chamada de um método virtual?**
  *R: O programa lê o ponteiro `vptr` localizado no início da instância, acessa a `vtable` da classe do objeto real e salta para o endereço do método correspondente.*
- **P: Qual a diferença entre classe abstrata e interface em C++?**
  *R: Uma classe abstrata pode conter atributos de dados e métodos com implementação concreta (além dos puros). Uma interface contém exclusivamente métodos virtuais puros e nenhum atributo.*
- **P: Por que `AMateria::clone()` retorna `AMateria*` e não `void`?**
  *R: Padrão Prototype: a função aloca na heap uma nova instância idêntica da classe derivada concreta (`new Ice(*this)` ou `new Cure(*this)`) e a devolve polimorficamente.*

---

## 🚀 Comandos Rápidos de Teste para a Defesa

```bash
# Testar ex00
cd ex00 && make && valgrind --leak-check=full ./polymorphism && make fclean

# Testar ex01 (verificar deep copy e ausência de double free)
cd ../ex01 && make && valgrind --leak-check=full ./brain && make fclean

# Testar ex02
cd ../ex02 && make && valgrind --leak-check=full ./abstract_animal && make fclean

# Testar ex03 (suíte completa de testes de Materia e inventário)
cd ../ex03 && make && valgrind --leak-check=full ./materia && make fclean
```
