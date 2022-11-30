/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:43:46 by clcarre           #+#    #+#             */
/*   Updated: 2022/11/30 12:27:08 by clcarrer         ###   ########.fr       */
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
	char			**check_map;
	char			*line;
	char			*add_line;
	unsigned long	max_x;
	unsigned long	max_y;
	int				p_x;
	int				p_y;
	int				p;
	int				e;
	int				c;			
	int				f;
	int				**enemy;
}					t_map;

typedef struct s_data
{
	void		*ptr;
	void		*window;
	void		*img;
	int			img_w;
	int			img_h;
	int			movements;
	int			i;
	int			position;
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

// animation
void	algae_animation(t_data *data);
void	fish_animation(t_data *data);
void	crab_animation(t_data *data);
void	squid_animation(t_data *data);

// checker_map
void	check_char_to_char(t_data *data);
void	copy_map(t_data *data);
int		find_the_exit(char **map, int y, int x, int collectives);
void	checker_map(t_data *data);

// errors
void	clean_map(t_data *data);
void	clean_check_map(t_data *data, int i);
void	*control_error(t_data *data, int error);

//draw_map
void	mov_counter(t_data *data);
void	put_imagine(int x, int y, char *patch);
int		draw_map(t_data *data);

// enemies
void	enemies_coor(t_data *data);
void	control_enemies(t_data *data);

// utils
char	**ft_split(char const *s, char c);
void	v_init(t_data *data);
char	*ft_strdup(t_data *data, const char *s1);
char	*ft_itoa(int n);

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
int		main(int argc, char **argv);

#endif