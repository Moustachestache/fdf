# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjochum <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 16:13:45 by mjochum           #+#    #+#              #
#    Updated: 2023/07/22 13:25:09 by mjochum          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

SOURCES =	ft_atoi.c ft_isalpha.c ft_itoa.c ft_memmove.c ft_putnbr_fd.c \
		ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c \
		ft_isascii.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c \
		ft_strlen.c ft_strrchr.c ft_toupper.c ft_calloc.c ft_isdigit.c \
		ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strmapi.c \
		ft_strtrim.c ft_substr.c ft_isalnum.c ft_isprint.c ft_memcpy.c \
		ft_putendl_fd.c ft_strchr.c ft_strlcat.c ft_strncmp.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstmap.c \
		ft_printf.c ft_functions.c ft_puthex.c ft_putnbr.c \
		get_next_line.c get_next_line_utils.c \

OBJECTS =	$(SOURCES:.c=.o)

CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror -g -pg

$(NAME): $(OBJECTS)
	ar cr $(NAME) $(OBJECTS)

all: $(NAME)

clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
