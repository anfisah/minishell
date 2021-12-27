NAME		=	libftprintf.a

SRCS		=	ft_init_struct.c \
				ft_printf_conversion.c \
				ft_printf_conversion2.c \
				ft_printf_parse_settings.c \
				ft_printf_parse.c \
				ft_printf_utils_p.c \
				ft_printf_utils.c \
				ft_printf_utils2.c \
				ft_printf_utils3.c \
				ft_printf_utils4.c \
				ft_printf_utils5.c \
				ft_printf.c 

OBJS		=	${SRCS:.c=.o}

INCLUDES	=	.

HEADER		=	ft_printf.h

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

LIBCC		=	ar -rcs

RM			=	rm -f

%.o:		%.c ${INCLUDES}/${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

${NAME}:	${OBJS}
			${LIBCC} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

test:		${NAME}
			clear
			${CC} main.c ${NAME} && ./a.out


.PHONY:		all clean fclean re .c.o