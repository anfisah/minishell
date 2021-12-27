#include "minishell.h"

int	unset(char *line, t_env *env)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	if (ft_strncmp("unset", split[0], 5) != 0)
		return (1);
	else
		i = 1;
	while (split[i])
	{
		ft_lstremoveif(&env, split[i]);
		i++;
	}
	return (0);
}
