#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main() {
	std::cout << "=== Subject Test ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n=== Additional Tests: Inventory Full, Unequip, Unknown Type ===" << std::endl;
	AMateria* unequippedMateria = src->createMateria("ice");
	me->equip(unequippedMateria);
	me->use(2, *bob);
	me->unequip(2);
	me->use(2, *bob); // Slot 2 is now empty, does nothing!
	delete unequippedMateria; // Saved address and cleaned up!

	AMateria* unknown = src->createMateria("fire");
	if (!unknown)
		std::cout << "Successfully ignored unknown materia type 'fire'." << std::endl;

	std::cout << "\n=== Testing Deep Copy of Character ===" << std::endl;
	Character* hero1 = new Character("Hero1");
	hero1->equip(src->createMateria("ice"));
	Character* hero2 = new Character(*hero1);
	delete hero1;
	hero2->use(0, *bob); // Still works because hero2 has a deep clone!
	delete hero2;

	delete bob;
	delete me;
	delete src;

	return 0;
}
