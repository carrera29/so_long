/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloeplatt <chloeplatt@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:28:09 by clcarre           #+#    #+#             */
/*   Updated: 2022/11/10 14:03:20 by chloeplatt       ###   ########.fr       */
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

// int	end_game(t_data *data)
// {
// 	mlx_destroy_window(data->ptr, data->window);
// 	write(1, "Bye!\n", 5);
// 	exit (EXIT_SUCCESS);
// }

// // mouse_hook(int button, int x, int y, void *param);
// int	key_hook(int keycode, t_data *data)
// {
// 	if (keycode == M_UP || keycode == A_UP)
// 		write (1, "move up\n", 8);
// 	else if (keycode == M_DOWN || keycode == A_DOWN)
// 		write (1, "move down\n", 10);
// 	else if (keycode == M_RIGHT || keycode == A_RIGHT)
// 		write (1, "move right\n", 11);
// 	else if (keycode == M_LEFT || keycode == A_LEFT)
// 		write (1, "move left\n", 10);
// 	else if (keycode == 53)
// 	{
// 		mlx_destroy_window(data->ptr, data->window);
// 		write(1, "Bye!\n", 5);
// 		exit (EXIT_SUCCESS);
// 	}
// 	return (0);
// }

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

int	main(int argc, char **argv)
{
	// t_data	data;
	t_map	map;

	if (argc == 1)
		return (0);
	get_map(&map, argv);
	map.i = 0;
	while (map.map[map.i])
		printf("%s\n", map.map[map.i++]);
	checker_map(&map);
	draw_map(&map);
	// int		img_width;
	// int		img_height;

	// data.ptr = mlx_init();

	// data.window = mlx_new_window(data.ptr, WINDOW_X, WINDOW_Y, "NEW GAME!");
	// // mlx_hook(data.window, 2, 1L<<0, key_hook, &data);
	// // mlx_mouse_hook(data.window, mouse_hook, &data);
	// // mlx_hook(data.window, 17, 1L<<0, end_game, &data);
	
	// data.img = mlx_xpm_file_to_image(data.ptr, "/Users/clcarrer/Desktop/sample_640×426.xpm", &img_width, &img_height);
	// // data.img = mlx_new_image(data.ptr, WINDOW_X, WINDOW_Y);
	// data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	// 	&data.line_length, &data.endian);

	// mlx_put_image_to_window(data.ptr, data.window, data.img, 0, 0);
	// // mlx_loop_hook(data.ptr, render, &data);
	
	// mlx_loop(data.ptr);
	clean_map(&map);
	return (0);
}
