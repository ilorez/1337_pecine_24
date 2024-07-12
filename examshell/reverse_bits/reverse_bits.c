/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:44:47 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/12 11:13:29 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	int len;
	int r;
	int x;
	int integer;
	
	integer = octet;
	len = 8;
	r = 0;
	x = 0;
	i = 0;
	while (i < len)
	{
		x = integer <<  i;
		x = x >> (len - 1);
		x = x << i;
		r = r | x;
		i++;
	}
	return (r);
}

int	main()
{
	printf("before: %d\n after: %d\n", 38, reverse_bits(38));
}
