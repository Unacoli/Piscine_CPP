#include "Harl.hpp"

int main(int ac, char **av)
{
    std::string level;
    Harl    harl;

    if (ac != 2)
    {
        std::cout << "Usage: ./HarlFilter \"{\"DEBUG\", \"INFO\", \"WARNING\", \"ERROR\"}\"" << std::endl;
        return (1);
    }
    level = av[1];
    harl.complain(level);
    return (0);
}