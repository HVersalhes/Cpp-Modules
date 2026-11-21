#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat {
private:
	const std::string _name;
	int               _grade;

public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat();

	std::string getName() const;
	int         getGrade() const;

	void incrementGrade();
	void decrementGrade();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif
