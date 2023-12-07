#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other)
{
    return *this;
}

const std::string& AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter& target) {}
