/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:16:36 by clcarrer          #+#    #+#             */
/*   Updated: 2022/12/15 15:20:58 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mov_counter(t_data *data)
{
	char	*text;

	text = ft_itoa(data->movements);
	if (data->movements > 0)
	{
		write(1, text, sizeof(text) - 1);
		write(1, " moves\n", 7);
	}
	mlx_string_put(data->ptr, data->window, \
		((data->map.max_x * 64) + 24), 24, RED, text);
	free(text);
}

void	draw_water(t_data *data, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->ptr, \
		"./sprites/water.xpm", &data->img_w, &data->img_h);
	mlx_put_image_to_window(data->ptr, \
		data->window, data->img, (x * 64), (y * 64));
}

void	put_img(t_data *data, int y, int x)
{
	char	c;

	draw_water(data, x, y);
	c = data->map.map[y][x];
	if (c == '1')
		algae_animation(data);
	else if (c == 'E')
		clam_animation(data);
	else if (c == 'C')
		fishes_animation(data);
	else if (c == 'P')
		squid_animation(data);
	else if (c == 'F')
		jellyfish_animation(data);
	mlx_put_image_to_window(data->ptr, \
		data->window, data->img, (x * 64), (y * 64));
}

int	draw_map(t_data *data)
{
	int			y;
	int			x;

	draw_water(data, data->map.max_x, 0);
	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] != '0')
				put_img(data, y, x);
			x++;
		}
		y++;
	}
	mov_counter(data);
	return (0);
}

int	first_draw_map(t_data *data)
{
	int			y;
	int			x;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			draw_water(data, x, y);
			put_img(data, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
