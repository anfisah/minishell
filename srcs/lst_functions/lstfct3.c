#include "minishell.h"

void	ft_lstadd_back(t_env **alst, t_env *new)
{
	t_env	*last;

	if (!alst || !new)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		last = ft_lstlast(*alst);
		last->next = new;
	}
}

void	ft_lstdelone(t_env *lst)
{
	if (!lst)
		return ;
	if (lst->id)
		free(lst->id);
	if (lst->value)
		free(lst->value);
	free(lst);
}

void	ft_lstremoveif(t_env **begin, char *id)
{
	t_env	*previous;
	t_env	*lst;

	previous = NULL;
	lst = *begin;
	while (lst)
	{
		if (!ft_strncmp(lst->id, id, ft_strlen(id)))
		{
			if (previous)
				previous->next = lst->next;
			else
				*begin = lst->next;
			ft_lstdelone(lst);
			if (previous)
				lst = previous->next;
			else
				lst = *begin;
		}
		else
		{
			previous = lst;
			lst = lst->next;
		}
	}
}

void	ft_2dstrdel(char ***as)
{
	int		i;

	i = 0;
	if (as && *as)
	{
		while ((*as)[i])
			ft_strdel(&(*as)[i++]);
		free(*as);
		*as = NULL;
	}
}

void	ft_strdel(char **ap)
{
	if (*ap == NULL)
		return ;
	free(*ap);
	*ap = NULL;
}
