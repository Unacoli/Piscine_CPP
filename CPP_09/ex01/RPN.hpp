#pragma once

# include <iostream>
# include <stack>
# include <sstream>
# include <cstdlib>
# include <exception>
# include <cstring>

class RPN
{
    private:
        std::stack<double> result;
        bool    is_operation(char c);
        void    operation(double nbr1, double nbr2, char opt);

    public:
        void    execute_operation(char *exp);
        RPN(void);
        RPN(RPN const &src);
        ~RPN(void);
        RPN& operator=(RPN const &rhs);
};