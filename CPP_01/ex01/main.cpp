#include "Zombie.hpp"

int main(int ac, char **av)
{
    int i;
    int N;

    i = 0;
    N = 0;
    if (ac != 2)
    {
        std::cout << "Give a number between 1 and 500" << std::endl;
        return (EXIT_FAILURE);
    }
    else
        N = atoi(av[1]);
    if (N <= 0)
        return (std::cout << "Number must be positive" << std::endl, EXIT_FAILURE);
    if (N > 500)
        return (std::cout << "Number must be less than 500" << std::endl, EXIT_FAILURE);
    
    Zombie  *zombie;
    Zombie  *zombie_bis;

    zombie = zombieHorde(N, "Yves");
    zombie_bis = zombieHorde(N, "Belle");
    while (i < N)
    {
        zombie[i].announce();
        i++;
    }
    i = 20;
    while (i < N)
    {
        zombie_bis[i].announce();
        i++;
    }
    delete[] zombie;
    delete[] zombie_bis;
    return (0);
}