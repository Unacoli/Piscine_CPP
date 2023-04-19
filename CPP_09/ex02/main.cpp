#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error" << std::endl;
        return (-1);
    }

    PmergeMe pmergeMe;
    pmergeMe.mergeMe(av, ac);
    return (0);
}