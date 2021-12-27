#include "minishell.h"

t_env	*ft_lstnew(char *id, char *value)
{
	t_env	*list;

	list = ft_malloc(sizeof(t_env));
	if (!list)
		return (NULL);
	list->id = ft_strdup(id);
	list->value = ft_strdup(value);
	list->next = NULL;
	return (list);
}

t_int	*ft_lstnewint(int value)
{
	t_int	*lst;

	lst = ft_malloc(sizeof(t_int));
	lst->val = value;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back_int(t_int **alst, t_int *new)
{
	t_int	*last;

	if (!alst || !new)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		last = ft_lstlast_int(*alst);
		last->next = new;
	}
}

t_int	*ft_lstlast_int(t_int *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_env	*ft_lstlast(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
