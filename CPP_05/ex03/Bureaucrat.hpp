#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
# include <string>
# include <iostream>
# include <limits>
# include "AForm.hpp"

class   AForm;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &src);
        ~Bureaucrat(void);
        Bureaucrat & operator=(Bureaucrat const &rhs);
        std::string const getName(void) const;
        int getGrade(void) const;
        void    upGrade(void);
        void    downGrade(void);
        void    signForm(AForm &form) const;
        void    executeForm(AForm const &form);
    class   GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("Bureaucrat::exception : Grade Too High\n");
            }
    };
    class   GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("Bureaucrat::exception : Grade Too Low\n");
            }
    };
};

std::ostream & operator<<(std::ostream &out, Bureaucrat const &in);

#endif