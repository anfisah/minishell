#include "minishell.h"

void	ft_exit(char *msg, char *pb, int ex, int error)
{
	t_main	*main;

	main = get_main();
	ft_printf(2, "minishell: %s: %s\n", pb, msg);
	main->ret_funct = error;
	if (ex == 1)
		exit(error);
}
