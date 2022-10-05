#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ScavTrap Lucy("Lucy");
    ClapTrap David("David");
    FragTrap Rebecca("Rebecca");

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
    Rebecca.attack("Lucy");
    Rebecca.takeDamage(20);
    Rebecca.beRepaired(100);
    Rebecca.highFiveGuys();
    Rebecca.attack("David");
    David.takeDamage(30);
    return (0);
}