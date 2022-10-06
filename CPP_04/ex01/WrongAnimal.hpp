#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal(void);
    WrongAnimal(std::string const type);
    WrongAnimal(WrongAnimal const &src);
    virtual ~WrongAnimal(void);
    WrongAnimal& operator=(WrongAnimal const &rhs);
    std::string getType(void) const;
    void    makeSound(void) const;
};

#endif