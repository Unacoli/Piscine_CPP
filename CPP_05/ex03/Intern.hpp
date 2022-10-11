#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
    private:
        AForm   *createPresidentialPardonForm(std::string target);
        AForm   *createRobotomyRequestForm(std::string target);
        AForm   *createShrubberyCreationForm(std::string target);
    public:
        Intern(void);
        Intern(Intern const &src);
        ~Intern(void);
        Intern& operator=(Intern const &rhs);
        AForm   *makeForm(std::string formName, std::string formTarget);
        class CantFindForm : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Intern::exception : Intern can't find this form.\n");
                }
        };
};

#endif