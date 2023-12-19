#include <cstdlib>
#include <iostream>
#include <cassert>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    // Subject tests
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
    delete bob;
    delete me;
    delete src;


    {
        // Cloning a materia returns a new instance of the same type
        AMateria* ice = new Ice();

        AMateria* ice_clone = ice->clone();
        assert(ice != ice_clone); // Distinct instance
        assert(ice->getType() == ice_clone->getType()); // Same type

        delete ice;
        delete ice_clone;
    
        // Cloning a materia returns a new instance of the same type
        AMateria* cure = new Ice();

        AMateria* cure_clone = cure->clone();
        assert(cure != cure_clone); // Distinct instance
        assert(cure->getType() == cure_clone->getType()); // Same type

        delete cure;
        delete cure_clone;
    }

    {
        Character character1, character2;

        std::cout << "Using unexisting materia does nothing\n";
        character1.use(-1, character2); // Out of bounds
        character1.use(4, character2); // Out of bounds
        character1.use(0, character2); // No materia
        std::cout << "--\n";
    }
    return EXIT_SUCCESS;
}
