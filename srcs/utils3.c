#include "minishell.h"

void	put_termcaps(char *buf)
{
	tputs(tgetstr("im", NULL), 1, putchar_int);
	tputs(tgetstr("ic", NULL), 1, putchar_int);
	ft_printf(1, "%s", buf);
	tputs(tgetstr("ei", NULL), 1, putchar_int);
}

int	ft_isdollar_break(char c)
{
	return (c == ' ' || c == '\0' || c == '\n'
		|| c == '"' || c == '\'' || c == '$');
}

int	ft_isquote(char c)
{
	return (c == '"' || c == '\'');
}

void	change_quotes_state(char c, int *dbquote, int *squote, size_t *size)
{
	if (c == '"' && *squote == 0)
	{
		if (*dbquote == 0)
			*dbquote = 1;
		else
			*dbquote = 0;
	}
	else if (c == '\'' && *dbquote == 0)
	{
		if (*squote == 0)
			*squote = 1;
		else
			*squote = 0;
	}
	(*size)++;
}

void	ft_arrow(char *buf, t_main *main, t_history **lst)
{
	if (buf[2] == 'A')
		press_up(main, lst);
	else if (buf[2] == 'B')
		press_bottom(main, lst);
	else if (buf[2] == 'C')
	{
		if (main->pos < main->len)
		{
			tputs(tgetstr("nd", NULL), 1, putchar_int);
			main->pos++;
		}
	}
	else if (buf[2] == 'D')
	{
		if (main->pos > 0)
		{
			tputs(tgetstr("le", NULL), 1, putchar_int);
			main->pos--;
		}
	}
}
