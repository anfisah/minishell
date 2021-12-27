#include "minishell.h"

void	parse_env(char *str, char **id, char **value)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str);
	*id = NULL;
	*value = NULL;
	while (str[i] != '=')
		i++;
	*id = ft_malloc(sizeof(char) * (i + 2));
	if (!id)
		exit(EXIT_SUCCESS);
	*value = ft_malloc(sizeof(char) * (size - i));
	if (!value)
		exit(EXIT_SUCCESS);
	ft_strlcpy(*id, str, i + 2);
	ft_strlcpy(*value, &str[i + 1], size - i);
}

char	**ft_new_array(char **new_array, char *line)
{
	new_array = ft_malloc(sizeof(char *) * 2);
	if (!new_array)
		return (NULL);
	new_array[0] = ft_strdup(line);
	new_array[1] = 0;
	return (new_array);
}

char	**ft_addto_array(char **array, char *line)
{
	int		i;
	char	**new_array;

	new_array = NULL;
	if (!line)
		return (NULL);
	if (!array)
		return (ft_new_array(new_array, line));
	new_array = NULL;
	i = 0;
	while (array[i])
		i++;
	new_array = ft_malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		i++;
	}
	new_array[i] = ft_strdup(line);
	new_array[i + 1] = 0;
	return (new_array);
}

t_redirection	*parse_redirection(char ***split)
{
	t_redirection	*chevron;
	t_utils			*utils;
	char			**new_split;

	utils = init_utils();
	chevron = NULL;
	new_split = NULL;
	while ((*split)[utils->i])
	{
		ft_redir(utils, split, &chevron, &new_split);
		if ((*split)[utils->i] == NULL || (*split)[utils->i][0] == '>'
			|| (*split)[utils->i][0] == '<')
		{
			ft_exit("error near unexpected token `newline'", "syntax", 0, 258);
			ft_2dstrdel(split);
			return (NULL);
		}
		else
			utils->i++;
	}
	ft_2dstrdel(split);
	if (new_split)
		*split = new_split;
	return (chevron);
}
