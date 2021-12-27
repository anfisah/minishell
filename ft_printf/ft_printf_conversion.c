/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:15:48 by xle-du            #+#    #+#             */
/*   Updated: 2021/05/12 13:27:20 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list valist, size_t *count, t_settings settings)
{
	char	c;

	c = va_arg(valist, int);
	if (settings.flag_zero)
	{
		ft_putchar_c('0', settings.width - 1, count);
		ft_putchar(c, count);
	}
	else if (settings.flag_minus)
	{
		ft_putchar(c, count);
		ft_putchar_c(' ', settings.width - 1, count);
	}
	else
	{
		ft_putchar_c(' ', settings.width - 1, count);
		ft_putchar(c, count);
	}
}

void	ft_print_string(va_list valist, size_t *count, t_settings settings)
{
	char				*str;
	int					size_str;
	int					prec;
	t_display_settings	dsettings;

	str = va_arg(valist, char *);
	if (settings.precision != 0)
	{
		if (!str)
			str = "(null)";
		size_str = ft_strlen_pf(str);
		prec = size_str;
		if (settings.precision != -1 && settings.precision < prec)
			prec = settings.precision;
		dsettings.width = settings.width - prec;
		dsettings.precision = prec;
		display_str(str, settings, dsettings, count);
	}
	else
	{
		dsettings.width = settings.width;
		dsettings.precision = 0;
		display_str("", settings, dsettings, count);
	}
}

void	ft_print_address(va_list valist, size_t *count, t_settings settings)
{
	void				*address;
	unsigned long long	nbr;
	char				*str_address;

	address = va_arg(valist, void *);
	nbr = (unsigned long long)address;
	str_address = ft_itoa_hexa(nbr, "0123456789abcdef");
	display_p(str_address, settings, count);
	free(str_address);
}

void	ft_print_nbr(va_list valist, size_t *count, t_settings settings)
{
	int		nbr;
	char	*nombre;
	int		negative;

	nbr = va_arg(valist, int);
	negative = 0;
	if (nbr < 0)
		negative = 1;
	nombre = ft_itoa_pf(nbr);
	if (settings.precision == 0 && nbr == 0)
		display_d("", negative, settings, count);
	else
		display_d(nombre, negative, settings, count);
	free(nombre);
}

void	ft_print_unsigned(va_list valist, size_t *count, t_settings settings)
{
	unsigned int	nbr;
	char			*nombre;

	nbr = va_arg(valist, unsigned int);
	nombre = ft_itoa_u(nbr);
	if (settings.precision == 0 && nbr == 0)
		display_d("", 0, settings, count);
	else
		display_d(nombre, 0, settings, count);
	free(nombre);
}
