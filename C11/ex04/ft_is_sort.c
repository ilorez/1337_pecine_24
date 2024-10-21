/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:05:29 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/18 21:40:12 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	a;
	int	b;

	a = 1;
	b = 1;
	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
			a = 0;
		if (f(tab[i - 1], tab[i]) < 0)
			b = 0;
		i++;
	}
	return (a || b);
}
