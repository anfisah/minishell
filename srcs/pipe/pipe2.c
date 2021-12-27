#include "minishell.h"

int	init_pipe(int **pfd, int *pid)
{
	if (pipe(*pfd) == -1)
	{
		ft_printf(1, "Pipe failed\n");
		return (1);
	}
	*pid = fork();
	if (*pid < 0)
	{
		ft_printf(1, "Fork failed\n");
		return (2);
	}
	return (0);
}

void	create_pipe(t_main *main, char **command, char **envp)
{
	replace_dollar(command, &main->env);
	remove_quotes(command);
	main->path = find_path_cmd(envp, command[0]);
	pipe(main->p);
	main->pid = fork();
}

void	cmd_pipe2(t_main *main, size_t *i, t_history **begin,
	t_history **current)
{
	char		*str;
	char		*tmp;

	str = ft_strtrim(main->line, " ");
	while (main->line[*i])
	{
		change_quotes_state(main->line[*i], &main->dquote, &main->squote, i);
		(*i)--;
		if (main->line[*i] == '|' && main->dquote == 0 && main->squote == 0)
		{
			main->is_pipe = 1;
			tmp = ft_substr(main->line, main->start, *i - main->start);
			free(str);
			str = ft_strtrim(tmp, " ");
			free(tmp);
			*current = ft_lstnew_history2(str);
			ft_lstadd_back_history(begin, *current);
			main->start = *i + 1;
		}
		(*i)++;
	}
}

t_history	*find_cmd_piped(t_main *main)
{
	size_t		i;
	char		*str;
	char		*tmp;
	t_history	*begin;
	t_history	*current;

	i = 0;
	main->start = 0;
	main->is_pipe = 0;
	begin = NULL;
	current = NULL;
	cmd_pipe2(main, &i, &begin, &current);
	if (main->is_pipe == 1)
	{
		tmp = ft_substr(main->line, main->start, i - main->start);
		str = ft_strtrim(tmp, " ");
		free(tmp);
		current = ft_lstnew_history2(str);
		ft_lstadd_back_history(&begin, current);
	}
	return (begin);
}
