#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    int i = 0;

    std::cout << "MateriaSource default constructor called" << std::endl;
    while (i < 4)
    {
        inventory[i] = NULL;
        i++;
    }
    return ;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    *this = src;
    std::cout << "MateriaSource copy constructor called" << std::endl;
    return ;
}

MateriaSource::~MateriaSource(void)
{
    int i = 0;
    std::cout << "MateriaSource destructor called" << std::endl;
    while (i < 4)
    {
        if (inventory[i])
            delete(inventory[i]);
        i++;
    }
    return ;
}

MateriaSource& MateriaSource::operator=(MateriaSource const &rhs)
{
    int i = 0;

    if (this != &rhs)
    {
        while (i < 4)
        {
            if (this->inventory[i] != NULL)
                delete(this->inventory[i]);
            if (rhs.inventory[i] != NULL)
                this->inventory[i] = rhs.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
            i++;
        }
    }
    return (*this);
}

void    MateriaSource::learnMateria(AMateria *src)
{
    int idx = 0;

    if (!src || (*src).getType() == "None")
    {
        std::cout << "MateriaSource : No materia available" << std::endl;
        return ;
    }
    else
    {
        while (idx < 4)
        {
            if (inventory[idx] == NULL)
            {
                inventory[idx] = src;
                std::cout << "MateriaSource : " << "Materia " << src->getType() << " learned at index " << idx << std::endl;
                return ;
            }
            idx++;
        }
        std::cout << "Inventory is full" << std::endl;
        delete (src);
        return ;
    }
    return ;
}

AMateria*   MateriaSource::createMateria(std::string const &type)
{
    int i = 0;

    while (i < 4)
    {
        if (inventory[i] != NULL && inventory[i]->getType() == type)
            return (inventory[i]->clone());
        i++;
    }
    std::cout << "MateriaSource can't create " << type << std::endl;
    return (NULL);
}