#include "Cat.hpp"

Cat::Cat(void)
{
    this->type = "Cat";
    std::cout << this->type << " default constructor called" << std::endl;
    return ;
}

Cat::Cat(Cat const &src)
{
    std::cout << this->type << " copy constructor called" << std::endl;
    return ;
}

Cat::~Cat(void)
{
    std::cout << this->type << " destructor called" << std::endl;
    return ;
}

Cat& Cat::operator=(Cat const &rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << this->type << ": *purr on your knees*" << std::endl;
    return ;
}