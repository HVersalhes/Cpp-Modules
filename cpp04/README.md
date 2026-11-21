# 📘 CPP Module 04 — Polimorfismo de Subtipos, Classes Abstratas e Interfaces

## 🎯 Visão Geral do Módulo
O **CPP Module 04** é o ápice da Programação Orientada a Objetos clássica em C++98, introduzindo:
- **Polimorfismo de Subtipos (Dynamic Dispatch)**: A diferença fundamental entre vinculação estática (*early binding*) e vinculação dinâmica (*late binding*) através da tabela virtual (**vtable/vptr**).
- **Destrutores Virtuais**: A regra de ouro da herança polimórfica para prevenir vazamentos de memória ao desalocar classes derivadas via ponteiro de classe base.
- **Cópia Profunda (Deep Copy)**: Gestão de recursos internos em classes compostas (`Brain` em `Dog` e `Cat`), garantindo que cópias possuam suas próprias regiões independentes na heap.
- **Classes Abstratas Puro-Sangue**: Classes com métodos virtuais puros (`= 0`) que não podem ser instanciadas diretamente (`AAnimal`).
- **Interfaces e Padrões de Projeto**: Interfaces puras (`ICharacter`, `IMateriaSource`) e o padrão Prototype/Factory para criação e clonagem de objetos (`AMateria::clone()`).

---

## 📂 Estrutura de Diretórios

```
cpp04/
├── ex00/   # Polymorphism (Animal, Dog, Cat vs WrongAnimal, WrongCat)
├── ex01/   # I don’t want to set the world on fire (Brain, deep copy)
├── ex02/   # Abstract class (AAnimal com método virtual puro)
├── ex03/   # Interface & recap (AMateria, Ice, Cure, Character, MateriaSource)
├── DEFENSE_GUIDE.md   <-- Guia didático completo para defesa e estudo
└── README.md          <-- Documentação técnica
```

---

## 🛠️ Compilação e Execução

Compilação com `c++ -Wall -Wextra -Werror -std=c++98`:
```bash
# ex00: Polimorfismo e Vtable
cd ex00 && make && ./polymorphism

# ex01: Deep Copy com Brain
cd ../ex01 && make && ./brain

# ex02: Classe Abstrata AAnimal
cd ../ex02 && make && ./abstract_animal

# ex03: Interfaces e Sistema de Materias (RPG)
cd ../ex03 && make && ./materia
```

---

## 🛡️ Validação de Memória
Todos os 4 exercícios foram testados com **Valgrind**:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./<executavel>
```
Resultado: **0 bytes perdidos, 0 erros de contexto em todos os cenários**.
