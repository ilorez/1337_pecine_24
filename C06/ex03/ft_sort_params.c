/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:20:31 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/08 11:15:22 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_print_strs(char *strs[], int *sorted_indexs, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (sorted_indexs[j] == i)
			{
				ft_putstr(strs[j + 1]);
				ft_putchar('\n');
			}
			j++;
		}
		i++;
	}
}

int	main(const int argc, char *argv[])
{
	int	i;
	int	j;
	int	sorted_indexs[argc - 1];
	int	pos;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		pos = 0;
		while (++j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
				pos++;
		}
		sorted_indexs[i - 1] = pos;
	}
	ft_print_strs(argv, sorted_indexs, argc - 1);
	return (0);
}
// test 1
/*
				ft_putchar(48+j);
				ft_putchar(':');
				ft_putchar(48+j+1);
*/
// test 2
/*
		ft_putchar(i+48);
		ft_putchar(':');
		ft_putchar(pos + 48);
		ft_putchar('\n');
*/

// write(1, "----------\n", 11);
