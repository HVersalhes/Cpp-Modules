#include "Zombie.hpp"

int main() {
	int N = 5;
	std::cout << "Allocating horde of " << N << " zombies on heap..." << std::endl;
	Zombie* horde = zombieHorde(N, "HordeRunner");
	if (horde) {
		for (int i = 0; i < N; i++) {
			horde[i].announce();
		}
		std::cout << "Deleting horde with delete[]..." << std::endl;
		delete[] horde;
	}

	std::cout << "\nTesting invalid N (<= 0):" << std::endl;
	Zombie* emptyHorde = zombieHorde(0, "Ghost");
	if (!emptyHorde)
		std::cout << "zombieHorde returned NULL correctly." << std::endl;

	return 0;
}
