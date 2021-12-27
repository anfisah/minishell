/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:43:55 by xle-du            #+#    #+#             */
/*   Updated: 2020/12/19 14:14:24 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_conversion(va_list valist, char *str, size_t *count)
{
	size_t		index;
	t_settings	settings;

	index = 0;
	settings = parse_settings(valist, str, &index);
	if (str[index] == 'c')
		ft_print_char(valist, count, settings);
	else if (str[index] == 's')
		ft_print_string(valist, count, settings);
	else if (str[index] == 'p')
		ft_print_address(valist, count, settings);
	else if (str[index] == 'd' || str[index] == 'i')
		ft_print_nbr(valist, count, settings);
	else if (str[index] == 'u')
		ft_print_unsigned(valist, count, settings);
	else if (str[index] == 'x')
		ft_print_hexa_lower(valist, count, settings);
	else if (str[index] == 'X')
		ft_print_hexa_upper(valist, count, settings);
	else if (str[index] == '%')
		ft_print_percent(count, settings);
	return (index);
}

int	parse(va_list valist, char *str)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] != '%')
			ft_putchar(str[index], &count);
		else if (str[index] == '%')
		{
			index++;
			index = index + parse_conversion(valist, &str[index], &count);
		}
		index++;
	}
	return (count);
}
