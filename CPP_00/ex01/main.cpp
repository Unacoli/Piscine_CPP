#include "PhoneBook.hpp"

int	main(void)
{
	std::string	cmd;
	Phonebook	phonebook;

	while (cmd != "EXIT")
	{
		if (Phonebook::ContactIndex() > 0)
		std::cout << std::endl;
		std::cout << "PLease enter a command :" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			Phonebook::Add(&phonebook);
		else if (cmd == "SEARCH")
			Phonebook::Search(&phonebook);
		else if (cmd == "EXIT")
			break ;
		else if (std::cin.eof())
			break ;
		else
			std::cout << "Please enter ADD, SEARCH or EXIT." << std::endl;
	}
	return (0);
}
