#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Lucy;
    ClapTrap David("David");

    int i = 0;
    while (i < 10)
    {
        Lucy.attack("David");
        i++;
    }
    i = 0;
    while (i < 10)
    {
        David.takeDamage(10);
        i++;
    }
    David.attack("Lucy");
    David.beRepaired(10);
    David.attack("Lucy");
    return (0);
}