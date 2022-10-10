#include "Animal.hpp"

Animal::Animal(void) : type("None")
{
    std::cout << "Animal default constructor called" << std::endl;
    return ;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal " << type << " constructor called" << std::endl;
    return ;
}

Animal::Animal(Animal const &src)
{
    *this = src;
    std::cout << "Animal copy constructor called" << std::endl;
    return ;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
    return ;
}

Animal& Animal::operator=(Animal const &rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void    Animal::makeSound(void) const
{
    std::cout << "An animal makes sound" << std::endl;
    return ;
}