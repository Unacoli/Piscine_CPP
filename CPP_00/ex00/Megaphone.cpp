#include <iostream>

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	c;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			c = std::toupper(av[i][j]);
			std::cout << c;
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
