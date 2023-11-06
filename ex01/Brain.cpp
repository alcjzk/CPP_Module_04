#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called\n";
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignment operator called\n";
    if (this == &other)
        return *this;
    for (size_t i = 0; i < _ideas_max; i++)
    {
        _ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}

void Brain::firstIdea(std::string idea)
{
    _ideas[0] = idea;
}

const std::string& Brain::firstIdea() const
{
    return _ideas[0];
}
