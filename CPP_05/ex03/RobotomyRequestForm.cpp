#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Default Robotomy Form", 72, 45), _target("None")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm " << this->_target << " constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    *this = src;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
    return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    (void)rhs;
    return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->getSign() == false)
        throw (FormNotSignedException());
    else if (this->getGradeToExec() < executor.getGrade())
        throw (FormGradeTooLowToExec());
    else
    {
        std::cout << "Bzzzzzzzzzzzz krkrr bzzzzzzzz" << std::endl;
        int i = std::rand();
        if (i % 2 == 0)
            std::cout << this->getTarget() << " has been robotomised." << std::endl;
        else
            std::cout << this->getTarget() << " can't be robotomised." << std::endl;
    }
    return ;
}