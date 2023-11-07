#ifndef AMATERIA_H
# define AMATERIA_H

# include <string>

class AMateria
{
    public:
        AMateria(const std::string& type = "");
        AMateria(const AMateria& other);        
        ~AMateria();

        AMateria&   operator=(const AMateria& other);

        const std::string&  getType() const;
        
        virtual AMateria*   clone() const = 0;
        virtual void        use(/* TODO */);

    protected:
        std::string _type;
};

#endif
