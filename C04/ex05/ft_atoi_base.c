/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:35:41 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/06 09:44:24 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
int	ft_is_space(char	c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == 32)
	{
		return (1);
	}
	return (0);
}
int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || ft_is_space(bas[i]))
		{
			return (0);
		}
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_number(char c)
{
	if (c <= '9' && c >= '0')
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
		}
		else if (my_n > 0)
		{
			return (my_n * signe);
		}
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	return (my_n * signe);
}
void	ft_convert_base_string(char *str, base, bl)
{
	
}

int	ft_atoi_base(char *str, char *base)
{
	int	bl;

	bl = ft_strlen(base);
	if (bl <= 1 || !is_valid_base(base))
		return (0);
	ft_convert_base_string(str, base, bl);	
}
