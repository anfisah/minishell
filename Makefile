NAME		=	minishell

SRCS		=	srcs/builtins/builtins.c \
				srcs/builtins/cd.c \
				srcs/builtins/commands.c \
				srcs/builtins/echo.c \
				srcs/builtins/export.c \
				srcs/builtins/export2.c \
				srcs/builtins/pwd.c \
				srcs/builtins/unset.c \
				srcs/builtins/open_file.c \
				srcs/heredoc/heredoc.c \
				srcs/initialisation/initialisation.c \
				srcs/initialisation/initialisation2.c \
				srcs/lst_functions/lstfct.c \
				srcs/lst_functions/lstfct2.c \
				srcs/lst_functions/lstfct3.c \
				srcs/lst_functions/lstfct4.c \
				srcs/parsing/dollar.c \
				srcs/parsing/ms_count_word.c \
				srcs/parsing/ms_split_sub.c \
				srcs/parsing/ms_split.c \
				srcs/parsing/ms_split2.c \
				srcs/parsing/ms_split3.c \
				srcs/parsing/parsing.c \
				srcs/parsing/redirections.c \
				srcs/pipe/pipe.c \
				srcs/pipe/pipe2.c \
				srcs/termcaps/history.c \
				srcs/termcaps/press_arrow.c \
				srcs/termcaps/press_arrow2.c \
				srcs/ctrl.c \
				srcs/exec.c \
				srcs/path.c \
				srcs/exit.c \
				srcs/main.c \
				srcs/static_struct.c \
				srcs/utils.c \
				srcs/utils2.c \
				srcs/utils3.c 

OBJS		=	${SRCS:.c=.o}

INCLUDES	=	includes

HEADER		=	minishell.h

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror #-g3 -fsanitize=address

RM			=	rm -f

%.o:		%.c ${INCLUDES}/${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

all:		buildlibft buildprintf ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} libft/libft.a ft_printf/libftprintf.a -ltermcap -lreadline -o ${NAME} ${OBJS}

buildlibft:
			make -C libft/

buildprintf:
			make -C ft_printf/

clean:
			${RM} ${OBJS}
			make clean -C libft/
			make clean -C ft_printf/

fclean:		clean
			${RM} ${NAME} libft/libft.a ft_printf/libftprintf.a

re:			fclean all

.PHONY:		all clean fclean re .c.o
