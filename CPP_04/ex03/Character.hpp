#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include <string>
# include "ICharacter.hpp"

class   Character : public ICharacter
{
    public:
        Character(void);
        Character(std::string name);
        Character(Character const &src);
        virtual ~Character(void);
        Character& operator=(Character const &rhs);
        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
        protected:
            std::string _name;
            AMateria    *inventory[4];
};

#endif