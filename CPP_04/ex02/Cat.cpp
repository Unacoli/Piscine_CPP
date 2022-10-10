#include "Cat.hpp"

Cat::Cat(void)
{
    this->type = "Cat";
    this->_brain = new Brain;
    std::cout << this->type << " default constructor called" << std::endl;
    return ;
}

Cat::Cat(Cat &src)
{
    this->type = src.type;
    this->_brain = new Brain(*(src._brain));
    std::cout << this->type << " copy constructor called" << std::endl;
    return ;
}

Cat::~Cat(void)
{
    delete(this->_brain);
    std::cout << this->type << " destructor called" << std::endl;
    return ;
}

Cat& Cat::operator=(Cat const &rhs)
{
    if (this != &rhs)
    {
        this->type = rhs.type;
        *(this->_brain) = *(rhs._brain);
    }
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << this->type << ": *purr on your knees*" << std::endl;
    return ;
}

void Cat::getIdeas(void)
{
    int i = 0;

    while (i < 100)
    {
        std::cout << (this->_brain)->getIdeas()[i] << std::endl;
        i++;
    }
    return ;
}