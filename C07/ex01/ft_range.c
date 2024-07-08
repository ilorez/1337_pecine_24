/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:28 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/08 17:28:36 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	arr;
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (!arr)
		return (0);
	while (min < max)
		arr[i++] = min++;
	return (arr);
}
