# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 19:41:13 by moerradi          #+#    #+#              #
#    Updated: 2022/02/16 16:08:57 by moerradi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
SRCS= main.c utils.c routine.c supervisor.c init.c
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCS) Makefile
	gcc $(SRCS) $(CFLAGS) -o $(NAME) -pthread

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re