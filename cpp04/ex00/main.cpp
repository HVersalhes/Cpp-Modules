#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "=== Correct Polymorphism with virtual ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nTypes:" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << "\nSounds:" << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\nDestructors:" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n=== Incorrect Polymorphism without virtual ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\nWrong Sounds:" << std::endl;
	wrongCat->makeSound(); // will output WrongAnimal sound because makeSound is not virtual!
	wrongMeta->makeSound();

	std::cout << "\nWrong Destructors:" << std::endl;
	delete wrongMeta;
	delete wrongCat;

	return 0;
}
