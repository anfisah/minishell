#include "minishell.h"

void	only_id(t_env **lst, char *str, int *i, t_env **env)
{
	*lst = ft_lstnew("", "");
	(*lst)->id = ft_substr(str, 0, *i + 1);
	(*lst)->value = ft_substr(str, *i + 1, ft_strlen(str) - *i - 1);
	ft_lstadd_back(env, *lst);
}

void	add_arg(t_env **env, char *str, int *i)
{
	char	*tmp;
	char	*tmp2;
	t_env	*lst;

	tmp = ft_substr(str, 0, *i + 1);
	tmp2 = ft_substr(str, 0, *i);
	lst = *env;
	if (check_id(str, tmp, *env) != 0 && check_id(str, tmp2, *env) != 0)
		only_id(&lst, str, i, env);
	else
	{
		while (lst)
		{
			if (ft_strcmp(tmp, lst->id) == 0 || ft_strcmp(tmp2, lst->id) == 0)
			{
				if (find_char(lst->id, '=') == -1)
					lst->id = ft_strjoin(lst->id, "=");
				lst->value = ft_substr(str, *i + 1, ft_strlen(str) - *i - 1);
			}
			lst = lst->next;
		}
	}
}

int	ft_export2(t_env **env, char **split, int *i)
{
	t_env	*lst;

	lst = NULL;
	while (split[++(*i)])
	{
		if (ft_isalpha(split[*i][0]))
		{
			parse_arg(split[*i], lst, env);
			ft_lstadd_back(env, lst);
		}
		else
			ft_exit("not a valid identifier", split[*i], 0, 1);
	}
	return (0);
}

int	ft_export(char *line, t_env **env)
{
	int		i;
	char	**split;
	t_env	*envcpy;

	i = 0;
	split = ms_split(line);
	replace_dollar(split, *env);
	remove_quotes(split);
	if (ft_strncmp("export", split[0], 7) != 0)
		return (1);
	else
	{
		ft_export2(env, split, &i);
		if (i == 1)
		{
			envcpy = list_copy(*env);
			display_export(envcpy);
		}
	}
	return (0);
}
