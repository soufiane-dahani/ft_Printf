SRCS = ft_printf.c ft_printf_utils.c 

OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCSB:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
all: ${NAME}

#bonus: ${OBJS} ${OBJSB}
	#${LIBC} ${NAME} ${OBJSB}
clean:
	${RM} ${OBJS} ${OBJSB}

fclean: clean
	${RM} ${NAME} 

re: fclean all

.PHONY: all bonus clean fclean re
