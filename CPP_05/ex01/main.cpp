#include "Bureaucrat.hpp"
#include "Form.hpp"

void    normalBureaucrat(void)
{
    std::cout << "Normal bureaucrat with a grade 1" << std::endl;
    try
    {
        Bureaucrat Normal("Normal", 1);
        Form    form("A38", 50, 70);
        std::cout << Normal;
        std::cout << form;
        Normal.signForm(form);
    }
    catch(const std::exception &except)
    {
        std::cerr << except.what() << std::endl;
    }
    return ;
}

void    BureaucratTooLowGrade(void)
{
    std::cout << "Create a bureaucrat with too low grade to sign" << std::endl;
    try
    {
        Bureaucrat TooLow("TooLow", 30);
        Form    form("A38", 15, 15);
        std::cout << TooLow;
        std::cout << form;
        TooLow.signForm(form);
    }
    catch(const std::exception &except)
    {
        std::cerr << except.what() << std::endl;
    }
    return ;
}

void    BureaucratTooLowException(void)
{
    std::cout << "Create a form with too high grade to be signed" << std::endl;
    try
    {
        Bureaucrat TooLow("TooLow", 30);
        Form    form("A38", 15, 15);
        std::cout << TooLow;
        std::cout << form;
        form.beSigned(TooLow);
    }
    catch(const std::exception &except)
    {
        std::cerr << except.what() << std::endl;
    }
    return ;
}

int main(void)
{
    normalBureaucrat();
    BureaucratTooLowGrade();
    BureaucratTooLowException();
    return (0);
}