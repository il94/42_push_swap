NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCPATH = src/
SRC = main.c \
		push_swap.c \
		parsing.c \
		list.c \
		operation_swap_push.c \
		operation_rotate_reverse.c \
		sort.c \
		other/print.c
		
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) --no-print-directory -C libft
	@echo "\033[36mMaking Push Swap\033[0m"
	@$(CC) $(OBJ) -L libft/. -lft -o $(NAME)
	@echo "\033[32mDone\033[0m"

%.o : $(SRCPATH)%.c
	@$(CC) -c $^

clean :
	@$(MAKE) --no-print-directory fclean -C libft
	@echo "\033[35mCleaning Push_Swap's objects...\033[0m"
	@rm -f $(OBJ)
	@echo "\033[32mDone\033[0m"

fclean : clean
	@echo "\033[35mCleaning Push_Swap...\033[0m"
	@rm -f $(NAME)
	@echo "\033[32mDone\033[0m"

re : fclean all

.PHONY : all clean fclean re