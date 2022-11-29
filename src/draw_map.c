/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:16:36 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/29 12:42:20 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_data *data, int y, int x)
{
	char	c;

	c = data->map.map[y][x];
	if (c == '1')
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/wall.xpm", &data->img_w, &data->img_h);
	else if (c == 'E')
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/exit.xpm", &data->img_w, &data->img_h);
	else if (c == 'C')
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/collect.xpm", &data->img_w, &data->img_h);
	else if (c == 'P')
		egg_animation(data);
	mlx_put_image_to_window(data->ptr, \
		data->window, data->img, (x * 60), (y * 60));
}

int	draw_map(t_data *data)
{
	int		y;
	int		x;

	mlx_clear_window(data->ptr, data->window);
	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			data->img = mlx_xpm_file_to_image(data->ptr, \
				"./sprites/floor.xpm", &data->img_w, &data->img_h);
			mlx_put_image_to_window(data->ptr, \
				data->window, data->img, (x * 60), (y * 60));
			put_img(data, y, x);
			x++;
		}
		y++;
	}
	mov_counter(data);
	return (0);
}
