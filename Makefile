# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 15:47:22 by ibenhoci          #+#    #+#              #
#    Updated: 2023/04/25 14:50:08 by ibenhoci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = source/ft_printf.c source/printf_tools.c source/printf_tools_2.c

FLAGS = -Wall -Wextra -Werror
CC = cc -c

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(SOURCES)
		ar rcs $(NAME) *.o

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
