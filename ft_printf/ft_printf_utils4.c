/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:11:56 by xle-du            #+#    #+#             */
/*   Updated: 2021/05/12 13:34:16 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_nb(long nb)
{
	int	size;

	size = 1;
	while (nb >= 10)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

char	*ft_itoa_pf(int nb)
{
	long	nbr;
	int		sizenb;
	char	*nombre;

	nbr = nb;
	if (nbr < 0)
		nbr = -nbr;
	sizenb = count_nb(nbr);
	nombre = (char *)malloc(sizeof(char) * (sizenb + 1));
	if (!nombre)
		return (NULL);
	nombre[sizenb--] = '\0';
	while (nbr >= 10)
	{
		nombre[sizenb] = (nbr % 10) + '0';
		nbr = nbr / 10;
		sizenb--;
	}
	nombre[sizenb] = (nbr % 10) + '0';
	return (nombre);
}

char	*ft_itoa_u(unsigned int nb)
{
	unsigned int	nbr;
	int				sizenb;
	char			*nombre;

	nbr = nb;
	sizenb = 1;
	while (nbr >= 10)
	{
		sizenb++;
		nbr = nbr / 10;
	}
	nombre = (char *)malloc(sizeof(char) * (sizenb + 1));
	if (!nombre)
		return (NULL);
	nbr = nb;
	nombre[sizenb--] = '\0';
	while (nbr >= 10)
	{
		nombre[sizenb] = (nbr % 10) + '0';
		nbr = nbr / 10;
		sizenb--;
	}
	nombre[sizenb] = (nbr % 10) + '0';
	return (nombre);
}

void	ft_putstr_prec_p(char *s, int precision, size_t *count)
{
	size_t	index;
	int		sizes;

	index = 0;
	sizes = ft_strlen_pf(s);
	if (sizes < precision)
	{
		while (sizes < precision)
		{
			ft_putchar('0', count);
			sizes++;
		}
	}
	ft_putstr(s, count);
}

void	ft_putstr_prec_d(char *nombre, int precision, size_t *count)
{
	int	sizenb;

	sizenb = ft_strlen_pf(nombre);
	ft_putchar_c('0', precision - sizenb, count);
	ft_putstr(nombre, count);
}
