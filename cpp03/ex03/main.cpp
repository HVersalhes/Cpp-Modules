#include "DiamondTrap.hpp"

int main() {
	std::cout << "=== Constructing DiamondTrap ===" << std::endl;
	DiamondTrap diamond("MonsterDiamond");

	std::cout << "\n=== Testing Special Abilities ===" << std::endl;
	diamond.whoAmI();
	diamond.attack("TargetDummy");
	diamond.guardGate();
	diamond.highFivesGuys();

	std::cout << "\n=== Testing Damage & Repair ===" << std::endl;
	diamond.takeDamage(45);
	diamond.beRepaired(20);

	std::cout << "\n=== Destructing DiamondTrap ===" << std::endl;
	return 0;
}
