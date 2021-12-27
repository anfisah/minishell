#include "minishell.h"

void	count_word2(char const *s, size_t *count, size_t *index,
	char redir)
{
	(*count)++;
	if (s[*index + 1] == redir)
		(*index)++;
	(*index)++;
}

void	count_word_digit(char const *s, size_t *count, size_t *index,
	char redir)
{
	(*count)++;
	(*index)++;
	if (s[*index + 1] == redir)
		(*index)++;
	(*index)++;
}

void	ft_count_word(char const *s, size_t *count, size_t *index)
{
	if (s[*index] == '>')
		count_word2(s, count, index, '>');
	else if (s[*index] == '<')
		count_word2(s, count, index, '<');
	else if (ft_isdigit(s[*index]) && s[*index + 1] == '>')
		count_word_digit(s, count, index, '>');
	else if (ft_isdigit(s[*index]) && s[*index + 1] == '<')
		count_word_digit(s, count, index, '<');
}

int	ms_count_word2(char const *s, size_t *i, int *redir, size_t *count)
{
	int		dq;
	int		sq;	

	dq = 0;
	sq = 0;
	if (s[*i] && !sep(s[*i]))
	{
		if (!ft_isdigit(s[*i]) || (s[*i + 1] != '>' && s[*i + 1] != '<'))
			*redir = 0;
		if (s[*i] != '>' && s[*i] != '<' && *redir == 0)
			(*count)++;
		while (s[*i] && ((s[*i] && !sep(s[*i])) || (dq != 0 || sq != 0)))
		{
			if ((s[*i] == '>' || s[*i] == '<') && dq == 0 && sq == 0)
				break ;
			if (ft_isdigit(s[*i]) && (s[*i + 1] == '>' || s[*i + 1] == '<')
				&& dq == 0 && sq == 0 && *redir == 1)
				break ;
			change_quotes_state(s[*i], &dq, &sq, i);
		}
		ft_count_word(s, count, i);
		if (dq != 0 || sq != 0)
			return (-1);
	}
	return (0);
}

int	ms_count_word(char const *s)
{
	size_t	i;
	size_t	count;
	int		redir;

	i = 0;
	count = 0;
	while (s[i])
	{
		redir = 1;
		while (s[i] && sep(s[i]))
			i++;
		if (ms_count_word2(s, &i, &redir, &count) == -1)
			return (-1);
	}
	return (count);
}
