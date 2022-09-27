#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie  random_z = Zombie(name);
    random_z.announce();
    return ;
}