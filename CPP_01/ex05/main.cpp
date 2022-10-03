#include "Harl.hpp"

int main(void)
{
    Harl    harl;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            harl.complain(levels[i]);
            harl.complain(levels[j]);
            j++;
        }
        i++;
    }
    return (0);
}