#include "Converter.hpp"

Converter::Converter(void) : _str("Default")
{
    std::cout << "Converter default constructor called" << std::endl;
    return ;
}

Converter::Converter(std::string str) : _str(str)
{
    std::cout << "Converter contructor called" << std::endl;
    return ;
}

Converter::Converter(Converter const &src)
{
    std::cout << "Converter copy constructor called" << std::endl;
    this->_str = src.getStr();
    return ;
}

Converter::~Converter(void)
{
    std::cout << "Converter destructor called" << std::endl;
    return ;
}

Converter& Converter::operator=(Converter const &rhs)
{
    if (this != &rhs)
        this->_str = rhs.getStr();
    return (*this);
}

std::string Converter::getStr(void) const
{
    return (this->_str);
}

Converter::operator char()
{
    char c = 0;

    if (_str.size() == 1 && isprint(_str[0]))
    {
        c = _str[0];
        std::cout << "char: " << c << std::endl;
        return (c);
    }

    int d = atoi(_str.c_str());
    if (d < CHAR_MIN || d > CHAR_MAX)
    {
        std::cout << "char: overflow" << std::endl;
        return (c);
    }
    c = static_cast<char>(d);
    if (isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    return (c);
}

Converter::operator int()
{
    int d = 0;

    if (_str.size() == 1 && !isdigit(_str[0]))
    {
        d = _str[0];
        std::cout << "int: " << d << std::endl;
        return (d);
    }

    if ((d = atoi(_str.c_str())) == 0 && _str != "0")
    {
        std::cout << "int: Non displayable" << std::endl;
        return (d);
    }
    if (d < INT_MIN || d > INT_MAX)
    {
        std::cout << "int: overflow" << std::endl;
        return (d);
    }
    std::cout << "int: " << d << std::endl;
    return (d);
}

Converter::operator float()
{
    float   f = 0;

    if (_str.size() == 1 && !isdigit(_str[0]))
    {
        f = _str[0];
        std::cout << "float: " << f << std::endl;
        return (f);
    }

    if ((f = atof(_str.c_str())) == 0 && _str != "0")
    {
        std::cout << "float: Non displayable" << std::endl;
        return (f);
    }
    else if (f == INFINITY || f == -INFINITY)
    {
        std::cout << "float: " << (f < 0 ? "-inff" : "+inff") << std::endl;
        return (f);
    }
    else if ((f > FLT_MAX || f < FLT_MIN) && _str != "0")
    {
        std::cout << "float: overflow" << std::endl;
        return (f);
    }
    else
    {
        std::cout.precision(std::numeric_limits<float>::digits10);
        std::cout << "float: " << f;
        if (floor(f) == f)
            std::cout << ".0";
        std::cout << 'f' << std::endl;
    }
    return (f);
}

Converter::operator double()
{
    double  db = 0;

    if (_str.size() == 1 && !isdigit(_str[0]))
    {
        db = _str[0];
        std::cout << "double: " << db << std::endl;
        return (db);
    }

    if ((db = strtod(_str.c_str(), NULL)) == (0.0) && _str != "0")
    {
        std::cout << "double: Non displayable" << std::endl;
        return (db);
    }
    else if ((db == HUGE_VALF || db == -HUGE_VALF) && errno == ERANGE)
    {
        std::cout << "double: overflow" << std::endl;
        return (db);
    }
    else if (db == INFINITY || db == -INFINITY)
    {
        std::cout << "double: " << (db > 0 ? '+' : '\0') << db << std::endl;
        return (db);
    }
    else
    {
        std::cout.precision(std::numeric_limits<double>::digits10);
        std::cout << "double: " << db;
        if (floor(db) == db)
            std::cout << ".0";
        std::cout << std::endl;
    }
    return (db);
}