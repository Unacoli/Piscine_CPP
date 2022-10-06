#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "WrongAnimal " << type << " constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
    *this = src;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    return ;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
    return ;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "A WrongAnimal makes sound" << std::endl;
    return ;
}