#include "minishell.h"

t_env	init_envir(char **env)
{
	int		i;
	t_env	*envlist;
	t_env	*lst;
	char	*id;
	char	*value;

	i = 0;
	envlist = NULL;
	while (env[i])
	{
		parse_env(env[i], &id, &value);
		lst = ft_lstnew(id, value);
		ft_lstadd_back(&envlist, lst);
		i++;
	}
	return (*envlist);
}

t_main	*init_main(t_env *env)
{
	t_main	*main;

	main = ft_malloc(sizeof(t_main));
	main->ret_funct = 0;
	main->save_line = NULL;
	main->test = 0;
	main->bottom = 0;
	main->found = 0;
	main->pos = 0;
	main->len = 0;
	main->i = 0;
	main->status = 0;
	main->line = NULL;
	main->dquote = 0;
	main->squote = 0;
	main->is_pipe = 0;
	main->start = 0;
	main->cmd = NULL;
	main->env = *env;
	return (main);
}

t_termcaps	*init_termcaps(void)
{
	t_termcaps	*term;

	term = ft_malloc(sizeof(t_termcaps));
	term->le = NULL;
	term->dc = NULL;
	term->nd = NULL;
	term->im = NULL;
	term->ei = NULL;
	return (term);
}

void	init_signal(void)
{
	signal(SIGINT, &ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	ctrl_d_disable();
}

int	ft_signal(int *status)
{
	signal(SIGINT, SIG_IGN);
	wait(status);
	signal(SIGINT, &ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	return (*status);
}
