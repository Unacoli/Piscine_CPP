#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    this->type = "WrongCat";
    std::cout << this->type << " default constructor called" << std::endl;
    return ;
}

WrongCat::WrongCat(WrongCat const &src)
{
    this->type = src.type;
    std::cout << this->type << " copy constructor called" << std::endl;
    return ;
}

WrongCat::~WrongCat(void)
{
    std::cout << this->type << " destructor called" << std::endl;
    return ;
}

WrongCat& WrongCat::operator=(WrongCat const &rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << this->type << ": *hiss*" << std::endl;
    return ;
}