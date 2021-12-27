/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:59:48 by xle-du            #+#    #+#             */
/*   Updated: 2021/05/12 13:27:56 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long nbr, char *base, size_t *count)
{
	long	nb;
	int		sizebase;

	sizebase = ft_strlen_pf(base);
	nb = nbr;
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb = -nb;
	}
	if (nb >= sizebase)
		ft_putnbr_base(nb / sizebase, base, count);
	ft_putchar(base[nb % sizebase], count);
}

void	ft_putnbr_u(unsigned int nb, size_t *count)
{
	if (nb >= 10)
		ft_putnbr_u(nb / 10, count);
	ft_putchar((nb % 10) + '0', count);
}

void	ft_putstr(char *s, size_t *count)
{
	size_t	index;

	if (!s)
		return ;
	index = 0;
	while (s[index])
	{
		ft_putchar(s[index], count);
		index++;
	}
}

void	ft_putchar(char c, size_t *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

size_t	ft_strlen_pf(const char *s)
{
	size_t	lenght;

	lenght = 0;
	while (s[lenght])
		lenght++;
	return (lenght);
}
