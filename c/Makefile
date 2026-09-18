# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeonhan <jeonhan@student.42gyeongsan.kr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/13 11:50:29 by jeonhan           #+#    #+#              #
#    Updated: 2026/09/18 15:50:17 by jeonhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= rt
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I. -Ivec3 -Iray -g
MATH_FLAG	= -lm

SRCS		= $(shell find . -name "*.c")
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MATH_FLAG) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re