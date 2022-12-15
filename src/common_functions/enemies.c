/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:39:25 by clcarrer          #+#    #+#             */
/*   Updated: 2022/12/15 16:13:10 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_mov(t_data *data, int y, int x, int i)
{
	static int	dir;

	if (dir == 0 && data->map.map[y - 1][x] == 'P')
		end_game(data, 1);
	else if (dir == 0 && data->map.map[y - 1][x] == '0')
	{
		data->map.map[y - 1][x] = 'F';
		data->map.map[y][x] = '0';
		data->map.enemy[i][0] = y - 1;
	}
	else
		dir = 1;
	if (dir == 0 && data->map.map[y + 1][x] == 'P')
		end_game(data, 1);
	else if (dir == 1 && data->map.map[y + 1][x] == '0')
	{
		data->map.map[y + 1][x] = 'F';
		data->map.map[y][x] = '0';
		data->map.enemy[i][0] = y + 1;
	}
	else
		dir = 0;
}

void	move_enemies(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < data->map.f)
	{
		y = data->map.enemy[i][0];
		x = data->map.enemy[i][1];
		enemy_mov(data, y, x, i);
		i++;
	}
}

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
