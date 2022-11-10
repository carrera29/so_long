/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloeplatt <chloeplatt@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:43:46 by clcarre           #+#    #+#             */
/*   Updated: 2022/11/10 14:45:08 by chloeplatt       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

# define WINDOW_X 960
# define WINDOW_Y 540
# define BUFFER_SIZE 1

typedef struct s_picture
{
	int		x;
	int		y;
	int		color;
}				t_picture;

typedef struct s_data
{
	void		*ptr;
	void		*window;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_picture	picture;
}				t_data;

typedef struct s_map
{
	char			**map;
	char			*line;
	char			*add_line;
	unsigned long	max_x;
	unsigned long	max_y;
	int				x;
	int				y;
	int				p;
	int				e;
	int				c;
	int				fd;
	int				i;
}					t_map;

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
void	check_char_to_char(t_map *map);
void	checker_map(t_map *map);

// errors
void	clean_map(t_map *map);
void    *control_error(t_map *map, int error);

//draw_map
void	put_imagine(t_map *map, int x, int y, char *patch);
void	draw_map(t_map *map);

// utils
char	**ft_split(char const *s, char c);

// get map
void	get_values(t_map *map);
void	get_map(t_map *map, char **argv);

// so_long
void	ft_draw_pixel(t_data *data, int x, int y, int color);
int		ft_end_game(t_data *data);
int		ft_key_hook(t_data *data, int keycode);
int		ft_mouse_hook(int keycode);
int		main(int argc, char **argv);

#endif