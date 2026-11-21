#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructed." << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy constructed." << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = rhs.ideas[i];
		}
	}
	std::cout << "Brain copy assigned." << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destroyed." << std::endl;
}
