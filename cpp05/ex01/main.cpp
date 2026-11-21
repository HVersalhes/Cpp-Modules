#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat boss("The Boss", 1);
		Bureaucrat intern("The Intern", 150);

		Form topSecretForm("Top Secret Tax Cut", 50, 20);
		std::cout << topSecretForm << std::endl;

		std::cout << "\n--- Intern tries to sign ---" << std::endl;
		intern.signForm(topSecretForm);
		std::cout << topSecretForm << std::endl;

		std::cout << "\n--- Boss signs form ---" << std::endl;
		boss.signForm(topSecretForm);
		std::cout << topSecretForm << std::endl;

	} catch (std::exception& e) {
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing Invalid Form Creation ---" << std::endl;
	try {
		Form invalidForm("Impossible", 0, 50);
	} catch (std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	return 0;
}
