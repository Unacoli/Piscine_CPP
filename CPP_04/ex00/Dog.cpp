#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    std::cout << this->type << " default constructor called" << std::endl;
    return ;
}

Dog::Dog(Dog const &src)
{
    std::cout << this->type << " copy constructor called" << std::endl;
    return ;
}

Dog::~Dog(void)
{
    std::cout << this->type << " deconstructor called" << std::endl;
    return ;
}

Dog& Dog::operator=(Dog const &rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << this->type << ": *bark happily for food*" << std::endl;
    return ;
}