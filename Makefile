NAME = so_long

SRCS = $(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) $(CHECK)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C ./libft fclean

fclean: clean 
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re