#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern default constructor called" << std::endl;
    return ;
}

Intern::Intern(Intern const &src)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = src;
    return ;
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor called" << std::endl;
    return ;
}

Intern& Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return (*this);
}

AForm   *Intern::createPresidentialPardonForm(std::string target)
{
    AForm   *form = new PresidentialPardonForm(target);
    return (form);
}

AForm   *Intern::createRobotomyRequestForm(std::string target)
{
    AForm   *form = new RobotomyRequestForm(target);
    return (form);
}

AForm   *Intern::createShrubberyCreationForm(std::string target)
{
    AForm   *form = new ShrubberyCreationForm(target);
    return (form);
}

AForm   *Intern::makeForm(std::string formName, std::string formTarget)
{
    AForm   *(Intern::*create_ptr[3])(std::string) = {&Intern::createPresidentialPardonForm, &Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm};
    std::string formNames[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    int i = 0;

    try
    {
        while (i < 3)
        {
            if (formName == formNames[i])
            {
                std::cout << "Intern creates " << formName << std::endl;
                return ((this->*create_ptr[i])(formTarget));
            }
            i++;
        }
        throw (CantFindForm());
    }
    catch(const std::exception &except)
    {
        std::cerr << except.what() << std::endl;
    }
    return (NULL);
}