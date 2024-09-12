# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 15:13:08 by eriviere          #+#    #+#              #
#    Updated: 2024/09/05 11:32:03 by eriviere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRCS = src/pipex.c src/utils_pipex.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = src/pipex.h libft/libft.h libft/ft_printf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror  #-fsanitize=adress

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
