# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 13:43:31 by clcarre           #+#    #+#              #
#    Updated: 2022/12/16 16:27:57 by clcarrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  	= 	so_long
NAME_B 	=	so_long_bonus

INC_DIR = 	./include

SRC_SL	=	src/so_long/so_long.c

SRC_B	=	src/so_long_bonus/so_long_bonus.c \

SRC_CMM	=	src/common_functions/checker_map.c \
			src/common_functions/animation.c \
			src/common_functions/control_error.c \
			src/common_functions/draw_map.c \
			src/common_functions/end_game.c \
			src/common_functions/enemies.c \
			src/common_functions/ft_split.c \
			src/common_functions/start_game.c \
			src/common_functions/movements.c \
			src/common_functions/utils.c

SRC_GNL	=	src/gnl/get_next_line.c \
			src/gnl/get_next_line_utils.c
		
OBJ_SL 	= 	$(SRC_SL:.c=.o)
OBJ_B	= 	$(SRC_B:.c=.o)
OBJ_CMM	= 	$(SRC_CMM:.c=.o)
OBJ_GNL = 	$(SRC_GNL:.c=.o)

CFLAGS 	= 	-Wall -Wextra -Werror -I$(INC_DIR)

LINKS 	=	-I libft -L libft \
    		-I /usr/local/include -L /usr/local/lib \
			-l mlx -l ft -framework OpenGL -framework Appkit

$(NAME) : $(OBJ_SL) $(OBJ_CMM) $(OBJ_GNL)
	gcc $(OBJ_SL) $(OBJ_CMM) $(OBJ_GNL) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_B) : $(OBJ_B) $(OBJ_CMM) $(OBJ_GNL)
	gcc $(OBJ_B) $(OBJ_CMM) $(OBJ_GNL) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

.c.o :
	@gcc $(CFLAGS) -Imlx -c $< -o $@

all	: $(NAME)

bonus : $(NAME_B)

clean : 
	@rm -f $(OBJ_SL)
	@rm -f $(OBJ_B)
	@rm -f $(OBJ_CMM)
	@rm -f $(OBJ_GNL)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)

re : fclean all

.PHONY : all clean fclean re
