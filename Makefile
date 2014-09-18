#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plavaux <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/15 14:41:00 by plavaux           #+#    #+#              #
#    Updated: 2014/09/15 17:54:14 by plavaux          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPS = -O2

NAME = bsq

SRCS = srcs/*.c srcs/libft/*.c srcs/utils/*.c
INCS = includes/*.h

OBJ = $(patsubst srcs/%.c, %.o, $(SRCS))

all:
	@$(CC) $(CFLAGS) -I $(INCS) -c $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(OPS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re