CC = cc
CFLAGS = -Wall -Werror -Wextra -ggdb
SRC = ./mandatory/main.c ./mandatory/only_2345.c ./mandatory/parsing2.c ./mandatory/parsing.c ./mandatory/small_stack.c ./mandatory/stack_funcs.c ./mandatory/stack_op1.c ./mandatory/stack_op2.c ./mandatory/stack_op3.c ./mandatory/stack_op4.c
NAME = push_swap
LIBFT = libft/libft.a
OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJECT)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re bonus
