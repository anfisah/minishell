#include "minishell.h"

t_redirection	*ft_lstnew_chevron(char *file, int quotes, int fd)
{
	t_redirection	*list;

	list = ft_malloc(sizeof(t_redirection));
	if (!list)
		return (NULL);
	list->line = ft_strdup(file);
	list->quotes = quotes;
	list->fd = fd;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back_redirection(t_redirection **alst, t_redirection *new)
{
	t_redirection	*last;

	if (!alst || !new)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		last = ft_lstlast_redirection(*alst);
		last->next = new;
	}
}

t_redirection	*ft_lstlast_redirection(t_redirection *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
