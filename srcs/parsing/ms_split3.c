#include "minishell.h"

void	remove_quotes_dq(t_threestr **str, t_utils **iq, int i, char **line)
{
	(*str)->str1 = ft_substr(line[i], (*iq)->start,
			(*iq)->end - (*iq)->start - 1);
	(*iq)->start = (*iq)->end;
	while (line[i][(*iq)->end] != '"')
		(*iq)->end++;
	if (line[i][(*iq)->end] == '"')
	{
		(*str)->str2 = ft_substr(line[i],
				(*iq)->start, (*iq)->end - (*iq)->start);
		(*iq)->start = (*iq)->end + 1;
		(*str)->str3 = ft_substr(line[i],
				(*iq)->start, ft_strlen(line[i]) - (*iq)->start);
	}
	free(line[i]);
	line[i] = ft_strjoin((*str)->str1, (*str)->str2);
	line[i] = ft_strjoin(line[i], (*str)->str3);
	(*iq)->end = (*iq)->start - 2;
	(*iq)->dq = 0;
}

void	remove_quotes_sq(t_threestr **str, t_utils **iq, int i, char **line)
{
	(*str)->str1 = ft_substr(line[i], (*iq)->start,
			(*iq)->end - (*iq)->start - 1);
	(*iq)->start = (*iq)->end;
	while (line[i][(*iq)->end] != '\'')
		(*iq)->end++;
	if (line[i][(*iq)->end] == '\'')
	{
		(*str)->str2 = ft_substr(line[i],
				(*iq)->start, (*iq)->end - (*iq)->start);
		(*iq)->start = (*iq)->end + 1;
		(*str)->str3 = ft_substr(line[i],
				(*iq)->start, ft_strlen(line[i]) - (*iq)->start);
	}
	free(line[i]);
	line[i] = ft_strjoin((*str)->str1, (*str)->str2);
	line[i] = ft_strjoin(line[i], (*str)->str3);
	(*iq)->end = (*iq)->start - 2;
	(*iq)->sq = 0;
}

void	remove_quotes(char **line)
{
	int			i;
	size_t		j;
	t_threestr	*str;
	t_utils		*iq;

	i = 0;
	str = init_struct_threestr();
	iq = init_utils();
	while (line[i])
	{
		j = 0;
		set_zero_utils(&iq);
		while (line[i][j])
		{
			iq->start = 0;
			change_quotes_state(line[i][j], &iq->dq, &iq->sq, &j);
			iq->end = j;
			if (iq->dq == 1)
				remove_quotes_dq(&str, &iq, i, line);
			else if (iq->sq == 1)
				remove_quotes_sq(&str, &iq, i, line);
			j = iq->end;
		}	
		i++;
	}
}
