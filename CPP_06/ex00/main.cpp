#include "Converter.hpp"
#include <iomanip>

/*
**  static_cast:
**  used to do implicit conversion between type (int to float, 
**  ptr to void*...), and also call explicit conversion functions
**  it is a compiled cast
*/

enum e_type {CHAR, INT, FLOAT, DOUBLE, NONE};

static e_type  getType(std::string str)
{
    if (str.empty())
        return (NONE);
    if (str.size() == 1 && !isdigit(str[0]))
        return (CHAR);
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return (FLOAT);
    if (str == "nan" || str == "+inf" || str == "-inf")
        return (DOUBLE);
    
    size_t  i = 0;
    if (str[i] == '-')
        i++;
    while (isdigit(str[i]))
        i++;
    if (!str[i])
        return (INT);
    if (str[i] == '.')
        i++;
    while (isdigit(str[i]))
        i++;
    if (!str[i])
        return (DOUBLE);
    if (str[i] == 'f' && !str[i + 1])
        return (FLOAT);
    return (NONE);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage : ./convert [string_to_convert]" << std::endl;
        return (1); 
    }
  
    std::string arg = av[1];
    Converter converter(arg);
    char    c;
    int d;
    float   f;
    double  db;

    e_type  _type = getType(std::string(arg));;
    if (_type == NONE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return (0);
    }
    double huge;
    if (_type != CHAR)
    {
        huge = strtod(arg.c_str(), 0);
        if ((huge == HUGE_VALF || huge == -HUGE_VALF) && errno == ERANGE)
        {
            std::cout << "char: overflow" << std::endl;
            std::cout << "int: overflow" << std::endl;
            std::cout << "float: overflow" << std::endl;
            std::cout << "double: overflow" << std::endl;
            return (0);
        }
    }
    else
        huge = static_cast<double>(*arg.c_str());
    
    if (huge != huge)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
    }
    else
    {
        c = static_cast<char>(converter);
        d = static_cast<int>(converter);
        f = static_cast<float>(converter);
    }
    db = static_cast<double>(converter);
    return (0);
}