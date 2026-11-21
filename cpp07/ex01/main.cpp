#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T& element) {
	std::cout << element << " ";
}

void increment(int& n) {
	n++;
}

int main() {
	std::cout << "=== Test 1: Int Array ===" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original ints: ";
	::iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	::iter(intArray, intLen, increment);
	std::cout << "After incrementing: ";
	::iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	std::cout << "\n=== Test 2: String Array ===" << std::endl;
	std::string strArray[] = {"Hello", "42", "Porto", "Lisboa", "C++98"};
	size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "Strings: ";
	::iter(strArray, strLen, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}
