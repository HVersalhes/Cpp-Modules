#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << "WrongAnimal copy constructed." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	std::cout << "WrongAnimal copy assigned." << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destroyed." << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "* Wrong generic sound *" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
