NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
		parsing.c \
		list.c \
		operation_swap.c \
		operation_push.c \
		operation_rotate.c \
		operation_reverse_rotate.c \
		sort.c \
		utils.c
		
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -L libft/. -lft -g -o $(NAME)

%.o : %.c
	make -C libft
	$(MAKE) additional -C libft
	$(CC) -c $^

clean :
	$(MAKE) clean -C libft
	rm -f $(OBJ)

fclean : clean
	rm libft/libft.a
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re