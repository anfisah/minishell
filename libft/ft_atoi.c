/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:31:01 by xle-du            #+#    #+#             */
/*   Updated: 2021/06/07 14:42:50 by xle-du           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	negatif;
	int	nb;

	i = 0;
	negatif = 1;
	nb = 0;
	if (!str[i])
		return (0);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negatif = negatif * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb += str[i] - 48;
		i++;
		if (str[i] && str[i] >= '0' && str[i] <= '9')
			nb *= 10;
	}
	return (nb * negatif);
}
