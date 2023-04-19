#include "RPN.hpp"

RPN::RPN(void)
{
    return ;
}

RPN::RPN(RPN const &src)
{
    *this = src;
    return ;
}

RPN::~RPN(void)
{
    return ;
}

RPN& RPN::operator=(RPN const &rhs)
{
    if (this != &rhs)
    {
        this->result = rhs.result;
    }
    return (*this);
}

bool RPN::is_operation(char c)
{
    if (c == '-' || c == '+')
        return (true);
    if (c == '*' || c == '/')
        return (true);
    return (false);
}

void RPN::operation(double nbr1, double nbr2, char opt)
{
    double tmp;

    if (opt == '+')
        tmp = nbr1 + nbr2;
    else if (opt == '-')
        tmp = nbr2 - nbr1;
    else if (opt == '/')
        tmp = nbr2 / nbr1;
    else if (opt == '*')
        tmp = nbr1 * nbr2;
    this->result.push(tmp);
}

void RPN::execute_operation(char *exp)
{
    double  nb1, nb2, opt;
    char tmp[11];
    int i, tmp_len;

    if (!exp)
    {
        std::cout << "Error" << std::endl;
        return ;
    }
    i = 0;
    while (exp[i])
    {
        if (exp[i] == ' ')
            ++i;
        else if (exp[i] && isdigit(exp[i]))
        {
            tmp_len = 0;
            while (exp[i] && isdigit(exp[i]))
            {
                tmp[tmp_len] = exp[i];
                ++i;
                tmp_len++;
            }
            tmp[tmp_len] = '\0';
            opt = std::atoi(tmp);
            this->result.push(opt);
            memset(tmp, '\0', tmp_len);
        }
        else if (exp[i] && this->is_operation(exp[i]))
        {
            if (this->result.size() >= 2)
            {
                nb1 = this->result.top();
                this->result.pop();
                nb2 = this->result.top();
                this->result.pop();
                this->operation(nb1, nb2, exp[i]);
            }
            else
            {
                std::cout << "Error" << std::endl;
                return ;
            }
            ++i;
        }
        else
        {
            std::cout << "Error" << std::endl;
            return ;
        }
    }
    i--;

    while (exp[i] == ' ')
        i--;
    if (!is_operation(exp[i]))
        std::cout << "Error" << std::endl;
    else
        std::cout << this->result.top() << std::endl;
}