# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 11:51:45 by ksansom           #+#    #+#              #
#    Updated: 2023/11/06 15:27:31 by ksansom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB	= ar rcs
RM = rm -rf

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJS)
	@$(LIB) libft.a $(OBJS)
	
clean:
	@$(RM) $(OBJS)

fclean: clean 
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

