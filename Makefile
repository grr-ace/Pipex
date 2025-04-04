# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grmullin <grmullin@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 09:43:01 by grmullin          #+#    #+#              #
#    Updated: 2024/01/02 13:33:48 by grmullin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex
FILES := main.c functions.c utils.c
OBJS := $(FILES:.c=.o)
PIPEX_H := Pipex.h.gch
CC := cc
CFLAGS := -Wall -Werror -Wextra
RM := rm -f

LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): 
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(C_FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean: 
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(PIPEX_H)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
