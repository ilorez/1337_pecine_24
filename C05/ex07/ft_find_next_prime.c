/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:15:47 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/10 08:10:51 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdlib.h>
#include <stdio.h>
*/

int	ft_is_prime(int nb, int i)
{
	if (i * i > nb)
		return (1);
	if (nb % i == 0)
		return (0);
	return (ft_is_prime(nb, i + 1));
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (ft_is_prime(nb, 2))
		return (nb);
	return (ft_find_next_prime(++nb));
}

/*int	main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		printf("n %d : %d\n", i, ft_find_next_prime(atoi(argv[i])));
		i++;
	}
	
}*/
