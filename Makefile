# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 12:47:34 by mnurlybe          #+#    #+#              #
#    Updated: 2023/05/03 20:26:50 by mnurlybe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

MY_SOURCES = main.c \
	libft/ft_atoi.c \
	libft/ft_split.c \
	libft/ft_strlen.c \
	libft/ft_lstnew.c \
	libft/ft_lstadd_back.c \
	libft/ft_lstadd_front.c \
	srcs/fill_stack_a.c \
	srcs/error_main.c \
	srcs/error_checks.c \
	srcs/free_memory.c \
	srcs/stack_operations_a.c \
	srcs/stack_operations_b.c \
	srcs/stack_operations_ab.c \
	     
CFLAGS = -Wall -Wextra -Werror

MY_HEADER = ./includes/

MY_OBJECTS = $(MY_SOURCES:.c=.o)

.c.o:
	gcc $(CFLAGS) -c -I $(MY_HEADER) $< -o ${<:.c=.o}

$(NAME): $(MY_OBJECTS)
	cc $(CFLAGS) -o $(NAME) $(MY_OBJECTS)

all: $(NAME)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re