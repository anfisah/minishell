/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:10:37 by xle-du            #+#    #+#             */
/*   Updated: 2020/11/23 14:47:38 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	char	*last;

	index = 0;
	last = NULL;
	while (s[index])
	{
		if (s[index] == c)
			last = (&((char *)s)[index]);
		index++;
	}
	if (s[index] == c)
		last = (&((char *)s)[index]);
	return (last);
}
