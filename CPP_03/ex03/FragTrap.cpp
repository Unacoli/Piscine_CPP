#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("FragTrap")
{
    _hp = 100;
    _ep = 100;
    _dmg = 30;
    std::cout << "Default FragTrap constructor called" << std::endl;
    return ;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
    _hp = 100;
    _ep = 100;
    _dmg = 30;
    std::cout << "FragTrap " << _name << " constructor called" << std::endl;
    return ;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    *this = src;
    std::cout << "FragTrap copy constructor called" << std::endl;
    return ;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << _name << " deconstructor called" << std::endl;
    return ;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hp = rhs._hp;
        this->_ep = rhs._ep;
        this->_dmg = rhs._dmg;
    }
    return (*this);
}

void    FragTrap::attack(const std::string &target)
{
    if (--_ep < 0)
        std::cout << "FragTrap " << _name << " is out of energy" << std::endl;
    else if (_hp <= 0)
        std::cout << "FragTrap " << _name << " is KO. Repair him." << std::endl;
    else
        std::cout << "FragTrap " << _name << " do a rain attack on " << target << " causing " << _dmg << " point of damage !" << std::endl;
    return ;
}

void    FragTrap::highFiveGuys(void)
{
    std::cout << "FragTrap " << this->_name << " do a HIGH FIVE" << std::endl;
    return ;
}