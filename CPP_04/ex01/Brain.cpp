#include "Brain.hpp"

Brain::Brain(void)
{
    int i;

    std::cout << "Brain default constructor called" << std::endl;
    i = 0;
    while (i < 100)
    {
        this->ideas[i] = generateRandomIdea();
        i++;
    }
    return ;
}

Brain::Brain(Brain const &src)
{
    int i;

    std::cout << "Brain copy constructor called" << std::endl;
    i = 0;
    while (i < 100)
    {
        this->ideas[i] = src.ideas[i];
        i++;
    }
    *this = src;
    return ;
}

Brain::~Brain(void)
{
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

std::string Brain::generateRandomIdea(void)
{
    int i;
    int n = 10;
    char    letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    std::string idea = "";

    i = 0;
    while (i < n)
    {
        idea = idea + letters[std::rand() % 26];
        i++;
    }
    return (idea);
}

void    Brain::printMind(int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (!ideas[i].empty())
            std::cout << "Idea[" << i << "] : " << ideas[i] << std::endl;
        i++;
    }
    return ;
}