#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other._type)
{
    std::cout << "Cat copy constructor called\n";
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called\n";
    if (this == &other)
        return *this;
    _type = other._type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow!\n";
}
