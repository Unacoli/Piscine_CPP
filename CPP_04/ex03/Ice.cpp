#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
    return ;
}

Ice::Ice(const Ice &src) : AMateria(src)
{
    std::cout << "Ice copy constructor called" << std::endl;
    return ;
}

Ice::~Ice(void)
{
    std::cout << "Ice destructor called" << std::endl;
    return ;
}

Ice & Ice::operator=(Ice const &rhs)
{
    (void)rhs;
    return (*this);
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void    Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return ;
}