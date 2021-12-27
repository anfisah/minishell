#include "minishell.h"

void	change_pwd_env(t_env *env, char *id)
{
	t_env	*lst;
	char	*value;
	char	s[100];

	lst = env;
	value = getcwd(s, 100);
	while (lst)
	{
		if (ft_strcmp(lst->id, id) == 0)
			lst->value = ft_strdup(value);
		lst = lst->next;
	}
}

int	home_path(t_env *env)
{
	char	*str;

	while (env)
	{
		if (ft_strncmp(env->id, "HOME=", 5) == 0)
		{
			str = ft_strjoin(env->value, "/");
			if (chdir(env->value) == -1 || chdir(str) == -1)
			{
				ft_exit("No such file or directory", env->value, 0, 1);
				return (1);
			}
			change_pwd_env(env, "PWD=");
			return (0);
		}
		env = env->next;
	}
	ft_exit("HOME not set", "cd", 0, 1);
	return (1);
}

int	cd(char *line, t_env *env)
{
	int	i;

	i = 0;
	change_pwd_env(env, "OLDPWD=");
	if (ft_strncmp("cd ", line, 3) == 0)
	{
		i = skip_space(&line[2]);
		if (chdir(&line[2 + i]) == -1)
			ft_exit("No such file or directory", &line[2 + i], 0, 1);
		change_pwd_env(env, "PWD=");
		return (0);
	}
	else if (ft_strncmp("cd", line, 3) == 0)
		home_path(env);
	return (1);
}
