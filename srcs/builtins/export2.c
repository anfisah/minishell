#include "minishell.h"

void	parse_arg2(char *str, int *error, char **tmp, int *i)
{
	while (str[*i] && str[*i] != '=')
	{
		if (str[*i] == '+' && str[*i + 1] == '=')
		{
			*error = 2;
			*tmp = ft_substr(str, 0, *i);
			*tmp = ft_strjoin(*tmp, "=");
			break ;
		}
		if (!ft_isdigit(str[*i]) && !ft_isalpha(str[*i]))
			*error = 1;
		(*i)++;
	}
}

void	join_id_val(char *str, char *tmp, int *i, t_env **env)
{
	while (*env)
	{
		if (ft_strcmp(tmp, (*env)->id) == 0)
		{
			(*env)->value = ft_strjoin((*env)->value, &str[*i + 2]);
			free(tmp);
			tmp = NULL;
			break ;
		}
		*env = (*env)->next;
	}
}

void	without_equal(char *str, t_env **env, t_env **lst)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strjoin(str, "=");
	if (check_id(str, tmp, *env) != 0)
	{
		*lst = ft_lstnew("", "");
		(*lst)->id = ft_strdup(str);
		ft_lstadd_back(env, *lst);
	}
}

int	parse_arg(char *str, t_env *lst, t_env **env)
{
	int		i;
	char	*tmp;
	int		error;

	i = 0;
	error = 0;
	tmp = NULL;
	parse_arg2(str, &error, &tmp, &i);
	if (error == 1)
		ft_exit("not a valid identifier", str, 0, 1);
	else if (error == 2 && check_id(tmp, tmp, *env) == 0)
		join_id_val(str, tmp, &i, env);
	else if (error == 2 && check_id(tmp, tmp, *env) == 1)
	{
		tmp = ft_strjoin(tmp, &str[i + 2]);
		add_arg(env, tmp, &i);
	}
	else if (str[i] == '\0')
		without_equal(str, env, &lst);
	else
		add_arg(env, str, &i);
	return (0);
}
