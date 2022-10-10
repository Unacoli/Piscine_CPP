#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include <iostream>
# include <string>

class   Ice : public AMateria
{
    public:
        Ice(void);
        Ice(Ice const &src);
        ~Ice(void);
        Ice& operator=(Ice const &rhs);
        virtual AMateria* clone() const;
        virtual void use(ICharacter &target);
};

#endif