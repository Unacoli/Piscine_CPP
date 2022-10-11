#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class   Bureaucrat;

class AForm
{
    private:
        std::string const   _name;
        bool    _signed;
        int const   _gradeToSign;
        int const   _gradeToExec;
    public:
        AForm(void);
        AForm(std::string name, int gradeToSign, int gradeToExec);
        AForm(AForm const &src);
        virtual ~AForm(void);
        AForm & operator=(AForm const &rhs);
        std::string const   getName(void) const;
        bool    getSign(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;
        virtual void    beSigned(Bureaucrat const &bureaucrat);
        virtual void    execute(Bureaucrat const &executor) const = 0;
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("AForm::exception : Grade Too High\n");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("AForm::exception : Grade Too Low\n");
                }
        };
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("AForm::exception : Form not signed\n");
                }
        };
        class FormAlreadySigned : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("AForm::exception : Form not signed\n");
                }
        };
        class FormGradeTooLowToExec : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("AForm::exception : Bureaucrat grade is too low to execute form\n");
                }
        };
        class CantOpenFile : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("AForm::exception : Bureaucrat can't open the target file\n");
                }
        };
};

std::ostream &  operator<<(std::ostream &out, AForm const &in);

#endif