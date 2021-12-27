#include "minishell.h"

void	set_history(t_history **history, t_history **lst, int ac, char **av)
{
	(void)ac;
	(void)av;
	*lst = NULL;
	*history = NULL;
}

int	ms_init(char const *s, t_utils	**split_s, int *nb_word, char ***split)
{
	*split_s = ft_malloc(sizeof(t_utils));
	(*split_s)->i = 0;
	(*split_s)->wi = 0;
	(*split_s)->sq = 0;
	(*split_s)->dq = 0;
	*nb_word = ms_count_word(s);
	if (*nb_word == -1)
		return (0);
	*split = ft_malloc(sizeof(char *) * (*nb_word + 2));
	if (!(*split))
		return (0);
	return (1);
}

t_utils	*init_utils(void)
{
	t_utils	*utils;

	utils = ft_malloc(sizeof(t_utils));
	utils->i = 0;
	utils->wi = 0;
	utils->sq = 0;
	utils->dq = 0;
	utils->start = 0;
	utils->end = 0;
	return (utils);
}

t_threestr	*init_struct_threestr(void)
{
	t_threestr	*str;

	str = ft_malloc(sizeof(t_threestr));
	str->str1 = NULL;
	str->str2 = NULL;
	str->str3 = NULL;
	return (str);
}

void	set_zero_utils(t_utils **utils)
{
	(*utils)->i = 0;
	(*utils)->wi = 0;
	(*utils)->sq = 0;
	(*utils)->dq = 0;
	(*utils)->start = 0;
	(*utils)->end = 0;
}
