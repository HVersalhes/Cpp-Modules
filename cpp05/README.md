# 📘 CPP Module 05 — Tratamento de Exceções e Padrões de Projeto

## 🎯 Visão Geral do Módulo
O **CPP Module 05** introduz o mecanismo profissional de tratamento de erros em C++ através de **Exceções (`try`, `catch`, `throw`)** e classes derivadas de `std::exception`:
- **Hierarquia de Exceções**: Criação de classes de exceção personalizadas que herdam de `std::exception` e sobrescrevem o método virtual `const char* what() const throw();`.
- **Validação de Invariantes**: Garantir que um objeto nunca exista em um estado inválido (graus de 1 a 150 em `Bureaucrat` e `AForm`).
- **Padrão Template Method**: Validação centralizada na classe base abstrata `AForm::checkExecutionRequirements` antes de delegar a execução concreta para as subclasses.
- **Formulários Burocráticos Concretos**:
  - `ShrubberyCreationForm` (Grau 145/137)
  - `RobotomyRequestForm` (Grau 72/45)
  - `PresidentialPardonForm` (Grau 25/5)
- **Padrão Factory (Fábrica)**: A classe `Intern` instanciando formulários dinamicamente através de tabelas de ponteiros de funções sem estruturas `if/else if` caóticas.

---

## 📂 Estrutura de Diretórios

```
cpp05/
├── ex00/   # Bureaucrat básico com exceções de notas
├── ex01/   # Form com assinatura e requisitos de grau
├── ex02/   # AForm abstrato e formulários concretos (Shrubbery, Robotomy, Pardon)
├── ex03/   # Intern com criação dinâmica de formulários (Factory pattern)
├── DEFENSE_GUIDE.md   <-- Guia didático completo para defesa e estudo
└── README.md          <-- Documentação técnica
```

---

## 🛠️ Compilação e Execução

Compilação com `c++ -Wall -Wextra -Werror -std=c++98`:
```bash
# ex00: Bureaucrat
cd ex00 && make && ./bureaucrat

# ex01: Form
cd ../ex01 && make && ./form

# ex02: Formulários 28B
cd ../ex02 && make && ./28b

# ex03: Estagiário (Intern)
cd ../ex03 && make && ./intern
```

---

## 🛡️ Validação de Memória
Todos os 4 exercícios passaram sem nenhum vazamento ou erro no **Valgrind**:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./<executavel>
```
Resultado: **0 bytes perdidos em 0 blocos**.
