#include "minishell.h"

void	child_pipe2(char **command, char **cmd)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (!*cmd)
			*cmd = ft_strjoin("", command[i]);
		else
		{
			*cmd = ft_strjoin(*cmd, " ");
			*cmd = ft_strjoin(*cmd, command[i]);
		}
		i++;
	}
}

void	child_pipe(char **envp, t_main *main, char **command, t_int *fd_in)
{
	char			*cmd;
	t_redirection	*chevron;

	cmd = NULL;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	dup2(fd_in->val, 0);
	if (main->pipe->next)
		dup2(main->p[1], 1);
	close(main->p[0]);
	chevron = parse_redirection(&command);
	if (chevron)
		if (open_file(chevron, main) == -1)
			return ;
	child_pipe2(command, &cmd);
	main->found = ft_builtins(&main->env, main, cmd);
	if (main->found == 0)
	{
		main->path = find_path(&main->env, main);
		check_exec(command, envp, &main->status, main->path);
		signal(SIGINT, &ctrl_c);
	}
	else
		exit(EXIT_FAILURE);
}

void	parent_pipe(t_main *main, t_int **fd_in, t_int **begin_fdin)
{
	signal(SIGINT, &init_ctrl_c);
	signal(SIGQUIT, &init_back_slash);
	wait(&main->status);
	if (WIFEXITED(main->status))
		main->ret_funct = WEXITSTATUS(main->status);
	signal(SIGINT, &ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	close(main->p[1]);
	*fd_in = ft_lstnewint(main->p[0]);
	ft_lstadd_back_int(begin_fdin, *fd_in);
}

void	exec_pipe2(t_main *main, char **envp, t_int **begin_fdin)
{
	t_int		*fd_in;
	char		**command;

	fd_in = ft_lstnewint(0);
	ft_lstadd_back_int(begin_fdin, fd_in);
	while (main->pipe)
	{
		command = ms_split(main->pipe->line);
		create_pipe(main, command, envp);
		if (main->pid == -1)
			ft_exit("fork failed", "fork", 1, 1);
		else if (main->pid == 0)
			child_pipe(envp, main, command, fd_in);
		else
		{
			parent_pipe(main, &fd_in, begin_fdin);
			main->pipe = main->pipe->next;
		}
	}
}

int	exec_pipe(char **envp, t_main *main)
{
	t_int		*begin_fdin;

	main->p = NULL;
	main->p = ft_malloc(sizeof(int) * 2);
	begin_fdin = NULL;
	ctrl_d_able();
	exec_pipe2(main, envp, &begin_fdin);
	close_fd(begin_fdin);
	ctrl_d_disable();
	return (main->ret_funct);
}
