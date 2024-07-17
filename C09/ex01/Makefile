
TARGET=libft.a
SRCS= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c 
OBJS=${SRCS:.c=.o}

all: ${TARGET}

${TARGET}: ${OBJS}
	ar rcs $@ $^

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${TARGET}

re: fclean all

.PHONY: all clean fclean re

