#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other._type)
{
    std::cout << "WrongCat copy constructor called\n";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongAnimal copy assignment operator called\n";
    if (this == &other)
        return *this;
    _type = other._type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "[WrongCat Sound]\n";
}
