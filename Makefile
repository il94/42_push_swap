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
	$(MAKE) additional -C libft
	$(CC) $(OBJ) -L libft/. -lft -g -o $(NAME)

%.o : %.c
	$(CC) -c $^

clean :
	$(MAKE) clean -C libft
	rm -f $(OBJ)

fclean : clean
	rm libft/libft.a
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re