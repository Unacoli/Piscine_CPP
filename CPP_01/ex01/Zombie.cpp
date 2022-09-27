#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->name << " destroyed" << std::endl;
    return ;
}

void    Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}

void    Zombie::giveName(std::string name)
{
    this->name = name;
    return ;
}