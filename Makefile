SRC_FILES = main.c push_swap.c greedy_logic.c init_stack_a.c utils.c stack_operations.c stack_search.c
OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) -L./libft -lft

clean:
	@make clean -C ./libft
	rm -f $(OBJ_FILES)

fclean: clean
	@make fclean -C ./libft
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:
	all clean fclean re
