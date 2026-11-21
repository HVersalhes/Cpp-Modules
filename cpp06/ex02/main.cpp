#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	int r = std::rand() % 3;
	if (r == 0) {
		std::cout << "Generated type A" << std::endl;
		return new A();
	} else if (r == 1) {
		std::cout << "Generated type B" << std::endl;
		return new B();
	} else {
		std::cout << "Generated type C" << std::endl;
		return new C();
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::exception&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::exception&) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::exception&) {}

	std::cout << "Unknown type" << std::endl;
}

int main() {
	std::srand(std::time(NULL));

	std::cout << "=== Random generation and identification ===" << std::endl;
	for (int i = 0; i < 5; i++) {
		Base* ptr = generate();
		std::cout << "Identify via pointer:   ";
		identify(ptr);
		std::cout << "Identify via reference: ";
		identify(*ptr);
		delete ptr;
		std::cout << std::endl;
	}

	return 0;
}
