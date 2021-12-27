#include "minishell.h"

char	*good_path(t_main *main, char **split_path)
{
	int			i;
	char		**split_line;
	char		*good_path;
	char		*addback;
	struct stat	sb;

	i = 0;
	split_line = ft_split(main->line, ' ');
	while (split_path[i])
	{
		addback = ft_strjoin(split_path[i], "/");
		good_path = ft_strjoin(addback, split_line[0]);
		if (stat(good_path, &sb) == -1)
		{
			i++;
			free(addback);
			free(good_path);
		}
		else
			break ;
	}
	return (good_path);
}

char	*get_current_path(t_main *main)
{
	char		*curr_path;
	char		*addback;
	char		**split_line;
	struct stat	sb;

	curr_path = ft_malloc(sizeof(char) * 100);
	split_line = ft_split(main->line, ' ');
	if (getcwd(curr_path, 100) != NULL)
	{
		addback = ft_strjoin(curr_path, "/");
		free(curr_path);
		curr_path = ft_strjoin(addback, split_line[0]);
		free(addback);
	}
	if (stat(curr_path, &sb))
		return (NULL);
	else
		return (curr_path);
}

void	missing_path(t_main *main, t_env *env)
{
	if (!env && !main->pipe)
		ft_exit("No such file or directory", main->cmd[0], 0, 127);
	else if (!env)
		ft_exit("No such file or directory", main->cmd[0], 1, 127);
}

char	*find_path(t_env *env, t_main *main)
{
	int			i;
	char		*path;
	char		**split_path;
	char		*current_path;

	i = 0;
	path = NULL;
	current_path = get_current_path(main);
	if (current_path != NULL)
		return (current_path);
	while (env)
	{
		if (strncmp(env->id, "PATH=", 5) == 0)
		{
			path = ft_strdup(env->value);
			break ;
		}
		env = env->next;
	}
	missing_path(main, env);
	if (path == NULL)
		return (NULL);
	split_path = ft_split(path, ':');
	return (good_path(main, split_path));
}

char	*good_path_cmd(char *cmd, char **split_path)
{
	int			i;
	char		*good_path;
	char		*addback;
	struct stat	sb;

	i = 0;
	while (split_path[i])
	{
		addback = ft_strjoin(split_path[i], "/");
		good_path = ft_strjoin(addback, cmd);
		if (stat(good_path, &sb) == -1)
		{
			i++;
			free (addback);
			free(good_path);
		}
		else
			break ;
	}
	return (good_path);
}
