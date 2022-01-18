NAME = libft.a

SRCS = ft_memcpy.c ft_memchr.c ft_memset.c ft_bzero.c \
		ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strjoin.c \
		ft_atoi.c ft_isdigit.c ft_strncmp.c \
		ft_calloc.c ft_realloc.c ft_strdup.c \
		ft_substr.c	ft_split.c \
		get_next_line.c ft_atoi_base.c

 
OBJS = $(SRCS:.c=.o)

INCLUDE = ./

CC = gcc

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I${INCLUDE}

all : ${NAME}
dbg : ${NAME}
dbg : CFLAGS += -g -fsanitize=address

$(NAME) :	${OBJS}
	ar cr ${NAME} $?

%.o	: 	%.c
	${CC} ${CFLAGS} -o $@ -c $<

clean:
	rm -f ${OBJS}

fclean: clean
	echo ${SRCS}
	rm -f ${NAME}

re	: fclean all

.PHONY: all clean fclean re
