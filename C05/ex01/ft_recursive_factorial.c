/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:10:14 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/07 15:10:57 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int	nb)
{
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (nb);
	return (nb * ft_recursive_factorial(nb - 1));
}
