#include "ScavTrap.hpp"

int main() {
	std::cout << "--- Creating ScavTrap ---" << std::endl;
	ScavTrap scav("SC4V-TP");

	std::cout << "\n--- Testing Actions ---" << std::endl;
	scav.attack("Handsome Jack");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	std::cout << "\n--- Destruction Chain ---" << std::endl;
	return 0;
}
