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

float	ft_abs(float n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	_ft_sqrt(int nb, int x, float precision)
{
	x = (x + (nb / x)) / 2;
	if (ft_abs(nb - x * x) <= precision)
	{
		return ((int)x);
	}
	_ft_sqrt(nb, x, precision);
}

int	ft_sqrt(int nb)
{
	float	precision;

	if (nb <= 0)
	{
		return (0);
	}
	precision = 10e-10;
	return (_ft_sqrt(nb, nb, precision));
}
