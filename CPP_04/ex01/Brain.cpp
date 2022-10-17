#include "Brain.hpp"

Brain::Brain(void)
{
    int i;
    this->ideas = new std::string[100];

    std::cout << "Brain default constructor called" << std::endl;
    i = 0;
    while (i < 100)
    {
        this->ideas[i] = "Brain";
        i++;
    }
    return ;
}

Brain::Brain(Brain &src)
{
    int i;
    this->ideas = new std::string[100];
    
    std::cout << "Brain copy constructor called" << std::endl;
    i = 0;
    while (i < 100)
    {
        this->ideas[i] = src.ideas[i] + " copied";
        i++;
    }
    *this = src;
    return ;
}

Brain::~Brain(void)
{
    delete [] (this->ideas);
    std::cout << "Brain destructor called" << std::endl;
    return ;
}

Brain& Brain::operator=(Brain const &rhs)
{
    int i;

    i = 0;
    if (this != &rhs)
    {
        while (i < 100)
        {
            this->ideas[i] = rhs.ideas[i];
            i++;
        }
    }
    return (*this);
}

std::string *Brain::getIdeas(void)
{
    return (this->ideas);
}