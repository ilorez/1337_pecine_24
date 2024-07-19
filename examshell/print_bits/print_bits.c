#include <unistd.h>
//#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	_print_bits(int	num, int times)
{
	if (num == 0 && times == 8)
	{
		return ;
	}
	_print_bits(num / 2, ++times);
	ft_putchar(num % 2 + 48);
}

void	print_bits(unsigned char octet)
{
	_print_bits((int)octet, 0);
}

/*int main(int ac, char **av)
{
	print_bits(atoi(av[ac *0 +1]));
	return (0);
}*/
