CC = cc
CFLAGS = -Wall -Werror -Wextra -ggdb
SRC = ./mandatory/main.c ./mandatory/only_2345.c ./mandatory/parsing2.c ./mandatory/parsing.c ./mandatory/small_stack.c ./mandatory/stack_funcs.c ./mandatory/stack_op1.c ./mandatory/stack_op2.c ./mandatory/stack_op3.c ./mandatory/stack_op4.c ./mandatory/stack_funcs2.c ./mandatory/stack_algo0.c ./mandatory/stack_algo1.c ./mandatory/stack_algo2.c
SRC_BONUS = ./bonus/main_bonus.c ./bonus/only_2345_bonus.c ./bonus/parsing2_bonus.c ./bonus/parsing_bonus.c ./bonus/small_stack_bonus.c ./bonus/stack_algo0_bonus.c ./bonus/stack_algo1_bonus.c ./bonus/stack_algo2_bonus.c ./bonus/stack_funcs2_bonus.c ./bonus/stack_funcs_bonus.c ./bonus/stack_op1_bonus.c ./bonus/stack_op2_bonus.c ./bonus/stack_op3_bonus.c ./bonus/stack_op4_bonus.c ./bonus/parsing3_bonus.c ./bonus/exec_funcs_bonus.c
NAME = push_swap
NAME_BONUS = checker
LIBFT = libft/libft.a
OBJECT = $(SRC:.c=.o)
OBJECT_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECT) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJECT_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECT_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	rm -f $(OBJECT)
	rm -f $(OBJECT_BONUS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re bonus
