/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:29:18 by xle-du            #+#    #+#             */
/*   Updated: 2021/05/12 13:28:57 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_hexa(unsigned long long nb, char *base)
{
	char				*str;
	unsigned long long	nbr;
	int					sizebase;
	int					sizenb;

	sizebase = ft_strlen_pf(base);
	nbr = nb;
	sizenb = 1;
	while (nbr >= (unsigned long long)sizebase)
	{
		nbr = nbr / sizebase;
		sizenb++;
	}
	str = (char *)malloc(sizeof(char) * (sizenb + 1));
	if (!str)
		return (NULL);
	str[sizenb--] = '\0';
	while (nb >= (unsigned long long)sizebase)
	{
		str[sizenb--] = base[nb % sizebase];
		nb = nb / sizebase;
	}
	str[sizenb] = base[nb % sizebase];
	return (str);
}
