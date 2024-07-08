/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:39:55 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/07 18:32:42 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_abs(double n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	_ft_sqrt(int nb, double x, double precision)
{
	x = (x + (nb / x)) / 2;
	if (ft_abs(nb - (x * x)) <= precision)
	{
		return (x);
	}
	return (_ft_sqrt(nb, x, precision));
}

int	ft_sqrt(int nb)
{
	double	precision;

	if (nb <= 0)
	{
		return (0);
	}
	precision = 10e-10;
	return (_ft_sqrt(nb, nb, precision));
}
