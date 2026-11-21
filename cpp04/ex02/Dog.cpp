#include "Dog.hpp"

Dog::Dog() : _brain(new Brain()) {
	this->type = "Dog";
	std::cout << "Dog constructed." << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Dog copy constructed." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	std::cout << "Dog copy assigned." << std::endl;
	return *this;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->_brain;
}
