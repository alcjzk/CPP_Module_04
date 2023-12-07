#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called\n";
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called\n";
    if (this == &other)
        return *this;
    _type = other._type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Bark!\n";
}
