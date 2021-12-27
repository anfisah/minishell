#include "minishell.h"

t_history	*ft_lstnew_history(t_main *main)
{
	t_history	*list;

	list = ft_malloc(sizeof(t_history));
	if (!list)
		return (NULL);
	list->line = ft_strdup(main->line);
	list->next = NULL;
	list->previous = NULL;
	return (list);
}

t_history	*ft_lstnew_history2(char *str)
{
	t_history	*list;

	list = ft_malloc(sizeof(t_history));
	if (!list)
		return (NULL);
	list->line = ft_strdup(str);
	list->next = NULL;
	list->previous = NULL;
	return (list);
}

t_history	*ft_lstlast_history(t_history *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_history(t_history **history, t_history *new)
{
	t_history	*last;

	if (!history || !new)
		return ;
	if (*history == NULL)
		*history = new;
	else
	{
		last = ft_lstlast_history(*history);
		last->next = new;
		new->previous = last;
	}
}

void	init_history(t_main *main, t_history **history)
{
	t_history	*lst;

	if (main->line[0] != '\0')
	{
		lst = ft_lstnew_history(main);
		ft_lstadd_back_history(history, lst);
	}
}
