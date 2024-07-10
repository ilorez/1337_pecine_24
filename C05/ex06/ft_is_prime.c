/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:35:08 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/10 08:12:55 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_ft_is_prime(int nb, int i)
{
	if (i * i > nb)
		return (1);
	if (nb % i == 0)
		return (0);
	return (_ft_is_prime(nb, i + 1));
}

int	ft_is_prime(int nb)
{
	if (nb < 2)
	{
		return (0);
	}
	return (_ft_is_prime(nb, 2));
}
