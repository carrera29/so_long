# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 13:43:31 by clcarre           #+#    #+#              #
#    Updated: 2022/10/28 11:16:36 by clcarrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  	= so_long
LIB 	= ar -rcs

SRC		= main.c

OBJ 	= $(SRC:.c=.o)

CFLAGS 	= -Wall -Wextra -Werror

LINKS 	= -I libft -L libft \
    	-I /usr/local/include -L /usr/local/lib \
    	-l mlx -l ft -framework OpenGL -framework Appkit

$(NAME) : $(OBJ)
	gcc $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.c.o :
	gcc $(CFLAGS) -Imlx -c $< -o $@

all	: $(NAME)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re