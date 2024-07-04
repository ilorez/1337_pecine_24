/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:43:03 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/02 18:55:08 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		pos;

	i = 0;
	if (!*to_find)
		return (str);
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			pos = i;
			while (to_find[j] && str[i + j] == to_find[j])
			{
				if (!to_find[j + 1])
					return (&str[pos]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
