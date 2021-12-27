/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:59:00 by xle-du            #+#    #+#             */
/*   Updated: 2021/05/12 13:26:42 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size_s1;
	size_t	size_s2;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str = ft_malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, size_s1);
	ft_memcpy(str + size_s1, s2, size_s2);
	str[size_s1 + size_s2] = '\0';
	return (str);
}
