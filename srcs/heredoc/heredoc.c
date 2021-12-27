#include "minishell.h"

int	init_heredoc(char *eof)
{
	char	*str;
	int		*pfd;

	ctrl_d_able();
	str = input_heredoc(eof);
	pfd = (int *)ft_malloc(sizeof(int) * 2);
	pipe(pfd);
	if (fork() == 0)
	{
		close(pfd[0]);
		ft_putstr_fd(str, pfd[1]);
		ft_strdel(&str);
		exit(0);
	}
	wait(NULL);
	close(pfd[1]);
	ctrl_d_disable();
	return (pfd[0]);
}

char	*input_heredoc(char *eof)
{
	char	*str;
	char	*cmd;
	int		i;

	i = 0;
	str = ft_strnew(0);
	cmd = ft_strnew(0);
	while (ft_strcmp(cmd, eof) != 0)
	{
		if (i > 0)
		{
			str = ft_strjoinf(str, ft_strjoinf(cmd, "\n", 1), 3);
			cmd = ft_strnew(0);
		}
		ft_printf(1, "> ");
		if (heredoc(&cmd) == 0)
		{
			ft_printf(1, "\n");
			return (ft_strjoinf(str, ft_strjoinf(cmd, "\n", 1), 3));
		}
		i += 1;
	}
	ft_strdel(&cmd);
	return (str);
}

int	heredoc(char **cmd)
{
	int		ret;
	char	*buf;

	buf = ft_strnew(4);
	while (1)
	{
		ret = read(0, buf, 1);
		if (ret <= 0)
			break ;
		if (buf[0] == 10)
			break ;
		if (ft_isprint(buf[0]) == 1)
		{
			buf[ret] = '\0';
			*cmd = ft_strjoinf(*cmd, buf, 1);
		}
	}
	ft_strdel(&buf);
	return (ret);
}

char	*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	str = ft_malloc((sizeof(char) * (size + 1)));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
		str[i++] = '\0';
	return (str);
}

char	*ft_strjoinf(char const *s1, char const *s2, int i)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (i == 1)
		ft_strdel((char **)&s1);
	if (i == 2)
		ft_strdel((char **)&s2);
	if (i == 3)
	{
		ft_strdel((char **)&s1);
		ft_strdel((char **)&s2);
	}
	return (str);
}
