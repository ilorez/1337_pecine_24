/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:06:33 by znajdaou          #+#    #+#             */
/*   Updated: 2024/06/27 21:18:48 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	char_asc;
	char	a_asc;

	a_asc = 97;
	char_asc = 97 + 25;
	while (char_asc >= a_asc)
	{
		write(1, &char_asc, 1);
		--char_asc;
	}
}
