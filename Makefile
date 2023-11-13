# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:07:51 by ksansom           #+#    #+#              #
#    Updated: 2023/11/13 10:32:09 by ksansom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif
 
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif
 
all: $(MLX_LIB) $(NAME)
 
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
 
$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean 
	@$(RM) $(NAME)
	@$(RM) $(MLX_LIB)

re: fclean all

.PHONY: all clean fclean re
