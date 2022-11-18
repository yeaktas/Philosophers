CC		= gcc -g -pthread
NAME	= philo
FLAGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard src/*.c)
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

re: fclean all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

git:
	git add .
	git commit -m "$m"
	git push git@github.com:yeaktas/Philosophers.git

norm:
	@norminette $(wildcard philo_bonus/*.c)
	@norminette $(wildcard src/*.c)
	@norminette $(wildcard inc/*.h)

.PHONY: all re clean fleanc git norm