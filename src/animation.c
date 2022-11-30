/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:06:47 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/30 12:26:19 by clcarrer         ###   ########.fr       */
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

void	fish_animation(t_data *data)
{
	static int	i;

	if (i == 0)
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/fish_1.xpm", &data->img_w, &data->img_h);
		i++;
	}
	else
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/fish_2.xpm", &data->img_w, &data->img_h);
		i = 0;
	}
}

void	crab_animation(t_data *data)
{
	static int	i;

	if (i == 0)
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/crab_1.xpm", &data->img_w, &data->img_h);
		i++;
	}
	else
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/crab_2.xpm", &data->img_w, &data->img_h);
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
