/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:06:47 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/29 12:36:11 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	egg_animation(t_data *data)
{
	static int	i;

	if (i == 0)
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/lulu_w1.xpm", &data->img_w, &data->img_h);
		i++;
	}
	else
	{
		data->img = mlx_xpm_file_to_image(data->ptr, \
			"./sprites/lulu_w2.xpm", &data->img_w, &data->img_h);
		i = 0;
	}
}
