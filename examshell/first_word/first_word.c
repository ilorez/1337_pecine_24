#include <unistd.h>

int ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	char *my_str;
	
	if ( ac == 2)
	{
		my_str = av[1];
		while(*my_str && ft_is_space(*my_str))
				my_str++;
			
		while(*my_str && !ft_is_space(*my_str))
					write(1, my_str++, 1);
	}
	write(1, "\n", 1);
	return (0);
}
