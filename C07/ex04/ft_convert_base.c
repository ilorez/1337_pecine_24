/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:36:37 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/09 22:19:12 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	ft_number_digits(int	nbr)
{
	if (nbr < 10)
		return (1);
	return (1 + ft_number_digits(nbr / 10));
}

void	_ft_putnbr_base(int nbr, char *base, int len)
{
	int	mod;

	if (nbr > 0)
	{
		mod = nbr % len;
		nbr /= len;
		_ft_putnbr_base(nbr, base, len);
		// use maloc to store this numb as string
		//ft_putchar(base[mod]);
	}
}

void	ft_putnb_base(int nbr, char *base)
{
	int	bl;

	bl = ft_strlen(base);
	if (bl <= 1 || !is_valid_base(base))
		return ;
	else if (nbr < 0)
	{
		nbr = -nbr;
		// store mines
	}
	if (nbr == 0)
	// store 0
	else
		_ft_putnbr_base(nbr, base, bl);
}

char	*ft_convert_base(char *nbr, char *base_form, char *base_to)
{
	int	decnum;

	decum = ft_atoi_base(nbr, base_form);


	// convert from (nbr in base form ) to nbm in (nbr int base 10) using atoi base
	// from the another file ft_convert_base2.c

	// after get the number convert it to (base to) by editing in putnbr base funtioin
	
   	// return the nbr	
}
