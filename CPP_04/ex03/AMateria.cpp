#include "AMateria.hpp"

AMateria::AMateria(void) : type("None")
{
    std::cout << "AMateria default constructor called" << std::endl;
    return ;
}

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << "AMateria " << type << " constructor called" << std::endl;
    return ;
}

AMateria::AMateria(AMateria const &src)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = src;
    return ;
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria destructor called" << std::endl;
    return ;
}

AMateria& AMateria::operator=(AMateria const &rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

void    AMateria::use(ICharacter &target)
{
    std::cout << "Using: " << target.getName() << std::endl;
    return ;
}

std::string const &AMateria::getType() const
{
    return (type);
}