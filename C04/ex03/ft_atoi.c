/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:51:34 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/06 17:16:09 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\r' || c == 32)
		return (1);
	return (0);
}

int	ft_is_num_space_p_m(char c)
{
	if (ft_is_space(c) || is_number(c) || c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	my_n;

	my_n = 0;
	i = 0;
	signe = 1;
	while (str[i] && ft_is_num_space_p_m(str[i]))
	{
		if (is_number(str[i]))
		{
			my_n = my_n * 10 + (str[i] - 48);
			if (str[i + 1] && (str[i + 1] < '0' || str[i + 1] > '9'))
				return (my_n * signe);
		}
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	return (my_n * signe);
}
