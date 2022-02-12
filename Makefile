# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 19:41:13 by moerradi          #+#    #+#              #
#    Updated: 2022/02/12 19:31:30 by moerradi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
SRCS= main.c utils.c routines.c init.c
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME) -pthread -fsanitize=address

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re