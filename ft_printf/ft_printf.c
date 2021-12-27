/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:59:39 by xle-du            #+#    #+#             */
/*   Updated: 2021/05/12 13:07:58 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(int fd, const char *format, ...)
{
	va_list	valist;
	size_t	count;
	int		back;

	back = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	va_start(valist, format);
	count = parse(valist, (char *)format);
	va_end(valist);
	dup2(back, STDOUT_FILENO);
	close(back);
	return (count);
}
