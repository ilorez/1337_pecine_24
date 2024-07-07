/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:35:41 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/07 09:58:33 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space_get_len(char c, char *str, int choix)
{
	int	i;

	if (choix)
	{
		if (c == '\t' || c == '\n' || c == '\v')
			return (1);
		else if (c == '\f' || c == '\r' || c == 32)
			return (1);
		return (0);
	}
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (ft_is_space_get_len(base[i], "a ", 1))
			return (0);
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

int	ft_get_index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_power(int nb, int power)
{
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}

int	ft_atoi_base(char *str, char *base)
{
	int	bl;
	int	sl;
	int	i;
	int	n;
	int	signe;

	signe = 1;
	while (ft_is_space_get_len(*str, "a ", 1))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	bl = ft_is_space_get_len(' ', base, 0);
	sl = ft_is_space_get_len(' ', str, 0);
	if (bl <= 1 || !is_valid_base(base))
		return (0);
	n = 0;
	i = -1;
	while (str[++i])
		n += ft_get_index_of(base, str[i]) * ft_power(bl, sl - 1 - i);
	return (n * signe);
}
