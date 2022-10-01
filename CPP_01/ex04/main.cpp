#include "main.hpp"

int main(int ac, char **av)
{

    std::string         line;
    std::string         resultLine;
    size_t              i;

    if (ac != 4 || strlen(av[1]) == 0 || strlen(av[2]) == 0 || strlen(av[3]) == 0)
    {
        std::cerr << "Usage : ./sed <fileName> <s1> <s2>" << std::endl;
        return (1);
    }
    std::fstream filein(av[1], std::ios::in);
    const std::string fileName = av[1];
    const std::string newFileName = fileName + ".replace";
    std::ofstream   fileout;
    if (!filein.is_open())
    {
        std::cerr << "Error: " << fileName << " not found or can't be opened" << std::endl;
        return (1);
    }
    const std::string   s1 = av[2];
    const std::string   s2 = av[3];
    while (getline(filein, line))
    {
        while (1)
        {
            i = line.find(s1);
            if (i == std::string::npos)
            {
                resultLine += line;
                break ;
            }
            line.erase(i, strlen(av[2]));
            line.insert(i, s2);
        }
        resultLine += "\n";
    }
    fileout.open(newFileName.c_str(), std::ios::out);
    fileout << resultLine;
    filein.close();
    fileout.close();
    return (0);
}