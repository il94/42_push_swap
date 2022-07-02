NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
		parsing.c \
		list.c \
		operation_swap_push.c \
		operation_rotate_reverse.c \
		sort.c \
		utils.c \
		push_swap.c
		
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) --no-print-directory additional -C libft
	@echo "\033[36mMaking Push Swap\033[0m"
	@$(CC) $(OBJ) -L libft/. -lft -g -o $(NAME)
	@echo "\033[32mDone\033[0m"

%.o : %.c
	@$(CC) -c $^

clean :
	@$(MAKE) --no-print-directory clean -C libft
	@echo "\033[35mCleaning Push_Swap's objects...\033[0m"
	@rm -f $(OBJ)
	@echo "\033[32mDone\033[0m"

fclean : clean
	@echo "\033[35mCleaning Push_Swap...\033[0m"
	@rm libft/libft.a
	@rm -f $(NAME)
	@echo "\033[32mDone\033[0m"

re : fclean all

.PHONY : all clean fclean re