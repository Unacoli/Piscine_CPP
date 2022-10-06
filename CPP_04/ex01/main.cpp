#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << cat->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    dog->makeSound();
    cat->makeSound();
    animal->makeSound();

    const WrongAnimal* animal_bis = new WrongAnimal();
    const WrongCat* cat_bis = new WrongCat();
    std::cout << cat_bis->getType() << std::endl;
    cat_bis->makeSound();
    animal_bis->makeSound();

    return (0);
}