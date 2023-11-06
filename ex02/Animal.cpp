#include <iostream>
#include "Animal.hpp"

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& other) : _type(other._type)
{
    std::cout << "Animal copy constructor called\n";
}

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator called\n";
    if (this == &other)
        return *this;
    _type = other._type;
    return *this;
}

const std::string& Animal::getType() const
{
    return _type;
}

void Animal::makeSound() const
{
    std::cout << "-\n";
}
