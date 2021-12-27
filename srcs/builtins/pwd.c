#include "minishell.h"

int	pwd(char *line)
{
	int		i;
	char	s[100];

	i = 0;
	if (ft_strncmp("pwd", line, 3) == 0)
	{
		ft_printf(1, "%s\n", getcwd(s, 100));
		return (0);
	}
	else if (ft_strncmp("pwd ", line, 4) == 0)
	{
		ft_printf(1, "%s\n", getcwd(s, 100));
		return (0);
	}
	else
		return (1);
}
