#ifndef DATA_HPP
# define DATA_HPP
# include <string>
# include <iostream>

class Data
{
    private:
        std::string _name;
    public:
        Data(void);
        Data(std::string name);
        Data(Data const &src);
        ~Data(void);
        Data& operator=(Data const &rhs);
        std::string getName(void) const;
};

#endif