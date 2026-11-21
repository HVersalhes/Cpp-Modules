#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	checkExecutionRequirements(executor);

	std::string filename = _target + "_shrubbery";
	std::ofstream outFile(filename.c_str());
	if (!outFile.is_open()) {
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return;
	}

	outFile << "       _-_\n"
	        << "    /~~   ~~\\\n"
	        << " /~~         ~~\\\n"
	        << "{               }\n"
	        << " \\  _-     -_  /\n"
	        << "   ~  \\\\ //  ~\n"
	        << "_- -   | | _- _\n"
	        << "  _ -  | |   -_\n"
	        << "      // \\\\\n";

	outFile.close();
}
