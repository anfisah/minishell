#include "minishell.h"

void	open_fd(t_redirection *chevron, int *fd)
{
	if (chevron->quotes == 1)
		*fd = open(chevron->line, O_CREAT | O_TRUNC | O_RDWR, 0777);
	else if (chevron->quotes == 2)
		*fd = open(chevron->line, O_CREAT | O_APPEND | O_RDWR, 0777);
	else if (chevron->quotes == 3)
		*fd = open(chevron->line, O_RDONLY, 0777);
	else if (chevron->quotes == 4)
		*fd = init_heredoc(chevron->line);
}

int	fd_error(t_redirection *chevron, t_main *main, t_int *beginfd, int fd)
{
	if (fd == -1 && !main->pipe)
	{
		ft_exit("No such file or directory", chevron->line, 0, 1);
		close_fd(beginfd);
		return (-1);
	}
	else if (fd == -1)
	{
		close_fd(beginfd);
		ft_exit("No such file or directory", chevron->line, 1, 1);
	}
	return (0);
}

int	open_file(t_redirection *chevron, t_main *main)
{
	int		fd;
	t_int	*lst;
	t_int	*beginfd;

	beginfd = NULL;
	main->backfd0 = dup(0);
	main->backfd1 = dup(1);
	main->backfd2 = dup(2);
	while (chevron)
	{
		open_fd(chevron, &fd);
		lst = ft_lstnewint(fd);
		ft_lstadd_back_int(&beginfd, lst);
		if (fd_error(chevron, main, beginfd, fd) == -1)
			return (-1);
		create_copy_fd(chevron->fd, fd);
		chevron = chevron->next;
	}
	close_fd(beginfd);
	return (0);
}

void	create_copy_fd(int chevron_fd, int fd)
{
	if (chevron_fd == 2)
		dup2(fd, 2);
	if (chevron_fd == 1)
		dup2(fd, 1);
	if (chevron_fd == 0)
		dup2(fd, 0);
}

void	get_back_fd(t_main *main)
{
	dup2(main->backfd0, 0);
	dup2(main->backfd1, 1);
	dup2(main->backfd2, 2);
}
