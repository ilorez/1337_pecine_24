/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 09:23:35 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/12 10:22:27 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int integer;
	int dividend;

	dividend = 128;
	integer = octet;
	while (dividend != 0)
	{
		if (dividend <= integer)
		{
			write(1, "1", 1);
		integer = integer % dividend;
		}
		else
			write(1, "0", 1);
		dividend = dividend / 2;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	print_bits(argc);
}
