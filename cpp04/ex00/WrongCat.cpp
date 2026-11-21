#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "WrongCat constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructed." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	if (this != &rhs) {
		WrongAnimal::operator=(rhs);
	}
	std::cout << "WrongCat copy assigned." << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destroyed." << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong Meow!" << std::endl;
}
