#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Intern  intern;
    AForm* form1 = NULL;
    form1 = intern.makeForm("RobotomyRequestForm", "Robot");
    if (form1)
        std::cout << std::endl;
    AForm* form2 = NULL;
    form2 = intern.makeForm("PresidentialPardonForm", "Macron");
    if (form2)
        std::cout << std::endl;
    AForm* form3 = NULL;
    form3 = intern.makeForm("ShrubberyCreationForm", "Luxembourg");
    if (form3)
        std::cout << std::endl;
    
    Bureaucrat Michel("Michel", 1);
    Michel.signForm(*form3);
    Michel.executeForm(*form3);
    Michel.signForm(*form3);
    std::cout << std::endl;

    int i = 0;
    while (i < 100)
    {
        Michel.downGrade();
        i++;
    }
    Michel.signForm(*form2);
    Michel.executeForm(*form2);
    std::cout << std::endl;
    Michel.executeForm(*form1);
    Michel.signForm(*form1);
    delete(form3);
    delete(form2);
    delete(form1);
    return (0);
}