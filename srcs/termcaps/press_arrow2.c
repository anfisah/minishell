#include "minishell.h"

void	ft_delete_line(t_main *main)
{
	while (main->pos != main->len)
	{
		if (main->pos < main->len)
		{
			tputs(tgetstr("nd", NULL), 1, putchar_int);
			main->pos++;
		}
		else
		{
			tputs(tgetstr("le", NULL), 1, putchar_int);
			main->pos--;
		}
	}
	while (main->len != 0)
	{
		tputs(tgetstr("le", NULL), 1, putchar_int);
		tputs(tgetstr("dc", NULL), 1, putchar_int);
		main->len--;
	}
}

void	press_delete(t_main *main)
{
	char	*tmp;
	char	*tmp2;

	if (main->pos > 0)
	{
		main->len--;
		main->pos--;
		tputs(tgetstr("le", NULL), 1, putchar_int);
		tputs(tgetstr("dc", NULL), 1, putchar_int);
		if (main->pos == main->len)
		{
			tmp = ft_substr(main->line, 0, ft_strlen(main->line) - 1);
			free(main->line);
			main->line = tmp;
		}
		else
		{
			tmp = ft_substr(main->line, 0, main->pos);
			tmp2 = ft_substr(main->line, main->pos + 1, ft_strlen(main->line));
			free(main->line);
			main->line = ft_strjoin(tmp, tmp2);
		}	
		free(main->save_line);
		main->save_line = ft_strdup(main->line);
	}
}

char	*modify_line(char *buf, t_main *main)
{
	char	*tmp;
	char	*tmp2;

	main->len++;
	main->pos++;
	if (main->pos == main->len)
	{
		ft_printf(1, "%s", buf);
		main->line = ft_strjoin(main->line, buf);
	}
	else if (main->pos < main->len)
	{
		put_termcaps(buf);
		tmp = ft_malloc(sizeof(char) * (main->pos + 1));
		ft_strlcpy(tmp, main->line, main->pos);
		tmp[main->pos - 1] = buf[0];
		tmp[main->pos] = '\0';
		tmp2 = ft_substr(main->line, main->pos - 1, ft_strlen(main->line));
		free(main->line);
		main->line = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
	return (ft_strdup(main->line));
}

void	bottom_without_next(t_main *main)
{
	ft_delete_line(main);
	if (main->save_line)
	{
		ft_printf(1, "%s", main->save_line);
		free(main->line);
		main->line = ft_strdup(main->save_line);
		main->len = ft_strlen(main->line);
		main->pos = main->len;
	}
	else
	{
		ft_printf(1, "");
		free(main->line);
		main->line = NULL;
		main->len = 0;
		main->pos = main->len;
	}
}

int	arrow_del(char *buf, t_main *main, t_history **lst)
{
	if (main->line == NULL)
	{
		main->line = ft_calloc(1, 1);
		main->line[0] = '\0';
	}
	if (buf[0] == 4)
	{
		if (main->len == 0)
			return (0);
	}
	else if (buf[0] == 127 && main->len > 0)
		press_delete(main);
	else if (ft_isprint(buf[0]))
		main->save_line = modify_line(buf, main);
	else if (buf[1] == '[')
		ft_arrow(buf, main, lst);
	return (1);
}
