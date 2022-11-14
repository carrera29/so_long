/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:16:36 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/14 14:03:52 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_map *map, t_data *data)
{
	char	c;
	
	map->y = 0;
	while (map->map[map->y])
	{
		map->x = 0;
		while (map->map[map->y][map->x])
		{
			c = map->map[map->y][map->x];
			if (c == '1')
				data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/wall.xpm", &data->img_w, &data->img_h);
			else if (c == '0')
				data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/floor.xpm", &data->img_w, &data->img_h);
			else if (c == 'P')
			{
				data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/floor.xpm", &data->img_w, &data->img_h);
				mlx_put_image_to_window(data->ptr, data->window, data->img, (map->x * 50), (map->y * 50));
				data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/character.xpm", &data->img_w, &data->img_h);
			}
			else if (c == 'E')
				data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/exit.xpm", &data->img_w, &data->img_h);
			else if (c == 'C')
			{
				data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/floor.xpm", &data->img_w, &data->img_h);
				mlx_put_image_to_window(data->ptr, data->window, data->img, (map->x * 50), (map->y * 50));
				data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/coins.xpm", &data->img_w, &data->img_h);
			}
			mlx_put_image_to_window(data->ptr, data->window, data->img, (map->x * 50), (map->y * 50));
			map->x++;
		}
		map->y++;
	}
}