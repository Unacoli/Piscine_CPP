#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    Cat *kitty = new Cat();
    Cat *kitten = new Cat();

    kitty->getIdeas();
    kitty->makeSound();
    dog->makeSound();
    kitten->makeSound();

    Cat *Cato = new Cat(*kitten);
	
	Cato->makeSound();
	
    delete(dog);
    delete(cat);
    delete(kitty);
    delete(kitten);
    delete(Cato);
    return (0);
}
