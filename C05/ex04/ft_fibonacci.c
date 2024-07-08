/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:37:11 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/07 17:08:05 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_ft_fibonacci(int bln, int ln, int index)
{
	int	swap;

	if (!index)
		return (bln);
	swap = bln;
	bln = ln;
	ln = swap + bln;
	index--;
	return (_ft_fibonacci(bln, ln, index));
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	return (_ft_fibonacci(0, 1, index));
}
