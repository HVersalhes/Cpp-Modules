#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _totalAdded(0) {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::_readLine(const std::string& prompt) {
	std::string input;
	while (true) {
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			return "";
		if (!input.empty()) {
			bool onlySpaces = true;
			for (size_t i = 0; i < input.length(); ++i) {
				if (input[i] != ' ' && input[i] != '\t') {
					onlySpaces = false;
					break;
				}
			}
			if (!onlySpaces)
				return input;
		}
		std::cout << "Field cannot be empty. Please try again." << std::endl;
	}
}

void PhoneBook::addContact() {
	std::cout << "--- Adding New Contact ---" << std::endl;
	std::string firstName = _readLine("Enter First Name: ");
	if (std::cin.eof()) return;
	std::string lastName = _readLine("Enter Last Name: ");
	if (std::cin.eof()) return;
	std::string nickname = _readLine("Enter Nickname: ");
	if (std::cin.eof()) return;
	std::string phoneNumber = _readLine("Enter Phone Number: ");
	if (std::cin.eof()) return;
	std::string darkestSecret = _readLine("Enter Darkest Secret: ");
	if (std::cin.eof()) return;

	int index = _totalAdded % 8;
	_contacts[index].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	_totalAdded++;
	std::cout << "Contact added successfully at slot " << index << "!" << std::endl;
}

void PhoneBook::searchContact() const {
	int count = _totalAdded < 8 ? _totalAdded : 8;
	if (count == 0) {
		std::cout << "PhoneBook is empty. Use ADD to insert contacts." << std::endl;
		return;
	}

	std::cout << std::string(43, '-') << std::endl;
	std::cout << std::setw(10) << std::right << "Index" << "|"
	          << std::setw(10) << std::right << "First Name" << "|"
	          << std::setw(10) << std::right << "Last Name" << "|"
	          << std::setw(10) << std::right << "Nickname" << std::endl;
	std::cout << std::string(43, '-') << std::endl;

	for (int i = 0; i < count; ++i) {
		_contacts[i].displaySummary(i);
	}
	std::cout << std::string(43, '-') << std::endl;

	std::cout << "Enter index to display details: ";
	std::string input;
	if (!std::getline(std::cin, input))
		return;

	if (input.length() != 1 || input[0] < '0' || input[0] > '7') {
		std::cout << "Invalid index! Must be a single digit from 0 to 7." << std::endl;
		return;
	}

	int idx = input[0] - '0';
	if (idx >= count) {
		std::cout << "No contact found at index " << idx << "." << std::endl;
		return;
	}

	std::cout << "--- Contact Details [Index " << idx << "] ---" << std::endl;
	_contacts[idx].displayFull();
}
