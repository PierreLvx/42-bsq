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

NAME = bsq

all:
	$(CC) $(CFLAGS) -o $(NAME)

clean:

fclean:

re:
	flcean all

.PHONY: all clean fclean re