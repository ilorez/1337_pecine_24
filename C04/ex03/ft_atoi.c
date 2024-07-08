/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:51:34 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/08 15:26:23 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	ft_get_my_str(char **str, int *signe)
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
	while (is_number((*str)[i]))
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	my_n;
	int	len;

	my_n = 0;
	i = 0;
	signe = 1;
	len = ft_get_my_str(&str, &signe);
	while (i < len)
	{
		if (!is_number(str[i]))
			break ;
		my_n = my_n * 10 + (str[i] - 48);
		i++;
	}
	return (my_n * (signe));
}
/*
int main() {
    printf("%d\n", ft_atoi("  +-+----22"));
}*/
