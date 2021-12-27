#include "minishell.h"

char	*parse_line(char *line, t_env *env, t_main *main)
{
	char			**command;
	int				i;
	t_redirection	*chevron;

	i = 0;
	command = ms_split(line);
	if (command == NULL)
	{
		ft_exit("missing quote", line, 0, 1);
		return (NULL);
	}
	replace_dollar(command, env);
	remove_quotes(command);
	chevron = parse_redirection(&command);
	main->cmd = command;
	if (!chevron && !command)
		return (NULL);
	if (chevron)
	{
		if (open_file(chevron, main) == -1)
			return (NULL);
	}
	i = 0;
	line = NULL;
	return (parse_line2(command, line, &i));
}

char	*parse_line2(char **command, char *line, int *i)
{
	if (command != NULL)
	{
		while (command[*i])
		{
			if (!line)
				line = ft_strjoin("", command[*i]);
			else
			{
				line = ft_strjoin(line, " ");
				line = ft_strjoin(line, command[*i]);
			}
			(*i)++;
		}
	}
	return (line);
}

int	ft_builtins(t_env *env, t_main *main, char *line)
{
	char	*line_ex;

	line_ex = line;
	line = parse_line(line, env, main);
	if (line == NULL)
		return (-1);
	main->line = line;
	if (ft_strncmp("pwd", line, 3) == 0)
		main->ret_funct = pwd(line);
	else if (ft_strncmp("cd", line, 2) == 0)
		cd(line, env);
	else if (ft_strncmp("exit", line, 4) == 0)
		exit_minishell(main, line);
	else if (ft_strncmp("env", line, 3) == 0)
		main->ret_funct = display_env(line, *env);
	else if (ft_strncmp("echo", line, 4) == 0)
		main->ret_funct = ft_echo(main, line);
	else if (ft_strncmp("unset", line, 5) == 0)
		main->ret_funct = unset(line, env);
	else if (ft_strncmp("export", line, 6) == 0)
		main->ret_funct = ft_export(line_ex, &env);
	else
		return (0);
	return (1);
}

void	ft_builtins2(t_env *env, char **envp, t_main *main, char *line)
{
	char	*path;

	ctrl_d_able();
	path = find_path(env, main);
	if (path)
		main->ret_funct = ft_execve(envp, path, line);
	ctrl_d_disable();
}
