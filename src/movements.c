/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:16:56 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/14 09:16:56 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_mov *mov, t_map *map, t_data *data)
{
	char	p;

	// put_imagine(map->x, map->y, "./xpm_img/p_up1.xpm");
	p = map->map[map->y - 1][map->x];
	if (p == 'E')
	{
		if (map->c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		map->y--;
		mov->movements++;
	}
	if (p == 'C')
		map->c++;
	data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/character.xpm", &data->img_w, &data->img_h);
    mlx_put_image_to_window(data->ptr, data->window, data->img, (map->x * 50), (map->y * 50));
}

void	move_down(t_mov *mov, t_map *map, t_data *data)
{
	char	p;

	// put_imagine(map->x, map->y, "./xpm_img/p_dw1.xpm");
	p = map->map[map->y + 1][map->x];
	if (p == 'E')
	{
		if (map->c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		map->y++;
		mov->movements++;
	}
	if (p == 'C')
		map->c++;
	data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/character.xpm", &data->img_w, &data->img_h);
    mlx_put_image_to_window(data->ptr, data->window, data->img, (map->x * 50), (map->y * 50));
}

void	move_right(t_mov *mov, t_map *map, t_data *data)
{
	char	p;

	// put_imagine(map->x, map->y, "./xpm_img/p_rg1.xpm");
	p = map->map[map->y][map->x + 1];
	if (p == 'E')
	{
		if (map->c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		map->x++;
		mov->movements++;
	}
	if (p == 'C')
		map->c++;
	data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/character.xpm", &data->img_w, &data->img_h);
    mlx_put_image_to_window(data->ptr, data->window, data->img, (map->x * 50), (map->y * 50));
}

void	move_left(t_mov *mov, t_map *map, t_data *data)
{
	char	p;

	// put_imagine(map->x, map->y, "./xpm_img/p_lf1.xpm");
	p = map->map[map->y][map->x - 1];
	if (p == 'E')
	{
		if (map->c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		map->x--;
		mov->movements++;
	}
	if (p == 'C')
		map->c++;
	data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/character.xpm", &data->img_w, &data->img_h);
    mlx_put_image_to_window(data->ptr, data->window, data->img, (map->x * 50), (map->y * 50));
}