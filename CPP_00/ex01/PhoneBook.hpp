#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "Contact.hpp"
# include <iostream>
# include <string>
# include <cstdlib>

class Phonebook {
    private :
        static int Index;
        Contact contact[8];
    public :
        Phonebook(void);
        ~Phonebook(void);
        static int  ContactIndex(void);
        static void Add(Phonebook *phonebook);
        static void Search(Phonebook *phonebook);
};

#endif