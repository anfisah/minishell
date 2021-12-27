#include "minishell.h"

char	**ms_split(char const *s)
{
	t_utils	*sp;
	int		nb_word;
	char	**split;
	int		redir;
	char	*str;

	if (!s)
		return (NULL);
	if (!ms_init(s, &sp, &nb_word, &split))
		return (NULL);
	str = NULL;
	while (s[sp->i])
	{
		redir = 1;
		while (s[sp->i] && sep(s[sp->i]))
			(sp->i)++;
		if (s[sp->i] && !sep(s[sp->i]))
		{
			ms_split_1(s, sp, split, redir);
			ms_split_2(s, sp, split, str);
		}
	}
	split[sp->wi] = 0;
	return (split);
}

void	ms_split_1(char const *s, t_utils *sp, char **split, int redir)
{
	if (!ft_isdigit(s[sp->i]) || (s[sp->i + 1] != '>' && s[sp->i + 1] != '<'))
		redir = 0;
	if (s[sp->i] != '>' && s[sp->i] != '<' && redir == 0)
	{
		split[(sp->wi)++] = ms_malloc_word(&s[sp->i]);
	}
	while (s[sp->i] && (!sep(s[sp->i]) || sp->dq != 0 || sp->sq != 0))
	{
		if ((s[sp->i] == '>' || s[sp->i] == '<')
			&& sp->dq == 0 && sp->sq == 0)
		{
			break ;
		}
		if (ft_isdigit(s[sp->i]) && (s[sp->i + 1] == '>' || s[sp->i + 1] == '<')
			&& sp->dq == 0 && sp->sq == 0 && (redir) == 1)
			break ;
		change_quotes_state(s[sp->i], &sp->dq, &sp->sq, &sp->i);
	}
	if (sp->dq == 1 || sp->sq == 1)
		exit(0);
}

void	ms_split_2(char const *s, t_utils *sp, char **split, char *str)
{
	if (s[sp->i] == '>')
		ms_split_sub1(s, sp, split, 1);
	else if (s[sp->i] == '<')
		ms_split_sub1(s, sp, split, 2);
	else if (ft_isdigit(s[sp->i]) && s[sp->i + 1] == '>')
		str = ms_split_sub2(s, sp, split, 1);
	else if (ft_isdigit(s[sp->i]) && s[sp->i + 1] == '<')
		str = ms_split_sub2(s, sp, split, 2);
}
