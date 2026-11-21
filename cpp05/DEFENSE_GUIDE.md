# 🎓 CPP05 — Guia Pedagógico de Estudo e Preparação para Defesas

Este guia explica como funcionam as **Exceções em C++98**, comparando o modelo de tratamento de erros com o retorno de códigos de erro em **C puro**.

---

## 🧠 Tabela Comparativa: Do C para o C++

| Em C Puro | Em C++98 | O que muda? Vantagem arquitetural |
| :--- | :--- | :--- |
| Retorno de códigos de erro (`return -1;` ou `errno`) | Lançamento de Exceções (`throw MyException();`) | **Separação de fluxo**: o caminho feliz do código não é poluído por dezenas de `if (ret == -1)`. Erros sobem automaticamente a pilha até o tratador adequado. |
| Erros ignorados silenciosamente pelo chamador | Impossível ignorar: se não houver `catch`, chama `std::terminate` | **Garantia de segurança**: nenhum erro crítico passa despercebido sem ser tratado. |
| Mensagens de erro em strings globais ou `strerror` | `const char* what() const throw();` | O método `what()` é polimórfico e padronizado na hierarquia `std::exception`. |
| Construtores não existem em C; se inicialização falhar, retorna `NULL` | Se o construtor falha, ele lança exceção | O objeto nem chega a ser criado se os parâmetros forem inválidos, preservando invariantes de classe. |

---

## 🔍 Análise Detalhada Exercício por Exercício

### 🔹 Exercício 00: `bureaucrat` (Mamãe, quando eu crescer, quero ser um burocrata!)

#### 1. A Lógica Invertida dos Graus:
Atenção à pegadinha número 1 da 42:
- **Grau 1**: Mais alto (Presidente).
- **Grau 150**: Mais baixo (Estagiário).
- **Incrementar grau (`incrementGrade`)**: Promover o burocrata significa **diminuir o número** (`_grade--`). Se tentar passar de 1, lança `GradeTooHighException`!
- **Decrementar grau (`decrementGrade`)**: Rebaixar o burocrata significa **aumentar o número** (`_grade++`). Se passar de 150, lança `GradeTooLowException`!

#### 2. Sintaxe da Exceção:
```cpp
class GradeTooHighException : public std::exception {
public:
    virtual const char* what() const throw();
};
```
O especificador `throw()` no final da função significa: "garanto que este método `what()` nunca lançará nenhuma exceção secundária".

---

### 🔹 Exercício 01: `form` (Em formação, vermes!)

#### 1. O que este exercício ensina?
- Relação entre duas classes (`Bureaucrat` e `Form`).
- Atributos `const` de identificação e requisitos que não podem ser modificados após a criação do formulário.
- Método `beSigned(const Bureaucrat& b)` e método de fachada `Bureaucrat::signForm(Form& form)`.

---

### 🔹 Exercício 02: `28b` (Não, você precisa do formulário 28B...)

#### 1. Arquitetura de Execução:
Um formulário só pode ser executado se:
1. Ele já tiver sido assinado (`_isSigned == true`).
2. O burocrata executor possuir grau suficiente (`executor.getGrade() <= _gradeToExecute`).

Na nossa implementação, criamos o método na classe base `checkExecutionRequirements(executor)`:
```cpp
void AForm::checkExecutionRequirements(const Bureaucrat& executor) const {
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
}
```
Isso evita repetição de código (DRY - Don't Repeat Yourself) em todos os 3 formulários concretos!

---

### 🔹 Exercício 03: `intern` (Pelo menos isso é melhor do que fazer café)

#### 1. O Padrão Factory (Fábrica):
O subject proíbe expressamente "uma floresta feia de if/else if/else".
Como implementamos elegantemente?
Com uma tabela de nomes associada a uma tabela de **ponteiros de funções fábrica**:
```cpp
static AForm* createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }
static AForm* createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }
static AForm* createPresidential(const std::string& target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string names[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
    AForm* (*creators[3])(const std::string&) = { &createShrubbery, &createRobotomy, &createPresidential };

    for (int i = 0; i < 3; i++) {
        if (names[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }
    std::cout << "Error: Intern does not know form " << formName << std::endl;
    return NULL;
}
```

---

## 🧪 Perguntas Comuns de Defesa

- **P: Por que capturamos exceções por referência (`catch (std::exception& e)`) em vez de por valor?**
  *R: Para evitar o fenômeno de "object slicing" (fatiamento de objeto) e permitir a execução polimórfica correta do método virtual `what()` da exceção derivada.*
- **P: O que acontece se uma exceção for lançada dentro de um construtor?**
  *R: O construtor é abortado imediatamente. Os destrutores de quaisquer atributos membros já construídos até aquele ponto são chamados automaticamente, e a memória do objeto não é vazada (prevenção RAII).*

---

## 🚀 Comandos Rápidos de Teste para a Defesa

```bash
# Testar ex00
cd ex00 && make && valgrind --leak-check=full ./bureaucrat && make fclean

# Testar ex01
cd ../ex01 && make && valgrind --leak-check=full ./form && make fclean

# Testar ex02
cd ../ex02 && make && valgrind --leak-check=full ./28b && make fclean

# Testar ex03 (Fábrica do Intern)
cd ../ex03 && make && valgrind --leak-check=full ./intern && make fclean
```
