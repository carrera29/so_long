# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 13:43:31 by clcarre           #+#    #+#              #
#    Updated: 2022/11/08 19:16:01 by clcarrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  	= 	so_long

INC_DIR = 	./include

SRC_SL	=	src/checker_map.c \
			src/control_error.c \
			src/ft_split.c \
			src/get_map.c \
			src/main.c
			
SRC_GNL	=	src/gnl/get_next_line.c \
			src/gnl/get_next_line_utils.c
		
OBJ_SL 	= 	$(SRC_SL:.c=.o)
OBJ_GNL = 	$(SRC_GNL:.c=.o)

CFLAGS 	= 	-Wall -Wextra -Werror -I$(INC_DIR)

LINKS 	=	-I libft -L libft \
    		-I /usr/local/include -L /usr/local/lib \
			-l mlx -l ft -framework OpenGL -framework Appkit

$(NAME) : $(OBJ_SL) $(OBJ_GNL)
	gcc $(OBJ_SL) $(OBJ_GNL) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.c.o :
	gcc $(CFLAGS) -Imlx -c $< -o $@

all	: $(NAME)

clean : 
	rm -f $(OBJ_SL) 
	rm -f $(OBJ_GNL)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re