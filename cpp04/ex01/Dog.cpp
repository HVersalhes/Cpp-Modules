#include "Dog.hpp"

Dog::Dog() : _brain(new Brain()) {
	this->type = "Dog";
	std::cout << "Dog constructed with new Brain." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Dog copy constructed with deep copy of Brain." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	std::cout << "Dog copy assigned with deep copy of Brain." << std::endl;
	return *this;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destroyed and Brain freed." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->_brain;
}
