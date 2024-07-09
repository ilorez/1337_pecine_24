/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:55:46 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/09 09:25:58 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	*range = (int *)malloc((int)(sizeof(int) * (max - min)));
	if (max <= min)
		return (NULL);
	if (!*range)
		return (-1);
	while (min < max)
		(*range)[i++] = min++;
	return (**range);
}
