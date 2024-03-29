#include "Form.hpp"

Form::Form(void) : _name("DefaultForm"), _signed(0), _gradeToSign(2), _gradeToExec(1)
{
    std::cout << "Form default constructor called" << std::endl;
    return ;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name((std::string const)name), _signed(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    std::cout << "Form " << name << " constructor called" << std::endl;
    if (gradeToSign > 150 || gradeToExec > 150)
        throw (GradeTooLowException());
    else if (gradeToSign < 1 || gradeToExec < 1)
        throw (GradeTooHighException());
    else
        return ;
    return ;
}

Form::Form(Form const &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
    std::cout << "Form copy constructor called" << std::endl;
    *this = src;
    return ;
}

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl;
    return ;
}

Form& Form::operator=(Form const &rhs)
{
    if (this != &rhs)
        this->_signed = rhs._signed;
    return (*this);
}

std::string const   Form::getName(void) const
{
    return (this->_name);
}

bool    Form::getSign(void) const
{
    return (this->_signed);
}

int Form::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

int Form::getGradeToExec(void) const
{
    return (this->_gradeToExec);
}

void    Form::beSigned(Bureaucrat const &bureaucrat)
{
    try
    {
        if (this->getSign())
            throw (FormNotSignedException());
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
            this->_signed = 1;
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

std::ostream &  operator<<(std::ostream &out, Form const &in)
{
    out << "Form name : " << in.getName() << std::endl;
    out << "Signed value : " << in.getSign() << std::endl;
    out << "Grade to sign : " << in.getGradeToSign() << std::endl;
    out << "Grade to exec : " << in.getGradeToExec() << std::endl;
    return (out);
}