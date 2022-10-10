#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor called" << std::endl;
    return ;
}

Cure::Cure(const Cure &src) : AMateria(src)
{
    std::cout << "Cure copy constructor called" << std::endl;
    return ;
}

Cure::~Cure(void)
{
    std::cout << "Cure destructor called" << std::endl;
    return ;
}

Cure & Cure::operator=(Cure const &rhs)
{
    (void)rhs;
    return (*this);
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void    Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    return ;
}