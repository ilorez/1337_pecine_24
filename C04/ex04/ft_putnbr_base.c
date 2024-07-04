/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:20:23 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/03 17:15:26 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
		{
			return (0);
		}
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	_ft_putnbr_base(int nbr, char *base, int len)
{
	int	mod;

	if (nbr > 0)
	{
		mod = nbr % len;
		nbr /= len;
		_ft_putnbr_base(nbr, base, len);
		ft_putchar(base[mod]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	bl;

	bl = ft_strlen(base);
	if (bl <= 1 || !is_valid_base(base))
		return ;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr == 0)
		ft_putchar('0');
	else
		_ft_putnbr_base(nbr, base, bl);
}
