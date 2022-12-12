/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:06:47 by clcarrer          #+#    #+#             */
/*   Updated: 2022/12/12 09:32:22 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	algae_animation(t_data *data)
{
	static int	i;

	if (i == 0)
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/algae_1.xpm", &data->img_w, &data->img_h);
		i++;
	}
	else
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/algae_2.xpm", &data->img_w, &data->img_h);
		i = 0;
	}
}

void	clam_animation(t_data *data)
{
	static int	i;

	if (data->map.c <= 0)
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/clam_open.xpm", &data->img_w, &data->img_h);
	else if (i == 0)
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/clam_1.xpm", &data->img_w, &data->img_h);
		i++;
	}
	else
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/clam_2.xpm", &data->img_w, &data->img_h);
		i = 0;
	}
}

void	jellyfish_animation(t_data *data)
{
	static int	i;

	if (i == data->map.f + 1)
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/jellyfish_1.xpm", &data->img_w, &data->img_h);
		i = 0;
	}
	else
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/jellyfish_2.xpm", &data->img_w, &data->img_h);
		i++;
	}
}

void	fishes_animation(t_data *data)
{
	static int	i;

	if (i == 0)
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/fishes_1.xpm", &data->img_w, &data->img_h);
		i++;
	}
	else
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/fishes_2.xpm", &data->img_w, &data->img_h);
		i = 0;
	}
}

void	squid_animation(t_data *data)
{
	static int	i;

	if (i == 0)
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/squid_1.xpm", &data->img_w, &data->img_h);
		i++;
	}
	else
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/squid_2.xpm", &data->img_w, &data->img_h);
		i = 0;
	}
}
