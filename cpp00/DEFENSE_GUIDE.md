# 🎓 CPP00 — Guia Pedagógico de Estudo e Preparação para Defesas

Este guia foi elaborado para explicar em detalhes o raciocínio por trás de cada linha de código, comparando cada funcionalidade com a linguagem **C** que você utilizou nos projetos anteriores da 42 (como *libft*, *ft_printf*, *push_swap*, *minishell*, *philosophers*).

---

## 🧠 Mapa Mental da Transição: Do C para o C++

| Em C Puro (Norminette) | Em C++98 (POO) | Por que mudou? O que ganhamos? |
| :--- | :--- | :--- |
| `printf("%s\n", str);` | `std::cout << str << std::endl;` | **Type-safety**: O compilador identifica o tipo automaticamente sem precisar de `%s`, `%d`, evitando falhas de segmentação por tipagem incorreta. |
| `scanf("%s", buffer);` ou `get_next_line` | `std::getline(std::cin, input);` | **Buffer Overflow Prevention**: `std::string` cresce dinamicamente na heap sem risco de estouro de array estático de char. |
| `char str[100]; strlen(str);` | `std::string str; str.length();` | Manipulação segura de memória; a classe gerencia sua própria alocação e destruição (RAII). |
| `typedef struct s_contact { ... } t_contact;` | `class Contact { private: ... public: ... };` | **Encapsulamento**: Os dados internos da struct ficam protegidos de alterações indevidas de fora. Funções agora operam diretamente dentro da classe. |
| Variáveis globais (`static int total;` fora de funções) | Atributos estáticos de classe (`static int _nbAccounts;`) | Escopo controlado. A variável pertence à abstração da classe e não ao escopo global do arquivo. |

---

## 🔍 Análise Detalhada Exercício por Exercício

### 🔹 Exercício 00: `megaphone`

#### 1. O que este exercício ensina?
- Estrutura básica de um programa C++.
- O cabeçalho `<iostream>` e os objetos `std::cout` e `std::endl`.
- O namespace padrão `std::`.
- Conversão segura de tipos através de `static_cast<char>`.

#### 2. Como comparamos com C?
- **Em C**: Usaríamos `write(1, &c, 1)` ou `putchar(toupper(c))`.
- **Em C++**: Usamos o operador de inserção em fluxo (`<<`) com `std::cout`. Ele encadeia operações de escrita de forma limpa e segura.

#### 3. Como construímos e por quê?
- Se `argc == 1`, emitimos `* LOUD AND UNBEARABLE FEEDBACK NOISE *`.
- Para cada argumento a partir de `argv[1]`, convertemos cada caractere para maiúsculo com `std::toupper`.
- Por que usar `static_cast<char>(std::toupper(static_cast<unsigned char>(c)))`?
  Em C/C++, `toupper` recebe um `int` que deve ter o valor de um `unsigned char` ou `EOF`. Passar um `char` negativo com acento diretamente é comportamento indefinido. O `static_cast` explicita a conversão segura.

#### 4. Perguntas comuns na defesa:
- **P: Por que usar `std::endl` em vez de `\n`?**
  *R: `std::endl` imprime o caractere `\n` e executa um `flush` no buffer de saída, garantindo que tudo apareça imediatamente no terminal.*
- **P: O que significa `std::`?**
  *R: É a resolução de escopo (`::`) dentro do namespace padrão (`std`). Evita colisão de nomes entre bibliotecas.*

---

### 🔹 Exercício 01: `phonebook` (My Awesome PhoneBook)

#### 1. O que este exercício ensina?
- Criação e instanciação de classes (`Contact` e `PhoneBook`).
- Modificadores de acesso: `private` vs `public`.
- Métodos getters, setters e métodos de exibição.
- Formatação de saída com `<iomanip>` (`std::setw`, `std::right`).
- Buffer circular com operador módulo (`%`).
- Gerenciamento seguro de fluxos de entrada (`std::cin.eof()`).

#### 2. Como comparamos com C?
- **Em C**: Teríamos um array de `t_contact contacts[8]` com ponteiros soltos. Qualquer função do código poderia alterar diretamente o nome de um contato: `contacts[i].name[0] = '\0'`. Não existia proteção de dados.
- **Em C++**: Os atributos do contato são `private`. Ninguém fora da classe `Contact` consegue lê-los ou alterá-los sem chamar métodos públicos explicitamente projetados para isso.

#### 3. Como construímos e por quê?
- **Separação de responsabilidades**:
  - `Contact`: Conhece apenas os dados de um indivíduo (nome, apelido, telefone, segredo) e sabe formatar sua própria exibição.
  - `PhoneBook`: Conhece a coleção de contatos (array fixo de 8 elementos), controla o índice circular de inserção e gerencia os comandos `ADD` e `SEARCH`.
- **Buffer Circular**:
  `int index = _totalAdded % 8;`
  Ao atingir o 9º contato (`_totalAdded = 8`), `8 % 8 = 0`, sobrescrevendo o contato mais antigo exatamente como solicitado no subject!
- **Formatação de 10 caracteres**:
  Usamos `std::setw(10)` e `std::right`. Se a string tem mais de 10 caracteres, truncamos com `.substr(0, 9) + "."`.
- **Proteção contra Ctrl+D (EOF)**:
  Se o usuário pressionar Ctrl+D na entrada, `std::cin` entra em estado de falha/EOF. Nosso código verifica `std::cin.eof()` e sai elegantemente sem travar em loop infinito!

#### 4. Perguntas comuns na defesa:
- **P: Qual a diferença entre `class` e `struct` em C++?**
  *R: Em C++, a única diferença formal é a visibilidade padrão: na `class`, membros e herança são `private` por padrão; na `struct`, são `public` por padrão.*
- **P: Por que os atributos de `Contact` são `private`?**
  *R: Princípio do encapsulamento: proteger o estado interno do objeto para que ele só seja manipulado por métodos validados da própria classe.*
- **P: Por que o subject proíbe `using namespace std;`?**
  *R: Importar o namespace inteiro no escopo global polui o namespace e pode causar conflitos de nomes (ambiguidade) entre identificadores definidos pelo programador e identificadores da biblioteca padrão.*

---

### 🔹 Exercício 02: `bank_tests` (The Job of Your Dreams / Account.cpp)

#### 1. O que este exercício ensina?
- Variáveis estáticas de classe (`static int _nbAccounts`, etc.).
- Métodos estáticos (`static void displayAccountsInfos()`).
- O ciclo de vida de um objeto: construtor e destrutor.
- Engenharia reversa baseada em arquivo de cabeçalho (`Account.hpp`) e logs de teste.

#### 2. Como comparamos com C?
- **Em C**: Para contar quantas instâncias de uma struct existem no programa inteiro, criaríamos uma variável global no topo do arquivo `.c`. Qualquer arquivo externo poderia acidentalmente modificar essa variável global (`total_accounts = -999;`).
- **Em C++**: Membros estáticos pertencem à **classe**, não a instâncias específicas. Existe apenas uma única cópia compartilhada entre todos os objetos da classe `Account`. Além disso, sendo `private`, apenas a classe pode alterar esses totais.

#### 3. Como construímos e por quê?
- **Inicialização de membros estáticos**:
  Membros estáticos precisam ser definidos fora da declaração da classe, no arquivo `.cpp`:
  ```cpp
  int Account::_nbAccounts = 0;
  int Account::_totalAmount = 0;
  ```
- **Construtor**:
  Incrementa `_nbAccounts`, soma `initial_deposit` em `_totalAmount`, atribui o índice da conta e imprime a criação com timestamp.
- **Destrutor**:
  Imprime o encerramento da conta ao ser destruída (quando sai de escopo).
- **Depósitos e Saques**:
  Em `makeWithdrawal`, verificamos se o saldo é suficiente. Se não for, imprimimos `refused` e retornamos `false`. Se for suficiente, deduzimos e atualizamos os contadores globais e locais.
- **Timestamp**:
  Usamos `std::time` e `std::strftime` para formatar `[%Y%m%d_%H%M%S]`.

#### 4. Perguntas comuns na defesa:
- **P: Um método estático pode acessar atributos normais (não-estáticos) da classe?**
  *R: Não! Métodos estáticos não possuem o ponteiro implícito `this`. Eles só podem acessar membros estáticos da classe.*
- **P: Por que variáveis membros estáticas devem ser inicializadas no arquivo `.cpp` e não no `.hpp`?**
  *R: Porque o arquivo de cabeçalho pode ser incluído em múltiplas unidades de tradução. Se a definição estivesse no `.hpp`, o linker acusaria erro de símbolo duplicado (ODR - One Definition Rule).*

---

## 🧪 Comandos Rápidos de Teste para a Defesa

```bash
# 1. Testar ex00
cd ex00 && make && ./megaphone "Ola 42" && ./megaphone && make fclean

# 2. Testar ex01 com entradas válidas e inválidas
cd ../ex01 && make
./phonebook
# Testar:
# - Enviar espaços vazios no ADD (deve recusar)
# - Adicionar mais de 8 contatos (verificar se o 1º é substituído)
# - Enviar índice fora do alcance ou letras no SEARCH (deve tratar com erro amigável)
# - Pressionar Ctrl+D (deve sair graciosamente)
make fclean

# 3. Testar ex02 e conferir saída com o log oficial
cd ../ex02 && make
./bank_tests > meu_log.log
diff <(cut -d ' ' -f2- ../19920104_091532.log) <(cut -d ' ' -f2- meu_log.log)
# O diff não deve retornar nenhuma diferença!
make fclean
```
