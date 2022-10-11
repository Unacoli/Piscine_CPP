#include "Bureaucrat.hpp"

void    normalBureaucrat(void)
{
    int i = 1;

    std::cout << "Normal bureaucrat with a grade 1" << std::endl;
    Bureaucrat *Normal = new Bureaucrat("Normal", 1);
    while (i < 149)
    {
        Normal->downGrade();
        i++;
    }
    std::cout << *Normal;
    while (i > 1)
    {
        Normal->upGrade();
        i--;
    }
    std::cout << *Normal;
    if (Normal)
        delete (Normal);
    std::cout << std::endl;
    return ;
}

void    BureaucratTooLowGrade(void)
{
    std::cout << "Create a bureaucrat with too low grade" << std::endl;
    Bureaucrat TooLow("TooLow", 151);
    return ;
}

void    BureaucratTooHighGrade(void)
{
    std::cout << "Create a bureaucrat with too high grade" << std::endl;
    Bureaucrat TooHigh("TooHigh", 0);
    return ;
}

void    downGradeException(void)
{
    std::cout << "Dowmgrading too much" << std::endl;
    Bureaucrat DownGrade("DownGrade", 150);
    std::cout << DownGrade;
    DownGrade.downGrade();
    return ;
}

void    upGradeException(void)
{
    std::cout << "Upgrading too much" << std::endl;
    Bureaucrat UpGrade("UpGrade", 1);
    std::cout << UpGrade;
    UpGrade.upGrade();
    return ;
}

int main(void)
{
    {
        try
        {
            normalBureaucrat();
        }
        catch(const std::exception &except)
        {
            std::cerr << except.what() << '\n';
        }
    }
    {
        try
        {
            BureaucratTooLowGrade();
        }
        catch(const std::exception &except)
        {
            std::cerr << except.what() << '\n';
        }
    }
    {
        try
        {
            BureaucratTooHighGrade();
        }
        catch(const std::exception &except)
        {
            std::cerr << except.what() << '\n';
        }
    }
    {
        try
        {
            downGradeException();
        }
        catch(const std::exception &except)
        {
            std::cerr << except.what() << '\n';
        } 
    }
    {
        try
        {
            upGradeException();
        }
        catch(const std::exception &except)
        {
            std::cerr << except.what() << '\n';
        } 
    }
    return (0);
}