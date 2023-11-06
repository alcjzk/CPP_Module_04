#include <iostream>
#include "Brain.hpp"
#include "Dog.hpp"

Dog::Dog() :
    Animal("Dog"),
    _brain(new Brain())
{
    std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& other) :
    Animal(other._type),
    _brain(new Brain(*other._brain))
{
    std::cout << "Dog copy constructor called\n";
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
    delete _brain;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called\n";
    if (this == &other)
        return *this;
    _type = other._type;
    *_brain = *other._brain;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Bark!\n";
}

Brain& Dog::brain() const
{
    return *_brain;
}
