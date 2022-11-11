/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:28:09 by clcarre           #+#    #+#             */
/*   Updated: 2022/11/11 15:25:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_draw_pixel(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	ft_drawing(t_data *data)
// {
// 	t_picture	p;
// 	int 		color[3];
// 	static int	i;	

// 	color[0] = 0xFF0000;
// 	color[1] = 0x00FF00;
// 	color[2] = 0x0000FF;
// 	p.x = 100;
// 	p.y = 100;
// 	while (p.x < 400)
// 	{
// 		while (p.y < 400)
// 		{
// 			ft_draw_pixel(data, p.x, p.y, color[2]);
// 			p.y++;
// 		}
// 		p.y = 100;
// 		p.x++;
// 	}
// 	i++;
// 	if (i == 2)
// 		i = 0;
// 	return (0);
// }

int	end_game(t_data *data)
{
	t_map	*map;
	
	clean_map(map);
	mlx_destroy_window(data->ptr, data->window);
	exit (EXIT_SUCCESS);
}

// // mouse_hook(int button, int x, int y, void *param);
int	key_hook(int keycode, t_data *data)
{
	t_mov	mov;
	t_map	map;
	
	if (keycode == M_UP || keycode == A_UP)
		move_up(&mov, &map, data);
	else if (keycode == M_DOWN || keycode == A_DOWN)
		move_down(&mov, &map, data);
	else if (keycode == M_RIGHT || keycode == A_RIGHT)
		move_right(&mov, &map, data);
	else if (keycode == M_LEFT || keycode == A_LEFT)
		move_left(&mov, &map, data);
	else if (keycode == 53)
		end_game(data);
	return (0);
}

// int	mouse_hook(int keycode)
// {
// 	if (keycode == 4)
// 		write (1, "move up\n", 8);
// 	else if (keycode == 5)
// 		write (1, "move down\n", 10);
// 	else if (keycode == 2)
// 		write (1, "move right\n", 11);
// 	else if (keycode == 1)
// 		write (1, "move left\n", 10);
// 	return (0);
// }

// int	render(t_data *data)
// {
// 	// ft_drawing(data);
// 	return (0);
// }


void	v_init(t_map *map)

{
	t_mov	*mov;

	mov.movements = 0;
	map->max_x = 0;
	map->max_y = 0;
	map->y = 0;
}

int	main(int argc, char **argv)
{
	// t_data	data;
	t_map	map;

	if (argc > 1)
	{
		v_init(&map);
		get_map(&map, argv);
		checker_map(&map);
		data.ptr = mlx_init();
		data.window = mlx_new_window(data.ptr, map.max_x * 50, map.max_y * 50, "New Game!");
		draw_map(&map);
		// // mlx_mouse_hook(data.window, mouse_hook, &data);
		mlx_hook(data.window, 2, 1L<<0, key_hook, &data);
		mlx_hook(data.window, 17, 1L<<0, end_game, &data);
	
		// data.img = mlx_xpm_file_to_image(data.ptr, "/Users/clcarrer/Desktop/sample_640×426.xpm", &img_width, &img_height);
		// // data.img = mlx_new_image(data.ptr, WINDOW_X, WINDOW_Y);
		// data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
		// 	&data.line_length, &data.endian);

		// mlx_put_image_to_window(data.ptr, data.window, data.img, 0, 0);
		// // mlx_loop_hook(data.ptr, render, &data);
	
		// mlx_loop(data.ptr);
		clean_map(&map);
	}
	return (0);
}
