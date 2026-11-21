#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
	Contact _contacts[8];
	int     _totalAdded;

	static std::string _readLine(const std::string& prompt);

public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContact() const;
};

#endif
