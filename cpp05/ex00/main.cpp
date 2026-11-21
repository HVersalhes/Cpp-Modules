#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	std::cout << "=== Test 1: Valid Bureaucrats ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << "After promotion: " << bob << std::endl;
		bob.incrementGrade(); // Should throw GradeTooHighException!
	} catch (std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade Too High at Construction ===" << std::endl;
	try {
		Bureaucrat god("God", 0);
	} catch (std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade Too Low at Construction ===" << std::endl;
	try {
		Bureaucrat peasant("Peasant", 151);
	} catch (std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Decrement Beyond Limit ===" << std::endl;
	try {
		Bureaucrat intern("Intern", 149);
		intern.decrementGrade();
		std::cout << intern << std::endl;
		intern.decrementGrade(); // Should throw GradeTooLowException!
	} catch (std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	return 0;
}
