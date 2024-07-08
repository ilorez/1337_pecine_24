/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:15:47 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/08 07:42:17 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	_ft_is_prime(int nb, int i)
{
	if (i == nb)
		return (1);
	if (nb % i == 0)
		return (0);
	retirn (_ft_is_prime(nb, i + 1));
}

int	ft_is_prime(int nb)
{
	return (_ft_is_prime(nb, 2));
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	return (ft_find_next_prime(++nb));
}
