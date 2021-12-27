/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:40:51 by xle-du            #+#    #+#             */
/*   Updated: 2021/05/12 13:27:02 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	size;

	size = ft_strlen(s);
	cpy = ft_malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s, size);
	cpy[size] = '\0';
	return (cpy);
}
