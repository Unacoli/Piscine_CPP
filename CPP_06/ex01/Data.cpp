#include "Data.hpp"

Data::Data(void) : _name("Default")
{
    std::cout << "Data default constructor called" << std::endl;
    return ;
}

Data::Data(std::string name) : _name(name)
{
    std::cout << "Data " << name << " constructor called" << std::endl;
    return ;
}

Data::Data(Data const &src)
{
    std::cout << "Data copy constructor called" << std::endl;
    *this = src;
    return ;
}

Data::~Data(void)
{
    std::cout << "Data destructor called" << std::endl;
    return ;
}

Data& Data::operator=(Data const &rhs)
{
    if (this != &rhs)
        this->_name = rhs.getName();
    return (*this);
}

std::string Data::getName(void) const
{
    return (this->_name);
}