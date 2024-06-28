/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:24:38 by znajdaou          #+#    #+#             */
/*   Updated: 2024/06/27 21:29:22 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int	num_asc;
	int	nine_asc;

	nine_asc = 57;
	num_asc = 57 - 9;
	while (num_asc <= nine_asc)
	{
		write(1, &num_asc, 1);
		++num_asc;
	}
}
