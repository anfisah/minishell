#include "minishell.h"

void	ctrl_c(int sig)
{
	t_main	*main;

	(void)sig;
	main = get_main();
	free(main->line);
	main->line = NULL;
	main->pos = 0;
	main->len = 0;
	main->ret_funct = 1;
	write(1, "\n", 1);
	ft_printf(1, "%s➜  %sminishell%s ", GREEN, PURPLE, DEFAULT);
}

void	init_ctrl_c(int sig)
{
	(void)sig;
	write(1, "\n", 1);
}

void	init_back_slash(int sig)
{
	(void)sig;
	write(1, "Quit: 3\n", 8);
}

void	ctrl_d_disable(void)
{
	struct termios	t;

	tcgetattr(0, &t);
	t.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &t);
}

void	ctrl_d_able(void)
{
	struct termios	t;

	tcgetattr(0, &t);
	t.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, TCSANOW, &t);
}
