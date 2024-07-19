
#include <unistd.h>

int	ft_is_space(char c)
{
	if ( c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	char	*str;
	int	found_word;

	found_word = 0;
	if (ac == 2)
	{
		str = av[1];
	while (*str)
	{
		while (*str && ft_is_space(*str))
			str++;
		if (*str && found_word)
			write(1, "   ", 3);
		while (*str && !ft_is_space(*str))
			write(1, str++, 1);
		if (!found_word)
			found_word = 1;
	}
	}
	write(1, "\n", 1);
	return (0);
}
