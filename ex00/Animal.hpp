#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>

class Animal {
    public:
        Animal(std::string type = "Animal");
        Animal(const Animal& other);
        virtual ~Animal();
    
        Animal& operator=(const Animal& other);

        virtual void        makeSound() const;    
        const std::string&  getType() const;

    protected:
        std::string _type;
};

#endif
