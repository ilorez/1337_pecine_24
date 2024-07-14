/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:55:46 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/14 18:46:05 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	j;

	if (max <= min)
	{
		(*range) = NULL;
		return (-1);
	}
	len = max - min;
	(*range) = malloc((sizeof(int) * (len)));
	if ((*range) == NULL)
		return (-1);
	j = 0;
	while (j < len)
	{
		(*range)[j] = (min + j);
		j++;
	}
	return (len);
}

/*int main()
{
	int	**range;
	int *range1;
	int min = 2;
	int max = 10;
	int len;
	int i = 0;

	range = &range1;
	len = ft_ultimate_range(range, min, max);
	printf("Min: %d\nMax: %d\nSize of range: %d\n", min, max, len);
	while (i < len)
	{
		printf("n %d:%d\n", i, range1[i]);
		i++;
	}
}*/
