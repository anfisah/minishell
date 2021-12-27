#include "minishell.h"

char	*ms_malloc_word(char const *s)
{
	char	*word;
	int		qstate;
	int		sqstate;
	size_t	size;

	size = 0;
	qstate = 0;
	sqstate = 0;
	if (s[0] == '>' || s[0] == '<')
	{
		word = ft_strdup(s);
		return (word);
	}
	else if (ft_isdigit(s[0]) && (s[1] == '>' || s[1] == '<'))
	{
		word = ft_strdup(s);
		return (word);
	}
	word = ms_malloc_word_sub(s, &qstate, &sqstate, &size);
	return (word);
}

char	*ms_malloc_word_sub(char const *s, int *qst, int *sqst, size_t *size)
{
	char	*word;

	word = NULL;
	while (s[*size] && ((s[*size] && !sep(s[*size]))
			|| (*qst != 0 || *sqst != 0)))
	{
		if ((s[*size] == '>' || s[*size] == '<') && *qst == 0 && *sqst == 0)
			break ;
		if (ft_isdigit(s[0]) && (s[1] == '>' || s[1] == '<')
			&& *qst == 0 && *sqst == 0)
			break ;
		change_quotes_state(s[*size], qst, sqst, &(*size));
	}
	word = ft_malloc(sizeof(char) * (*size + 1));
	if (!word)
		return (NULL);
	ft_memcpy(word, s, *size);
	word[*size] = '\0';
	return (word);
}
