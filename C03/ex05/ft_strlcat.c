/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:00:07 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/07 14:21:05 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strncat(char *dest, char *src, unsigned int nb, unsigned int dl)
{
	unsigned int	j;

	j = 0;
	while (src[j] && j < nb)
	{
		dest[dl + j] = src[j];
		j++;
	}
	dest[dl + j] = '\0';
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_p_src_len;
	unsigned int	dest_len;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	dest_p_src_len = dest_len + src_len;
	if (size <= dest_len)
		return (size + src_len);
	ft_strncat(dest, src, (size - dest_len - 1), dest_len);
	return (dest_p_src_len);
}
