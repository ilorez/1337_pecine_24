/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:56:28 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/07 15:18:45 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_interative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb <= 0)
		return (0);
	while (nb != 1)
	{
		result *= nb;
		nb--;
	}
	return (result);
}
