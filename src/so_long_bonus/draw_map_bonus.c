/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:16:36 by clcarrer          #+#    #+#             */
/*   Updated: 2022/12/12 10:39:39 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mov_counter_bonus(t_data *data)
{
	char	*text;

	text = ft_itoa(data->movements);
	if (data->movements > 0)
	{
		write(1, text, sizeof(text) - 1);
		write(1, " moves\n", 7);
	}
	mlx_string_put(data->ptr, data->window, \
		((data->map.max_x * 64) + 32), 32, RED, text);
	free(text);
}

void	put_img_bonus(t_data *data, int y, int x)
{
	char	c;

	c = data->map.map[y][x];
	if (c == '1')
		algae_animation(data);
	else if (c == 'E')
		clam_animation(data);
	else if (c == 'C')
		fishes_animation(data);
	else if (c == 'F')
		jellyfish_animation(data);
	else if (c == 'P')
		squid_animation(data);
	mlx_put_image_to_window(data->ptr, \
		data->window, data->img, (x * 64), (y * 64));
}

int	draw_map_bonus(t_data *data)
{
	int			y;
	int			x;

	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			data->img = mlx_xpm_file_to_image(data->ptr, \
				"./sprites/water.xpm", &data->img_w, &data->img_h);
			mlx_put_image_to_window(data->ptr, \
				data->window, data->img, (x * 64), (y * 64));
			put_img(data, y, x);
			x++;
		}
		y++;
	}
	mov_counter(data);
	return (0);
}

int	first_draw_map_bonus(t_data *data)
{
	int			y;
	int			x;

	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			data->img = mlx_xpm_file_to_image(data->ptr, \
				"./sprites/water.xpm", &data->img_w, &data->img_h);
			mlx_put_image_to_window(data->ptr, \
				data->window, data->img, (x * 64), (y * 64));
			put_img(data, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
