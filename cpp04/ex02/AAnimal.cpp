#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << "AAnimal constructed." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
	std::cout << "AAnimal copy constructed." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	std::cout << "AAnimal copy assigned." << std::endl;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destroyed." << std::endl;
}

std::string AAnimal::getType() const {
	return this->type;
}
