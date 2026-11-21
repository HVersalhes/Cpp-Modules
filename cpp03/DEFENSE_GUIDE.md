# 🎓 CPP03 — Guia Pedagógico de Estudo e Preparação para Defesas

Este guia desvenda toda a mecânica de **Herança** e **Herança Virtual** em C++, comparando os conceitos com a arquitetura que usávamos em C puro.

---

## 🧠 Tabela Comparativa: Do C para o C++

| Em C Puro | Em C++98 | O que muda? Vantagens de C++ |
| :--- | :--- | :--- |
| Composição manual de structs:<br>`struct s_scav { t_clap base; int guard; };` | Herança direta:<br>`class ScavTrap : public ClapTrap` | `ScavTrap` **é um** `ClapTrap`. Pode ser passado para qualquer função que espere um `ClapTrap` sem casts manuais. |
| Inicialização manual da struct base:<br>`init_clap(&scav.base);` | Construtor em cadeia automático | C++ garante que o construtor da classe base SEMPRE execute antes do corpo da classe filha. |
| Desalocação manual na ordem inversa | Destrutores em cadeia reversa | Ao destruir a filha, o compilador chama automaticamente o destrutor da filha e, em seguida, o da base. |
| Structs aninhadas com duplicação em diamante | Herança Virtual (`virtual public`) | Garante uma **única instância compartilhada** da classe ancestral comum na memória. |

---

## 🔍 Análise Detalhada Exercício por Exercício

### 🔹 Exercício 00: `claptrap` (Aaaaand... OPEN!)

#### 1. O que este exercício ensina?
- Criação da classe base fundamental com atributos de saúde (`_hitPoints`), energia (`_energyPoints`) e dano de ataque (`_attackDamage`).
- Lógica de estados: um robô sem energia ou destruído (0 HP) não pode atacar nem ser reparado.

#### 2. Modificadores de Acesso:
- `private`: Acessível **apenas** dentro da própria classe.
- `protected`: Acessível pela própria classe **e por suas classes filhas (derivadas)**.
- `public`: Acessível por qualquer código externo.

---

### 🔹 Exercício 01: `scavtrap` (Serena, my love!)

#### 1. A Cadeia de Construtores e Destrutores:
Quando executamos:
```cpp
ScavTrap scav("SC4V");
```
A saída no terminal é:
1. `ClapTrap SC4V constructed.` (Base primeiro!)
2. `ScavTrap SC4V constructed.` (Filha depois!)

E ao término do escopo (destruição):
1. `ScavTrap SC4V destroyed.` (Filha primeiro!)
2. `ClapTrap SC4V destroyed.` (Base depois!)

#### 2. Por que a ordem é invertida?
Analogia pedagógica:
- Para construir o 2º andar de uma casa, a fundação (1º andar) deve ser construída primeiro.
- Para demolir a casa sem desabar tudo, o 2º andar deve ser demolido antes da fundação!

---

### 🔹 Exercício 02: `fragtrap` (Trabalho Repetitivo)

#### 1. O que este exercício ensina?
- Reforço do padrão de herança com valores de atributos diferentes (100 HP, 100 EP, 30 AD).
- Habilidade única: `highFivesGuys()`.
- Demonstra que múltiplos tipos derivados (`ScavTrap` e `FragTrap`) podem herdar da mesma classe base `ClapTrap`.

---

### 🔹 Exercício 03: `diamondtrap` (O Problema do Diamante)

#### 1. O que é o Problema do Diamante (Diamond Problem)?
Considere o grafo de herança:
```
      ClapTrap
       /    \
  ScavTrap  FragTrap
       \    /
     DiamondTrap
```
Sem a palavra-chave `virtual`:
- `ScavTrap` contém uma cópia inteira de `ClapTrap`.
- `FragTrap` contém OUTRA cópia inteira de `ClapTrap`.
- `DiamondTrap` herdaria **duas cópias** de `ClapTrap`!
  Isso causa:
  1. Ambiguidade: ao acessar `_name`, qual `_name` deve ser lido? O de `ScavTrap` ou o de `FragTrap`?
  2. Duplicação de memória e de construtores/destrutores (ClapTrap seria construído 2 vezes).

#### 2. Como resolvemos em C++?
Com **Herança Virtual**:
```cpp
class ScavTrap : virtual public ClapTrap { ... };
class FragTrap : virtual public ClapTrap { ... };
```
A palavra `virtual` instrui o compilador a criar uma **tabela de ponteiros de base virtual (vptr/vbtable)**, garantindo que exista apenas **uma única instância** de `ClapTrap` no layout de memória do `DiamondTrap`!

#### 3. Como DiamondTrap mescla os atributos:
- `_hitPoints`: 100 (de `FragTrap`)
- `_energyPoints`: 50 (de `ScavTrap`)
- `_attackDamage`: 30 (de `FragTrap`)
- `attack()`: herdado de `ScavTrap` através da diretiva `using ScavTrap::attack;`.
- Atributo próprio: `_name` (ocultando o `_name` de `ClapTrap`, que é acessível via `ClapTrap::_name`).

---

## 🧪 Perguntas Comuns de Defesa

- **P: Por que o destrutor da classe base `ClapTrap` deve ser `virtual`?**
  *R: Se deletarmos um objeto derivado através de um ponteiro para a classe base (`ClapTrap* ptr = new ScavTrap(); delete ptr;`), se o destrutor não for virtual, apenas o destrutor de `ClapTrap` será chamado, causando vazamento de memória da parte derivada!*
- **P: Por que o construtor do `ClapTrap` deve ser chamado explicitamente na lista de inicialização de `DiamondTrap`?**
  *R: Na herança virtual, a responsabilidade de inicializar a base virtual mais distante salta as classes intermediárias e vai diretamente para a classe mais derivada (`DiamondTrap`).*

---

## 🚀 Comandos Rápidos de Teste para a Defesa

```bash
# Testar ex00
cd ex00 && make && ./claptrap && make fclean

# Testar ex01 (observar a ordem de criação/destruição)
cd ../ex01 && make && ./scavtrap && make fclean

# Testar ex02
cd ../ex02 && make && ./fragtrap && make fclean

# Testar ex03 (verificar a criação única de ClapTrap e whoAmI)
cd ../ex03 && make && ./diamondtrap && make fclean
```
