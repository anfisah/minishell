/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:23:47 by xle-du            #+#    #+#             */
/*   Updated: 2020/12/19 15:35:05 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_settings	ft_init_settings(void)
{
	t_settings	settings;

	settings.flag_zero = 0;
	settings.flag_minus = 0;
	settings.width = 0;
	settings.precision = -1;
	settings.error = 0;
	return (settings);
}
