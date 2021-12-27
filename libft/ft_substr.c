/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:52:40 by xle-du            #+#    #+#             */
/*   Updated: 2021/06/22 15:24:49 by xle-du           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	str = ft_malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (index < len && ((index + start) < size))
	{
		str[index] = s[start + index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
