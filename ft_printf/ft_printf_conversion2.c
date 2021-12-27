/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:21:18 by xle-du            #+#    #+#             */
/*   Updated: 2020/12/21 12:11:15 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa_lower(va_list valist, size_t *count, t_settings settings)
{
	unsigned int	nbr;
	char			*str_hexa;

	nbr = va_arg(valist, int);
	str_hexa = ft_itoa_hexa(nbr, "0123456789abcdef");
	display_x(str_hexa, settings, count);
	free(str_hexa);
}

void	ft_print_hexa_upper(va_list valist, size_t *count, t_settings settings)
{
	unsigned int	nbr;
	char			*str_hexa;

	nbr = va_arg(valist, int);
	str_hexa = ft_itoa_hexa(nbr, "0123456789ABCDEF");
	display_x(str_hexa, settings, count);
	free(str_hexa);
}

void	ft_print_percent(size_t *count, t_settings settings)
{
	if (settings.flag_zero)
	{
		ft_putchar_c('0', settings.width - 1, count);
		ft_putchar('%', count);
	}
	else if (settings.flag_minus)
	{
		ft_putchar('%', count);
		ft_putchar_c(' ', settings.width - 1, count);
	}
	else
	{
		ft_putchar_c(' ', settings.width - 1, count);
		ft_putchar('%', count);
	}
}
