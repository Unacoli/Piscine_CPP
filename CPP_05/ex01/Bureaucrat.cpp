#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name((std::string const)name), _grade(grade)
{
    std::cout << "Bureaucrat " << name << " constructor called" << std::endl;
    if (grade > 150)
        throw (GradeTooLowException());
    else if (grade < 1)
        throw (GradeTooHighException());
    else
        return ;
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = src;
    return ;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
    return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
        this->_grade = rhs.getGrade();
    return (*this);
}

void    Bureaucrat::upGrade(void)
{
    if (this->_grade <= 1)
        throw (GradeTooHighException());
    this->_grade--;
    return ;
}

void    Bureaucrat::downGrade(void)
{
    if (this->_grade >= 150)
        throw (GradeTooLowException());
    this->_grade++;
    return ;
}

void    Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.getSign();
    }
    catch(const std::exception &except)
    {
        return ;
    }
    try
    {
        form.beSigned(*this);
    }
    catch(const std::exception &except)
    {
        return ;
    }
    return ;
}

std::string const   Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

std::ostream & operator<<(std::ostream &out, Bureaucrat const &in)
{
    out << in.getName() << ", bureaucrat grade " << in.getGrade() << "." << std::endl;
    return (out); 
}