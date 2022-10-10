#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include <string>
# include "ICharacter.hpp"

class   ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(std::string const &type);
        AMateria(void);
        virtual ~AMateria(void);
        AMateria(AMateria const &src);
        AMateria& operator=(AMateria const &rhs);
        std::string const &getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif