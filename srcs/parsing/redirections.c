#include "minishell.h"

void	ft_redir_digit(t_utils *utils, char ***split,
	t_redirection **chevron, int q)
{
	int				quotes;
	t_redirection	*lst;

	quotes = q;
	lst = ft_lstnew_chevron((*split)[utils->i + 1], quotes,
			ft_atoi((*split)[utils->i]));
	ft_lstadd_back_redirection(chevron, lst);
	utils->i++;
}

void	ft_redir_1(t_utils *utils, char ***split,
	t_redirection **chevron, int q)
{
	int				quotes;
	t_redirection	*lst;

	quotes = q;
	lst = ft_lstnew_chevron((*split)[utils->i + 1], quotes, 1);
	ft_lstadd_back_redirection(chevron, lst);
	utils->i++;
}

void	ft_redir_0(t_utils *utils, char ***split,
	t_redirection **chevron, int q)
{
	int				quotes;
	t_redirection	*lst;

	quotes = q;
	lst = ft_lstnew_chevron((*split)[utils->i + 1], quotes, 0);
	ft_lstadd_back_redirection(chevron, lst);
	utils->i++;
}

void	multi_digit_redir(t_utils *utils, char ***split,
	t_redirection **chevron, char ***new_split)
{
	if (ft_strcmp(&(*split)[utils->i][1], ">") == 0)
		ft_redir_digit(utils, split, chevron, 1);
	else if (ft_strcmp(&(*split)[utils->i][1], ">>") == 0)
		ft_redir_digit(utils, split, chevron, 2);
	else if (ft_strcmp(&(*split)[utils->i][1], "<") == 0)
		ft_redir_digit(utils, split, chevron, 3);
	else if (ft_strcmp(&(*split)[utils->i][1], "<<") == 0)
		ft_redir_digit(utils, split, chevron, 4);
	else
		*new_split = ft_addto_array(*new_split, (*split)[utils->i]);
}

void	ft_redir(t_utils *utils, char ***split, t_redirection **chevron,
	char ***new_split)
{
	if (ft_isdigit((*split)[utils->i][0]))
		multi_digit_redir(utils, split, chevron, new_split);
	else if (ft_strcmp((*split)[utils->i], ">") == 0)
		ft_redir_1(utils, split, chevron, 1);
	else if (ft_strcmp((*split)[utils->i], ">>") == 0)
		ft_redir_1(utils, split, chevron, 2);
	else if (ft_strcmp((*split)[utils->i], "<") == 0)
		ft_redir_0(utils, split, chevron, 3);
	else if (ft_strcmp((*split)[utils->i], "<<") == 0)
		ft_redir_0(utils, split, chevron, 4);
	else
		*new_split = ft_addto_array(*new_split, (*split)[utils->i]);
}
