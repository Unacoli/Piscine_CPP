#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
# include <iomanip>

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string Name);
        FragTrap(const FragTrap &rhs);
        ~FragTrap(void);
        FragTrap& operator=(const FragTrap &rhs);
        void    highFiveGuys(void);
        void    attack(const std::string &target);
};

#endif