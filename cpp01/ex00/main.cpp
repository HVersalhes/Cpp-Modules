#include "Zombie.hpp"

int main() {
	std::cout << "=== Test 1: Heap Allocation (newZombie) ===" << std::endl;
	Zombie* heapZombie = newZombie("HeapWalker");
	heapZombie->announce();
	delete heapZombie;

	std::cout << "\n=== Test 2: Stack Allocation (randomChump) ===" << std::endl;
	randomChump("StackWalker");

	return 0;
}
