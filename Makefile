NAME = push_swap
BONUS = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCPATH = src/
SRC = main.c \
		parsing.c \
		sort_small_list.c \
		sort_big_list.c \
		moves.c \
		list.c \
		utils.c

OBJ = $(SRC:.c=.o)

BONUS_SRCPATH = checker_bonus/
BONUS_SRC = c_main.c \
		checker.c \
		c_parsing.c \
		c_list.c \
		c_swap.c \
		c_push.c \
		c_rotate.c \
		c_reverse_rotate.c
		
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) --no-print-directory -C libft
	@echo "\033[36mMaking Push Swap\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -L libft/. -lft -o $(NAME)
	@echo "\033[32mDone\033[0m"

%.o : $(SRCPATH)%.c
	@$(CC) $(CFLAGS) -c $^

bonus : $(BONUS)

$(BONUS) : $(BONUS_OBJ)
	@$(MAKE) --no-print-directory -C libft
	@echo "\033[36mMaking Checker\033[0m"
	@$(CC) $(CFLAGS) $(BONUS_OBJ) -L libft/. -lft -o $(BONUS)
	@echo "\033[32mDone\033[0m"

%.o : $(BONUS_SRCPATH)%.c
	@$(CC) $(CFLAGS) -c $^

clean :
	@$(MAKE) --no-print-directory fclean -C libft
	@echo "\033[35mCleaning Push_Swap's objects...\033[0m"
	@rm -f $(OBJ)
	@echo "\033[32mDone\033[0m"
	@echo "\033[35mCleaning Checker's objects...\033[0m"
	@rm -f $(BONUS_OBJ)
	@echo "\033[32mDone\033[0m"

fclean : clean
	@echo "\033[35mCleaning Push_Swap...\033[0m"
	@rm -f $(NAME)
	@echo "\033[32mDone\033[0m"
	@echo "\033[35mCleaning Checker...\033[0m"
	@rm -f $(BONUS)
	@echo "\033[32mDone\033[0m"

re : fclean
	make all

.PHONY : all clean fclean re bonus