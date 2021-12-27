#include "minishell.h"

int	check_id(char *str, char *tmp, t_env *env)
{
	t_env	*lst;

	lst = env;
	while (lst)
	{
		if (ft_strcmp(str, lst->id) == 0 || ft_strcmp(tmp, lst->id) == 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

char	*find_path_cmd(char **envp, char *cmd)
{
	int			i;
	char		*path;
	char		**split_path;

	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
			path = ft_strdup(envp[i]);
		i++;
	}
	split_path = ft_split(&path[5], ':');
	return (good_path_cmd(cmd, split_path));
}

void	init_terminal_data(void)
{
	char	*termtype;
	int		success;

	termtype = getenv("TERM");
	success = tgetent(NULL, termtype);
}

int	sep(char sep)
{
	return (' ' == sep);
}

void	close_fd(t_int *begin_fdin)
{
	while (begin_fdin)
	{
		if (begin_fdin->val != 0)
			close(begin_fdin->val);
		begin_fdin = begin_fdin->next;
	}
}
