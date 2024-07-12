/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 08:59:22 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/12 09:14:22 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
unsigned char	swap_bits(unsigned char octet)
{
	int	a;
	int	b;

	a = octet << 4;
	b = octet >> 4;
	octet = a | b;
	return (octet);
}

int	main()
{
	unsigned char octet = 48;
	printf("octet: %d\nreturned value:%d\n",octet, swap_bits(octet));
}
