#include "minishell.h"

t_main	*set_main(t_main *tmp)
{
	static t_main	*main;

	if (tmp)
		main = tmp;
	return (main);
}

t_main	*get_main(void)
{
	return (set_main(NULL));
}
