#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap")
{
    _hp = 100;
    _ep = 50;
    _dmg = 20;
    std::cout << "Default ScavTrap constructor called" << std::endl;
    return ;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    _hp = 100;
    _ep = 50;
    _dmg = 20;
    std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
    return ;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    *this = src;
    std::cout << "ScavTrap copy constructor called" << std::endl;
    return ;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << _name << " deconstructor called" << std::endl;
    return ;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs)
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

void    ScavTrap::attack(const std::string &target)
{
    if (--_ep < 0)
        std::cout << "ScavTrap " << _name << " is out of energy" << std::endl;
    else if (_hp <= 0)
        std::cout << "ScavTrap " << _name << " is KO. Repair him." << std::endl;
    else
        std::cout << "ScavTrap " << _name << " do a rainbow attack on " << target << " causing " << _dmg << " point of damage !" << std::endl;
    return ;
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << _name << " is GateKeeping" << std::endl;
    return ;
}
