#include "Cat.hpp"

Cat::Cat() : _brain(new Brain()) {
	this->type = "Cat";
	std::cout << "Cat constructed with new Brain." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Cat copy constructed with deep copy of Brain." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	std::cout << "Cat copy assigned with deep copy of Brain." << std::endl;
	return *this;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destroyed and Brain freed." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->_brain;
}
