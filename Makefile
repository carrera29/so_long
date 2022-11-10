# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chloeplatt <chloeplatt@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 13:43:31 by clcarre           #+#    #+#              #
#    Updated: 2022/11/10 10:27:13 by chloeplatt       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  	= 	so_long

INC_DIR	= 	./include

SRC		= 	./src/checker_map.c \
			./src/control_error.c \
			./src/ft_split.c \
			./src/get_map.c \
			./src/so_long.c

SRC_GNL =	./src/gnl/get_next_line_utils.c \
			./src/gnl/get_next_line.c

OBJ 	= 	$(SRC:.c=.o)
OBJ_GNL = 	$(SRC_GNL:.c=.o)

CFLAGS 	= 	-Wall -Wextra -Werror -I$(INC_DIR)

$(NAME) : 	$(OBJ) $(OBJ_GNL)
	gcc $(CFLAGS) $(OBJ) $(OBJ_GNL) -o $(NAME)

%.o : 		/%.c
	gcc -c $(CFLAGS) $< -o $@

all	: 		$(NAME)

clean : 
	rm -f $(OBJ) $(OBJ_GNL)

fclean : 	clean
	rm -f $(NAME)

re : 		fclean all

.PHONY : 	all clean fclean re
