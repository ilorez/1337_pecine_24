/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:28:03 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/11 16:53:32 by znajdaou         ###   ########.fr       */
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
	c_str = (char *)malloc(sizeof(char) * (m_size + 1));
	return (c_str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	int		sep_len;
	char	*c_str;

	if (size <= 0)
		return (0);
	sep_len = ft_strlen(sep);
	c_str = ft_calcule_c_size(strs, size, sep_len);
	if (!c_str)
		return (NULL);
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
	c_str[j] = 0;
	return (c_str);
}

/*int main(int argc, char **argv)
{
	int i;
	
	i = argc ;
	(argc)--;
	printf("s: %s\n", ft_strjoin( argc, ++argv, ", "));

}*/
