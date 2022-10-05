#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# include <iomanip>

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(std::string Name);
        ScavTrap(const ScavTrap &rhs);
        ~ScavTrap(void);
        ScavTrap& operator=(const ScavTrap &rhs);
        void    guardGate(void);
        void    attack(const std::string &target);
};

#endif