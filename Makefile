# Variables
SRCS_C = client.c
SRCS_S = server.c

OBJS_C = ${SRCS_C:.c=.o}
OBJS_S = ${SRCS_S:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

all: server client

server: ${OBJS_S} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS_S} -o server -Llibft -lft

client: ${OBJS_C} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS_C} -o client -Llibft -lft

${LIBFT}:
	make -C libft

clean:
	rm -f ${OBJS_C} ${OBJS_S}
	make -C libft clean

fclean: clean
	rm -f client server libft/libft.a

re: fclean all

.PHONY: all clean fclean re
