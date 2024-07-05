/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:40:05 by znajdaou          #+#    #+#             */
/*   Updated: 2024/06/27 21:03:55 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	char_asc;
	char	z_asc;

	char_asc = 97;
	z_asc = char_asc + 25;
	while (char_asc <= z_asc)
	{
		write(1, &char_asc, 1);
		++char_asc;
	}
}
