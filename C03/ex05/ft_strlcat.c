/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:00:07 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/03 10:25:22 by znajdaou         ###   ########.fr       */
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

void	ft_strncat(char *dest, char *src, unsigned int nb, unsigned int dl)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (src[j] && j < nb)
	{
		dest[dl] = src[j];
		dl++;
		j++;
	}
	while (j < nb)
	{
		dest[dl] = '\0';
		dl++;
		j++;
	}
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	dest_p_src_len;
	int	dest_len;

	dest_len = ft_strlen(dest);
	dest_p_src_len = dest_len + ft_strlen(src);
	ft_strncat(dest, src, (size - dest_len - 1), dest_len);
	return (dest_p_src_len);
}
