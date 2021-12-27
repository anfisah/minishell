/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_settings.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:27:21 by xle-du            #+#    #+#             */
/*   Updated: 2020/12/21 12:13:12 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_settings_flags(char *str, size_t *index, t_settings *settings)
{
	while (str[*index] == '0' || str[*index] == '-')
	{
		if (str[*index] == '0' && settings->flag_minus == 0)
			settings->flag_zero = 1;
		else if (str[*index] == '-')
		{
			settings->flag_minus = 1;
			settings->flag_zero = 0;
		}
		*index = *index + 1;
	}
}

void	parse_settings_width(va_list valist, char *str, size_t *index,
			t_settings *settings)
{
	int	flagstar;

	if (str[*index] == '*')
	{
		flagstar = va_arg(valist, int);
		if (flagstar < 0)
		{
			settings->flag_minus = 1;
			settings->flag_zero = 0;
			flagstar = -flagstar;
		}
		settings->width = flagstar;
		*index = *index + 1;
	}
	while (str[*index] && ft_isdigit(str[*index]))
		settings->width = settings->width * 10 + (str[(*index)++] - '0');
}

void	parse_settings_precision(va_list valist, char *str, size_t *index,
			t_settings *settings)
{
	int	precision;

	if (str[*index] == '.')
	{
		settings->precision = 0;
		*index = *index + 1;
		if (str[*index] == '*')
		{
			precision = va_arg(valist, int);
			if (precision >= 0)
				settings->precision = precision;
			else
				settings->precision = -1;
			*index = *index + 1;
		}
		while (str[*index] && ft_isdigit(str[*index]))
		{
			settings->precision = settings->precision * 10;
			settings->precision += (str[(*index)++] - '0');
		}
	}
}

t_settings	parse_settings(va_list valist, char *str, size_t *index)
{
	t_settings	settings;

	settings = ft_init_settings();
	parse_settings_flags(str, index, &settings);
	parse_settings_width(valist, str, index, &settings);
	parse_settings_precision(valist, str, index, &settings);
	if (!(str[*index] && ft_isconversion(str[*index])))
		settings.error = 1;
	return (settings);
}
