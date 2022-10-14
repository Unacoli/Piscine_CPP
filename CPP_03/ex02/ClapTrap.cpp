#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hp(10), _ep(10), _dmg(10)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string const Name) : _name(Name), _hp(10), _ep(10), _dmg(10)
{
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    *this = src;
    std::cout << "ClapTrap copy constructor called" << std::endl;
    return ;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << _name << " deconstructor called" << std::endl;
    return ;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &rhs)
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

void    ClapTrap::attack(const std::string &target)
{
    if (--_ep < 0)
        std::cout << "ClapTrap " << _name << " is out of energy" << std::endl;
    else if (_hp <= 0)
        std::cout << "ClapTrap " << _name << " is KO. Repair him." << std::endl;
    else
        std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _dmg << " point of damage !" << std::endl;
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hp <= 0)
        std::cout << "ClapTrap " << _name << " is KO. Repair him." << std::endl;
    else
    {
        _hp -= amount;
        if (_hp < 0)
            _hp = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damage" << std::endl;
    }
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (--_ep < 0)
        std::cout << "ClapTrap" << _name << " is KO. Repair him." << std::endl;
    else
    {
        _hp += amount;
        std::cout << "ClapTrap " << _name << " heals " << amount << std::endl;
        std::cout << "ClapTrap " << _name << " have now " << _hp << " HP" << std::endl;
    }
    return ;
}