#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact {
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

	static std::string _formatColumn(const std::string& str);

public:
	Contact();
	~Contact();

	void setContact(const std::string& firstName,
	                const std::string& lastName,
	                const std::string& nickname,
	                const std::string& phoneNumber,
	                const std::string& darkestSecret);

	void displaySummary(int index) const;
	void displayFull() const;
	bool isEmpty() const;
};

#endif
