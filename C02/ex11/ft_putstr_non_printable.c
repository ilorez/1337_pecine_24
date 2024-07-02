/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:20:26 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/02 09:05:29 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;

	len = 0;
	if (size > 0)
	{
		while (src[len] && --size)
		{
			dest[len] = src[len];
			len++;
		}
		dest[len] = '\0';
	}
	while (src[len])
	{
		len++;
	}
	return (len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	char			hex_str[17];

	ft_strlcpy(hex_str, "0123456789abcdef", 17);
	i = 0;
	while (str[i])
	{
		if (str[i] < 127 && str[i] > 31)
		{
			ft_putchar(str[i]);
		}
		else
		{
			ft_putchar('\\');
			ft_putchar(hex_str[(unsigned char)str[i] / 16]);
			ft_putchar(hex_str[(unsigned char)str[i] % 16]);
		}
		i++;
	}
}
