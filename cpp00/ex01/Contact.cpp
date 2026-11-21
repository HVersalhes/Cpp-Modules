#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setContact(const std::string& firstName,
                         const std::string& lastName,
                         const std::string& nickname,
                         const std::string& phoneNumber,
                         const std::string& darkestSecret) {
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickname;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

std::string Contact::_formatColumn(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Contact::displaySummary(int index) const {
	std::cout << std::setw(10) << std::right << index << "|"
	          << std::setw(10) << std::right << _formatColumn(_firstName) << "|"
	          << std::setw(10) << std::right << _formatColumn(_lastName) << "|"
	          << std::setw(10) << std::right << _formatColumn(_nickname) << std::endl;
}

void Contact::displayFull() const {
	std::cout << "First Name:     " << _firstName << std::endl;
	std::cout << "Last Name:      " << _lastName << std::endl;
	std::cout << "Nickname:       " << _nickname << std::endl;
	std::cout << "Phone Number:   " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}

bool Contact::isEmpty() const {
	return _firstName.empty();
}
