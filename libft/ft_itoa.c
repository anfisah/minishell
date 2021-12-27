/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 01:45:59 by xle-du            #+#    #+#             */
/*   Updated: 2021/04/20 10:28:14 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	number_size(long n)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n >= 10)
	{
		size++;
		n = n / 10;
	}
	size++;
	return (size);
}

char	*ft_itoa(int n)
{
	char	*number;
	long	nbr;
	size_t	size;

	nbr = n;
	size = number_size(nbr);
	number = ft_malloc(sizeof(char) * (size + 1));
	if (!number)
		return (NULL);
	if (n < 0)
	{
		number[0] = '-';
		nbr = -nbr;
	}
	number[size] = '\0';
	while (nbr >= 10)
	{
		number[size - 1] = (nbr % 10) + '0';
		size--;
		nbr = nbr / 10;
	}
	number[size - 1] = (nbr % 10) + '0';
	return (number);
}
