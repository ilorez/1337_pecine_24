/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:52:28 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/01 13:57:32 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cap_it(char c)
{
	if ((c < '0' || c > '9') && (c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 90 && str[i] >= 65)
		{
			str[i] = str[i] + 32;
		}
		if (str[i] >= 97 && str[i] <= 122)
		{
			if (i == 0 || cap_it(str[i - 1]))
			{
				str[i] -= 32;
			}
		}
		i++;
	}
	return (str);
}
