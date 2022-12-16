/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:39:25 by clcarrer          #+#    #+#             */
/*   Updated: 2022/12/16 16:20:22 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_moves(t_data *data, int i, char c)
{
	data->map.map[data->map.enemy[i][0]][data->map.enemy[i][1]] = '0';
	draw_water(data, data->map.enemy[i][1], data->map.enemy[i][0]);
	if (c == 'u')
		data->map.enemy[i][0] -= 1;
	else if (c == 'd')
		data->map.enemy[i][0] += 1;
	else if (c == 'r')
		data->map.enemy[i][1] += 1;
	else if (c == 'l')
		data->map.enemy[i][1] -= 1;
	data->map.map[data->map.enemy[i][0]][data->map.enemy[i][1]] = 'F';
}

void	enemy_direction(t_data *data, int y, int x, int i)
{
	int		hor_x;
	char	c;	

	hor_x = '\0';
	c = '\0';
	if ((data->map.p_x > x) && (data->map.map[y][x + 1] == '0'))
	{
		c = 'r';
		hor_x = data->map.p_x - x;
	}
	else if (data->map.map[y][x - 1] == '0')
	{
		c = 'l';
		hor_x = x - data->map.p_x;
	}
	if ((data->map.p_y > y) && (data->map.p_y - y < hor_x || hor_x == '\0')
		&& (data->map.map[y + 1][x] == '0'))
		c = 'd';
	else if ((data->map.p_y < y) && (y - data->map.p_y < hor_x || hor_x == '\0')
		&& (data->map.map[y - 1][x] == '0'))
		c = 'u';
	if (c != '\0')
		enemy_moves(data, i, c);
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
		// if (data->map.map[y + 1][x] == 'P' || data->map.map[y - 1][x] == 'P'
		// || data->map.map[y][x + 1] == 'P' || data->map.map[y][x - 1] == 'P')
		// {
		// 	data->map.map[y][x] = '0';
		// 	draw_water(data, x, y);
		// 	data->map.map[data->map.p_y][data->map.p_x] = 'F';
		// }
		// else
			enemy_direction(data, y, x, i);
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

	printf(" el num de enemigos es %d\n", data->map.f);
	data->map.enemy = malloc(sizeof(int **) * data->map.f);
	if (!data->map.enemy)
		control_error(data, 5);
	i = 0;
	while (i <= data->map.f)
	{
		data->map.enemy[i] = malloc(sizeof(int) * 2);
		if (!data->map.enemy[i])
			control_error(data, 5);
		i++;
	}
	enemies_coor(data);
}
