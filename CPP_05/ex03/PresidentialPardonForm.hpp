#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <string>
# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm& operator=(PresidentialPardonForm const &rhs);
        std::string getTarget(void) const;
        void    execute(Bureaucrat const &executor) const;
};

#endif