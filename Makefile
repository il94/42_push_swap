NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c parsing.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -L libft/. -lft -L libft_custom/. -lft_custom -o $(NAME)

%.o : %.c
	make -C libft
	make -C libft_custom
	$(CC) -c $^

clean :
	$(MAKE) clean -C libft
	$(MAKE) clean -C libft_custom
	rm -f $(OBJ)

fclean : clean
	rm libft/libft.a
	rm libft_custom/libft_custom.a
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re