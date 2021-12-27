/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:36:43 by xle-du            #+#    #+#             */
/*   Updated: 2020/12/21 12:16:11 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_p_case1(char *s, t_settings settings, int size, size_t *cnt)
{
	ft_putstr("0x", cnt);
	ft_putchar_c('0', settings.width - size, cnt);
	ft_putstr_prec_p(s, settings.precision, cnt);
}

void	ft_put_p_case2(char *s, t_settings settings, int size, size_t *cnt)
{
	ft_putstr("0x", cnt);
	ft_putstr_prec_p(s, settings.precision, cnt);
	ft_putchar_c(' ', settings.width - size, cnt);
}

void	ft_put_p_case3(char *s, t_settings settings, size_t *cnt)
{
	ft_putstr("0x", cnt);
	ft_putstr_prec_p(s, settings.precision, cnt);
	ft_putchar_c(' ', settings.width - settings.precision - 2, cnt);
}

void	ft_put_p_case4(char *s, t_settings settings, size_t *cnt)
{
	ft_putchar_c(' ', settings.width - settings.precision - 2, cnt);
	ft_putstr("0x", cnt);
	ft_putstr_prec_p(s, settings.precision, cnt);
}

void	ft_put_p_case5(char *s, t_settings settings, int size, size_t *cnt)
{
	ft_putchar_c(' ', settings.width - size, cnt);
	ft_putstr("0x", cnt);
	ft_putstr_prec_p(s, settings.precision, cnt);
}
