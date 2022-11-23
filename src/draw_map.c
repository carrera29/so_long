/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:16:36 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/23 13:51:29 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_data *data)
{
	char	c;
	int		y;
	int		x;

	mlx_clear_window(data->ptr, data->window);
	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			c = data->map.map[y][x];
			data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/floor.xpm", &data->img_w, &data->img_h);
			mlx_put_image_to_window(data->ptr, data->window, data->img, (x * 60), (y * 60));
			if (c == '1')
				data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/wall.xpm", &data->img_w, &data->img_h);
			else if (c == 'P')
				data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/lulu_rg_1.xpm", &data->img_w, &data->img_h);
			else if (c == 'E')
				data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/exit.xpm", &data->img_w, &data->img_h);
			else if (c == 'C')
				data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/collect.xpm", &data->img_w, &data->img_h);
			mlx_put_image_to_window(data->ptr, data->window, data->img, (x * 60), (y * 60));
			x++;
		}
		y++;
	}
	mov_counter(data);
}