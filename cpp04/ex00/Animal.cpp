#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal constructed." << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Animal copy constructed." << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	std::cout << "Animal copy assigned." << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destroyed." << std::endl;
}

void Animal::makeSound() const {
	std::cout << "* Generic animal sound *" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}
