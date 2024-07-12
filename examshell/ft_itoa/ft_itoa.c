/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:13:53 by znajdaou          #+#    #+#             */
/*   Updated: 2024/07/12 12:00:05 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int    cout_digits(int nbr)
{
    int i;

    i = 1;
    while (nbr > 9)
    {
        nbr /= 10;
        i++;
    }
    return (i);
}

void ft_stock(int nbr, int i, char *result)
{
    int mod;

    if (nbr == 0)
        return ;
    mod = nbr % 10 + 48;
    nbr /= 10;
    ft_stock(nbr, i, result);
    result[i++] = mod;
    //if (nbr > 9)
    //  ft_stock(nbr / 10, i, result);
    //mod = nbr % 10 + 48;
    //result[*i] = mod;
    //(*i)++;
}

char    *ft_itoa(int nbr)
{
    int malloc_s;
    int signe;
    char *result;
    int i;

    if (nbr == -2147483648)
    {
      result = malloc(12);
      result = "-2147483648";
      return (result);
    }
    i = 0;
    signe = 1;
    malloc_s = 1;
    if (nbr < 0)
    {
        signe = -1;
        malloc_s += 1;
        nbr = -nbr;
    }
    malloc_s += cout_digits(nbr);

    result = malloc(sizeof(char) * malloc_s);
    if (!result)
        return (NULL);


    if (signe == -1)
    {
        result[i] = '-';
        i++;
    }
    ft_stock(nbr, i, result);
    result[malloc_s - 1] = '\0';
    return (result);
}

int    main()
{
    printf("my string: %s\n", ft_itoa(2147483648));
}
