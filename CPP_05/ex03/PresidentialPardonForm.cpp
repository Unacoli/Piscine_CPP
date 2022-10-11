#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default Presidential Form", 25, 5), _target("None")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm " << this->_target << " constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = src;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
    return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    (void)rhs;
    return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (this->getSign() == false)
        throw (FormNotSignedException());
    else if (this->getGradeToExec() < executor.getGrade())
        throw (FormGradeTooLowToExec());
    else
        std::cout << this->getTarget() << " has received a presidential pardon by Zaphod Beeblebrox." << std::endl;
    return ;
}