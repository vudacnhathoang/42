LIBFT := ./Libft
PRINTF := ./ft_printf
FLAGS := -Wall -Wextra -Werror
LIBS := $(LIBFT)/libft.a $(PRINTF)/libftprintf.a
CC := cc
SRC_CLIENT = client.c
SRC_SERVER = server.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
CLIENT = client 
SERVER = server

all: libs client server

libs:
	@echo "Building libft in directory: $(LIBFT)"
	$(MAKE) -C $(LIBFT)
	@echo "Building ft_printf in directory: $(PRINTF)"
	$(MAKE) -C $(PRINTF)

$(CLIENT): $(SRC_CLIENT)
	@$(CC)  $(FLAGS) $(SRC_CLIENT) $(LIBS) -o $(CLIENT)

$(SERVER): $(SRC_SERVER)
	@$(CC)  $(FLAGS) $(SRC_SERVER) $(LIBS) -o $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean

fclean: clean
	@rm -rf $(SERVER) $(CLIENT)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean

re: clean all

.PHONY: all, clean, fclean, re, libs