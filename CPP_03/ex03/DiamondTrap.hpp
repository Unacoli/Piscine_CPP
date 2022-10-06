#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iomanip>

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _name;
public:
    using FragTrap::_hp;
    using FragTrap::_dmg;
    using ScavTrap::_ep;
    using ScavTrap::attack;
    
    DiamondTrap(void);
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap const &src);
    ~DiamondTrap();
    DiamondTrap& operator=(DiamondTrap const &rhs);
    void    whoAmI(void);
};

#endif