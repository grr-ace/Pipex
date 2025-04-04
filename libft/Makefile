# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grmullin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 11:14:12 by grmullin          #+#    #+#              #
#    Updated: 2023/12/12 17:30:32 by grmullin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
FILES := ft_isalpha.c ft_toupper.c ft_isdigit.c ft_tolower.c ft_isalnum.c ft_isascii.c ft_strchr.c  ft_isprint.c ft_strrchr.c ft_strlen.c ft_strncmp.c ft_memset.c ft_bzero.c ft_memchr.c ft_memcpy.c  ft_memcmp.c ft_memmove.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_atoi.c ft_calloc.c ft_strdup.c  ft_substr.c ft_striteri.c ft_strjoin.c ft_strtrim.c ft_substr.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS := $(FILES:.c=.o)
LIBFT_H := libft.h.gch
CC := cc
CFLAGS := -Wall -Werror -Wextra
AR := ar
ARFLAGS := -r
RM := rm -f

all: $(NAME)
	
$(NAME): $(OBJS) 
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(LIBFT_H)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
