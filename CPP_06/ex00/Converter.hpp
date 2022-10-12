#ifndef CONVERTER_HPP
# define CONVERTER_HPP
# include <iostream>
# include <limits.h>
# include <limits>
# include <string>
# include <cstdlib>
# include <cstdio>
# include <math.h>
# include <errno.h>
# include <float.h>

class Converter
{
    private:
        std::string _str;
    public:
        Converter(void);
        Converter(std::string str);
        Converter(Converter const &src);
        ~Converter(void);
        Converter& operator=(Converter const &rhs);
        std::string getStr(void) const;
        operator    char();
        operator    int();
        operator    float();
        operator    double();
};

#endif