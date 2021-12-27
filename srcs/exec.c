#include "minishell.h"

void	check_exec(char **command, char **envp, int *status, char *path)
{
	struct stat	sb;

	stat(command[0], &sb);
	if (stat(command[0], &sb) == -1 && stat(path, &sb) == -1)
	{
		if (find_char(command[0], '/') != -1)
			ft_exit("no such file or directory", command[0], 1, 127);
		else
			ft_exit("command not found", command[0], 1, 127);
	}
	else if (sb.st_mode & S_IFDIR)
		ft_exit("is a directory", command[0], 1, 126);
	else if (stat(command[0], &sb) == 0)
		execve(command[0], command, envp);
	else
		*status = execve(path, command, envp);
}

int	ft_execve(char **envp, char *path, char *line)
{
	pid_t		pid;
	int			status;
	char		**command;
	t_main		*main;

	main = get_main();
	status = 0;
	pid = fork();
	command = ft_split(line, ' ');
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		check_exec(command, envp, &status, path);
	}	
	if (pid > 0)
	{
		ft_signal(&status);
		if (WIFEXITED(status))
			main->ret_funct = WEXITSTATUS(status);
	}
	return (main->ret_funct);
}
