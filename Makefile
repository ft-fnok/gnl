# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 18:31:50 by nlalleik          #+#    #+#              #
#    Updated: 2022/01/30 19:16:01 by nlalleik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=42

SRCS =	get_next_line.c \
		get_next_line_utils.c \

#OBJS = $(SRCS:c=o)

OBJS = $(subst .c,.o,$(SRCS))

NAME =	get_next_line.a

all: $(NAME)

# %.o:%.c
# 	$(CC) -c $(CFLAGS) $(SRCS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean: 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean all

.PHONY:    all    clean    fclean    re bonus