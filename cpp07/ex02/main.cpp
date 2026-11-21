#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**) {
	std::cout << "=== 1. Testing Default and Parameter Constructors ===" << std::endl;
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	std::srand(std::time(NULL));

	for (int i = 0; i < MAX_VAL; i++) {
		const int value = std::rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << "=== 2. Testing Deep Copy ===" << std::endl;
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);

		tmp[0] = -42;
		test[0] = -1337;
		if (numbers[0] == mirror[0])
			std::cout << "Deep copy verified successfully!" << std::endl;
		else
			std::cerr << "FAIL: Deep copy corrupted original!" << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			delete[] mirror;
			return 1;
		}
	}
	std::cout << "All 750 values matched mirror array perfectly!" << std::endl;

	std::cout << "=== 3. Testing Out of Bounds Exceptions ===" << std::endl;
	try {
		numbers[-2] = 0;
	} catch (const std::exception& e) {
		std::cout << "Caught expected negative index exception: " << e.what() << std::endl;
	}

	try {
		numbers[MAX_VAL] = 0;
	} catch (const std::exception& e) {
		std::cout << "Caught expected beyond bound exception: " << e.what() << std::endl;
	}

	delete[] mirror;
	return 0;
}
