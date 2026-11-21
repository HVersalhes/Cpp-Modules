#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "=== Testing Abstract Class AAnimal ===" << std::endl;
	// AAnimal test; // Descomentar esta linha gerará erro de compilação!

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << "\nTypes and Sounds:" << std::endl;
	std::cout << j->getType() << " says: ";
	j->makeSound();
	std::cout << i->getType() << " says: ";
	i->makeSound();

	std::cout << "\nDeleting heap objects:" << std::endl;
	delete j;
	delete i;

	return 0;
}
