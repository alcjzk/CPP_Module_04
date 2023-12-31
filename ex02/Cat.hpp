#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& other);
        ~Cat();
    
        Cat&    operator=(const Cat& other);

        virtual void    makeSound() const;
        Brain&          brain() const;

    private:
        Brain*  _brain;
};

#endif
