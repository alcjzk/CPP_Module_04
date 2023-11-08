#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _materias() {}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    *this = other;
}

MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < _materias_max; i++)
    {
        delete _materias[i];
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this == &other)
        return *this;
    for (size_t i = 0; i < _materias_max; i++)
    {
        delete _materias[i];
        _materias[i] = other._materias[i];
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (size_t i = 0; i < _materias_max; i++)
    {
        if (!_materias[i])
        {
            _materias[i] = materia;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (size_t i = 0; i < _materias_max; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
}
