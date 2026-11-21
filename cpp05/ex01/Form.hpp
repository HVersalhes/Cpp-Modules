#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Form {
private:
	const std::string _name;
	bool              _isSigned;
	const int         _gradeToSign;
	const int         _gradeToExecute;

public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	Form();
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& rhs);
	~Form();

	std::string getName() const;
	bool        getIsSigned() const;
	int         getGradeToSign() const;
	int         getGradeToExecute() const;

	void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& rhs);

#endif
