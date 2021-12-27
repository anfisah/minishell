/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:24:15 by xle-du            #+#    #+#             */
/*   Updated: 2021/04/20 11:13:26 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	jndex;
	size_t	size_little;

	index = -1;
	size_little = ft_strlen(little);
	if (size_little == 0)
		return ((char *)big);
	while (big[++index] && index < len)
	{
		jndex = 0;
		if (big[index] == little[jndex])
		{
			while ((big[index] == little[jndex])
				&& (jndex < size_little) && index < len)
			{
				if ((big[index] == little[jndex]) && (jndex == size_little - 1))
					return (&((char *)big)[index - size_little + 1]);
				index++;
				jndex++;
			}
			index = index - jndex;
		}
	}
	return (NULL);
}
