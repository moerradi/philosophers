NAME=philosophers
SRCS= main.c

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re