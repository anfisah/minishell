#include "minishell.h"

void	ft_echo_n2(char *line, int *loop, int *i, int *start)
{
	while (line[4 + *i] && sep(line[4 + *i]))
		(*i)++;
	if (line[4 + *i] == '-')
		*loop = 1;
	else
		*loop = 0;
	*start = *i;
}

void	ft_echo_n(char *line, int *start, int *loop, int *option)
{
	int	i;

	i = 0;
	while (line[4 + i])
	{
		while (line[4 + i] && sep(line[4 + i]))
			i++;
		if (line[4 + i] && ((line[4 + i] == '-'
					&& line[4 + i + 1] == 'n') || *loop == 1))
		{
			if (*loop == 0)
				i += 2;
			else
				i++;
			while (line[4 + i] && line[4 + i] == 'n')
				i++;
			if (line[4 + i] && line[4 + i] != ' ' && line[4 + i] != '\0')
				break ;
			*option = 1;
			ft_echo_n2(line, loop, &i, start);
		}
		else
			break ;
		i++;
	}
}

void	ft_echo2(char *line)
{
	int	i;
	int	start;
	int	loop;
	int	option;

	i = skip_space(&line[4]);
	start = i;
	loop = 0;
	option = 0;
	ft_echo_n(line, &start, &loop, &option);
	if (option)
		ft_printf(1, "%s", &line[4 + start]);
	else
		ft_printf(1, "%s\n", &line[4 + 1]);
}

int	ft_echo(t_main *main, char *line)
{
	int	j;

	j = skip_space(&line[4]);
	if (ft_strncmp("$?", &line[j + 4], 2) == 0)
		ft_printf(1, "%d\n", main->ret_funct);
	else if (ft_strncmp("-n", &line[j + 4], 2) == 0)
		ft_echo2(line);
	else if (ft_strncmp("echo ", line, 5) == 0)
		ft_printf(1, "%s\n", &line[4 + 1]);
	else if (ft_strncmp("echo", line, 5) == 0)
		ft_printf(1, "\n");
	return (0);
}
