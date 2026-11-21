#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap("CL4P-TP");

	claptrap.attack("Bandit");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.takeDamage(10);
	claptrap.attack("Bandit");
	claptrap.beRepaired(5);

	return 0;
}
