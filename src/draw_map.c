/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:16:36 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/30 12:28:33 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mov_counter(t_data *data)
{
	char	*text;

	text = ft_strjoin(ft_itoa(data->movements), " moves");
	mlx_string_put(data->ptr, data->window, \
		(data->map.max_x * 50), 64, RED, text);
	free(text);
}

void	put_img(t_data *data, int y, int x)
{
	char	c;

	c = data->map.map[y][x];
	if (c == '1')
		algae_animation(data);
	else if (c == 'E')
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/algae_1.xpm", &data->img_w, &data->img_h);
	else if (c == 'C')
		fish_animation(data);
	else if (c == 'F')
		crab_animation(data);
	else if (c == 'P')
		squid_animation(data);
	mlx_put_image_to_window(data->ptr, \
		data->window, data->img, (x * 64), (y * 64));
}

int	draw_map(t_data *data)
{
	int		y;
	int		x;

	y = 0;
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
