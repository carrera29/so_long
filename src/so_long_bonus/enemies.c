/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:39:25 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/30 12:12:25 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemies_coor(t_data *data)
{
	int		y;
	int		x;
	int		i;

	i = 0;
	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'F')
			{
				data->map.enemy[i][0] = y;
				data->map.enemy[i][1] = x;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	control_enemies(t_data *data)
{
	int	i;

	data->map.enemy = malloc(sizeof(int **) * data->map.f);
	if (!data->map.enemy)
		control_error(data, 5);
	i = 0;
	while (i <= data->map.f)
	{
		data->map.enemy[i] = malloc(sizeof(int) * 2);
		i++;
		if (!data->map.enemy[i])
			control_error(data, 5);
	}
	enemies_coor(data);
}

