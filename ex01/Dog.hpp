#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog();
        Dog(const Dog& other);
        ~Dog();

        Dog&    operator=(const Dog& other);
    
        virtual void    makeSound() const;
        Brain&          brain() const;
    private:
        Brain*  _brain;
};

#endif
