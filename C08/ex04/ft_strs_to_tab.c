/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:19:24 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/13 16:25:07 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_create_cpy(char *str, int len)
{
	char	*m_dest;

	m_dest = malloc(sizeof(char) * (len + 1));
	if (!m_dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		m_dest[i] = str[i];
		i++;
	}
	m_dest[i] = '\0';
	return (my_dest);
}

struct	s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	**m_s_strs;
	int	i;
	int len;

	m_s_strs = malloc(sizeof(char) * (ac + 1));
	if (!m_s_strs)
		return (NULL);
	i = 0;	
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		m_s_strs[i].size = len;
		m_s_strs[i].str = av[i];
		m_s_strs[i].copy = ft_create_cpy(av[i], len);
		if (!m_s_strs[i].copy)
			return (NULL);
		i++;
	}
	return (m_s_strs);
}
