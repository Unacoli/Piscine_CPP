#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>
# include <string>
# include <cstdlib>

class Contact {
    private:
        std::string FirstName;
        std::string LastName;
        std::string Nickname;
        std::string PhoneNumber;
        std::string DarkestSecret;
    public:
        Contact(void);
        ~Contact(void);
        void    Informations(std::string Type, Contact *contact);
        static std::string  TruncColumn(Contact *contact, std::string Type);
        void    PrintContact(Contact contact);
        static int  is_empty(Contact contact);
};

#endif