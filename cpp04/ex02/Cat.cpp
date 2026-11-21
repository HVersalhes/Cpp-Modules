#include "Cat.hpp"

Cat::Cat() : _brain(new Brain()) {
	this->type = "Cat";
	std::cout << "Cat constructed." << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Cat copy constructed." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	std::cout << "Cat copy assigned." << std::endl;
	return *this;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->_brain;
}
