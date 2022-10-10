#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    this->_brain = new Brain;
    std::cout << this->type << " default constructor called" << std::endl;
    return ;
}

Dog::Dog(Dog &src)
{
    this->type = src.type;
    this->_brain = new Brain(*(src._brain));
    std::cout << this->type << " copy constructor called" << std::endl;
    return ;
}

Dog::~Dog(void)
{
    delete(this->_brain);
    std::cout << this->type << " deconstructor called" << std::endl;
    return ;
}

Dog& Dog::operator=(Dog &rhs)
{
    if (this != &rhs)
    {
        this->type = rhs.type;
        *(this->_brain) = *(rhs._brain);
    }
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << this->type << ": *bark happily for food*" << std::endl;
    return ;
}

void Dog::getIdeas(void)
{
    int i = 0;

    while (i < 100)
    {
        std::cout << (this->_brain)->getIdeas()[i] << std::endl;
        i++;
    }
    return ;
}