NAME := push_swap
LIBFT := ./Libft
PRINTF := ./ft_printf
SRCS := push_swap.c input_handle.c algos.c algos_utils.c utils.c ops.c ops2.c
FLAGS := -Wall -Wextra -Werror
LIBS := $(LIBFT)/libft.a $(PRINTF)/libftprintf.a
CC := cc
OBJS := ${SRCS:.c=.o}

all: libs $(NAME)

libs:
	@echo "Building libft in directory: $(LIBFT)"
	$(MAKE) -C $(LIBFT)
	@echo "Building ft_printf in directory: $(PRINTF)"
	$(MAKE) -C $(PRINTF)

$(NAME): $(OBJS)
	@$(CC)  $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< 


clean:
	@rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean

fclean: clean
	@rm -rf $(NAME)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean

re: clean all

.PHONY: all, clean, fclean, re, libs