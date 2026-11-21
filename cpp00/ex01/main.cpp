#include "PhoneBook.hpp"
#include <iostream>

int main() {
	PhoneBook phoneBook;
	std::string command;

	std::cout << "========================================" << std::endl;
	std::cout << "       WELCOME TO AWESOME PHONEBOOK     " << std::endl;
	std::cout << " Available commands: ADD, SEARCH, EXIT  " << std::endl;
	std::cout << "========================================" << std::endl;

	while (true) {
		std::cout << "PhoneBook> ";
		if (!std::getline(std::cin, command)) {
			std::cout << std::endl << "Exiting PhoneBook. Goodbye!" << std::endl;
			break;
		}
		if (command == "ADD") {
			phoneBook.addContact();
			if (std::cin.eof()) {
				std::cout << std::endl << "Input stream closed. Exiting..." << std::endl;
				break;
			}
		} else if (command == "SEARCH") {
			phoneBook.searchContact();
			if (std::cin.eof()) {
				std::cout << std::endl << "Input stream closed. Exiting..." << std::endl;
				break;
			}
		} else if (command == "EXIT") {
			std::cout << "Contacts lost forever. Goodbye!" << std::endl;
			break;
		} else if (!command.empty()) {
			std::cout << "Unknown command: '" << command << "'. Use ADD, SEARCH, or EXIT." << std::endl;
		}
	}
	return 0;
}
