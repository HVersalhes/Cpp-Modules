#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unnamed_Frag") {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " default constructed." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	*this = other;
	std::cout << "FragTrap " << _name << " copy constructed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
	}
	std::cout << "FragTrap " << _name << " copy assigned." << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests a positive high five! ✋" << std::endl;
}
