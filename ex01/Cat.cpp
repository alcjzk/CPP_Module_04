#include <iostream>
#include "Cat.hpp"

Cat::Cat() :
    Animal("Cat"),
    _brain(new Brain())
{
    std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& other) :
    Animal(other),
    _brain(new Brain(*other._brain))
{
    std::cout << "Cat copy constructor called\n";
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
    delete _brain;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called\n";
    if (this == &other)
        return *this;
    _type = other._type;
    *_brain = *other._brain;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow!\n";
}

Brain& Cat::brain() const
{
    return *_brain;
}
