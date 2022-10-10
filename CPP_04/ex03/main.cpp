#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void)
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* Mercy = new Character("Mercy");

    AMateria* owo;
    AMateria* uwu;
    owo = src->createMateria("ice");
    uwu = src->createMateria("cure");
    Mercy->equip(owo);
    Mercy->unequip(0);
    Mercy->unequip(0);

    AMateria* icu;
    icu = src->createMateria("ice");
    Mercy->equip(icu);
    Mercy->equip(uwu);
    Mercy->unequip(-1);
    Mercy->unequip(2);

    ICharacter* Ana = new Character("Ana");
    Mercy->use(0, *Ana);
    Mercy->use(2, *Ana);
    Mercy->use(1, *Ana);
    
    delete (Ana);
    delete (Mercy);
    delete (src);
    return (0);
}