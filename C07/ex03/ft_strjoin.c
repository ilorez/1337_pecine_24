/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:28:03 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/14 18:46:39 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_calcule_c_size(char **strs, int size, int sl)
{
	int		m_size;
	int		i;
	char	*c_str;

	i = 0;
	m_size = 0;
	while (i < size)
	{
		m_size += ft_strlen(strs[i]);
		if (++i < size)
			m_size += sl;
	}
	c_str = malloc(sizeof(char) * (m_size + 1));
	return (c_str);
}

int	ft_conca(char **strs, char *c_str, int size, char *sep)
{
	int	k;
	int	j;
	int	i;
	int	sep_len;

	sep_len = ft_strlen(sep);
	i = 0;
	j = 0;
	while (i < size)
	{
		k = 0;
		while (strs[i][k])
			c_str[j++] = strs[i][k++];
		k = 0;
		if (++i < size)
			while (k < sep_len)
				c_str[j++] = sep[k++];
	}
	return (j);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		j;
	int		sep_len;
	char	*c_str;

	if (size <= 0)
	{
		c_str = malloc(1);
		c_str[0] = '\0';
		return (c_str);
	}
	sep_len = ft_strlen(sep);
	c_str = ft_calcule_c_size(strs, size, sep_len);
	if (!c_str)
		return (NULL);
	j = ft_conca(strs, c_str, size, sep);
	c_str[j] = 0;
	return (c_str);
}

/*int main(int argc, char **argv)
{
	(argc)--;
	printf("s: %s\n", ft_strjoin( argc, ++argv, ", "));

}*/
