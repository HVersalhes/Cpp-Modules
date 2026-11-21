#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <iostream>

class RPN {
private:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& rhs);
	~RPN();

public:
	static void evaluate(const std::string& expression);
};

#endif
