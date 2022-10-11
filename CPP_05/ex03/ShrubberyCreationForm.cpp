#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default Shruberry Form", 145, 137), _target("None")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm " << this->_target << " constructor called" << std::endl;
    return ;  
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = src;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
    return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    (void)rhs;
    return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    std::ofstream file;

    if (this->getSign() == false)
        throw (FormNotSignedException());
    else if (this->getGradeToExec() < executor.getGrade())
        throw (FormGradeTooLowToExec());
    else
    {
        file.open((_target + "_shrubbery").c_str());
        if (!file.is_open() || !file.good())
            throw (CantOpenFile());
        else
        {
            file << " ^  ^  ^ " << std::endl;
            file << "/|\\/|\\/|\\" << std::endl;
            file << "/|\\/|\\/|\\" << std::endl;
            file << " |  |  | " << std::endl;
        }
    }
    return ;
}