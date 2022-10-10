#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <cstdlib>

class Brain
{
    private:
        std::string *ideas;
    public:
        Brain(void);
        Brain(Brain &src);
        ~Brain(void);
        Brain& operator=(Brain const &rhs);
        std::string *getIdeas(void);
};

#endif