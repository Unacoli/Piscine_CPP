#include "Character.hpp"

Character::Character(void) : _name("Default")
{
    int i = 0;

    std::cout << "Character default constructor called" << std::endl;
    while (i < 4)
    {
        inventory[i] = NULL;
        i++;
    }
    return ;
}

Character::Character(std::string name) : _name(name)
{
    int i = 0;

    std::cout << "Character " << this->getName() << " constructor called" << std::endl;
    while (i < 4)
    {
        inventory[i] = NULL;
        i++;
    }
    return ;
}

Character::Character(const Character &src)
{
    std::cout << "Character " << this->getName() << " copy constructor called" << std::endl;
    *this = src;
    return ;
}

Character::~Character(void)
{
    int i = 0;
    std::cout << "Character " << this->getName() << " destructor called" << std::endl;
    while (i < 4)
    {
        if (inventory[i])
            delete(inventory[i]);
        i++;
    }
    return ;
}

Character& Character::operator=(Character const &rhs)
{
    int i = 0;

    if (this != &rhs)
    {
        this->_name = rhs.getName();
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

void    Character::equip(AMateria *m)
{
    int idx;

    if (!m || (*m).getType() == "None")
    {
        std::cout << "No materia equiped" << std::endl;
        return ;
    }
    else
    {
        idx = 0;
        while (idx < 4)
        {
            if (inventory[idx] == NULL)
            {
                inventory[idx] = m;
                std::cout << this->getName() << " : " << "Materia " << m->getType() << " equiped at index " << idx << std::endl;
                return ;
            }
            idx++;
        }
        std::cout << "Inventory is full" << std::endl;
        return ;
    }
    return ;
}

void    Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << this->getName() << " : Inventory goes from 0 to 3" << std::endl;
        return ;
    }
    else if (inventory[idx] == NULL)
        std::cout << this->getName() << " : Nothing to unequip" << std::endl;
    else
    {
        std::cout << this->getName() << " : Unequipping " << inventory[idx]->getType() << " at index " << idx << std::endl;
        delete(inventory[idx]);
        inventory[idx] = NULL;
        return ;
    }
    return ;
}

void    Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << this->getName() << " : Inventory goes from 0 to 3" << std::endl;
        return ;
    }
    else if (inventory[idx] != NULL)
    {
        std::cout << this->getName() << " : " << std::endl;
        inventory[idx]->use(target);
    }
    else
    {
        std::cout << this->getName() << " : Nothing to use here" << std::endl;
        return ;
    }
    return ;
}

std::string const & Character::getName() const
{
    return (this->_name);
}