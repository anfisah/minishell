/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 13:09:35 by xle-du            #+#    #+#             */
/*   Updated: 2021/05/12 13:28:15 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_str(char *str, t_settings settings,
						t_display_settings dsettings, size_t *count)
{
	if (settings.flag_zero)
	{
		ft_putchar_c('0', dsettings.width, count);
		ft_putstr_prec(str, dsettings.precision, count);
	}
	else if (settings.flag_minus)
	{
		ft_putstr_prec(str, dsettings.precision, count);
		ft_putchar_c(' ', dsettings.width, count);
	}
	else
	{
		ft_putchar_c(' ', dsettings.width, count);
		ft_putstr_prec(str, dsettings.precision, count);
	}
}

void	display_p(char *str, t_settings settings, size_t *count)
{
	int	sizestr;

	if (str[0] == '0' && str[1] == '\0' && settings.precision == 0)
		str[0] = '\0';
	sizestr = ft_strlen_pf(str) + 2;
	if (settings.flag_zero && settings.precision == -1)
		ft_put_p_case1(str, settings, sizestr, count);
	else if (settings.flag_minus && settings.precision <= (sizestr - 2))
		ft_put_p_case2(str, settings, sizestr, count);
	else if (settings.flag_minus && settings.precision > (sizestr - 2))
		ft_put_p_case3(str, settings, count);
	else if (settings.precision > (sizestr - 2))
		ft_put_p_case4(str, settings, count);
	else
		ft_put_p_case5(str, settings, sizestr, count);
}

void	display_d2(char *nombre, int neg, t_settings settings, size_t *count)
{
	int	sizenbr;

	sizenbr = ft_strlen_pf(nombre);
	ft_putchar_c(' ', settings.width - sizenbr - neg, count);
	if (neg)
		ft_putchar('-', count);
	ft_putstr_prec_d(nombre, settings.precision, count);
}

void	display_d(char *nombre, int neg, t_settings settings, size_t *count)
{
	int	sizenbr;

	sizenbr = ft_strlen_pf(nombre);
	if (sizenbr < settings.precision)
		sizenbr = settings.precision;
	if (settings.flag_zero && settings.precision == -1)
	{
		if (neg)
			ft_putchar('-', count);
		ft_putchar_c('0', settings.width - sizenbr - neg, count);
		ft_putstr_prec_d(nombre, settings.precision, count);
	}
	else if (settings.flag_minus)
	{
		if (neg)
			ft_putchar('-', count);
		ft_putstr_prec_d(nombre, settings.precision, count);
		ft_putchar_c(' ', settings.width - sizenbr - neg, count);
	}
	else
		display_d2(nombre, neg, settings, count);
}

void	display_x(char *str, t_settings settings, size_t *count)
{
	int	sizestr;

	if (str[0] == '0' && str[1] == '\0' && settings.precision == 0)
		str[0] = '\0';
	sizestr = ft_strlen_pf(str);
	if (sizestr < settings.precision)
		sizestr = settings.precision;
	if (settings.flag_zero && settings.precision == -1)
	{
		ft_putchar_c('0', settings.width - sizestr, count);
		ft_putstr_prec_p(str, settings.precision, count);
	}
	else if (settings.flag_minus)
	{
		ft_putstr_prec_p(str, settings.precision, count);
		ft_putchar_c(' ', settings.width - sizestr, count);
	}
	else
	{
		ft_putchar_c(' ', settings.width - sizestr, count);
		ft_putstr_prec_p(str, settings.precision, count);
	}
}
