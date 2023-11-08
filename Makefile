# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:07:51 by ksansom           #+#    #+#              #
#    Updated: 2023/11/08 16:09:15 by ksansom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = $(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME) $(CHECK)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./mlx_linux
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)
	@$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C ./libft fclean
	@$(MAKE) -C ./mlx_linux fclean

fclean: clean 
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re