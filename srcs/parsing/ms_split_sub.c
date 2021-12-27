#include "minishell.h"

void	ms_split_sub1(char const *s, t_utils *sp, char **split, int chevron)
{
	if (chevron == 1)
	{
		if (s[sp->i + 1] == '>')
		{
			split[(sp->wi)++] = ms_malloc_word(">>");
			(sp->i)++;
		}
		else
			split[(sp->wi)++] = ms_malloc_word(">");
		(sp->i)++;
	}
	else if (chevron == 2)
	{
		if (s[sp->i + 1] == '<')
		{
			split[(sp->wi)++] = ms_malloc_word("<<");
			(sp->i)++;
		}
		else
			split[(sp->wi)++] = ms_malloc_word("<");
		(sp->i)++;
	}
}

char	*ms_split_sub2(char const *s, t_utils *sp, char **split, int chevron)
{
	char	*str;

	str = NULL;
	if (chevron == 1)
	{
		(sp->i)++;
		if (s[sp->i + 1] == '>')
			str = ms_split_sub3(s, sp, split, 1);
		else
			str = ms_split_sub3(s, sp, split, 2);
		(sp->i)++;
	}
	else if (chevron == 2)
	{
		(sp->i)++;
		if (s[sp->i + 1] == '<')
			str = ms_split_sub3(s, sp, split, 3);
		else
		{
			str = ft_substr(s, sp->i - 1, 2);
			split[(sp->wi)++] = ms_malloc_word(str);
		}
		(sp->i)++;
	}
	return (str);
}

char	*ms_split_sub3(char const *s, t_utils *sp, char **split, int chevron)
{
	char	*str;

	str = NULL;
	if (chevron == 1)
	{
		str = ft_substr(s, sp->i - 1, 3);
		split[(sp->wi)++] = ms_malloc_word(str);
		(sp->i)++;
	}
	else if (chevron == 2)
	{
		str = ft_substr(s, sp->i - 1, 2);
		split[(sp->wi)++] = ms_malloc_word(str);
	}
	else if (chevron == 3)
	{
		str = ft_substr(s, sp->i - 1, 3);
		split[(sp->wi)++] = ms_malloc_word(str);
		(sp->i)++;
	}
	return (str);
}
