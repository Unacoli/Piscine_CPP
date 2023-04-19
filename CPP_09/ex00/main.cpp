#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    std::string data_path = "./data.csv";
    if (ac != 2)
    {
        std::cout << "Error : could not open file." << std::endl;
        return (-1);
    }
    BitcoinExchange btc;
    btc.print_output(data_path, av[1]);

    return (0);
}