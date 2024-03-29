#include "Harl.hpp"

Harl::Harl(void)
{
    return ;
}

Harl::~Harl(void)
{
    return ;
}

void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
    std::cout << std::endl;
    return ;
}

void    Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
    std::cout << std::endl;
    return ;
}

void    Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
    return ;
}

void    Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
    return ;
}

void    Harl::complain(std::string level)
{
    void    (Harl::*complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    size_t  i;

    i = 0;
    while (i < 4)
    {
        if (level == levels[i])
            break ;
        i++;
    }
    switch(i)
    {
        case 0 :
            (this->*complain[i])();
            i++;
        case 1 :
            (this->*complain[i])();
            i++;
        case 2 :
            (this->*complain[i])();
            i++;
        case 3 :
            (this->*complain[i])();
            break ;
        default :
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break ;
    }
    return ;
}