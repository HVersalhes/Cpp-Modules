#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const int count = 4;
	Animal* animals[count];

	std::cout << "=== Creating Animals Array (Half Dogs, Half Cats) ===" << std::endl;
	for (int i = 0; i < count; i++) {
		if (i < count / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n=== Testing Deep Copy ===" << std::endl;
	Dog originalDog;
	originalDog.getBrain()->ideas[0] = "Chase the tennis ball!";
	{
		Dog copyDog = originalDog;
		std::cout << "Original Dog Idea[0]: " << originalDog.getBrain()->ideas[0] << std::endl;
		std::cout << "Copy Dog Idea[0]:     " << copyDog.getBrain()->ideas[0] << std::endl;
		copyDog.getBrain()->ideas[0] = "Bark at mailman!";
		std::cout << "After modifying Copy Dog:" << std::endl;
		std::cout << "Original Dog Idea[0] (should still be Chase): " 
		          << originalDog.getBrain()->ideas[0] << std::endl;
		std::cout << "Copy Dog Idea[0]: " << copyDog.getBrain()->ideas[0] << std::endl;
	}

	std::cout << "\n=== Deleting Animals Array ===" << std::endl;
	for (int i = 0; i < count; i++) {
		delete animals[i];
	}

	return 0;
}
