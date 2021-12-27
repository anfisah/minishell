/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:19:49 by xle-du            #+#    #+#             */
/*   Updated: 2020/11/23 02:13:36 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			index;
	int				step;
	unsigned char	*dst;
	unsigned char	*source;

	if (dest == NULL && src == NULL)
		return (NULL);
	dst = (unsigned char *)dest;
	source = (unsigned char *)src;
	index = 0;
	step = 1;
	if (dest > src)
	{
		dst = dst + n - 1;
		source = source + n - 1;
		step = -1;
	}
	while (index++ < n)
	{
		*dst = *source;
		dst = dst + step;
		source = source + step;
	}
	return (dest);
}
