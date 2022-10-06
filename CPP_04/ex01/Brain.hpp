#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <cstdlib>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain(void);
        Brain(Brain const &src);
        ~Brain(void);
        Brain& operator=(Brain const &rhs);
        std::string generateRandomWords(int n);
        void    printMind(int n);
};

#endif