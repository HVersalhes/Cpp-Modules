#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>

int main() {
	std::srand(std::time(NULL));

	Bureaucrat president("President", 1);
	Bureaucrat manager("Manager", 40);
	Bureaucrat intern("Intern", 140);

	ShrubberyCreationForm shrub("garden");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Ford Prefect");

	std::cout << "=== 1. Testing Unsigned Execution ===" << std::endl;
	president.executeForm(shrub); // Should fail: not signed!

	std::cout << "\n=== 2. Testing Shrubbery Form ===" << std::endl;
	intern.signForm(shrub);
	intern.executeForm(shrub); // Intern grade 140 can execute shrub (exec grade 137? 140 > 137, fails!)
	manager.executeForm(shrub); // Manager grade 40 can execute!

	std::cout << "\n=== 3. Testing Robotomy Form ===" << std::endl;
	manager.signForm(robot);
	manager.executeForm(robot);

	std::cout << "\n=== 4. Testing Presidential Pardon Form ===" << std::endl;
	manager.signForm(pardon); // Manager grade 40 cannot sign (requires 25)
	president.signForm(pardon);
	manager.executeForm(pardon); // Manager cannot exec (requires 5)
	president.executeForm(pardon);

	return 0;
}
