#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* _brain;
    public:
        Dog(void);
        Dog(Dog &src);
        ~Dog(void);
        Dog& operator=(Dog &rhs);
        void    makeSound(void) const;
        void getIdeas(void);
};

#endif