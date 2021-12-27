#include "minishell.h"

char	*new_str_dollar_replace(char *str, t_env *env, int start, size_t *end)
{
	char	*new_str;
	char	*before;
	char	*after;

	before = ft_substr(str, 0, start);
	after = ft_substr(str, *end, ft_strlen(str) - *end);
	if (env == NULL)
		new_str = ft_strnew(0);
	else
		new_str = ft_strdup(env->value);
	new_str = ft_strjoin(before, new_str);
	free(before);
	if (ft_strlen(new_str) != 0)
		*end = ft_strlen(new_str) - 1;
	else
		*end = 0;
	new_str = ft_strjoin(new_str, after);
	free(after);
	return (new_str);
}

char	*substitute_dollar(char *str, size_t *index, t_env *env)
{
	char	*new_str;
	char	*id;
	int		start;

	*index = *index + 1;
	start = *index;
	while (!ft_isdollar_break(str[*index]))
		(*index)++;
	id = ft_substr(str, start, *index - start);
	id = ft_strjoin(id, "=");
	while (env != NULL)
	{
		if (ft_strcmp(id, env->id) == 0)
		{
			new_str = new_str_dollar_replace(str, env, start - 1, index);
			return (new_str);
		}
		env = env->next;
	}
	new_str = new_str_dollar_replace(str, env, start - 1, index);
	return (new_str);
}

void	replace_dollar2(char **split, size_t *i, size_t *j)
{
	char	*tmp;

	tmp = ft_strdup(&split[*i][*j + 1]);
	free(split[*i]);
	split[*i] = tmp;
	free(tmp);
}

void	replace_dollar(char **split, t_env *env)
{
	size_t	i;
	size_t	j;
	int		dq;
	int		sq;

	i = 0;
	while (split[i])
	{
		j = 0;
		dq = 0;
		sq = 0;
		while (split[i][j])
		{
			if (split[i][j] == '$' && dq == 0 && sq == 0 &&
				ft_isquote(split[i][j + 1]))
				replace_dollar2(split, &i, &j);
			if (split[i][j] == '$' &&
				!ft_isdollar_break(split[i][j + 1]) && sq == 0)
				split[i] = substitute_dollar(split[i], &j, env);
			if (split[i][j])
				change_quotes_state(split[i][j], &dq, &sq, &j);
		}
		i++;
	}
}
