# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gscorzon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/18 12:14:13 by gscorzon          #+#    #+#              #
#    Updated: 2026/07/23 18:59:14 by gscorzon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= gnl.a
CFLAGS	= -Wall -Wextra -Werror
SRCS	=  get_next_line_utils.c get_next_line.c 
# get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
$(OBJS): $(SRCS)
	cc -c $(CFLAGS) $(SRCS) -g
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
