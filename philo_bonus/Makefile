NAME	= philo_bonus
CC	= @gcc
CFLAGS	= -Wall -Wextra -Werror -I ./include
SRCS	= $(wildcard src_bonus/*.c)
OBJS	= $(SRCS:.c=.o)

INCLUDE	= -pthread
FLAGS = -g -fsanitize=thread

HEADER	= philosophers_bonus.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(INCLUDE) $(CFLAGS) -o $(NAME) $(OBJS)
clean:
	@rm -f src_bonus/*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
