/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:35:28 by xle-du            #+#    #+#             */
/*   Updated: 2021/06/07 13:16:31 by xle-du           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int	reach_eol(char *str)
{
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

static int	search_nextline(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

static int	read_next_line(char **str, char **line, char *tmp, int eof)
{
	int		index_nextl;

	if (tmp == 0 && eof == 1)
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (0);
	}
	index_nextl = search_nextline(*str);
	*line = ft_substr(*str, 0, index_nextl);
	tmp = ft_substr(*str, index_nextl + 1, ft_strlen(*str) - index_nextl - 1);
	free(*str);
	*str = tmp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*fd_line[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			nb_read;
	int			eof;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	eof = 0;
	while ((reach_eol(fd_line[fd])) == 0)
	{
		if (fd_line[fd] == NULL)
			fd_line[fd] = ft_calloc(1, 1);
		nb_read = read(fd, buf, BUFFER_SIZE);
		buf[nb_read] = '\0';
		if (nb_read < BUFFER_SIZE)
			eof = 1;
		tmp = ft_strjoin(fd_line[fd], buf);
		free(fd_line[fd]);
		fd_line[fd] = tmp;
		tmp = ft_strchr(fd_line[fd], '\n');
		if (tmp != NULL || eof == 1)
			break ;
	}
	return (read_next_line(&fd_line[fd], line, tmp, eof));
}
