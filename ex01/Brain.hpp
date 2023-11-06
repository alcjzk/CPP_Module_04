#ifndef BRAIN_H
# define BRAIN_H

# include <string>

class Brain
{
    public:
        Brain();
        Brain(const Brain& other);
        ~Brain();

        Brain&  operator=(const Brain& other);
    
    private:
        static const size_t _ideas_max = 100;
        std::string         _ideas[_ideas_max];
};

#endif
