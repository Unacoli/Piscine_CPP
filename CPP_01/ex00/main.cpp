#include "Zombie.hpp"

int main(void)
{
    Zombie  *z_1;
    Zombie  *z_2;
    Zombie  *z_3;
    Zombie  *z_4; 
    Zombie  *z_5;
    Zombie  *z_6;
    
    z_1 = newZombie("Yves");
    z_2 = newZombie("Belle");
    z_3 = newZombie("Jean");
    z_4 = newZombie("Eude");
    z_5 = newZombie("Caroline");
    z_6 = newZombie("Catherine");
    delete(z_2);
    z_1->announce();
    delete(z_1);
    randomChump("Pierre");
    delete(z_3);
    randomChump("Paul");
    z_4->announce();
    randomChump("Jacques");
    z_5->announce();
    delete(z_6);
    delete(z_5);
    return (0);
}