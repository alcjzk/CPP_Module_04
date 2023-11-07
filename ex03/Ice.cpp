#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria("Ice") {}

Ice::Ice(const Ice& other) : AMateria("Ice") {}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& other)
{
    if (this == &other)
        return *this;
    AMateria::operator=(other);
    return *this;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
