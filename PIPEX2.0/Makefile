# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Executable name
NAME = pipex

# Source files
SRCS = main.c libft.c utils.c fork_execute.c 

# Object files
OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

