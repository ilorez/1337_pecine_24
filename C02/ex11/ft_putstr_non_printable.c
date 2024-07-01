/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:20:26 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/01 21:10:47 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

void	ft_dec_to_hexa(int n, char *dest)
{
	int	i;
	int	teamp;

	i = 0;
	while (n != 0)
	{
		if (i == 0 && n < 16)
			dest[i++] = 48;
		teamp = n % 16;
		if (teamp < 10)
			dest[i] = teamp + 48;
		else
			dest[i] = teamp + 55;
		i++;
		n = n / 16;
	}
}

void	ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 32;
		}
		i++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	char			hex[100];
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 127 && str[i] > 31)
		{
			ft_putchar(str[i]);
		}
		else if (str[i] == 127 || (str[i] >= 0 && str[i] <= 31))
		{
			ft_putchar('\\');
			ft_dec_to_hexa(str[i], hex);
			ft_strlowcase(hex);
			ft_putstr(hex);
		}
		i++;
	}
}
