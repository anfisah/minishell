/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:30:59 by xle-du            #+#    #+#             */
/*   Updated: 2021/04/20 10:26:00 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	fullsize;

	fullsize = nmemb * size;
	array = ft_malloc(fullsize);
	if (!array)
		return (NULL);
	ft_bzero(array, fullsize);
	return (array);
}
