#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	std::cout << "--- Constructing FragTrap ---" << std::endl;
	FragTrap frag("FR4G-TP");

	std::cout << "\n--- Testing FragTrap ---" << std::endl;
	frag.attack("Hyperion Drone");
	frag.takeDamage(40);
	frag.beRepaired(25);
	frag.highFivesGuys();

	std::cout << "\n--- Destructing FragTrap ---" << std::endl;
	return 0;
}
