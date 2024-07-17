/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:36:37 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/17 09:52:21 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		ft_is_valid_base(char *base);

int	ft_get_b_size(unsigned int nbr, int len)
{
	if (nbr < (unsigned int)len)
		return (1);
	return (1 + ft_get_b_size(nbr / len, len));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnb_base(char **result, int nbr, char *base, int m_s)
{
	int				i;
	int				bl;
	int				m;
	unsigned int	dnbr;

	i = 0;
	m = 0;
	if (nbr < 0)
	{
		(*result)[i] = '-';
		dnbr = (unsigned int)(-nbr);
		m = 1;
	}
	else
		dnbr = (unsigned int)(nbr);
	bl = ft_strlen(base);
	while (i < m_s - m)
	{
		(*result)[m_s - 1 - i] = base[dnbr % bl];
		dnbr /= bl;
		i++;
	}
}

int	get_malloc_size(int *anum, unsigned int *decnum, int btl)
{
	if (*anum < 0)
	{
		*decnum = (unsigned int)((*anum) * -1);
		return (2 + ft_get_b_size((*decnum), btl));
	}
	*decnum = (unsigned int)(*anum);
	return (1 + ft_get_b_size((*decnum), btl));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				anum;
	unsigned int	decnum;
	int				m_s;
	char			*result;
	int				btl;

	if (!base_from || !base_to || !nbr
		|| !ft_is_valid_base(base_to) || !ft_is_valid_base(base_from))
		return (NULL);
	anum = ft_atoi_base(nbr, base_from);
	btl = ft_strlen(base_to);
	m_s = get_malloc_size(&anum, &decnum, btl);
	result = (char *)malloc(sizeof(char) * (m_s));
	if (!result)
		return (NULL);
	result[m_s - 1] = '\0';
	if (decnum == 0)
		(result)[0] = base_to[0];
	else
		ft_putnb_base(&result, anum, base_to, (m_s - 1));
	return (result);
}

/*int	main(int argc, char **argv)
{
	printf("%s\n", ft_convert_base(argv[argc * 0 + 1], argv[2], argv[3]));
	return (0);
}*/
