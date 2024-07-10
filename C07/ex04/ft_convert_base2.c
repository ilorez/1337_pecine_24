/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:36:04 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/09 11:36:20 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_valid_base(char *base)
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
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	ft_get_index_of(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_power(int nb, int power)
{
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}

int	ft_get_my_str(char **str, char **base, int *signe)
{
	int	i;

	i = 0;
	while (**str && ((**str >= 9 && **str <= 13) || **str == 32))
		(*str)++;
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*signe *= -1;
		(*str)++;
	}
	while ((*str)[i])
	{
		if (ft_get_index_of(*base, (*str)[i]) == -1)
			break ;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	signe;
	int	len;
	int	n;
	int	i;
	int	bl;

	if (!ft_is_valid_base(base))
		return (0);
	signe = 1;
	len = ft_get_my_str(&str, &base, &signe);
	n = 0;
	i = -1;
	bl = 0;
	while (base[bl])
		bl++;
	while (++i < len)
		n += ft_get_index_of(base, str[i]) * ft_power(bl, len - 1 - i);
	return (n * signe);
}
