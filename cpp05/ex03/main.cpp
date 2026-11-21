#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern someRandomIntern;
	Bureaucrat boss("The Boss", 1);

	std::cout << "=== Test 1: Robotomy Request ===" << std::endl;
	AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf) {
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n=== Test 2: Shrubbery Creation ===" << std::endl;
	AForm* scf = someRandomIntern.makeForm("shrubbery creation", "home");
	if (scf) {
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
	}

	std::cout << "\n=== Test 3: Presidential Pardon ===" << std::endl;
	AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (ppf) {
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf;
	}

	std::cout << "\n=== Test 4: Unknown Form Name ===" << std::endl;
	AForm* unknown = someRandomIntern.makeForm("coffee request", "Boss");
	if (!unknown) {
		std::cout << "Correctly handled unknown form!" << std::endl;
	}

	return 0;
}
