#include "AForm.hpp"

AForm::AForm(void) : _name("DefaultAForm"), _signed(false), _gradeToSign(2), _gradeToExec(1)
{
    std::cout << "AForm default constructor called" << std::endl;
    return ;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name((std::string const)name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    std::cout << "AForm " << name << " constructor called" << std::endl;
    if (gradeToSign > 150 || gradeToExec > 150)
        throw (GradeTooLowException());
    else if (gradeToSign < 1 || gradeToExec < 1)
        throw (GradeTooHighException());
    else
        return ;
    return ;
}

AForm::AForm(AForm const &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
    std::cout << "AForm copy constructor called" << std::endl;
    *this = src;
    return ;
}

AForm::~AForm(void)
{
    std::cout << "AForm destructor called" << std::endl;
    return ;
}

AForm& AForm::operator=(AForm const &rhs)
{
    if (this != &rhs)
        this->_signed = rhs._signed;
    return (*this);
}

std::string const   AForm::getName(void) const
{
    return (this->_name);
}

bool    AForm::getSign(void) const
{
    return (this->_signed);
}

int AForm::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

int AForm::getGradeToExec(void) const
{
    return (this->_gradeToExec);
}

void    AForm::beSigned(Bureaucrat const &bureaucrat)
{
    try
    {
        if (this->getSign() == true)
            throw (FormAlreadySigned());
    }
    catch(const std::exception &except)
    {
        std::cerr << bureaucrat.getName() << " couldn't sign " << this->getName() << " because it has already been signed." << std::endl;
        return ;
    }
    try
    {
        if (bureaucrat.getGrade() <= this->getGradeToSign())
        {
            this->_signed = true;
            std::cout << bureaucrat.getName() << " signed " << this->getName() << "." << std::endl;
        }
        else
            throw (GradeTooLowException());
    }
    catch(const std::exception &except)
    {
        std::cerr << bureaucrat.getName() << " couldn't sign " << this->getName() << " because his grade is too low." << std::endl;
        return ;
    }
    return ;
}

std::ostream &  operator<<(std::ostream &out, AForm const &in)
{
    out << "AForm name : " << in.getName() << std::endl;
    out << "Signed value : " << in.getSign() << std::endl;
    out << "Grade to sign : " << in.getGradeToSign() << std::endl;
    out << "Grade to exec : " << in.getGradeToExec() << std::endl;
    return (out);
}