#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <string>

class WrongAnimal
{
    public:
        WrongAnimal(std::string type = "");
        WrongAnimal(const WrongAnimal& other);
        ~WrongAnimal();

        WrongAnimal&    operator=(const WrongAnimal& other);

        const std::string&  getType() const;
        void                makeSound() const;

    protected:
        std::string _type;
};

#endif
