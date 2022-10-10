#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain*  _brain;
    public:
        Cat(void);
        Cat(Cat &src);
        ~Cat(void);
        Cat& operator=(const Cat &rhs);
        void    makeSound(void) const;
        void getIdeas(void);
};

#endif