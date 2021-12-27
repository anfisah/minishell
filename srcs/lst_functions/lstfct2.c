#include "minishell.h"

void	swap_lst_env(t_env **lst1, t_env **lst2, t_env **lst3)
{
	t_env	*tmp;

	tmp = *lst1;
	*lst1 = *lst2;
	*lst2 = *lst3;
	*lst3 = tmp;
}

int	reset_var_lstsort(t_env **begin, t_env **lst, t_env **prev, t_env **next)
{
	*lst = *begin;
	*prev = NULL;
	*next = (*lst)->next;
	return (0);
}

void	ft_lstsort(t_env **begin)
{
	t_env	*lst;
	t_env	*previous;
	t_env	*next;
	int		trie;

	trie = reset_var_lstsort(begin, &lst, &previous, &next);
	while (lst->next || trie == 1)
	{
		if (trie == 1)
			trie = reset_var_lstsort(begin, &lst, &previous, &next);
		if (ft_strcmp(lst->id, lst->next->id) > 0)
		{
			if (previous)
				swap_lst_env(&previous->next, &lst->next, &next->next);
			else
				swap_lst_env(begin, &lst->next, &next->next);
			trie = 1;
		}
		else
		{
			previous = lst;
			lst = lst->next;
			next = next->next;
		}
	}
}	

t_env	*list_copy(t_env *env)
{
	t_env	*export;
	t_env	*lst;

	export = NULL;
	while (env)
	{
		lst = ft_lstnew(env->id, env->value);
		ft_lstadd_back(&export, lst);
		env = env->next;
	}
	return (export);
}
