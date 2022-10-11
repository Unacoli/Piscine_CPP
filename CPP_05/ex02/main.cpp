#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void    ShrubberyOK(void)
{
    std::cout << "ShrubberyOK test" << std::endl;
    try
    {
        Bureaucrat Normal("Normal", 1);
        ShrubberyCreationForm Tree("tree");
        Normal.signForm(Tree);
        Tree.execute(Normal);
        Normal.executeForm(Tree);
    }
    catch(const std::exception &except)
    {
        std::cerr << except.what() << std::endl;
    }
    std::cout << std::endl;
    return ;
}

void    ShrubberyError(void)
{
    std::cout << "Shrubbery Error test" << std::endl;
    try
    {
        Bureaucrat Cat("Cat", 146);
        ShrubberyCreationForm Tree("tree");
        Cat.signForm(Tree);
        Tree.execute(Cat);
        Cat.executeForm(Tree);
    }
    catch(const std::exception &except)
    {
        std::cerr << except.what() << std::endl;
    }
    std::cout << std::endl;
    return ;
}

void    PresidentOK(void)
{
    std::cout << "President OK test" << std::endl;
    try
    {
        Bureaucrat Annie("Annie", 4);
        PresidentialPardonForm president("president");
        Annie.signForm(president);
        president.execute(Annie);
        Annie.executeForm(president);
    }
    catch(const std::exception &except)
    {
        std::cerr << except.what() << std::endl;
    }
    std::cout << std::endl;
    return ;
}

void    PresidentError(void)
{
    std::cout << "President Error test" << std::endl;
    try
    {
        Bureaucrat Emmanuel("Emmanuel", 47);
        PresidentialPardonForm president("president");
        Emmanuel.signForm(president);
        president.execute(Emmanuel);
        Emmanuel.executeForm(president);
    }
    catch(const std::exception &except)
    {
        std::cerr << except.what() << std::endl;
    }
    std::cout << std::endl;
    return ;
}

void    RobotOK(void)
{
    std::cout << "Robot OK test" << std::endl;
    try
    {
        Bureaucrat RobotOWO("OWO", 1);
        RobotomyRequestForm robot("robot");
        RobotOWO.signForm(robot);
        robot.execute(RobotOWO);
        RobotOWO.executeForm(robot);
        robot.execute(RobotOWO);
        RobotOWO.executeForm(robot);
    }
    catch(const std::exception &except)
    {
        std::cerr << except.what() << std::endl;
    }
    std::cout << std::endl;
    return ;
}

void    RobotError(void)
{
    std::cout << "Robot Error test" << std::endl;
    try
    {
        Bureaucrat RobotUWU("UWU", 47);
        RobotomyRequestForm robot("robot");
        RobotUWU.signForm(robot);
        robot.execute(RobotUWU);
        RobotUWU.executeForm(robot);
        robot.execute(RobotUWU);
        RobotUWU.executeForm(robot);
    }
    catch(const std::exception &except)
    {
        std::cerr << except.what() << std::endl;
    }
    std::cout << std::endl;
    return ;
}

int main(void)
{
    ShrubberyOK();
    ShrubberyError();
    PresidentOK();
    PresidentError();
    RobotOK();
    RobotError();
    return (0);
}