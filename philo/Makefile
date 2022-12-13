
NAME	= philo
CC	= @gcc
CFLAGS	= -Wall -Wextra -Werror -I ./include
SRCS	= $(wildcard src_man/*.c)
OBJS	= $(SRCS:.c=.o)

INCLUDE	= -pthread
FLAGS = -g -fsanitize=thread

HEADER	= philosophers.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(INCLUDE) $(CFLAGS) $(FLAGS) -o $(NAME) $(OBJS)
	
clean:
	@rm -f src_man/*.o
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re