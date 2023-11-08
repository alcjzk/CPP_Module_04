#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        
        virtual ~MateriaSource();

        MateriaSource&  operator=(const MateriaSource& other);

        virtual void        learnMateria(AMateria* materia);
        virtual AMateria*   createMateria(const std::string& type);

    public:
        static const size_t _materias_max = 4;
        AMateria*           _materias[_materias_max];
};

#endif
