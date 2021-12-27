/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:44:06 by xle-du            #+#    #+#             */
/*   Updated: 2021/06/11 15:29:05 by xle-du           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep(char c, char sep)
{
	return (c == sep);
}

int	count_word(char const *s, char c)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	while (s[index])
	{
		while (s[index] && is_sep(s[index], c))
			index++;
		if (s[index] && !is_sep(s[index], c))
		{
			count++;
			while (s[index] && !is_sep(s[index], c))
				index++;
		}
	}
	return (count);
}

char	*malloc_word(char const *s, char c)
{
	char	*word;
	size_t	size;

	size = 0;
	while (s[size] && !is_sep(s[size], c))
		size++;
	word = ft_malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	ft_memcpy(word, s, size);
	word[size] = '\0';
	return (word);
}

void	init(size_t *index, size_t *windex)
{
	*index = 0;
	*windex = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	size_t	windex;
	size_t	nb_word;
	char	**split;

	if (!s)
		return (NULL);
	init(&index, &windex);
	nb_word = count_word(s, c);
	split = ft_malloc(sizeof(char *) * (nb_word + 1));
	if (!split)
		return (NULL);
	while (s[index])
	{
		while (s[index] && is_sep(s[index], c))
			index++;
		if (s[index] && !is_sep(s[index], c))
		{
			split[windex++] = malloc_word(&s[index], c);
			while (s[index] && !is_sep(s[index], c))
				index++;
		}
	}
	split[windex] = 0;
	return (split);
}

//Test a"nouveau pour" voir'si ca'marche
