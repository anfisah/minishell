/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:43:31 by xle-du            #+#    #+#             */
/*   Updated: 2020/12/21 12:16:47 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, size_t *count)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr((nbr / 10), count);
	ft_putchar(((nbr % 10) + '0'), count);
}

int	ft_isconversion(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

void	ft_putchar_c(char c, int size, size_t *count)
{
	int	index;

	index = 0;
	while (index < size)
	{
		ft_putchar(c, count);
		index++;
	}
}

void	ft_putstr_prec(char *s, int precision, size_t *count)
{
	size_t	index;

	if (!s)
		return ;
	index = 0;
	while (s[index] && (int)index < precision)
	{
		ft_putchar(s[index], count);
		index++;
	}
}
