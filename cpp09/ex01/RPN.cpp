#include "RPN.hpp"
#include <sstream>

RPN::RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& rhs) { (void)rhs; return *this; }
RPN::~RPN() {}

void RPN::evaluate(const std::string& expression) {
	std::stack<int> s;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.length() == 1 && std::isdigit(token[0])) {
			s.push(token[0] - '0');
		} else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
			if (s.size() < 2) {
				std::cout << "Error" << std::endl;
				return;
			}
			int b = s.top();
			s.pop();
			int a = s.top();
			s.pop();

			int result = 0;
			if (token[0] == '+')
				result = a + b;
			else if (token[0] == '-')
				result = a - b;
			else if (token[0] == '*')
				result = a * b;
			else if (token[0] == '/') {
				if (b == 0) {
					std::cout << "Error" << std::endl;
					return;
				}
				result = a / b;
			}
			s.push(result);
		} else {
			std::cout << "Error" << std::endl;
			return;
		}
	}

	if (s.size() != 1) {
		std::cout << "Error" << std::endl;
		return;
	}

	std::cout << s.top() << std::endl;
}
