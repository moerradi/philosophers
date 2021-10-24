# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 19:41:13 by moerradi          #+#    #+#              #
#    Updated: 2021/10/24 15:42:45 by moerradi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
SRCS= main.c utils.c routine.c init.c
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(CFLAGS) $(SRCS) -o $(NAME) -pthread

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re