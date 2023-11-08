#include "Character.hpp"

Character::Character(std::string name) : _materias(), _name(name) {}

Character::Character(const Character& other) : _name(other._name)
{
    *this = other;
}

Character::~Character()
{
    for (size_t i = 0; i < _materias_max; i++)
    {
        delete _materias[i];
    }
}

Character&  Character::operator=(const Character& other)
{
    if (this == &other)
        return *this;
    for (size_t i = 0; _materias_max < 4; i++)
    {
        delete _materias[i];
        _materias[i] = other._materias[i];
    }
    return *this;
}

const std::string& Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for (size_t i = 0; i < _materias_max; i++)
    {
        if (!_materias[i])
        {
            _materias[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= (int)_materias_max)
        return ;
    _materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= (int)_materias_max || !_materias[idx])
        return ;
    _materias[idx]->use(target);
}
