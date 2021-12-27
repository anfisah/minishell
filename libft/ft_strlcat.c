/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:01:47 by xle-du            #+#    #+#             */
/*   Updated: 2020/11/23 02:14:01 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	size_dest;
	size_t	size_src;

	index = 0;
	size_dest = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size <= size_dest)
		return (size + size_src);
	while (src[index] && (size_dest + index) < (size - 1))
	{
		dst[index + size_dest] = src[index];
		index++;
	}
	dst[index + size_dest] = '\0';
	return (size_dest + size_src);
}
