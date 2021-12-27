#include "minishell.h"

void	exit_2arg(t_main *main)
{
	int	j;

	j = 0;
	if (main->cmd[1][0] == '-')
		j++;
	while (ft_isdigit(main->cmd[1][j]))
		j++;
	if (main->cmd[1][j] == '\0')
	{
		ft_free(main->free_lst);
		ft_printf(1, "exit\n");
		exit(ft_atoi(main->cmd[1]));
	}
	else
	{
		ft_free(main->free_lst);
		ft_printf(1, "exit\n");
		ft_exit("numeric argument required", "exit", 1, 255);
	}
}

void	exit_minishell(t_main *main, char *line)
{
	int	i;

	i = 0;
	while (main->cmd[i])
		i++;
	if (ft_strncmp("exit", line, 5) == 0 && i == 1)
	{
		ft_free(main->free_lst);
		ft_printf(1, "exit\n");
		exit(0);
	}
	else if (i > 2)
	{
		ft_printf(1, "exit\n");
		ft_exit("too many arguments", "exit", 0, 1);
	}
	else if (i == 2)
		exit_2arg(main);
}

int	display_env(char *line, t_env env)
{
	int	i;

	i = 0;
	if (ft_strncmp("env", line, 4) == 0)
		display(&env);
	else if (ft_strncmp("env ", line, 4) == 0)
	{
		i = 4 + skip_space(&line[4]);
		if (line[i] != '\0')
			return (1);
		else
			display(&env);
	}
	else
		return (1);
	return (0);
}

void	inc_shell_lv(t_env **env)
{
	int	value;

	while (*env)
	{
		if (ft_strcmp((*env)->id, "SHLVL=") == 0)
		{
			value = ft_atoi((*env)->value);
			value++;
			(*env)->value = ft_itoa(value);
		}
		*env = (*env)->next;
	}
}

void	replace_global_err(t_main *main)
{
	int		i;
	char	*before;
	char	*after;
	char	*new_str;

	i = 0;
	new_str = NULL;
	while (main->line[i])
	{
		if (main->line[i] == '$' && main->line[i + 1] == '?')
		{
			before = ft_substr(main->line, 0, i);
			after = ft_substr(main->line, i + 2, ft_strlen(main->line) - i + 2);
			new_str = ft_strdup(ft_itoa(main->ret_funct));
			new_str = ft_strjoin(before, new_str);
			new_str = ft_strjoin(new_str, after);
			free(main->line);
			main->line = ft_strdup(new_str);
		}
		i++;
	}
}
