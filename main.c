/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarre <clcarrer@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:28:09 by clcarre           #+#    #+#             */
/*   Updated: 2022/06/01 18:09:21 by clcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"
/*
La estructura t_data almacena todas las variables
y bastará con invocar dicha struct en el main
para usar esas variabes.
*/

void	ft_draw_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_end_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	write(1, "Bye!\n", 5);
	exit (EXIT_SUCCESS);
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		ft_end_game(data);
	else if (keycode == 16)
		write (1, "key hook active\n", 16);
	return (1);
}

int	ft_mouse_hook(int keycode)
{
	if (keycode == 1)
		write (1, "Mouse hook active\n", 18);
	return (0);
}
/*
int	ft_render_uno(t_data *data, t_picture picture)
{
	int	x;
	int	y;

	x = 100;
	while (x <= picture.x)
	{
		y = 100;
		while (y <= picture.y)
			ft_draw_pixel(data, x, y++, picture.color);
		x++;
	}
	return (0);
}

int	ft_render(t_data *data)
{
	ft_render_uno(data, (t_picture){300, 300, RED});
	return (0);
}*/

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (ft_end_game(&data));
	data.window = mlx_new_window(data.mlx, WINDOW_X, WINDOW_Y, "New data!");
	if (data.window == NULL)
	{
		free(data.window);
		return (ft_end_game(&data));
	}
	data.img = mlx_new_image(data.mlx, WINDOW_X, WINDOW_Y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
		&data.line_length, &data.endian);
	mlx_put_image_to_window(data.mlx, data.window, data.img, 0, 0);
	// (void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
	mlx_hook(data.window, 2, (1L << 0), ft_key_hook, &data);
	// (void *win_ptr, int (*funct_ptr)(), void *param) -> tecla es presionada
	mlx_mouse_hook(data.window, ft_mouse_hook, &data);
	//ft_render_uno(&data, (t_picture){300, 300, RED});
	//mlx_loop_hook(data.mlx, ft_render, &data);
	//(void *mlx_ptr, int (*funct_ptr)(), void *param)
	ft_draw_pixel(&data, 10, 10, RED);
	mlx_loop(data.mlx);
}
