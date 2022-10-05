#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
    ScavTrap Lucy("Lucy");
    ClapTrap David("David");

    int i = 0;
    while (i < 5)
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
    Lucy.takeDamage(10);
    Lucy.beRepaired(10);
    Lucy.guardGate();
    return (0);
}