/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:58:22 by xle-du            #+#    #+#             */
/*   Updated: 2021/04/20 10:29:36 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if ((((unsigned char *)src)[index]) == ((unsigned char)c))
		{
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
			return (&((unsigned char *)dest)[index + 1]);
		}
		((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (NULL);
}
