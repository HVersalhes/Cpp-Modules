# 🎓 CPP01 — Guia Pedagógico de Estudo e Preparação para Defesas

Este guia explica todos os conceitos técnicos do CPP01 em palavras simples, comparando cada funcionalidade com a linguagem C e antecipando as pegadinhas e perguntas dos avaliadores.

---

## 🧠 Tabela Comparativa: Do C para o C++

| Em C Puro | Em C++98 | O que muda? Vantagens fundamentais |
| :--- | :--- | :--- |
| `malloc(sizeof(t_zombie))` | `new Zombie("Nome")` | `malloc` aloca apenas bytes brutos na memória. `new` aloca a memória **e chama o construtor**, garantindo estado válido inicial. |
| `free(ptr)` | `delete ptr` | `free` apenas libera a região. `delete` **invoca o destrutor** do objeto antes de desalocar a memória. |
| `malloc(N * sizeof(t_zombie))` / `free(arr)` | `new Zombie[N]` / `delete[] arr` | `delete[]` consulta os metadados do array para saber o tamanho exato `N` e chama o destrutor de cada elemento individualmente. |
| Ponteiro: `t_var *ptr = &var;` | Referência: `t_var &ref = var;` | Uma referência é um alias (apelido imutável). **Não pode ser nula** e **não pode ser reatribuída** para apontar para outro endereço. |
| `fopen()`, `fputs()`, `fclose()` | `std::ifstream`, `std::ofstream` | Gerenciamento automático de recursos via RAII. Ao sair do escopo, o arquivo é fechado automaticamente. |
| Ponteiro de função: `void (*f)(void)` | Ponteiro de membro: `void (Class::*f)(void)` | Métodos de classe exigem o ponteiro de instância `this` para serem executados (`(obj.*f)()` ou `(this->*f)()`). |

---

## 🔍 Análise Detalhada Exercício por Exercício

### 🔹 Exercício 00: `zombie` (BraiiiiiiinnnzzzZ)

#### 1. O que este exercício ensina?
- Alocação na **Stack** vs alocação na **Heap**.
- Quando um objeto deve viver apenas no escopo de uma função (Stack) vs quando sua vida útil deve ultrapassar o término da função (Heap).
- O operador `delete` chamando o destrutor.

#### 2. Como comparamos com C?
- Em C:
  - Stack: `t_zombie z; init_zombie(&z);` (destruído automaticamente ao desempilhar).
  - Heap: `t_zombie *z = malloc(sizeof(t_zombie));` (requer `free(z)` manual).
- Em C++:
  - `newZombie`: usa `new Zombie(name)` e retorna o ponteiro `Zombie*`. A responsabilidade de chamar `delete` é de quem recebe o ponteiro.
  - `randomChump`: cria `Zombie z(name)` diretamente na stack. Quando a função termina (`}`), o destrutor `~Zombie()` é executado automaticamente.

#### 3. Perguntas da defesa:
- **P: O que acontece se chamarmos `free` em vez de `delete` em um objeto C++?**
  *R: O `free` apenas libera a memória bruta, mas NUNCA chama o destrutor. Se o objeto tiver strings ou ponteiros internos, eles vazarão memória (leak)!*
- **P: Quando devo usar Stack e quando devo usar Heap?**
  *R: Use Stack por padrão (muito mais rápido e desalocação garantida). Use Heap apenas se o objeto precisar sobreviver ao escopo atual ou for grande demais para a pilha (evitar stack overflow).*

---

### 🔹 Exercício 01: `moar_brainz` (Moar brainz!)

#### 1. O que este exercício ensina?
- Alocação contígua de múltiplos objetos com `new[]`.
- Desalocação obrigatória com `delete[]`.
- Construtor padrão necessário para arrays de objetos.

#### 2. Como comparamos com C?
- Em C: `malloc(N * sizeof(t_zombie))` e `free(ptr)`.
- Em C++: `new Zombie[N]` aloca memória para N zumbis e chama o construtor padrão em cada um deles.
  Se você usar `delete ptr` em vez de `delete[] ptr`, o C++ chamará o destrutor **apenas do primeiro elemento**, deixando os outros N-1 sem destruição (comportamento indefinido e vazamento!).

---

### 🔹 Exercício 02: `hi_this_is_brain` (HI THIS IS BRAIN)

#### 1. O que este exercício ensina?
- A sintaxe e semântica de ponteiros (`std::string*`) vs referências (`std::string&`).
- Comparação explícita de endereços de memória e valores.

#### 2. Raciocínio & Código:
- `&brain`: endereço da variável.
- `stringPTR`: armazena o endereço de `brain`.
- `&stringREF`: produz o mesmo endereço de `brain`, pois a referência é a própria variável com outro nome.
- `*stringPTR`: desreferencia o ponteiro para ler o valor.
- `stringREF`: lê o valor diretamente sem precisar de `*`.

---

### 🔹 Exercício 03: `unnecessary_violence` (Unnecessary violence)

#### 1. O que este exercício ensina?
- Escolha arquitetural crucial em C++: **Ponteiro vs Referência em atributos de classe**.
- Lista de inicialização de construtores.

#### 2. Por que HumanA usa Referência e HumanB usa Ponteiro?
- **HumanA**:
  - Exigência: "HumanA will always be armed".
  - Por isso, recebe `Weapon&` no construtor e armazena `Weapon& _weapon;`.
  - Como referências devem ser vinculadas no momento da instanciação, **precisa obrigatoriamente** ser inicializado na lista de inicialização do construtor:
    `HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}`
- **HumanB**:
  - Exigência: "HumanB may not always have a weapon".
  - Um HumanB pode ser criado desarmado. Referências não podem ser nulas nem deixadas para depois.
  - Portanto, HumanB armazena um ponteiro `Weapon* _weapon;` inicializado com `NULL`, e recebe uma arma depois através de `setWeapon(Weapon& weapon)`.

#### 3. Perguntas da defesa:
- **P: Posso inicializar uma referência com NULL?**
  *R: Não! Uma referência sempre deve apontar para um objeto válido na memória.*
- **P: Posso alterar uma referência para referenciar outro objeto depois?**
  *R: Não! Se fizer `ref = outro;`, você estará copiando o valor de `outro` para dentro do objeto referenciado, e não mudando o vínculo da referência.*

---

### 🔹 Exercício 04: `replace` (Sed is for losers)

#### 1. O que este exercício ensina?
- Entrada e saída de arquivos com `std::ifstream` e `std::ofstream`.
- Algoritmo de busca e substituição de strings usando `std::string::find` e `std::string::substr`.
- Prevenção de loop infinito em substituições recursivas (ex: substituir "a" por "aa").

#### 2. Como comparamos com C?
- Em C: Abriríamos com `fopen`, teríamos que calcular tamanhos de buffers com `fseek`/`ftell`, alocar dinamicamente com `malloc`, usar `strstr` e gerenciar `fclose`.
- Em C++: Os fluxos fecham automaticamente ao sair do escopo (RAII). O método `.find()` e manipulação de `std::string` eliminam riscos de estouro de memória.

---

### 🔹 Exercício 05: `harl` (Harl 2.0)

#### 1. O que este exercício ensina?
- Ponteiros para funções membro de classe: `void (Harl::*actions[4])(void)`.
- Eliminação de sequências de `if / else if / else` (Open-Closed Principle).

#### 2. Como comparamos com C?
- Em C: Criávamos tabelas de ponteiros de funções comuns: `void (*funcs[4])(void);`.
- Em C++: Funções membros não são funções globais; elas operam sobre uma instância (`this`).
  A sintaxe requer vincular a função à classe:
  `void (Harl::*actions[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };`
  E para chamá-la sobre a instância atual:
  `(this->*actions[i])();`

---

### 🔹 Exercício 06: `harlFilter` (Harl filter)

#### 1. O que este exercício ensina?
- A declaração `switch` e a técnica de **fallthrough deliberado**.
- Filtragem de mensagens hierárquicas de log (ex: se o nível for WARNING, exibe WARNING e ERROR).

#### 2. O que avaliar na defesa?
- O avaliador perguntará por que não há `break;` entre os casos do `switch`.
- Resposta: O comportamento esperado pelo subject é que um filtro de nível exiba todas as mensagens daquele nível **e dos níveis superiores**. Portanto, o fallthrough deliberado é a solução correta e canônica.

---

## 🧪 Comandos Rápidos de Teste para a Defesa

```bash
# Teste ex00 (leak check)
cd ex00 && make && valgrind --leak-check=full ./zombie && make fclean

# Teste ex01 (leak check horde)
cd ../ex01 && make && valgrind --leak-check=full ./moar_brainz && make fclean

# Teste ex02 (endereços e referências)
cd ../ex02 && make && ./hi_this_is_brain && make fclean

# Teste ex03 (HumanA e HumanB)
cd ../ex03 && make && ./unnecessary_violence && make fclean

# Teste ex04 (substituição)
cd ../ex04 && make
echo "42 Lisboa e 42 Porto sao 42" > entrada.txt
./replace entrada.txt "42" "Escola 42"
cat entrada.txt.replace
# Deve imprimir: Escola 42 Lisboa e Escola 42 Porto sao Escola 42
rm -f entrada.txt entrada.txt.replace && make fclean

# Teste ex05 (Harl)
cd ../ex05 && make && ./harl && make fclean

# Teste ex06 (Harl Filter)
cd ../ex06 && make
./harlFilter "WARNING"
./harlFilter "BATATA"
make fclean
```
