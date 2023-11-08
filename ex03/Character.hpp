#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
    public:
        Character(std::string name = "");
        Character(const Character& other);

        virtual ~Character();
        
        Character&  operator=(const Character& other);

        virtual const std::string&  getName() const;
        virtual void                equip(AMateria *m);
        virtual void                unequip(int idx);
        virtual void                use(int idx, ICharacter& target);

    private:
        static const size_t _materias_max = 4;
        AMateria*           _materias[_materias_max];
        std::string         _name;
};

#endif
