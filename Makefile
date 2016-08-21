# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avella <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/21 16:34:10 by avella            #+#    #+#              #
#    Updated: 2016/02/21 16:34:12 by avella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

INCLUDES = "libft/includes"

FLAGS = -Wall -Wextra -Werror

MLXFLA = -lmlx -framework OpenGL -framework AppKit

SRC =	fractol.c init_ok.c mandel.c burningship.c \
	julia.c usefull_func.c

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : 
	make -C libft/
	$(CC) $(FLAGS) -c $(SRC) -I $(INCLUDES)
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(MLXFLA) $(LIB) -I $(INCLUDES)

clean :	
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIB)
	rm -f $(NAME)

re : fclean all
