#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
	std::cout << "=== Test 1: std::vector<int> ===" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i * 10);

	try {
		std::vector<int>::iterator it = easyfind(vec, 40);
		std::cout << "Found value: " << *it << " in vector!" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::cout << "Searching for 42..." << std::endl;
		easyfind(vec, 42);
	} catch (const std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: std::list<int> ===" << std::endl;
	std::list<int> lst;
	lst.push_back(100);
	lst.push_back(200);
	lst.push_back(300);

	try {
		std::list<int>::iterator it = easyfind(lst, 200);
		std::cout << "Found value: " << *it << " in list!" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
