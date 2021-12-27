#include "minishell.h"

void	press_up(t_main *main, t_history **lst)
{
	main->bottom = 1;
	if (*lst && (*lst)->previous && main->test == 1)
	{
		ft_delete_line(main);
		if (*lst && (*lst)->previous && main->test == 1)
		{
			*lst = (*lst)->previous;
			ft_printf(1, "%s", (*lst)->line);
			free(main->line);
			main->line = ft_strdup((*lst)->line);
			main->len = ft_strlen(main->line);
			main->pos = main->len;
		}
	}
	else if (*lst && main->test == 0)
	{
		ft_delete_line(main);
		ft_printf(1, "%s", (*lst)->line);
		main->len = ft_strlen((*lst)->line);
		free(main->line);
		main->line = ft_strdup((*lst)->line);
		main->pos = main->len;
		main->test = 1;
	}	
}

void	press_bottom(t_main *main, t_history **lst)
{
	if (*lst && (*lst)->next)
	{
		ft_delete_line(main);
		if (*lst && (*lst)->next)
		{
			*lst = (*lst)->next;
			ft_printf(1, "%s", (*lst)->line);
			free(main->line);
			main->line = ft_strdup((*lst)->line);
			main->len = ft_strlen(main->line);
			main->pos = main->len;
		}
	}
	else if (*lst && !(*lst)->next && main->bottom != 0)
	{
		bottom_without_next(main);
		main->bottom = 0;
	}
	if (main->bottom == 0)
		main->test = 0;
}

void	press_enter2(t_main *main)
{	
	char	*tmp;

	main->test = 0;
	main->len = 0;
	main->pos = 0;
	main->save_line = NULL;
	ft_printf(1, "\n");
	main->i = 0;
	main->i = skip_space(main->line);
	tmp = ft_strdup(&main->line[main->i]);
	free(main->line);
	main->line = tmp;
}

void	press_enter3(t_main *main, char **envp, t_env *env)
{
	main->pipe = find_cmd_piped(main);
	if (main->pipe)
	{
		main->ret_funct = exec_pipe(envp, main);
		free(main->line);
		main->line = NULL;
	}
	else if (main->line[0] != '\0')
	{
		main->found = ft_builtins(env, main, main->line);
		if (main->found == 0)
			ft_builtins2(env, envp, main, main->line);
		free(main->line);
		main->line = NULL;
	}
	get_back_fd(main);
}

void	press_enter(t_main *main, t_history **history, char **envp, t_env *env)
{
	int		i;
	int		sq;
	int		dq;
	size_t	size;

	i = 0;
	sq = 0;
	dq = 0;
	size = 0;
	press_enter2(main);
	init_history(main, history);
	replace_global_err(main);
	while (main->line[i])
	{
		change_quotes_state(main->line[i], &dq, &sq, &size);
		i++;
	}
	if (sq == 0 && dq == 0)
		press_enter3(main, envp, env);
	else
		ft_exit("missing quote", main->line, 0, 1);
	free(main->line);
	main->line = NULL;
	ft_printf(1, "%s➜  %sminishell%s ", GREEN, PURPLE, DEFAULT);
	main->len = 0;
}
