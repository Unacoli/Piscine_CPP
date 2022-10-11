#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class   Bureaucrat;

class Form
{
    private:
        std::string const   _name;
        bool    _signed;
        int const   _gradeToSign;
        int const   _gradeToExec;
    public:
        Form(void);
        Form(std::string name, int gradeToSign, int gradeToExec);
        Form(Form const &src);
        ~Form(void);
        Form & operator=(Form const &rhs);
        std::string const   getName(void) const;
        bool    getSign(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;
        void    beSigned(Bureaucrat const &bureaucrat);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Form::exception : Grade Too High\n");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Form::exception : Grade Too Low\n");
                }
        };
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Form::exception : Form not signed\n");
                }
        };
};

std::ostream &  operator<<(std::ostream &out, Form const &in);

#endif