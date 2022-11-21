/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:43:46 by clcarre           #+#    #+#             */
/*   Updated: 2022/11/21 10:34:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

typedef struct s_map
{
	char			**map;
	char			*line;
	char			*add_line;
	unsigned long	max_x;
	unsigned long	max_y;
	int				p_x;
	int				p_y;
	int				e_x;
	int				e_y;
	int				p;
	int				e;
	int				c;
}					t_map;

typedef struct s_data
{
	void		*ptr;
	void		*window;
	void		*img;
	int			img_w;
	int			img_h;
	int			movements;
	t_map		map;
}				t_data;

enum e_keycode
{
	M_UP = 13, 
	A_UP = 126,
	M_DOWN = 1,
	A_DOWN = 125,
	M_RIGHT = 2,
	A_RIGHT = 124,
	M_LEFT = 0,
	A_LEFT = 123,
	MOUSE_UP = 5,
	MOUSE_DOWN = 4,
	MOUSE_MOVE = 6,
	EXPOSE = 12,
	DESTROY = 17,
	KEY_RESET = 15,
	ESCAPE = 53
};

enum e_colors
{
	WHITE = 0xFFFFFF,
	BLACK = 0x000000,
	RED = 0xFF0000,
	YELLOW = 0x00FF00,
	BLUE = 0x0000FF,
};

// gnl
char	*get_next_line(int fd);
void	*ft_bzero(char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *str, char *aux);

// checker_map
void	check_char_to_char(t_data *data);
void	checker_map(t_data *data);

// errors
void	clean_map(t_data *data);
void    *control_error(t_data *data, int error);

//draw_map
void	put_imagine(int x, int y, char *patch);
void	draw_map(t_data *data);

// utils
char	**ft_split(char const *s, char c);

// movements
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);

// get map
void	get_map(t_data *data, char **argv);

// so_long
int		end_game(t_data *data);
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, void *param);
int		main(int argc, char **argv);

#endif