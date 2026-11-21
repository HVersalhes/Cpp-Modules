# 📘 CPP Module 01 — Alocação Dinâmica, Referências, Ponteiros para Membros e Switch

## 🎯 Visão Geral do Módulo
O **CPP Module 01** tem como foco aprofundar o entendimento de gerenciamento de memória em C++ e introduzir novos paradigmas que não existiam em C:
- **Alocação Dinâmica (`new` e `delete`)**: Substituição de `malloc` e `free` garantindo a execução automática de construtores e destrutores.
- **Alocação de Arrays (`new[]` e `delete[]`)**: O porquê da obrigatoriedade do operador com colchetes para invocar destrutores de cada elemento.
- **Ponteiros vs Referências (`T*` vs `T&`)**: Quando usar referências (imutabilidade do endereço, garantia de não-nulo) e quando usar ponteiros (opcionalidade, reatribuição).
- **Manipulação de Arquivos e Streams (`std::ifstream`, `std::ofstream`)**: Leitura, escrita e substituição de padrões em texto.
- **Ponteiros para Funções Membro (`Ret (Class::*ptr)(Args)`)**: Despacho dinâmico de métodos sem estruturas condicionais pesadas.
- **Instrução `switch` e Fallthrough**: Controle de fluxo para níveis de criticidade (Harl filter).

---

## 📂 Estrutura de Diretórios

```
cpp01/
├── ex00/   # BraiiiiiiinnnzzzZ (Stack vs Heap, newZombie vs randomChump)
├── ex01/   # Moar brainz! (Array dinâmico com new[] e delete[])
├── ex02/   # HI THIS IS BRAIN (Ponteiro vs Referência na prática)
├── ex03/   # Unnecessary violence (HumanA com Weapon& vs HumanB com Weapon*)
├── ex04/   # Sed is for losers (Substituição de arquivos com streams)
├── ex05/   # Harl 2.0 (Ponteiros para funções membro)
├── ex06/   # Harl filter (Declaração switch com fallthrough)
├── DEFENSE_GUIDE.md   <-- Guia didático completo para defesa e estudo
└── README.md          <-- Documentação técnica
```

---

## 🛠️ Compilação e Execução

Todos os exercícios compilam com:
```bash
make
```
e são limpos com:
```bash
make fclean
```

### Comandos de Teste Rápido:
```bash
# ex00: Zombie
cd ex00 && make && ./zombie

# ex01: Horde
cd ../ex01 && make && ./moar_brainz

# ex02: Brain (Pointer vs Reference)
cd ../ex02 && make && ./hi_this_is_brain

# ex03: HumanA vs HumanB
cd ../ex03 && make && ./unnecessary_violence

# ex04: Sed is for losers
cd ../ex04 && make && ./replace <arquivo> <string_antiga> <nova_string>

# ex05: Harl
cd ../ex05 && make && ./harl

# ex06: Harl Filter
cd ../ex06 && make && ./harlFilter "WARNING"
```

---

## 🛡️ Validação de Memória
Todos os exercícios foram validados com Valgrind:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./<executavel>
```
Resultado: **0 bytes perdidos em 0 blocos (All heap blocks were freed -- no leaks are possible)**.
