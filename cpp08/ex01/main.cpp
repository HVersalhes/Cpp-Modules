#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
	std::cout << "=== Subject Example Test ===" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
	std::cout << "Longest:  " << sp.longestSpan() << " (Expected: 14)" << std::endl;

	std::cout << "\n=== Massive Test: 20,000 Numbers with addRange ===" << std::endl;
	std::srand(std::time(NULL));
	const unsigned int bigN = 20000;
	std::vector<int> randomValues;
	for (unsigned int i = 0; i < bigN; i++) {
		randomValues.push_back(std::rand());
	}

	Span bigSpan(bigN);
	bigSpan.addRange(randomValues.begin(), randomValues.end());
	std::cout << "Big Span Shortest: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Big Span Longest:  " << bigSpan.longestSpan() << std::endl;

	std::cout << "\n=== Testing Full Span Exception ===" << std::endl;
	try {
		bigSpan.addNumber(42);
	} catch (const std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	return 0;
}
