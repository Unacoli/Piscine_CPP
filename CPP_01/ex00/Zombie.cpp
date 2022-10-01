#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << "Zombie " << this->name << " created" << std::endl;    
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