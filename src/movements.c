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

void	mov_counter(t_data *data)
{
	char	*num;

	num = ft_itoa(data->movements);
	mlx_string_put(data->ptr, data->window, (data->map.max_x * 50), (data->map.max_x * 50), RED, num);
	free(num);
}

void	animation(t_data *data)
{
	// int	i;

	if (data->map.c == 0)
	{
		data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/exit_open.xpm", &data->img_w, &data->img_h);
		mlx_put_image_to_window(data->ptr, data->window, data->img, (data->map.e_x * 50), (data->map.e_y * 50));
	}
	// i = 2;
	// while (i != 0)
	// {
	// 	data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/floor.xpm", &data->img_w, &data->img_h);
	// 	mlx_put_image_to_window(data->ptr, data->window, data->img, (data->map.p_x * 50), (data->map.p_y * 50));
	// 	i--;
	// }
}

void	move_up(t_data *data)
{
	char	p;

	p = data->map.map[data->map.p_y - 1][data->map.p_x];
	if (p == 'E')
	{
		if (data->map.c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/floor.xpm", &data->img_w, &data->img_h);
		mlx_put_image_to_window(data->ptr, data->window, data->img, (data->map.p_x * 50), (data->map.p_y * 50));
		data->map.p_y--;
		data->movements++;
	}
	if (p == 'C')
		data->map.c--;
	data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/character.xpm", &data->img_w, &data->img_h);
	mlx_put_image_to_window(data->ptr, data->window, data->img, (data->map.p_x * 50), (data->map.p_y * 50));
	mov_counter(data);
}

void	move_down(t_data *data)
{
		char	p;

	p = data->map.map[data->map.p_y + 1][data->map.p_x];
	if (p == 'E')
	{
		if (data->map.c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/floor.xpm", &data->img_w, &data->img_h);
		mlx_put_image_to_window(data->ptr, data->window, data->img, (data->map.p_x * 50), (data->map.p_y * 50));
		data->map.p_y++;
		data->movements++;
	}
	if (p == 'C')
		data->map.c--;
	data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/character.xpm", &data->img_w, &data->img_h);
	mlx_put_image_to_window(data->ptr, data->window, data->img, (data->map.p_x * 50), (data->map.p_y * 50));
	mov_counter(data);
}

void	move_right(t_data *data)
{
		char	p;

	p = data->map.map[data->map.p_y][data->map.p_x + 1];
	if (p == 'E')
	{
		if (data->map.c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/floor.xpm", &data->img_w, &data->img_h);
		mlx_put_image_to_window(data->ptr, data->window, data->img, (data->map.p_x * 50), (data->map.p_y * 50));
		data->map.p_x++;
		data->movements++;
	}
	if (p == 'C')
		data->map.c--;
	data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/character.xpm", &data->img_w, &data->img_h);
	mlx_put_image_to_window(data->ptr, data->window, data->img, (data->map.p_x * 50), (data->map.p_y * 50));
	mov_counter(data);
}

void	move_left(t_data *data)
{
		char	p;

	p = data->map.map[data->map.p_y][data->map.p_x - 1];
	if (p == 'E')
	{
		if (data->map.c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/floor.xpm", &data->img_w, &data->img_h);
		mlx_put_image_to_window(data->ptr, data->window, data->img, (data->map.p_x * 50), (data->map.p_y * 50));
		data->map.p_x--;
		data->movements++;
	}
	if (p == 'C')
		data->map.c--;
	data->img = mlx_xpm_file_to_image(data->ptr, "./sprites/character.xpm", &data->img_w, &data->img_h);
	mlx_put_image_to_window(data->ptr, data->window, data->img, (data->map.p_x * 50), (data->map.p_y * 50));
	mov_counter(data);
}