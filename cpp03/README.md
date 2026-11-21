# 📘 CPP Module 03 — Herança e o Problema do Diamante

## 🎯 Visão Geral do Módulo
O **CPP Module 03** explora a relação de **Herança** ("é um") na Programação Orientada a Objetos, culminando na herança múltipla e na solução canônica para o **Problema do Diamante (Diamond Problem)** em C++98:
- **Herança Simples (`class ScavTrap : public ClapTrap`)**: Reutilização de código, especialização de comportamento e visibilidade de membros (`protected`).
- **Ordem de Construção e Destruição**: Como o compilador constrói os objetos de baixo para cima (da classe base para a mais derivada) e destrói na ordem estritamente inversa.
- **Herança Múltipla (`class DiamondTrap : public ScavTrap, public FragTrap`)**: Combinação de comportamentos de múltiplas classes base.
- **Herança Virtual (`virtual public ClapTrap`)**: Como evitar a duplicação do subobjeto base e resolver conflitos de ambiguidade na memória.
- **Resolução de Escopo e Ocultação de Membros**: O uso de `using ScavTrap::attack;` e desambiguação de nomes (`ClapTrap::_name`).

---

## 📂 Estrutura de Diretórios

```
cpp03/
├── ex00/   # Aaaaand... OPEN! (Classe base ClapTrap)
├── ex01/   # Serena, my love! (ScavTrap e Gate keeper mode)
├── ex02/   # Repetitive work (FragTrap e High Fives)
├── ex03/   # Now it's weird! (DiamondTrap e Herança Virtual)
├── DEFENSE_GUIDE.md   <-- Guia didático completo para defesa e estudo
└── README.md          <-- Documentação técnica
```

---

## 🛠️ Compilação e Execução

Compilação com `c++ -Wall -Wextra -Werror -std=c++98`:
```bash
# ex00: ClapTrap
cd ex00 && make && ./claptrap

# ex01: ScavTrap
cd ../ex01 && make && ./scavtrap

# ex02: FragTrap
cd ../ex02 && make && ./fragtrap

# ex03: DiamondTrap (com suporte a -Wshadow)
cd ../ex03 && make && ./diamondtrap
```

---

## 🛡️ Validação de Memória
Execução 100% limpa no Valgrind:
```bash
valgrind --leak-check=full ./<executavel>
```
Garantia de **0 leaks de memória e 0 erros**.
