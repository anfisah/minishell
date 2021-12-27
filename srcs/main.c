#include "minishell.h"

void	init_sig_term(void)
{
	init_terminal_data();
	init_signal();
}

int	main(int ac, char **av, char **envp)
{
	t_history	*history;
	t_history	*lst;
	t_main		*main;
	char		buf[256];
	t_env		env;

	env = init_envir(envp);
	main = init_main(&env);
	init_sig_term();
	set_history(&history, &lst, ac, av);
	set_main(main);
	ft_printf(1, "%s➜  %sminishell%s ", GREEN, PURPLE, DEFAULT);
	while (read(0, buf, 255))
	{
		if (arrow_del(buf, main, &lst) == 0)
			break ;
		if (buf[0] == 10)
		{
			press_enter(main, &history, envp, &env);
			lst = ft_lstlast_history(history);
		}
		ft_bzero(buf, 4);
	}
	free(main->line);
	ft_printf(1, "exit\n");
}
