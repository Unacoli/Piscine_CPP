#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    std::cout << "Default DiamondTrap constructor called" << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name), ScavTrap(Name), FragTrap(Name)
{
    this->_name = Name;
    std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
    *this = src;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    return ;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << _name << " deconstructor called" << std::endl;
    return ;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &rhs)
{
    this->_name = rhs._name;
    return (*this);
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name: " << this->_name << std::endl;
    std::cout << "ClapTrap name: " << this->ClapTrap::_name << std::endl;
    return ;
}