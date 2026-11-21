# 📘 CPP Module 06 — Os 4 Casts em C++ (Type Casting)

## 🎯 Visão Geral do Módulo
O **CPP Module 06** é dedicado à eliminação dos perigosos casts de estilo C (`(int)x`) e ao domínio dos **4 operadores de conversão explícita de tipos em C++**:
1. `static_cast<T>(v)`: Conversões reversíveis e bem-definidas em tempo de compilação (números, conversão de tipos escalares, upcasting seguro em herança).
2. `reinterpret_cast<T>(v)`: Reinterpretação pura do padrão de bits de um tipo para outro sem conversão de valor (como ponteiro para inteiro não assinado `uintptr_t` e vice-versa).
3. `dynamic_cast<T>(v)`: Conversão segura em tempo de execução para tipos polimórficos, usando a RTTI (Run-Time Type Information) baseada na vtable.
4. `const_cast<T>(v)`: Remoção ou adição do qualificador `const` (apenas teórico, para completar o quarteto de casts).

---

## 📂 Estrutura de Diretórios

```
cpp06/
├── ex00/   # Conversão de tipos escalares (ScalarConverter com static_cast)
├── ex01/   # Serialização (Serializer com reinterpret_cast para uintptr_t)
├── ex02/   # Identificar tipo real (dynamic_cast com ponteiro e referência)
├── DEFENSE_GUIDE.md   <-- Guia didático completo para defesa e estudo
└── README.md          <-- Documentação técnica
```

---

## 🛠️ Compilação e Execução

Compilação com `c++ -Wall -Wextra -Werror -std=c++98`:
```bash
# ex00: Conversor Escalar
cd ex00 && make
./convert 0
./convert 42.0f
./convert nan
./convert -inff

# ex01: Serializador
cd ../ex01 && make && ./serialize

# ex02: Identificação Dinâmica de Tipo Real
cd ../ex02 && make && ./identify
```

---

## 🛡️ Validação de Memória
Execução 100% limpa no Valgrind:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./<executavel>
```
Resultado: **0 bytes perdidos em 0 blocos**.
