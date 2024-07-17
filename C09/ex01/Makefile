
RUNFLAGS = -Wall -Wextra -Werror -Iincludes
TARGET=libft.a
SRCS=${wildcard ./srcs/*.c}
OBJS=${SRCS:./srcs/%.c=./srcs/%.c}
CC=cc

all: ${TARGET}


${TARGET}: ${OBJS}
	ar rcs $@ $^

${OBJS}: ${SRCS}
	${CC} ${RUNFLAGS} -c $^ -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f ${TARGET}
re: fclean all

.PHONY: all clean fclean re

