/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:52:33 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/01 13:51:53 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	len;

	len = 0;
	while (src[len] && --size)
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	while (src[len])
	{
		len++;
	}
	return (len);
}
