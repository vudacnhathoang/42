NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_puthexnum.c \
	   ft_putnbr.c \
	   ft_putptr.c \
 	   ft_putstr.c \
	   ft_putunsigned.c \

CC = cc

FLAGS = -Wall -Wextra -Werror 

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
	ar -rc ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
	
.PHONY: all clean fclean re
