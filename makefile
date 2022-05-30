# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clcarre <clcarrer@student.42madrid.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 13:43:31 by clcarre           #+#    #+#              #
#    Updated: 2022/05/30 09:19:09 by clcarre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "mlx.h"
#include <mlx.h>
#include "/Users/clcarrer/Desktop/so_long/minilibx/mlx.h"

NAME  	= so_long.a 
LIB 	= ar -rcs

SRC		= main.c

OBJ 	= $(SRC:.c=.o)

CFLAGS 	= -Wall -Wextra -Werror

LINKS = -I libft -L libft \
    -I /usr/local/include -L /usr/local/lib \
    -l mlx -l ft -framework OpenGL -framework Appkit

$(NAME) : $(OBJ)
	gcc $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.c.o :
	gcc $(CFLAGS) -Imlx -c $< -o $@

all : $(NAME)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re