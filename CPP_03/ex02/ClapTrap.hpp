#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
    private:

    protected:
        std::string _name;
        int _hp;
        int _ep;
        int _dmg;
    public:
        ClapTrap(void);
        ClapTrap(std::string const Name);
        ClapTrap(ClapTrap const &src);
        ~ClapTrap(void);
        ClapTrap& operator=(ClapTrap const &rhs);
        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

#endif