#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class   MateriaSource : public IMateriaSource
{
    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const &src);
        ~MateriaSource(void);
        MateriaSource& operator=(MateriaSource const &rhs);
        void learnMateria(AMateria *src);
        AMateria *createMateria(std::string const &type);
    protected:
        AMateria *inventory[4];
};

#endif