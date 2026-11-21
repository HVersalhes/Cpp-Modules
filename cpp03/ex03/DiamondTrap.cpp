#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("Unnamed_clap_name"), ScavTrap(), FragTrap(), _name("Unnamed") {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << _name << " default constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << _name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
	*this = other;
	std::cout << "DiamondTrap " << _name << " copy constructed." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		this->_name = rhs._name;
	}
	std::cout << "DiamondTrap " << _name << " copy assigned." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destroyed." << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "Who am I? DiamondTrap name: " << _name
	          << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
