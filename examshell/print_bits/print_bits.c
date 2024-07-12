/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 09:23:35 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/12 10:05:46 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	_print_bits(unsigned char octet, int i)
{
	// int mod;
	if ((i % 8 != 0) && octet == 0)
	{
		ft_putchar(48);
		_print_bits(octet, ++i);
		return ;
	}
	else if ( i % 8 == 0 && octet == 0)
	{
		return ;
	}
	//	ft_putchar('-');
	//	ft_putchar(octet);
	//	ft_putchar('_');
	// mod = octet % 2;
	// octet = octet / 2;
	_print_bits(octet / 2, ++i);
	ft_putchar((octet % 2 + 48));
}

void	print_bits(unsigned char octet)
{
	_print_bits(octet, 0);
}

int	main(int argc, char **argv)
{
	(void)argv;
	print_bits(argc);
}
