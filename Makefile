SRCS = ft_printf_handle_1.c \
		ft_printf_handle_2.c \
		ft_printf_utils_2.c \
		ft_printf_utils.c \
		ft_printf.c

OBJS = 	${SRCS:.c=.o}

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	ar -rcs $@ $^

all:		${NAME}

bonus:		${OBJS_BONUS}
	ar -rcs ${NAME} ${OBJS_BONUS}

clean:
	rm -f ${OBJS}

fclean:
	rm -f ${OBJS} ${OBJS_BONUS}
	rm -f ${NAME}

re:			fclean all

.PHONY: all clean re fclean