#include "minishell.h"

int	skip_space(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] == ' ')
		i++;
	return (i);
}

void	display(t_env *env)
{
	while (env != NULL)
	{
		if (find_char(env->id, '=') >= 0)
			ft_printf(1, "%s%s\n", env->id, env->value);
		env = env->next;
	}
}

void	display_export(t_env *env)
{
	ft_lstsort(&env);
	while (env != NULL)
	{
		if (find_char(env->id, '=') >= 0)
			ft_printf(1, "declare -x %s\"%s\"\n", env->id, env->value);
		else
			ft_printf(1, "declare -x %s\n", env->id);
		env = env->next;
	}
}

int	find_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	putchar_int(int ch)
{
	char	c;

	c = (char)ch;
	return (write(1, &c, 1));
}
