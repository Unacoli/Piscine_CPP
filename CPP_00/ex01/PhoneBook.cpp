#include "PhoneBook.hpp"

int Phonebook::Index = 0;

Phonebook::Phonebook(void)
{
    return ;
}

Phonebook::~Phonebook(void)
{
    return ;
}

int Phonebook::ContactIndex(void)
{
    return (Phonebook::Index);
}

void    Phonebook::Add(Phonebook *phonebook)
{
    Contact *contact;

    contact = phonebook->contact;
    if (Phonebook::Index < 8)
        Phonebook::Index++;
    else
        Phonebook::Index = 1;
    std::cout << std::endl << "Adding a new contact at index number " << Phonebook::Index << std::endl;
    Phonebook::Index--;
    contact[Phonebook::Index].Contact::Informations("First Name", &contact[Phonebook::Index]);
    contact[Phonebook::Index].Contact::Informations("Last Name", &contact[Phonebook::Index]);
    contact[Phonebook::Index].Contact::Informations("Nickname", &contact[Phonebook::Index]);
    contact[Phonebook::Index].Contact::Informations("Phone Number", &contact[Phonebook::Index]);
    contact[Phonebook::Index].Contact::Informations("Darkest Secret", &contact[Phonebook::Index]);
    Phonebook::Index++;
    return ;
}

void    Phonebook::Search(Phonebook *phonebook)
{
    int i;
    int flag;
    Contact *contact;
    std::string  wanted_index;

    i = 0;
    flag = 0;
    contact = phonebook->contact;
    if (Contact::is_empty(contact[0]))
    {
        std::cout << "Phonebook is empty." << std::endl;
        return ;
    }
    std::cout << "|  index   |first name| last name| nickname |" << std::endl;
    while (i < 7 && !Contact::is_empty(contact[i]))
    {
        std::cout << "|    " << i + 1 << "     |";
        std::cout << Contact::TruncColumn(&contact[i], "First Name") << "|";
        std::cout << Contact::TruncColumn(&contact[i], "Last Name") << "|";
        std::cout << Contact::TruncColumn(&contact[i], "Nickname") << "|" << std::endl;
        i++;
    }
    std::cout << std::endl << "Input the contact's index :" << std::endl;
    while (!flag)
    {
        std::getline(std::cin, wanted_index);
        if (std::cin.eof())
        {
            std::cin.clear();
            return ;
        }
        if (wanted_index.empty())
            std::cout << "Index can't be empty, input a valid index number :" << std::endl;
        else if (((std::atoi(wanted_index.c_str()) < 1 || std::atoi(wanted_index.c_str()) > 8))\
                || (Contact::is_empty(contact[std::atoi(wanted_index.c_str()) - 1])\
                && std::atoi(wanted_index.c_str()) > Phonebook::ContactIndex()))
            std::cout << "Index not valid, input a valid index number :" << std::endl;
        else
        {
            i = atoi(wanted_index.c_str()) - 1;
            flag = 1;
        }
    }
    std::cout << std::endl << "Contact details :" << std::endl;
    contact[i].PrintContact(contact[i]);
    return ;
}